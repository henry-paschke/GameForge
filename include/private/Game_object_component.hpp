#pragma once

#include "Time.hpp"

namespace gf
{
    class Game_object;

    class Game_object_component
    {
        public:
            Game_object* owner;
            virtual void update(const gf::Time& dt) = 0;

            void set_owner(Game_object* owner)
            {
                this->owner = owner;
            }
    };

} // namespace gf
