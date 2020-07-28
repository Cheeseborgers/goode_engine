//////////////////////////////////////////////////////////////////////////////////////////
//      file: StateMachine.cpp
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

#include "StateMachine.hpp"

namespace gcb {
// Constructor ---------------------------------------------------------------------------
StateMachine::StateMachine()
{
    mCurrentState = States::SPLASH_STATE;
    mIsAdding = false;
    mIsReplacing = false;
    mIsRemoving = false;
}
// Destructor ----------------------------------------------------------------------------
StateMachine::~StateMachine() {}
// Accessors -----------------------------------------------------------------------------
StateRef &StateMachine::getActiveState()
{
    return mStates.top();
}
// ---------------------------------------------------------------------------------------
States StateMachine::getCurrentState() const
{
    /***********************************************
     * @return unsigned int
     * Returns the mCurrentState int value
     * as set from the states Enum.
     * *********************************************/

    return mCurrentState;
}
// Modifiers -----------------------------------------------------------------------------
void StateMachine::addState(StateRef newState, bool isReplacing)
{
    mIsAdding = true;
    mIsReplacing = isReplacing;
    mNewState = std::move(newState);
}
// ---------------------------------------------------------------------------------------
void StateMachine::addState(StateRef newState)
{
    mIsAdding = true;
    mIsReplacing = true;
    mNewState = std::move(newState);
}
// ---------------------------------------------------------------------------------------
void StateMachine::setCurrentState(States currentState)
{
    /***********************************************
     * @return unsigned int
     * Sets the mCurrentState int value
     * matching a valid option from the states Enum.
     * *********************************************/

    mCurrentState = currentState;
}
//----------------------------------------------------------------------------------------
void StateMachine::removeState()
{
    mIsRemoving = true;
}
// Methods -------------------------------------------------------------------------------
void StateMachine::processStateChanges()
{
    if (mIsRemoving && !mStates.empty()) {
        mStates.pop();

        if (!mStates.empty()) {
            mStates.top()->resume();
        }

        mIsRemoving = false;
    }

    if (mIsAdding) {
        if (!mStates.empty()) {
            if (mIsReplacing) {
                mStates.pop();
            } else {
                mStates.top()->setPause();
            }
        }

        mStates.push(std::move(mNewState));
        mStates.top()->init();
        mIsAdding = false;
    }
}
// ---------------------------------------------------------------------------------------

}// namespace gcb


