#pragma once
#include <chrono>
#include <thread>

namespace Time
{
    using Clock = std::chrono::steady_clock;
    
    inline float time = 0;
    inline float deltaTime = 0;
    inline float fixedDt = 1.0f/60.0f;

    inline Clock::time_point frameStart = Clock::now();
    inline Clock::time_point previousFrame = frameStart;

    inline void beginFrame() {
        frameStart = Clock::now();
        deltaTime = std::chrono::duration<float>(
            frameStart - previousFrame
        ).count();

        previousFrame = frameStart;
        time += deltaTime;
    }

    inline void limitFrameRate(float frameTime){
        const auto targetDuration = std::chrono::duration_cast<Clock::duration>(
            std::chrono::duration<float>(frameTime)
        );
        const auto deadline = frameStart+targetDuration;
        if(Clock::now() < deadline)
            std::this_thread::sleep_until(deadline);
    }
}
