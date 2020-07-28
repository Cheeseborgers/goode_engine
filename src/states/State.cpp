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

#include "State.hpp"

namespace gcb
{
// Constructor ---------------------------------------------------------------------------
State::State()
{
    mQuit = false;
    mPaused = false;
    mKeyTime = 0.0F;
    mKeyTimeMax = 40.0F;
}
// Accessors------------------------------------------------------------------------------
const bool &State::getQuit() const
{
    return mQuit;
}
// ---------------------------------------------------------------------------------------
const bool &State::isPaused() const
{
    return mPaused;
}
// ---------------------------------------------------------------------------------------
bool State::getKeyTime()
{
    if (mKeyTime >= mKeyTimeMax)
    {
        mKeyTime = 0.0F;
        return true;
    }

    return false;
}
// Modifiers------------------------------------------------------------------------------
void State::setQuit(const bool &quitState)
{
    mQuit = quitState;
}
// ---------------------------------------------------------------------------------------
void State::setPause()
{
    mPaused = true;
}
// ---------------------------------------------------------------------------------------
void State::resume()
{
    mPaused = false;
}
//----------------------------------------------------------------------------------------
void State::updateKeyTime(const float &dT)
{
    if (mKeyTime < mKeyTimeMax)
    {
        mKeyTime += 100.f * dT;
    }
}
// ---------------------------------------------------------------------------------------


}// namespace gcb
