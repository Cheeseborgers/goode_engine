//////////////////////////////////////////////////////////////////////////////////////////
//      file: State.hpp
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

#ifndef ENGINE_BASE_STATE_HPP
#define ENGINE_BASE_STATE_HPP

#include "../pch.hpp"

namespace gcb
{
class State
{
private:
    // Private Member Variables
    bool mQuit;
    bool mPaused;
    float mKeyTime;
    float mKeyTimeMax;

  public:
    State();                                 // Constructor
    virtual ~State() = default;              // Destructor
    State(const State&) = delete;            // non construction-copyable
    State(State&&) = delete;                 // non movable
    State& operator=(const State&) = delete; // non copyable
    State& operator=(State&&) = delete;      // move assignment

    // Getters
    const bool &getQuit() const;
    const bool &isPaused() const;
    bool getKeyTime();

    // Setters
    void setQuit(const bool &quitState);
    void setPause();
    void resume();

    // Methods
    void updateKeyTime(const float &dT);

    // Pure virtual Methods
    virtual void init() = 0;
    virtual void handleWindowInput() = 0;
    virtual void handleInput(const float& dT) = 0;
    virtual void update (const float &dT) = 0;
    virtual void render(const float &dT) = 0;
};

}// namespace gcb

#endif//ENGINE_BASE_STATE_HPP
