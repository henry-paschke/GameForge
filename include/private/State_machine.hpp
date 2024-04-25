#pragma once

#include <vector>

namespace gf
{
    class State
    {
        public:
            int id;
            virtual void on_entry() {}
            virtual void on_exit() {}
            virtual void update() = 0;
            State* next_state = nullptr;
    };

    class State_machine
    {
        public:
            void push_state(State* state);
            void update();
            void set_state(State* state);
            int get_current_state_id();

        private:
            State* current_state;
            std::vector<State*> states;
    };

} // namespace gf
