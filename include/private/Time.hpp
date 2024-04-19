#pragma once

#ifdef GF_USING_SFML
    #include <SFML/System.hpp>
#endif

namespace gf
{
    /**
     * @brief A class to represent time
     * 
     * The internal representation of time is in milliseconds, and it is stored as a float.
    */
    class Time
    {
        public:

            /**
             * @brief Construct a new Time object
             * 
             * The default constructor initializes the time to 0 milliseconds.
            */
            constexpr Time():
                milliseconds{}
            {}

            /**
             * @brief Copy constructor
             * 
             * @param other The Time object to copy
            */
            constexpr Time(const Time& other):
                milliseconds(other.milliseconds)
            {}

            /**
             * @brief Construct a new Time object
             * 
             * @param milliseconds The time in milliseconds
            */
            constexpr Time(float milliseconds):
                milliseconds(milliseconds)
            {}
            
            #ifdef GF_USING_SFML
                /**
                 * @brief Construct a new Time object from an sf::Time object
                 * 
                 * @param time The sf::Time object
                */
                Time(const sf::Time& time);

                /**
                 * @brief Convert the Time object to an sf::Time object
                 * 
                 * @return The sf::Time object
                */
                operator sf::Time() const;
            #endif

            /**
             * @brief Construct a new Time object from seconds
             * 
             * @param amount The time in seconds
             * @return Time The Time object
            */
            static constexpr Time from_seconds(float amount)
            {
                return Time(amount * 1000.0f);
            }

            /**
             * @brief Construct a new Time object from milliseconds
             * 
             * @param amount The time in milliseconds
             * @return Time The Time object
            */
            static constexpr Time from_milliseconds(float amount)
            {
                return Time(amount / 1000.0f);
            }

            /**
             * @brief Construct a new Time object from microseconds
             * 
             * @param amount The time in microseconds
             * @return Time The Time object
            */
            static constexpr Time from_microseconds(float amount)
            {
                return Time(amount);
            }

            /**
             * @brief Get the time in seconds
             * 
             * @return float The time in seconds
            */
            constexpr float get_seconds() const
            {
                return milliseconds / 1000.0f;
            }

            /**
             * @brief Get the time in milliseconds
             * 
             * @return float The time in milliseconds
            */
            constexpr float get_milliseconds() const
            {
                return milliseconds;
            }

            /**
             * @brief Get the time in microseconds
             * 
             * @return float The time in microseconds
            */
            constexpr float get_microseconds() const
            {
                return milliseconds * 1000.0f;
            }

            /**
             * @brief Compare two Time objects for equality
             * 
             * @param other The other Time object
             * @return true If the two Time objects are equal
             * @return false If the two Time objects are not equal
            */
            bool operator==(const Time& other) const;

            /**
             * @brief Compare two Time objects for inequality
             * 
             * @param other The other Time object
             * @return true If the two Time objects are not equal
             * @return false If the two Time objects are equal
            */
            bool operator!=(const Time& other) const;

            /**
             * @brief Compare two Time objects for less than
             * 
             * @param other The other Time object
             * @return true If this Time object is less than the other Time object
             * @return false If this Time object is not less than the other Time object
            */
            bool operator<(const Time& other) const;

            /**
             * @brief Compare two Time objects for less than or equal to
             * 
             * @param other The other Time object
             * @return true If this Time object is less than or equal to the other Time object
             * @return false If this Time object is not less than or equal to the other Time object
            */
            bool operator<=(const Time& other) const;

            /**
             * @brief Compare two Time objects for greater than
             * 
             * @param other The other Time object
             * @return true If this Time object is greater than the other Time object
             * @return false If this Time object is not greater than the other Time object
            */
            bool operator>(const Time& other) const;

            /**
             * @brief Compare two Time objects for greater than or equal to
             * 
             * @param other The other Time object
             * @return true If this Time object is greater than or equal to the other Time object
             * @return false If this Time object is not greater than or equal to the other Time object
            */
            bool operator>=(const Time& other) const;

            /**
             * @brief Negate the Time object
             * 
             * @return Time The negated Time object
            */
            Time operator-() const;

            /**
             * @brief Add two Time objects
             * 
             * @param other The other Time object
             * @return Time The sum of the two Time objects
            */
            Time operator+(const Time& other) const;

            /**
             * @brief Subtract two Time objects
             * 
             * @param other The other Time object
             * @return Time The difference of the two Time objects
            */
            Time operator-(const Time& other) const;

            /**
             * @brief Multiply the Time object by a factor
             * 
             * @param factor The factor
             * @return Time The product of the Time object and the factor
            */
            Time operator*(float factor) const;

            /**
             * @brief Divide the Time object by a factor
             * 
             * @param factor The factor
             * @return Time The quotient of the Time object and the factor
            */
            Time operator/(float factor) const;

            /**
             * @brief Multiply two Time objects
             * 
             * @param other The other Time object
             * @return float The product of the two Time objects
            */
            float operator*(const Time& other) const;

            /**
             * @brief Add two Time objects
             * 
             * @param other The other Time object
             * @return Time& The sum of the two Time objects
            */
            float operator/(const Time& other) const;

            /**
             * @brief Add two Time objects
             * 
             * @param other The other Time object
             * @return Time& The sum of the two Time objects
            */
            Time& operator+=(const Time& other);

            /**
             * @brief Subtract two Time objects
             * 
             * @param other The other Time object
             * @return Time& The difference of the two Time objects
            */
            Time& operator-=(const Time& other);

            /**
             * @brief Multiply the Time object by a factor
             * 
             * @param factor The factor
             * @return Time& The product of the Time object and the factor
            */
            Time& operator*=(float factor);

            /**
             * @brief Divide the Time object by a factor
             * 
             * @param factor The factor
             * @return Time& The quotient of the Time object and the factor
            */
            Time& operator/=(float factor);


        private:
            float milliseconds; ///< The time in milliseconds
    };
} // namespace gf

/* Literals */

constexpr gf::Time operator"" _s(long double seconds)
{
    return gf::Time::from_seconds(static_cast<float>(seconds));
}

constexpr gf::Time operator"" _ms(long double milliseconds)
{
    return gf::Time::from_milliseconds(static_cast<float>(milliseconds));
}

constexpr gf::Time operator"" _us(long double microseconds)
{
    return gf::Time::from_microseconds(static_cast<float>(microseconds));
}
