#include "State_machine.hpp"

using namespace gf;

void State_machine::push_state(State* state)
{
    states.push_back(state);
    if (current_state == nullptr)
    {
        current_state = state;
        current_state->on_entry();
    }
}

void State_machine::update()
{   
    if (current_state == nullptr)
        return;
    current_state->update();
    if (current_state->next_state != nullptr)
    {
        current_state->on_exit();
        current_state = current_state->next_state;
        current_state->on_entry();
    }
}

void State_machine::set_state(State* state)
{
    if (current_state != nullptr)
        current_state->on_exit();
    current_state = state;
    current_state->on_entry();
}

int State_machine::get_current_state_id()
{
    return current_state->id;
}