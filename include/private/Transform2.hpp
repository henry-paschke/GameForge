#pragma once
#include <iostream>
#include "Angle.hpp"
#include "Vector2.hpp"

namespace gf
{
    struct Transform2
    {
        /* Constructors */

        /**
         * @brief Construct a new Transform2 object with a position of (0, 0), a rotation of 0 and a scale of (1, 1).
         *
        */
        Transform2();

        /**
         * @brief Construct a new Transform2 object.
         *
         * @param x The x position of the transform.
         * @param y The y position of the transform.
         * 
         * @param rotation The rotation of the transform.
        */
        Transform2(const float x, const float y, const Angle& rotation);

        /**
         * @brief Construct a new Transform2 object.
         *
         * @param position The position of the transform.
         * @param rotation The rotation of the transform.
        */
        Transform2(const Vector2f& position, const Angle& rotation);

        /**
         * @brief Construct a new Transform2 object.
         *
         * @param position The position of the transform.
         * @param rotation The rotation of the transform.
         * @param scale The scale of the transform.
        */
        Transform2(const Vector2f& position, const Angle& rotation, const Vector2f& scale);

        /**
         * @brief Construct a new Transform2 object.
         *
         * @param x The x position of the transform.
         * @param y The y position of the transform.
         * @param rotation The rotation of the transform.
         * @param scale_x The x scale of the transform.
         * @param scale_y The y scale of the transform.
        */
        Transform2(const float x, const float y, const Angle& rotation, const float scale_x, const float scale_y);

        /* Getters */

        /**
         * @brief Get the position of the transform.
         *
         * @return The position of the transform.
        */
        Vector2f get_position() const;

        /**
         * @brief Get the rotation of the transform.
         *
         * @return The rotation of the transform.
        */
        Angle get_rotation() const;

        /**
         * @brief Get the scale of the transform.
         *
         * @return The scale of the transform.
        */
        Vector2f get_scale() const;

        /**
         * @brief Get the transform as a string.
         *
         * @return The transform as a string.
        */
        std::string get_string() const;

        /* Setters */

        /**
         * @brief Set the position of the transform.
         *
         * @param position The new position of the transform.
        */
        void set_position(const Vector2f& position);

        /**
         * @brief Set the rotation of the transform.
         *
         * @param rotation The new rotation of the transform.
        */
        void set_rotation(const Angle& rotation);

        /**
         * @brief Set the scale of the transform.
         *
         * @param scale The new scale of the transform.
        */
        void set_scale(const Vector2f& scale);

        /* Operators */

        /**
         * @brief Multiply two transforms.
        */
        Transform2 operator*(const Transform2& other) const;

        /**
         * @brief Multiply a transform by another transform.
        */
        Transform2& operator*=(const Transform2& other);

        /**
         * @brief Add an angle to the transform's rotation.
        */
        Transform2 operator+(const Angle& angle) const;

        /**
         * @brief Add an angle to the transform's rotation.
        */
        Transform2& operator+=(const Angle& angle);

        /**
         * @brief Subtract an angle from the transform's rotation.
        */
        Transform2 operator-(const Angle& angle) const;

        /**
         * @brief Subtract an angle from the transform's rotation.
        */
        Transform2& operator-=(const Angle& angle);    

        /**
         * @brief Add a vector to the transform's position.
        */
        Transform2 operator+(const Vector2f& vector) const;

        /**
         * @brief Add a vector to the transform's position.
        */
        Transform2& operator+=(const Vector2f& vector);

        /**
         * @brief Subtract a vector from the transform's position.
        */
        Transform2 operator-(const Vector2f& vector) const;

        /**
         * @brief Subtract a vector from the transform's position.
        */
        Transform2& operator-=(const Vector2f& vector);

        /**
         * @brief Compare two transforms.
        */
        bool operator==(const Transform2& other) const;

        /**
         * @brief Compare two transforms.
        */
        bool operator!=(const Transform2& other) const;

        /* Methods */

        /**
         * @brief Translate the transform by a vector.
         *
         * @param offset The vector to translate by.
        */
        void translate(const Vector2f& offset);

        /**
         * @brief Rotate the transform by an angle.
         *
         * @param angle The angle to rotate by.
        */
        void rotate(const Angle& angle);

        /**
         * @brief Scale the transform by a vector.
         *
         * @param factors The vector to scale by.
        */
        void scale_by(const Vector2f& factors);

        /**
         * @brief Get the translation of the transform by a vector.
         *
         * @param offset The vector to translate by.
         * @return The translated transform.
        */
        Transform2 get_translated(const Vector2f& offset) const;

        /**
         * @brief Get the rotation of the transform by an angle.
         *
         * @param angle The angle to rotate by.
         * @return The rotated transform.
        */
        Transform2 get_rotated(const Angle& angle) const;


        /**
         * @brief Get a transform with its position rotated around the origin by an angle.
         *
         * @param angle The angle to rotate by.
         * @return The rotated transform.
        */
        Transform2 get_globally_rotated(const Angle& angle) const;

        /**
         * @brief Get the scale of the transform by a vector.
         *
         * @param factors The vector to scale by.
         * @return The scaled transform.
        */
        Transform2 get_scaled(const Vector2f& factors) const;

        /* Print utilities */

        /**
         * @brief Print the transform to an output stream.
         *
         * @param os The output stream to print to.
         * @param transform The transform to print.
         * @return The output stream.
        */
        friend std::ostream& operator<<(std::ostream& os, const Transform2& transform);

        /* Members */

        Vector2f position; ///< The position of the transform.
        Angle rotation; ///< The rotation of the transform.
        Vector2f scale; ///< The scale of the transform.
    };
} // namespace gf
