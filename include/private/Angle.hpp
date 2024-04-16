#pragma once

#include <cmath>
#include <string>
#include <iostream>

namespace gf
{

    const float M_PI{3.14159265f};   ///< The value of pi to 8 decimal places, defined as a constant here because it is not defined in the cmath header

    /**
     * @brief A class to represent an angle in degrees or radians
    */
    class Angle
    {
    public:

        /**
         * @brief Construct a new Angle object with a value of 0.
        */
        Angle():
            radians{}
        {}

        /**
         * @brief Construct a new Angle object.
         * 
         * @param radians The angle in radians.
        */
        Angle(float radians):
            radians{static_cast<float>(radians)}
        {}

        /**
         * @brief Construct a new Angle object.
         * 
         * @param radians The angle in radians.
        */
        Angle(double radians):
            radians{static_cast<float>(radians)}
        {}

        /**
         * @brief Construct a new Angle object.
         * 
         * @param degrees The angle in degrees.
        */
        static inline Angle from_degrees(float degrees);

        /**
         * @brief Construct a new Angle object.
         * 
         * @param radians The angle in radians.
        */
        static inline Angle from_radians(float radians);

        /**
         * @brief Get the angle in degrees.
        */
        float get_degrees() const
        {
            return radians * 180.0f / M_PI;
        }

        /**
         * @brief Get the angle in radians.
        */
        float get_radians() const
        {
            return radians;
        }

        Angle get_mod(const Angle& angle) const
        {
            return Angle{std::fmod(radians, angle.get_radians())}; 
        }

        /* Math Functions */

        /**
         * @brief Get the sine of the angle.
         * 
         * @return The sine of the angle.
        */
        float sin() const
        {
            return std::sinf(radians);
        }

        /**
         * @brief Get the cosine of the angle.
         * 
         * @return The cosine of the angle.
        */
        float cos() const
        {
            return std::cosf(radians);
        }

        /**
         * @brief Get the tangent of the angle.
         * 
         * @return The tangent of the angle.
        */
        float tan() const
        {
            return std::tanf(radians);
        }

        /**
         * @brief Get the arc sine of the angle.
         * 
         * @return The arc sine of the angle.
        */
        float asin() const
        {
            return std::asinf(radians);
        }

        /**
         * @brief Get the arc cosine of the angle.
         * 
         * @return The arc cosine of the angle.
        */
        float acos() const
        {
            return std::acosf(radians);
        }

        /**
         * @brief Get the arc tangent of the angle.
         * 
         * @return The arc tangent of the angle.
        */
        float atan() const
        {
            return std::atanf(radians);
        }


        /* Arithmetic Operators */

        /**
         * @brief Add two angles.
         * 
         * @param other The angle to add.
         * @return The sum of the two angles.
         */
        Angle operator+(const Angle& other) const
        {
            return Angle{radians + other.radians};
        }

        /**
         * @brief Subtract an angle from another angle.
         * 
         * @param other The angle to subtract.
         * @return The difference between the two angles.
         */
        Angle operator-(const Angle& other) const
        {
            return Angle{radians - other.radians};
        }

        /**
         * @brief Negate the angle.
         * 
         * @return The negated angle.
         */
        Angle operator-() const
        {
            return Angle{-radians};
        }
        
        /**
         * @brief Multiply the angle by a scalar value.
         * 
         * @param scalar The scalar value to multiply by.
         * @return The multiplied angle.
         */
        Angle operator*(float scalar) const
        {
            return Angle{radians * scalar};
        }

        /**
         * @brief Divide the angle by a scalar value.
         * 
         * @param scalar The scalar value to divide by.
         * @return The divided angle.
         */
        Angle operator/(float scalar) const
        {
            return Angle{radians / scalar};
        }

        /**
         * @brief Add another angle to the current angle.
         * 
         * @param other The angle to add.
         * @return A reference to the current angle after addition.
         */
        Angle& operator+=(const Angle& other)
        {
            radians += other.radians;
            return *this;
        }

        /**
         * @brief Subtract another angle from the current angle.
         * 
         * @param other The angle to subtract.
         * @return A reference to the current angle after subtraction.
         */
        Angle& operator-=(const Angle& other)
        {
            radians -= other.radians;
            return *this;
        }

        /**
         * @brief Multiply the current angle by a scalar value.
         * 
         * @param scalar The scalar value to multiply by.
         * @return A reference to the current angle after multiplication.
         */
        Angle& operator*=(float scalar)
        {
            radians *= scalar;
            return *this;
        }
        
        /**
         * @brief Divide the current angle by a scalar value.
         * 
         * @param scalar The scalar value to divide by.
         * @return A reference to the current angle after division.
         */
        Angle& operator/=(float scalar)
        {
            radians /= scalar;
            return *this;
        }

        /* Comparison Operators*/

        /**
         * @brief Check if two angles are equal.
         * 
         * @param other The angle to compare with.
         * @return True if the angles are equal, false otherwise.
         */
        bool operator==(const Angle& other) const { return radians == other.radians; }

        /**
         * @brief Check if two angles are not equal.
         * 
         * @param other The angle to compare with.
         * @return True if the angles are not equal, false otherwise.
         */
        bool operator!=(const Angle& other) const { return !(*this == other); }

        /**
         * @brief Check if the current angle is less than another angle.
         * 
         * @param other The angle to compare with.
         * @return True if the current angle is less than the other angle, false otherwise.
         */
        bool operator<(const Angle& other) const { return radians < other.radians; }

        /**
         * @brief Check if the current angle is greater than another angle.
         * 
         * @param other The angle to compare with.
         * @return True if the current angle is greater than the other angle, false otherwise.
         */
        bool operator>(const Angle& other) const { return radians > other.radians; }

        /**
         * @brief Check if the current angle is less than or equal to another angle.
         * 
         * @param other The angle to compare with.
         * @return True if the current angle is less than or equal to the other angle, false otherwise.
         */
        bool operator<=(const Angle& other) const { return !(*this > other); }

        /**
         * @brief Check if the current angle is greater than or equal to another angle.
         * 
         * @param other The angle to compare with.
         * @return True if the current angle is greater than or equal to the other angle, false otherwise.
         */
        bool operator>=(const Angle& other) const { return !(*this < other); }

        /* Printing utilities */

        /**
         * @brief Get the angle as a string.
         * 
         * @return The angle as a string.
         */
        std::string get_string() const
        {
            return std::to_string(get_degrees()) + "_deg";
        }

        /**
         * @brief Print the angle to an output stream.
         * 
         * @param os The output stream to print to.
         * @param angle The angle to print.
         * @return The output stream.
         */
        friend inline std::ostream& operator<<(std::ostream& os, const Angle& angle)
        {
            return os << angle.get_string();
        }

    private:

        float radians; ///< The angle in radians

    };

    /* Static definitions */

    inline Angle Angle::from_degrees(float degrees)
    {
        return Angle{degrees * M_PI / 180.0};
    }

    inline Angle Angle::from_radians(float radians)
    {
        return Angle{radians};
    }

    /* Constants for convenience */
    const Angle PI{M_PI};            ///< The value of pi as an angle for efficiency
    const Angle TWO_PI{2.0f * M_PI}; ///< The value of 2 * pi as an angle for efficiency


} // namespace gf

/* Literals */

inline gf::Angle operator"" _deg(long double degrees)
{
    return gf::Angle::from_degrees(static_cast<float>(degrees));
}

inline gf::Angle operator"" _rad(long double radians)
{
    return gf::Angle::from_radians(static_cast<float>(radians));
}