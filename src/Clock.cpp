#include "Clock.hpp"

using namespace gf;

Clock::Clock(const Time& length): 
    length{length},
    elapsed{},
    callback{}
{}

gf::Clock::Clock(const Time &length, const std::function<void()> &new_callback):
    length{length.get_milliseconds()},
    elapsed{},
    callback{new_callback}
{}

gf::Clock::Clock(const Time &length, const Time &elapsed, const std::function<void()> &new_callback):
    length{length},
    elapsed{elapsed},
    callback{new_callback}
{}

void Clock::restart()
{
    elapsed = 0.0_s;
}

void gf::Clock::reset(const Time &length)
{
    this->length = length.get_milliseconds();
    elapsed = 0.0_s;
}

void gf::Clock::set_length(const Time &new_length)
{
    length = new_length;
}

Time Clock::get_length() const
{
    return length;
}

float Clock::get_normalized_progress() const
{
    return (elapsed > length) ? 1.0f : elapsed / length;
}

Time Clock::get_elapsed_time() const
{
    return elapsed;
}

Time Clock::get_remaining_time() const
{
    return length - elapsed;
}

bool gf::Clock::get_finished() const
{
    return elapsed >= length;
}

void Clock::tick(const Time& delta_time)
{
    elapsed += delta_time;
    if (elapsed >= length && callback)
    {
        callback();
    }
}

void gf::Clock::add_callback(const std::function<void()> &new_callback)
{
    callback = new_callback;
}
