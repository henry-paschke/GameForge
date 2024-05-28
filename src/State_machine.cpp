#include "State_machine.hpp"

using namespace gf;

#include <iostream>

void State_machine::push_state(State* state)
{
    states[state->id] = state;
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

    for (auto& trigger : triggers)
    {
        if (current_state->id != trigger.first && !is_blocked(trigger.first) && trigger.second())
        {
            set_state(trigger.first);
            break;
        }
    }

    current_state->update();
    if (current_state->next_state_id != -1)
    {
        current_state->on_exit();
        int temp = current_state->next_state_id;
        current_state->next_state_id = -1;
        current_state = states[temp];
        current_state->on_entry();
    }
}

void State_machine::set_state(int state_id)
{
    if (current_state != nullptr)
        current_state->on_exit();
    current_state = states[state_id];
    current_state->on_entry();
}

int State_machine::get_current_state_id()
{
    return current_state->id;
}

void State_machine::add_trigger(int state_id, std::function<bool()> trigger)
{
    triggers.push_back({state_id, trigger});
}

bool gf::State_machine::is_blocked(int trigger_id)
{
    return std::find(current_state->blocked_triggers.begin(), current_state->blocked_triggers.end(), trigger_id) != current_state->blocked_triggers.end();
}
