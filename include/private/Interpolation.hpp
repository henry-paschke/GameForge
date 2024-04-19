#pragma once

#include <functional>

namespace gf
{
    using Easing_function = std::function<float(float)>;

    /**
     * @brief Linearly interpolates between two values
     * 
     * @tparam T The type of the values to interpolate, can be any type that supports the +, -, and * operators
     * @param start_point The starting value
     * @param end_point The ending value
     * @param normalized_time The normalized time between the start and end points
     * @param easing_function The easing function to use
    */
    template <typename T>
    T lerp(const T& start_point, const T& end_point, const float normalized_time, const Easing_function& easing_function = easing::linear)
    {   
        if (normalized_time > 1.0f || normalized_time < 0.0f)
        {
            throw std::invalid_argument("Normalized time must be between 0.0 and 1.0");
        }
        return start_point + (end_point - start_point) * easing_function(normalized_time);
    }

    namespace easing
    {
        float linear(float t);
        float in_quad(float t);
        float out_quad(float t);
        float in_out_quad(float t);
        float in_cubic(float t);
        float out_cubic(float t);
        float in_out_cubic(float t);
        float in_quart(float t);
        float out_quart(float t);
        float in_out_quart(float t);
        float in_quint(float t);
        float out_quint(float t);
        float in_out_quint(float t);
        float in_sine(float t);
        float out_sine(float t);
        float in_out_sine(float t);
        float in_expo(float t);
        float out_expo(float t);
        float in_out_expo(float t);
        float in_circ(float t);
        float out_circ(float t);
        float in_out_circ(float t);
    } // namespace easing

}; // namespace gf