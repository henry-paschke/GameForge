#pragma once

#ifdef GF_USING_CHIPMUNK2D 
    #include <chipmunk/chipmunk.h>
#endif
#ifdef GF_USING_SFML
    #include <SFML/System.hpp>
#endif

#include <cmath>
#include "Angle.hpp"

namespace gf
{
    /**
     * @brief A class to represent a 2D vector
    */
    template <typename Vector_type>
    struct Vector2
    {
        /*Constructors*/

        /**
         * @brief Default constructor for the vector, creates a 0 vector
        */
        constexpr Vector2():
            x{},
            y{}
        {}

        /**
         * @brief Constructor for the vector that takes an angle 
         * and constructs a unit vector in that direction
         * 
         * @param angle The angle of the vector
        */
        constexpr static inline Vector2 from_angle(const Angle& angle);

        /**
         * @brief Constructor for the vector that takes an x 
         * and y component and constructs a vector with those 
         * components by casting them to floats
         * 
         * @param x The x component of the vector
         * @param y The y component of the vector
        */
        template<typename T1, typename T2>
        constexpr Vector2(const T1 x, const T2 y): 
            x{static_cast<Vector_type>(x)}, 
            y{static_cast<Vector_type>(y)}
        {}

        /**
         * @brief Copy constructor for the vector that takes 
         * another vector and constructs a new vector with 
         * the same components, works with Vector2, cpVect, 
         * sf::Vector2f, and sf::Vector2i, or any other vector 
         * with x and y components exposed
         * 
         * @param vector The vector to copy
        */
        template <typename OtherType>
        constexpr Vector2(const OtherType& vector): 
            x{static_cast<Vector_type>(vector.x)}, 
            y{static_cast<Vector_type>(vector.y)}
        {}

        /*Conversion operators*/

        /**
         * @brief Conversion operator for the vector that
         * converts the vector to a different type
         * 
        */
        template <typename OtherType>
        operator Vector2<OtherType>() const
        {
            return Vector2<OtherType>(x, y);
        }
        
        #ifdef GF_USING_CHIPMUNK2D
        /**
         * @brief Conversion operator for the vector that
         * converts the vector to a cpVect
         * 
         * @param x The x component of the vector
         * @param y The y component of the vector
        */
        operator cpVect() const
        {
            return cpv(x, y);
        }
        #endif

        #ifdef GF_USING_SFML
        /**
         * @brief Conversion operator for the vector that
         * converts the vector to a sf::Vector2f
         * 
         * @param x The x component of the vector
         * @param y The y component of the vector
        */
        operator sf::Vector2f() const
        {
            return sf::Vector2f(x, y);
        }

        /**
         * @brief Conversion operator for the vector that
         * converts the vector to a sf::Vector2i by casting.
         * 
         * @param x The x component of the vector
         * @param y The y component of the vector
        */
        operator sf::Vector2i() const
        {
            return sf::Vector2i(static_cast<int>(x), static_cast<int>(y));
        }

        #endif

        /*Setters*/

        /**
         * @brief Sets the x component of the vector
         * 
         * @param x The new x component
        
        */
        void set_x(const Vector_type x)
        {
            this->x = x;
        }

        /**
         * @brief Sets the y component of the vector
         * 
         * @param y The new y component
        */
        void set_y(const Vector_type y)
        {
            this->y = y;
        }

        /**
         * @brief Sets the angle of the vector while keeping the magnitude the same
         * 
         * @param angle The new angle of the vector
        */
        void set_angle(const Angle& angle)
        {
           	if (angle != 0)
            {
                float sin_of = angle.sin();
                float cos_of = angle.cos();

                x = (x * cos_of) - (y * sin_of);
                y = (x * sin_of) + (y * cos_of);
            } 
        }

        /*Getters*/

        /**
         * @brief Gets the x component of the vector
        */
        Vector_type get_x() const
        {
            return x;
        }

        /**
         * @brief Gets the y component of the vector
        */
        Vector_type get_y() const
        {
            return y;
        }

        /**
         * @brief Gets the angle of the vector
        */
        Angle get_angle() const
        {
            return std::atan2(y, x);
        }

        /**
         * @brief Gets the normalized vector
        */
        Vector2 get_normalized() const
        {
            Vector_type length = get_length();
            if (length != 0)
                return Vector2(x / length, y / length);
            else
                return Vector2(0, 0);
        }

        /**
         * @brief Gets the magnitude of the vector
        */
        Vector_type get_length() const
        {
            return std::sqrt((x * x) + (y * y));
        }

        /**
         * @brief Gets the vector rotated by a certain angle about the origin
        */
        Vector2 get_rotated(const Angle& angle) const
        {
            double sin_of = angle.sin();
            double cos_of = angle.cos();
            return Vector2((x * cos_of) - (y * sin_of), (x * sin_of) + (y * cos_of));
        }

        /**
         * @brief Gets absolute value of the vector
        */
        Vector2 get_abs() const
        {
            return Vector2(std::abs(x), std::abs(y));
        }

