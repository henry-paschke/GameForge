#pragma once
#include <cmath>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

namespace gf
{
    /**
     * @brief A class to represent an angle in degrees or radians
    */
    template <typename AngleType>
    class AngleT
    {
    public:

        /**
         * @brief Construct a new Angle object with a value of 0.
        */
        AngleT():
            radians{}
        {}

        /**
         * @brief Construct a new Angle object.
         * 
         * @param radians The angle in radians.
        */
        template <typename OtherAngleType>
        AngleT(OtherAngleType radians):
            radians{static_cast<AngleType>(radians)}
        {}

        /**
         * @brief Conversion operator to convert the angle to another type.
        */
        template <typename OtherAngleType>
        operator AngleT<OtherAngleType>() const
        {
            return AngleT<OtherAngleType>{static_cast<OtherAngleType>(this->get_radians())};
        }

        /**
         * @brief Construct a new Angle object.
         * 
         * @param degrees The angle in degrees.
        */
        static AngleT from_degrees(AngleType degrees);

        /**
         * @brief Construct a new Angle object.
         * 
         * @param radians The angle in radians.
        */
        static AngleType from_radians(AngleType radians);

        /**
         * @brief Get the angle in degrees.
        */
        AngleType get_degrees() const
        {
            return radians * 180.0 / M_PI;
        }

        /**
         * @brief Get the angle in radians.
        */
        AngleType get_radians() const
        {
            return radians;
        }

        /* Math Functions */

        /**
         * @brief Get the sine of the angle.
         * 
         * @return The sine of the angle.
        */
        AngleType sin() const
        {
            return std::sin(radians);
        }

        /**
         * @brief Get the cosine of the angle.
         * 
         * @return The cosine of the angle.
        */
        AngleType cos() const
        {
            return std::cos(radians);
        }

        /**
         * @brief Get the tangent of the angle.
         * 
         * @return The tangent of the angle.
        */
        AngleType tan() const
        {
            return std::tan(radians);
        }

        /**
         * @brief Get the arc sine of the angle.
         * 
         * @return The arc sine of the angle.
        */
        AngleType asin() const
        {
            return std::asin(radians);
        }

        /**
         * @brief Get the arc cosine of the angle.
         * 
         * @return The arc cosine of the angle.
        */
        AngleType acos() const
        {
            return std::acos(radians);
        }

        /**
         * @brief Get the arc tangent of the angle.
         * 
         * @return The arc tangent of the angle.
        */
        AngleType atan() const
        {
            return std::atan(radians);
        }


        /* Arithmetic Operators */

        /**
         * @brief Add two angles.
         * 
         * @param other The angle to add.
         * @return The sum of the two angles.
         */
        AngleT operator+(const AngleT& other) const
        {
            return AngleT{radians + other.radians};
        }

        /**
         * @brief Subtract an angle from another angle.
         * 
         * @param other The angle to subtract.
         * @return The difference between the two angles.
         */
        AngleT operator-(const AngleT& other) const
        {
            return AngleT{radians - other.radians};
        }

        /**
         * @brief Negate the angle.
         * 
         * @return The negated angle.
         */
        AngleT operator-() const
        {
            return AngleT{-radians};
        }
        
        /**
         * @brief Multiply the angle by a scalar value.
         * 
         * @param scalar The scalar value to multiply by.
         * @return The multiplied angle.
         */
        AngleT operator*(AngleType scalar) const
        {
            return AngleT{radians * scalar};
        }

        /**
         * @brief Divide the angle by a scalar value.
         * 
         * @param scalar The scalar value to divide by.
         * @return The divided angle.
         */
        AngleT operator/(AngleType scalar) const
        {
            return AngleT{radians / scalar};
        }

        /**
         * @brief Add another angle to the current angle.
         * 
         * @param other The angle to add.
         * @return A reference to the current angle after addition.
         */
        AngleT& operator+=(const AngleT& other)
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
        AngleT& operator-=(const AngleT& other)
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
        AngleT& operator*=(AngleType scalar)
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
        AngleT& operator/=(AngleType scalar)
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
        bool operator==(const AngleT& other) const { return radians == other.radians; }

        /**
         * @brief Check if two angles are not equal.
         * 
         * @param other The angle to compare with.
         * @return True if the angles are not equal, false otherwise.
         */
        bool operator!=(const AngleT& other) const { return !(*this == other); }

        /**
         * @brief Check if the current angle is less than another angle.
         * 
         * @param other The angle to compare with.
         * @return True if the current angle is less than the other angle, false otherwise.
         */
        bool operator<(const AngleT& other) const { return radians < other.radians; }

        /**
         * @brief Check if the current angle is greater than another angle.
         * 
         * @param other The angle to compare with.
         * @return True if the current angle is greater than the other angle, false otherwise.
         */
        bool operator>(const AngleT& other) const { return radians > other.radians; }

        /**
         * @brief Check if the current angle is less than or equal to another angle.
         * 
         * @param other The angle to compare with.
         * @return True if the current angle is less than or equal to the other angle, false otherwise.
         */
        bool operator<=(const AngleT& other) const { return !(*this > other); }

        /**
         * @brief Check if the current angle is greater than or equal to another angle.
         * 
         * @param other The angle to compare with.
         * @return True if the current angle is greater than or equal to the other angle, false otherwise.
         */
        bool operator>=(const AngleT& other) const { return !(*this < other); }

    private:

        AngleType radians; ///< The angle in radians

    };

    using Angle = AngleT<double>; // Default angle type
    using Anglef = AngleT<float>; // Single-precision angle type

    /* Literals */
    inline Angle operator"" _deg(long double degrees)
    {
        return Angle::from_degrees(degrees);
    }

    inline Angle operator"" _rad(long double radians)
    {
        return Angle::from_radians(radians);
    }

    template <typename AngleType>
    AngleT<AngleType> AngleT<AngleType>::from_degrees(AngleType degrees)
    {
        return AngleT<AngleType>{degrees * M_PI / 180.0};
    }

    template <typename AngleType>
    AngleType AngleT<AngleType>::from_radians(AngleType radians)
    {
        return radians;
    }

} // namespace gf