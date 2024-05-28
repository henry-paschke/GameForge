#pragma once

#include <unordered_map>
#include <vector>
#include <functional>

namespace gf
{
    class State
    {
        public:
            int id;
            virtual void on_entry() {}
            virtual void on_exit() {}
            virtual void update() = 0;
            int next_state_id = -1;

            std::vector<int> blocked_triggers;

            State(int id):
                id{id}
            {}
    };

    class State_machine
    {
        public:
            void push_state(State* state);
            void update();
            void set_state(int state_id);
            int get_current_state_id();
            void add_trigger(int state_id, std::function<bool()> trigger);
            bool is_blocked(int trigger_id);

            State_machine():
                current_state{nullptr}
            {}

            ~State_machine()
            {
                for (auto& state : states)
                    delete state.second;
            }

        private:
            State* current_state;
            std::vector<std::pair<int, std::function<bool()>> > triggers;
            std::unordered_map<int, State*> states;
    };

} // namespace gf
