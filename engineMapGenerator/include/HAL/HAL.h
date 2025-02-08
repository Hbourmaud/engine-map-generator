#pragma once

class HAL
{
    public:
        virtual ~HAL() = default;

        virtual void Initialize() = 0;
        virtual void Shutdown() = 0;
        virtual void Update() = 0;
};
