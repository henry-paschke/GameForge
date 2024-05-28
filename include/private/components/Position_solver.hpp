#pragma once

#include <optional> 

#include "../Game_object.hpp"
#include "../Game_object_component.hpp"
#include "../Transform2.hpp"
#include "../Process.hpp"
#include "../Interpolation.hpp"

namespace gf::component
{
    class Position_solver: public Game_object_component
    {
        public:

            Position_solver(Game_object& game_object);

            void update(const gf::Time& dt) override;

            void set_target_position(const gf::Transform2& target_position, gf::Time duration, gf::Easing_function interpolation = gf::easing::linear);

        private:
            Game_object& game_object;
            std::optional<gf::Transform_linear_process> process;
    };
} // namespace gf::component
