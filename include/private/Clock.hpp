#pragma once

#include "Time.hpp"
#include <functional>

namespace gf
{
    class Clock
    {
    public:
        Clock(const Time& length);
        Clock(const Time& length, const std::function<void()>& new_callback);
        Clock(const Time& length, const Time& elapsed, const std::function<void()>& new_callback);
        void restart();
        void reset(const Time& length);

        void set_length(const Time& new_length);

        Time get_length() const;
        float get_normalized_progress() const;
        Time get_elapsed_time() const;
        Time get_remaining_time() const;
        bool get_finished() const;

        void tick(const Time& delta_time);

        void add_callback(const std::function<void()>& new_callback);

    private:
        Time length;
        Time elapsed;
        std::function<void()> callback;
    };

} // namespace gf
