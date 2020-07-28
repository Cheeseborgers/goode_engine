//////////////////////////////////////////////////////////////////////////////////////////
//      file: StateMachine.hpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 13/06/2020.
//      Copyright (C) 2020 - goodecheeseburgers@gmail.com
//
//      https://github.com/Cheeseborgers/GoodeEngine
//
//      This program is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <https://www.gnu.org/licenses/>.
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef ENGINE_BASE_STATEMACHINE_HPP
#define ENGINE_BASE_STATEMACHINE_HPP

#include "../pch.hpp"

#include "State.hpp"


namespace gcb
{

class State;

using StateRef = std::unique_ptr<State>;

enum States : unsigned char {
    SPLASH_STATE = 0,
    MAIN_MENU_STATE,
    GAME_STATE,
    EDITOR_STATE,
    SETTINGS_STATE,
    GAME_OVER_STATE};

class StateMachine final
{
private:
    plf::stack<StateRef> mStates;
    States mCurrentState;
    StateRef mNewState;

    bool mIsRemoving; // TODO : replace with enum?
    bool mIsAdding;
    bool mIsReplacing;

public:
    StateMachine(); // Constructor
    ~StateMachine(); // Destructor
    StateMachine(const StateMachine&) = delete; // non copyable constructor
    StateMachine& operator=(const StateMachine&) = delete; // non copyable

    // Getters
    StateRef &getActiveState();
    States getCurrentState() const;

    // Setters
    void addState(const StateRef newState);
    void addState(const StateRef newState, const bool isReplacing);
    void removeState();
    void setCurrentState(const States currentState);

    // Methods
    void processStateChanges();
};

}// namespace gcb

#endif//ENGINE_BASE_STATEMACHINE_HPP
