#pragma once 

#ifdef GF_USING_CHIPMUNK2D 
    #include <chipmunk/chipmunk.h>
#endif
#ifdef GF_USING_SFML
    #include <SFML/System.hpp>
    #include <SFML/Graphics.hpp>
#endif

#include "Vector2.hpp"

namespace gf
{
    struct Aabb
    {
        /**
         * @brief Default constructor.
         * 
         * Initializes the AABB with a position and dimensions of (0, 0).
         */
        constexpr Aabb():
            position{},
            dimensions{}
        {}

        /**
         * @brief Constructor that takes a position and dimensions.
         * 
         * @param position The center position of the AABB.
         * @param dimensions The dimensions (width and height) of the AABB.
         */
        template <typename A, typename B>
        constexpr Aabb(const A& position, const B& dimensions): 
            position(position),
            dimensions(dimensions) 
        {}

        /**
         * @brief Constructor that takes individual coordinates for position and dimensions.
         * 
         * @param x The x-coordinate of the position.
         * @param y The y-coordinate of the position.
         * @param width The width of the AABB.
         * @param height The height of the AABB.
         */
        template <typename A, typename B, typename C, typename D>
        constexpr Aabb(A x, B y, C width, D height): 
            position(x, y), 
            dimensions(width, height) 
        {}


        #ifdef GF_USING_CHIPMUNK2D 
            Aabb(const cpBB& bb);
            operator cpBB() const;
        #endif
        #ifdef GF_USING_SFML
            Aabb(const sf::IntRect& rect);
            operator sf::IntRect() const;
            Aabb(const sf::FloatRect& rect);
            operator sf::FloatRect() const;
            operator sf::RectangleShape() const;
        #endif

        /* Setters */

        /**
         * @brief Sets the position of the AABB.
         * 
         * @tparam T The type of the position.
         * @param position The new position.
         */
        template <typename T>
        void set_position(const T& position)
        {
            this->position = gf::Vector2f(position);
        }

        /**
         * @brief Sets the dimensions of the AABB.
         * 
         * @tparam T The type of the dimensions.
         * @param dimensions The new dimensions.
        */
        template <typename T>
        void set_dimensions(const T& dimensions)
        {
            this->dimensions = gf::Vector2f(dimensions);
        }

        /**
         * @brief Sets the left edge of the AABB.
         * 
         * @param x The new x-coordinate of the left edge.
        */
        void set_left(float x);

        /**
         * @brief Sets the right edge of the AABB.
         * 
         * @param x The new x-coordinate of the right edge.
        */
        void set_right(float x);

        /**
         * @brief Sets the top edge of the AABB.
         * 
         * @param y The new y-coordinate of the top edge.
        */
        void set_top(float y);

        /**
         * @brief Sets the bottom edge of the AABB.
         * 
         * @param y The new y-coordinate of the bottom edge.
        */
        void set_bottom(float y);

        /**
         * @brief Sets the center x-coordinate of the AABB.
         * 
         * @param x The new x-coordinate of the center.
        */
        void set_centerx(float x);

        /**
         * @brief Sets the center y-coordinate of the AABB.
         * 
         * @param y The new y-coordinate of the center.
        */
        void set_centery(float y);

        /**
         * @brief Sets the width of the AABB.
         * 
         * @param width The new width.
        */
        void set_width(float width);

        /**
         * @brief Sets the height of the AABB.
         * 
         * @param height The new height.
        */
        void set_height(float height);

        /* Getters */

        /**
         * @brief Returns the left edge of the AABB
         * 
         * @return The x-coordinate of the left edge
        */
        constexpr float get_left() const
        {
            return position.x - dimensions.x / 2;
        }

        /**
         * @brief Returns the right edge of the AABB
         * 
         * @return The x-coordinate of the right edge
        */
        constexpr float get_right() const
        {
            return position.x + dimensions.x / 2;
        }

        /**
         * @brief Returns the top edge of the AABB
         * 
         * @return The y-coordinate of the top edge
        */
        constexpr float get_top() const
        {
            return position.y - dimensions.y / 2;
        }

        /**
         * @brief Returns the bottom edge of the AABB
         * 
         * @return The y-coordinate of the bottom edge
        */
        constexpr float get_bottom() const
        {
            return position.y + dimensions.y / 2;
        }

        /**
         * @brief Returns the center x-coordinate of the AABB
         * 
         * @return The x-coordinate of the center
        */
        constexpr float get_centerx() const
        {
            return position.x;
        }

        /**
         * @brief Returns the center y-coordinate of the AABB
         * 
         * @return The y-coordinate of the center
        */
        constexpr float get_centery() const
        {
            return position.y;
        }

        /**
         * @brief Returns the width of the AABB
         * 
         * @return The width of the AABB
        */
        constexpr float get_width() const
        {
            return dimensions.x;
        }

        /**
         * @brief Returns the height of the AABB
         * 
         * @return The height of the AABB
        */
        constexpr float get_height() const
        {
            return dimensions.y;
        }

        /**
         * @brief Returns the position of the AABB
         * 
         * @return The position of the AABB
        */
        constexpr gf::Vector2f get_position() const
        {
            return position;
        }

        /**
         * @brief Returns the dimensions of the AABB
         * 
         * @return The dimensions of the AABB
        */
        constexpr gf::Vector2f get_dimensions() const
        {
            return dimensions;
        }

        /**
         * @brief Returns a string representation of the Aabb
        */
        std::string get_string() const;

        /**
         * @brief Returns a bool indicating whether the Aabb intersects with another Aabb
         * 
        */
        bool intersects(const Aabb& other) const;

        /* Printing utilities */

        /**
         * @brief Outputs the Aabb as a string
         * 
         * @param os The output stream
         * @param obj The Aabb to output
        */
        friend std::ostream& operator<<(std::ostream& os, const Aabb& obj);

        /* Member variables */
        gf::Vector2f position; ///< The center of the bounding box
        gf::Vector2f dimensions; ///< The width and height of the bounding box
    };

} // namespace gf
