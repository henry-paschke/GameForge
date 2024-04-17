#pragma once

#include "Angle.hpp"

#include <cmath>
#include <string>
#include <iostream>

using namespace gf;


Angle Angle::get_mod(const Angle& angle) const
{
    return Angle{std::fmod(radians, angle.radians)}; 
}

std::string Angle::get_string() const
{
    return std::to_string(get_degrees()) + "_deg";
}

/* Math Functions */

float Angle::sin() const
{
    return std::sinf(radians);
}

float Angle::cos() const
{
    return std::cosf(radians);
}

float Angle::tan() const
{
    return std::tanf(radians);
}

float Angle::asin() const
{
    return std::asinf(radians);
}

float Angle::acos() const
{
    return std::acosf(radians);
}

float Angle::atan() const
{
    return std::atanf(radians);
}


/* Arithmetic Operators */

Angle Angle::operator+(const Angle& other) const
{
    return Angle{radians + other.radians};
}

Angle Angle::operator-(const Angle& other) const
{
    return Angle{radians - other.radians};
}

Angle Angle::operator-() const
{
    return Angle{-radians};
}

Angle Angle::operator*(const float scalar) const
{
    return Angle{radians * scalar};
}

Angle Angle::operator/(const float scalar) const
{
    return Angle{radians / scalar};
}

Angle& Angle::operator+=(const Angle& other)
{
    radians += other.radians;
    return *this;
}

Angle& Angle::operator-=(const Angle& other)
{
    radians -= other.radians;
    return *this;
}

Angle& Angle::operator*=(const float scalar)
{
    radians *= scalar;
    return *this;
}

Angle& Angle::operator/=(const float scalar)
{
    radians /= scalar;
    return *this;
}

/* Comparison Operators*/

bool Angle::operator==(const Angle& other) const { return radians == other.radians; }
bool Angle::operator!=(const Angle& other) const { return !(*this == other); }
bool Angle::operator<(const Angle& other) const { return radians < other.radians; }
bool Angle::operator>(const Angle& other) const { return radians > other.radians; }
bool Angle::operator<=(const Angle& other) const { return !(*this > other); }
bool Angle::operator>=(const Angle& other) const { return !(*this < other); }

/* Printing utilities */

std::ostream& operator<<(std::ostream& os, const Angle& angle)
{
    return os << angle.get_string();
}
