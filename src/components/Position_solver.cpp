#include "components/Position_solver.hpp"

gf::component::Position_solver::Position_solver(Game_object &game_object):
    game_object{game_object}
{}

void gf::component::Position_solver::update(const gf::Time& dt)
{
    if (process)
    {
        process->update(dt);
        game_object.transform = process->get();
    }
}

void gf::component::Position_solver::set_target_position(const gf::Transform2 &target, gf::Time duration, gf::Easing_function interpolation)
{
    process.emplace(game_object.transform, target, duration, interpolation);
}
