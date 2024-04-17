#include "Transform2.hpp"

using namespace gf; 


Vector2f Transform2::get_position() const
{
    return position;
}

Angle Transform2::get_rotation() const
{
    return rotation;
}

Vector2f Transform2::get_scale() const
{
    return scale;
}

std::string Transform2::get_string() const
{
    return "Transform(Position: " + position.get_string() + ", Rotation: " + rotation.get_string() + ", Scale: " + scale.get_string() + ")";
}

void Transform2::set_position(const Vector2f &position)
{
    this->position = position;
}

void Transform2::set_rotation(const Angle &rotation)
{
    this->rotation = rotation;
}

void Transform2::set_scale(const Vector2f &scale)
{
    this->scale = scale;
}

Transform2 Transform2::operator*(const Transform2 &other) const
{
    return Transform2(
        position + other.position,
        rotation + other.rotation,
        scale * other.scale
    );
}

Transform2& Transform2::operator*= (const Transform2 &other)
{
    position += other.position;
    rotation += other.rotation;
    scale *= other.scale;
    return *this;
}

Transform2 Transform2::operator+(const Angle &angle) const
{
    return Transform2(position, rotation + angle, scale);
}

Transform2 &Transform2::operator+=(const Angle &angle)
{
    rotation += angle;
    return *this;
}

Transform2 Transform2::operator+(const Vector2f &vector) const
{
    return Transform2(position + vector, rotation, scale);
}

Transform2 &Transform2::operator+=(const Vector2f &vector)
{
    position += vector;
    return *this;
}

Transform2 Transform2::operator-(const Angle &angle) const
{
    return Transform2(position, rotation - angle, scale);
}

Transform2 &Transform2::operator-=(const Angle &angle)
{
    rotation -= angle;
    return *this;
}

Transform2 Transform2::operator-(const Vector2f &vector) const
{
    return Transform2(position - vector, rotation, scale);
}

Transform2 &Transform2::operator-=(const Vector2f &vector)
{
    position -= vector;
    return *this;
}

bool Transform2::operator==(const Transform2 &other) const
{
    return position == other.position && rotation == other.rotation && scale == other.scale;
}

bool Transform2::operator!=(const Transform2 &other) const
{
    return !(*this == other);
}

void Transform2::translate(const Vector2f &offset)
{
    position += offset;
}

void Transform2::rotate(const Angle &angle)
{
    rotation += angle;
}

void Transform2::scale_by(const Vector2f& factors)
{
    scale *= factors;
}

Transform2 Transform2::get_translated(const Vector2f &offset) const
{
    return Transform2();
}

Transform2 Transform2::get_rotated(const Angle &angle) const
{
    return Transform2();
}

Transform2 gf::Transform2::get_globally_rotated(const Angle &angle) const
{
    return Transform2(position.get_rotated(angle), rotation, scale);
}

Transform2 Transform2::get_scaled(const Vector2f &factors) const
{
    return Transform2();
}

std::ostream &gf::operator<<(std::ostream &os, const Transform2 &transform)
{
    return os << transform.get_string();
}
