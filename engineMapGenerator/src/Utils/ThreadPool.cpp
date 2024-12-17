#include "Utils/ThreadPool.h"

ThreadPool::ThreadPool(size_t numThreads)
{
    for (size_t i = 0; i < numThreads; ++i)
    {
        threads.emplace_back([this] 
        {
            while (true)
            {
                std::function<void()> task;

                {
                    std::unique_lock lock(queueMutex);

                    cv.wait(lock, [this]
                    {
                        return !tasks.empty() || stop;
                    });

                    if (stop && tasks.empty())
                    {
                        return;
                    }

                    task = std::move(tasks.front());
                    tasks.pop();
                }

                task();
            }
        });
    }
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock lock(queueMutex);
        stop = true;
    }

    cv.notify_all();

    for(auto &thread : threads)
    {
        thread.join();
    }
}

void ThreadPool::enqueue(std::function<void()> task)
{
    {
        std::unique_lock lock(queueMutex);
        tasks.emplace(std::move(task));
    }

    cv.notify_all();
}