        /**
         * @brief Gets the dot product of two vectors
         * 
         * @param other The vector to get the dot product with
        */
        Vector_type get_dot_product(const Vector2& other) const
        {
	        return (x * other.x) + (y * other.y);
        }

        /**
         * @brief Gets the cross product of two vectors
         * 
         * @param other The vector to get the cross product with
        */
        Vector_type get_cross_product(const Vector2& other) const
        {
            return (x * other.y) - (y * other.x);
        }

        /**
         * @brief Gets the vector mirrored about an axis
        */
        Vector2 get_reflected(const Vector2& axis) const
        {
            return *this - (axis * 2 * get_dot_product(axis));
        }

        /**
         * @brief Gets the vector flipped about a vertical axis
        */
        Vector2 get_flipped_x(Vector_type x) const
        {
            return Vector2(x - (this->x - x), y);
        }

        /**
         * @brief Gets the vector flipped about a horizontal axis
        */
        Vector2 get_flipped_y(Vector_type y) const
        {
            return Vector2(x, y - (this->y - y));
        }

        /**
         * @brief Gets the vector as a string
        */
        std::string get_string() const
        {
	        return "Vector2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
        }


        /*Operator overloads*/

        /**
         * @brief Adds two vectors together
         * 
         * @param other The vector to add to this vector
        */
        Vector2 operator+(const Vector2& other) const
        {
            return Vector2(x + other.x, y + other.y);
        }

        /**
         * @brief Subtracts two vectors
         * 
         * @param other The vector to subtract from this vector
        */
        Vector2 operator-(const Vector2& other) const
        {
            return Vector2(x - other.x, y - other.y);
        }

        /**
         * @brief Negates a vector by flipping the sign of its components
        */
        Vector2 operator-() const
        {
            return Vector2(-x, -y);
        }


        /**
         * @brief Multiplies a vector by a scalar
         * 
         * @param scalar The scalar to multiply the vector by
        */
        template <typename ScalarType>
        Vector2 operator*(const ScalarType scalar) const
        {
            return Vector2(x * scalar, y * scalar);
        }

        /**
         * @brief Multiplies two vectors together
         * 
         * @param other The vector to multiply this vector by
        */
        Vector2 operator*(const Vector2& other) const
        {
            return Vector2(x * other.x, y * other.y);
        }

        /**
         * @brief Divides a vector by a scalar
         * 
         * @param scalar The scalar to divide the vector by
        */
        template <typename ScalarType>
        Vector2 operator/(const ScalarType scalar) const
        {
            return Vector2(x / scalar, y / scalar);
        }

        /**
         * @brief Divides two vectors
         * 
         * @param other The vector to divide this vector by
        */
        Vector2 operator/(const Vector2& other) const
        {
            return Vector2(x / other.x, y / other.y);
        }

        /**
         * @brief Adds two vectors together
         * 
         * @param other The vector to add to this vector
        */
        Vector2 operator+=(const Vector2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        /**
         * @brief Subtracts two vectors
         * 
         * @param other The vector to subtract from this vector
        */
        Vector2 operator-=(const Vector2& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        /**
         * @brief Multiplies a vector by a scalar
         * 
         * @param scalar The scalar to multiply the vector by
        */
        Vector2 operator*=(const float scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        /**
         * @brief Multiplies two vectors together
         * 
         * @param other The vector to multiply this vector by
        */
        Vector2 operator*=(const Vector2& other)
        {
            x *= other.x;
            y *= other.y;
            return *this;
        }

        /**
         * @brief Divides a vector by a scalar
         * 
         * @param scalar The scalar to divide the vector by
        */
        Vector2 operator/=(const float scalar)
        {
            x /= scalar;
            y /= scalar;
            return *this;
        }

        /**
         * @brief Divides two vectors
         * 
         * @param other The vector to divide this vector by
        */
        Vector2 operator/=(const Vector2& other)
        {
            x /= other.x;
            y /= other.y;
            return *this;
        }

        /**
         * @brief Compares two vectors
         * 
         * @param other The vector to compare to this vector to
        */
        bool operator==(const Vector2& other) const
        {
            return (x == other.x) && (y == other.y);
        }

        /**
         * @brief Sends the vector to an output stream
         * 
         * @param os The output stream to send the vector to
         * @param vector The vector to send to the output stream
        */
        friend std::ostream& operator<<(std::ostream& os, const Vector2& vector)
        {
            return os << vector.get_string();
        }

        Vector_type x; ///< The x component of the vector
        Vector_type y; ///< The y component of the vector
    };

    using Vector2d = Vector2<double> ; // A vector with double components
    using Vector2f = Vector2<float>; // A vector with float components
    using Vector2i = Vector2<int> ; // A vector with int components

    template <typename Vector_type>
    constexpr inline Vector2<Vector_type> Vector2<Vector_type>::from_angle(const Angle& angle)
    {
        return Vector2<Vector_type>{static_cast<Vector_type>(angle.cos()), static_cast<Vector_type>(angle.sin())};
    }

};