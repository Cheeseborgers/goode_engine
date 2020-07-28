//////////////////////////////////////////////////////////////////////////////////////////
//      file: game.hpp
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

#ifndef ENGINE_BASE_GAME_HPP
#define ENGINE_BASE_GAME_HPP


#include "pch.hpp"

#include "states/StateMachine.hpp"
#include "managers/TextureManager.hpp"
#include "managers/WindowManager.hpp"
#include "managers/FontManager.hpp"
#include "managers/SoundManager.hpp"
#include "managers/MusicManager.hpp"
#include "input_handlers/InputHandler.hpp"


namespace gcb
{
    struct GameData
    {
        StateMachine machine;
        std::unique_ptr<gcb::window::WindowManager> window;
        std::unique_ptr<TextureManager> textures;
        std::unique_ptr<InputHandler> input;
        std::unique_ptr<FontManager> fonts;
        std::unique_ptr<SoundManager> sounds;
        std::unique_ptr<MusicManager> music;

        GameData() {std::cout << "c tor\n";};
        ~GameData() {std::cout << "d tor\n";};
    };

    using GameDataRef = std::shared_ptr<GameData>;

class Game
{
private:
    // Private Member Variables
    GameDataRef mData;
    sf::Clock mClock;
    sf::Vector2u mWindowSize;

    // Private Methods
    void initVariables();
    void initKeyBinds();
    void initWindow();
    void initStates();

    void run();
    void endApplication()
    {
        std::cout << "Ending Application\n";
    };

public:
    // Constructors
    Game();
    Game(const std::string &title, unsigned int width, unsigned int height);
    Game(const Game&) = delete;            // non construction-copyable
    Game& operator=(const Game&) = delete; // non copyable
    Game(Game&&) = delete;                 // non movable
    Game& operator=(Game&&) = delete;      // move assignment

};

}// namespace gcb

#endif//ENGINE_BASE_GAME_HPP
