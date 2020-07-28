//////////////////////////////////////////////////////////////////////////////////////////
//      file: SlashState.hpp
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

#ifndef ENGINE_BASE_SPLASHSTATE_HPP
#define ENGINE_BASE_SPLASHSTATE_HPP


#include "State.hpp"
#include "../Game.hpp"
#include "MainMenuState.hpp"

namespace gcb
{
class SplashState : public State
{
private:
    // Member Variables
    GameDataRef mData{nullptr};

    sf::Clock mClock;
    sf::Sprite mBackground;
    sf::Sound mSound;

    bool mSoundPlayed;

    // Initializers
    void initTextures();
    void initSounds();

public:
    // Constructor / Destructor
    SplashState(GameDataRef data);
    ~SplashState();
    SplashState(const SplashState &) = delete; // non construction-copyable
    SplashState & operator=(const SplashState &) = delete; // non copyable

    // Virtual methods
    void init();
    void handleWindowInput();
    void handleInput(const float& dT);
    void update(const float &dT);
    void render(const float &dT);

};

}// namespace gcb

#endif//ENGINE_BASE_SPLASHSTATE_HPP
