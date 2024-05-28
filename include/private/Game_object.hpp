#pragma once

#include <vector>
#include "Transform2.hpp"
#include "Vector2.hpp"
#include "Game_object_component.hpp"

namespace gf
{
    class Game_object
    {
        public:
            std::vector<Game_object_component*> components;
            std::vector<Game_object*> children;
            Game_object* parent;
            Transform2 transform;
            Vector2f anchor_point;
            Transform2 global_transform;

            Game_object(Game_object* parent = nullptr):
                parent(parent)
            {}

            ~Game_object()
            {
                for (auto& component : components)
                {
                    delete component;
                }
            }

            void update(const gf::Time& dt)
            {
                update_position();
                
                for (auto& child : children)
                {
                    child->update(dt);
                }
                
                update_components(dt);
            }

            void add_component(Game_object_component* component)
            {
                components.push_back(component);
                component->owner = this;
            }

            void add_child(Game_object* child)
            {
                children.push_back(child);
                child->parent = this;
            }

            void update_components(const gf::Time& dt)
            {
                for (auto& component : components)
                {
                    component->update(dt);
                }
            }

            void update_position(Transform2& parent_anchor = Transform2())
            {
                global_transform = parent_anchor * transform;

                gf::Vector2f anchor_offset = (anchor_point * transform.get_scale()).get_rotated(transform.get_rotation());

                for (auto& child : children)
                {
                    child->update_position(global_transform + anchor_offset);
                }
            }
    };

} // namespace gf
