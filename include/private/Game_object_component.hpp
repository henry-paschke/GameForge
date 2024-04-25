#pragma once

namespace gf
{
    class Game_object;

    class Game_object_component
    {
        public:
            Game_object* owner;
            virtual void update() = 0;

            void set_owner(Game_object* owner)
            {
                this->owner = owner;
            }
    };

} // namespace gf
