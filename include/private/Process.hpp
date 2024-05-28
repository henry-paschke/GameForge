#pragma once

#include "Clock.hpp"
#include "Interpolation.hpp"
#include "Angle.hpp"
#include "Vector2.hpp"
#include "Transform2.hpp"


namespace gf
{
    /**
     * @brief A linear process for interpolating between two values
     * 
     * @tparam T The type of the values to interpolate. Can be any type that supports the +, -, and * operators
    */
    template <typename T>
    class Linear_process
    {
        public:
            /**
             * @brief Construct a new Linear process object
             * 
             * @param start The starting value
             * @param end The ending value
             * @param length The length of the process
             * @param easing The easing function to use
            */
            Linear_process(const T& start, const T& end, const Time& length, const Easing_function& easing = easing::linear):
                start{start}, 
                end{end},
                clock{length},
                easing{easing}
            {}

            /**
             * @brief Reset the process
            */
            void reset_process()
            {
                clock.restart();
            }

            /**
             * @brief Reset the process with a new length
             * 
             * @param new_length The new length of the process
            */
            void reset_process(const Time& new_length)
            {
                clock.reset(new_length);
            }

            /**
             * @brief Set the end value of the process
             * 
             * @param new_end The new end value
            */
            void set_end(const T& new_end)
            {
                end = new_end;
            }

            /**
             * @brief Set the start value of the process
             * 
             * @param new_start The new start value
            */
            void set_start(const T& new_start)
            {
                start = new_start;
            }

            /**
             * @brief Set the length of the process
             * 
             * @param new_length The new length of the process
            */
            void set_length(const Time& new_length)
            {
                clock.set_length(new_length);
            }

            /**
             * @brief Get the length of the process
             * 
             * @return Time The length of the process
            */
            void update(const Time& dt)
            {
                clock.tick(dt);
            }

            /**
             * @brief Finish the process
            */
            void finish()
            {
                clock.tick(clock.get_remaining_time());
            }

            /**
             * @brief Get the current position of the process
             * 
             * @return T The current position
            */
            bool get_finished() const
            {
                return clock.get_finished();
            }

            const T& get_start() const
            {
                return start;
            }

            const T& get_end() const
            {
                return end;
            }

            /**
             * @brief Get the current position of the process
             * 
             * @return T The current position
            */
            T get() const
            {
                if (clock.get_finished())
                    return end;
                else
                    return gf::lerp(start, end, clock.get_normalized_progress());
            }

        private:
            T start; ///< The starting value
            T end; ///< The ending value
            Clock clock; ///< The clock for the process
            const Easing_function& easing; ///< The easing function to use
    };

    /**
     * @brief A linear process for angles
     * 
     * This process will interpolate between two angles, taking into account the shortest path. 
     * Using a normal linear interpolation would cause the angle to take an ambiguous path.
    */
    class Angular_linear_process : public Linear_process<Angle>
    {
        public:
            /**
             * @brief Construct a new Angular linear process object
             * 
             * @param start The starting angle
             * @param end The ending angle
             * @param length The length of the process
             * @param easing The easing function to use
            */
            Angular_linear_process(Angle start, Angle end, const Time& length, const Easing_function& easing = easing::linear): 
                Linear_process<gf::Angle>(start.get_mod(TWO_PI), end.get_mod(TWO_PI), length, easing) 
            {
                if (get_start() - get_end() > gf::PI)
                    set_end(get_end() + gf::TWO_PI);
                if (get_start() - get_end() < -gf::PI)
                    set_end(get_end() - gf::TWO_PI);
            }
    };

    class Transform_linear_process
    {
        public:
            /**
             * @brief Construct a new Transform linear process object
             * 
             * @param start The starting transform
             * @param end The ending transform
             * @param length The length of the process
            */
            Transform_linear_process(const Transform2& start, const Transform2& end, const Time& length, const Easing_function &easing_function = easing::linear);

            /**
             * @brief Reset the process
            */
            void reset_process();

            /**
             * @brief Reset the process with a new length
             * 
             * @param new_length The new length of the process
            */
            void reset_process(const Time& new_length);

            /**
             * @brief Set the end value of the process
             * 
             * @param new_end The new end value
            */
            void set_end(const Transform2& new_end);

            /**
             * @brief Set the start value of the process
             * 
             * @param new_start The new start value
            */
            void set_start(const Transform2& new_start);

            /**
             * @brief Set the length of the process
             * 
             * @param new_length The new length of the process
            */
            void set_length(const Time& new_length);

            /**
             * @brief Get the length of the process
             * 
             * @return Time The length of the process
            */
            void update(const Time& dt);

            /**
             * @brief Finish the process
            */
            void finish();

            /**
             * @brief Get the current position of the process
             * 
             * @return T The current position
            */
            bool get_finished() const;

            /**
             * @brief Get the starting transform of the process
            */
            Transform2 get_start() const;

            /**
             * @brief Get the ending transform of the process
            */
            Transform2 get_end() const;

            /**
             * @brief Get the current position of the process
             * 
             * @return T The current position
            */
            Transform2 get() const;

        private:
            Linear_process<gf::Vector2f> position; ///< The linear process for the position
            Angular_linear_process rotation; ///< The angular linear process for the rotation
    };

} // namespace gf
