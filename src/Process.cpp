#include "Process.hpp"

using namespace gf;

Transform_linear_process::Transform_linear_process(const Transform2 &start, const Transform2 &end, const Time &length, const Easing_function &easing_function):
    position{start.position, end.position, length, easing_function},
    rotation{start.rotation, end.rotation, length, easing_function}
{}

void Transform_linear_process::reset_process()
{
    position.reset_process();
    rotation.reset_process();
}

void Transform_linear_process::reset_process(const Time &new_length)
{
    position.reset_process(new_length);
    rotation.reset_process(new_length);
}

void Transform_linear_process::set_end(const Transform2 &new_end)
{
    position.set_end(new_end.position);
    rotation.set_end(new_end.rotation);
}

void Transform_linear_process::set_start(const Transform2 &new_start)
{
    position.set_start(new_start.position);
    rotation.set_start(new_start.rotation);
}

void Transform_linear_process::set_length(const Time &new_length)
{
    position.set_length(new_length);
    rotation.set_length(new_length);
}

void Transform_linear_process::update(const Time &dt)
{
    position.update(dt);
    rotation.update(dt);
}

void Transform_linear_process::finish()
{
    position.finish();
    rotation.finish();
}

bool Transform_linear_process::get_finished() const
{
    return position.get_finished() && rotation.get_finished();
}

Transform2 Transform_linear_process::get_start() const
{
    return {position.get_start(), rotation.get_start()};
}

Transform2 Transform_linear_process::get_end() const
{
    return {position.get_end(), rotation.get_end()};
}

Transform2 Transform_linear_process::get() const
{
    return {position.get(), rotation.get()};
}

