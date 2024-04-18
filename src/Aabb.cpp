#include "Aabb.hpp"

using namespace gf;

#ifdef GF_USING_CHIPMUNK2D 
    Aabb::Aabb(const cpBB& bb): 
        position{bb.l + (bb.r - bb.l) / 2, bb.b + (bb.t - bb.b) / 2}, 
        dimensions{bb.r - bb.l, bb.t - bb.b} 
    {}

    Aabb::operator cpBB() const 
    { 
        return cpBBNew(position.x - dimensions.x / 2, position.y - dimensions.y / 2, position.x + dimensions.x / 2, position.y + dimensions.y / 2); 
    }
#endif
#ifdef GF_USING_SFML
    Aabb::Aabb(const sf::IntRect& rect): 
        position{rect.left + rect.width / 2, rect.top + rect.height / 2}, 
        dimensions{rect.width, rect.height} 
    {}

    Aabb::operator sf::IntRect() const 
    { 
        return sf::IntRect(static_cast<int>(position.x - dimensions.x / 2), static_cast<int>(position.y - dimensions.y / 2), static_cast<int>(dimensions.x), static_cast<int>(dimensions.y)); 
    }

    Aabb::Aabb(const sf::FloatRect& rect): 
        position{rect.left + rect.width / 2, rect.top + rect.height / 2}, 
        dimensions{rect.width, rect.height} 
    {}

    Aabb::operator sf::FloatRect() const 
    { 
        return sf::FloatRect(position.x - dimensions.x / 2, position.y - dimensions.y / 2, dimensions.x, dimensions.y); 
    }

    Aabb::operator sf::RectangleShape() const 
    { 
        sf::RectangleShape rect; 
        rect.setPosition(position); 
        rect.setSize(dimensions); 
        return rect; 
    }
#endif

void gf::Aabb::set_left(float x)
{
    position.x = x + dimensions.x / 2;
}

void gf::Aabb::set_right(float x)
{
    position.x = x + dimensions.x / 2;
}

void gf::Aabb::set_top(float y)
{
    position.y = y - dimensions.y / 2;
}

void gf::Aabb::set_bottom(float y)
{
    position.y = y + dimensions.y / 2;
}

void gf::Aabb::set_centerx(float x)
{
    position.x = x;
}

void gf::Aabb::set_centery(float y)
{
    position.y = y;
}

void gf::Aabb::set_width(float width)
{
    dimensions.x = width;
}

void gf::Aabb::set_height(float height)
{
    dimensions.y = height;
}

std::string gf::Aabb::get_string() const
{
    return "AABB(Position: " + position.get_string() + ", Dimensions: " + dimensions.get_string() + ")";
}

bool gf::Aabb::intersects(const Aabb &other) const
{
    return get_left() < other.get_right() && get_right() > other.get_left() && get_top() < other.get_bottom() && get_bottom() > other.get_top();
}

std::ostream &gf::operator<<(std::ostream &os, const Aabb &obj)
{
    return os << obj.get_string();
}
