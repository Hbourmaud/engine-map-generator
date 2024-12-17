#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>

class ThreadPool
{
    public:
        ThreadPool(size_t numThreads);
        ~ThreadPool();

        void enqueue(std::function<void()> task);

    private:
        std::vector<std::thread> threads;

        std::queue<std::function<void()> > tasks;

        std::mutex queueMutex;

        std::condition_variable cv;
    
        bool stop = false;
};