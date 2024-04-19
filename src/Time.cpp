#include "Time.hpp"

using namespace gf;

#ifdef GF_USING_SFML
Time::Time(const sf::Time &time):
    Time{Time::from_microseconds(static_cast<float>(time.asMicroseconds()))}
{}

gf::Time::operator sf::Time() const
{
    return sf::microseconds(static_cast<sf::Int64>(get_microseconds()));
}
#endif

bool gf::Time::operator==(const Time &other) const
{
    return milliseconds == other.milliseconds;
}

bool gf::Time::operator!=(const Time &other) const
{
    return milliseconds != other.milliseconds;
}

bool gf::Time::operator<(const Time &other) const
{
    return milliseconds < other.milliseconds;
}

bool gf::Time::operator<=(const Time &other) const
{
    return milliseconds <= other.milliseconds;
}

bool gf::Time::operator>(const Time &other) const
{
    return milliseconds > other.milliseconds;
}

bool gf::Time::operator>=(const Time &other) const
{
    return milliseconds >= other.milliseconds;
}

Time gf::Time::operator-() const
{
    return Time(-milliseconds);
}

Time gf::Time::operator+(const Time &other) const
{
    return Time(milliseconds + other.milliseconds);
}

Time gf::Time::operator-(const Time &other) const
{
    return Time(milliseconds - other.milliseconds);
}

Time gf::Time::operator*(float factor) const
{
    return Time(milliseconds * factor);
}

Time gf::Time::operator/(float factor) const
{
    return Time(milliseconds / factor);
}

float gf::Time::operator*(const Time &other) const
{
    return milliseconds * other.milliseconds;
}

float gf::Time::operator/(const Time &other) const
{
    return milliseconds / other.milliseconds;
}

Time &gf::Time::operator+=(const Time &other)
{
    milliseconds += other.milliseconds;
    return *this;
}

Time &gf::Time::operator-=(const Time &other)
{
    milliseconds -= other.milliseconds;
    return *this;
}

Time &gf::Time::operator*=(float factor)
{
    milliseconds *= factor;
    return *this;
}

Time &gf::Time::operator/=(float factor)
{
    milliseconds /= factor;
    return *this;
}
