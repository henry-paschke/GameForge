#include "Interpolation.hpp"
#include "Angle.hpp"
#include <cmath>

using namespace gf;

float easing::linear(float t)
{
    return t;
}

float easing::in_quad(float t)
{
    return t * t;
}

float easing::out_quad(float t)
{
    return t * (2 - t);
}

float easing::in_out_quad(float t)
{
    if (t < 0.5f)
    {
        return 2 * t * t;
    }
    else
    {
        return -1 + (4 - 2 * t) * t;
    }
}

float easing::in_cubic(float t)
{
    return t * t * t;
}

float easing::out_cubic(float t)
{
    return (--t) * t * t + 1;
}

float easing::in_out_cubic(float t)
{
    if (t < 0.5f)
    {
        return 4 * t * t * t;
    }
    else
    {
        return (t - 1) * (2 * t - 2) * (2 * t - 2) + 1;
    }
}

float easing::in_quart(float t)
{
    return t * t * t * t;
}

float easing::out_quart(float t)
{
    return 1 - (--t) * t * t * t;
}

float easing::in_out_quart(float t)
{
    if (t < 0.5f)
    {
        return 8 * t * t * t * t;
    }
    else
    {
        return 1 - 8 * (--t) * t * t * t;
    }
}

float easing::in_quint(float t)
{
    return t * t * t * t * t;
}

float easing::out_quint(float t)
{
    return 1 + (--t) * t * t * t * t;
}

float easing::in_out_quint(float t)
{
    if (t < 0.5f)
    {
        return 16 * t * t * t * t * t;
    }
    else
    {
        return 1 + 16 * (--t) * t * t * t * t;
    }
}

float easing::in_sine(float t)
{
    return 1 - std::cos(t * M_PI * 2);
}

float easing::out_sine(float t)
{
    return std::sin(t * M_PI / 2);
}

float easing::in_out_sine(float t)
{
    return 0.5f * (1 - std::cos(t * M_PI));
}

float easing::in_expo(float t)
{
    return static_cast<float>((t == 0) ? 0 : std::pow(2, 10 * (t - 1)));
}

float easing::out_expo(float t)
{
    return static_cast<float>((t == 1) ? 1 : 1 - std::pow(2, -10 * t));
}

float easing::in_out_expo(float t)
{
    if (t == 0)
    {
        return 0;
    }
    if (t == 1)
    {
        return 1;
    }
    if (t < 0.5f)
    {
        return static_cast<float>(0.5f * std::pow(2, 20 * t - 10));
    }
    else
    {
        return static_cast<float>(1 - 0.5f * std::pow(2, -20 * t + 10));
    }
}

float easing::in_circ(float t)
{
    return 1 - std::sqrt(1 - t * t);
}

float easing::out_circ(float t)
{
    return std::sqrt((2 - t) * t);
}

float easing::in_out_circ(float t)
{
    if (t < 0.5f)
    {
        return 0.5f * (1 - std::sqrt(1 - 4 * t * t));
    }
    else
    {
        return 0.5f * (std::sqrt(-((2 * t - 3) * (2 * t - 1))) + 1);
    }
}

