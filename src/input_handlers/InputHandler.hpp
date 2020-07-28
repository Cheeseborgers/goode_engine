//////////////////////////////////////////////////////////////////////////////////////////
//      file: InputHandler.hpp
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

#ifndef ENGINE_BASE_INPUTHANDLER_HPP
#define ENGINE_BASE_INPUTHANDLER_HPP


#include "../pch.hpp"

#include "../states/State.hpp"
#include "../entities/players/Player.hpp"
#include "../commands/Walk.hpp"
#include "../states/StateMachine.hpp"

namespace gcb
{
using SupportedKeys = std::unordered_map<std::string, int>;
using StateKeyBinds =  std::unordered_map<std::string, int>;
using KeyBinds = std::unordered_map<std::string, StateKeyBinds>;

class InputHandler
{
    public:
        // Constructor
        InputHandler();

        // Getters
        bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
            sf::RenderWindow &window) const;
        const sf::Vector2i &getMousePosScreen() const;
        const sf::Vector2i &getMousePosWindow() const;
        const sf::Vector2f &getMousePosView() const;
        const sf::Vector2i &getMousePosGrid() const;

        // Initializers
        void loadSupportedKeys();
        void loadSupportedKeys(const std::string &path);
        void loadKeybinds(const std::string &path);
        void loadStateKeybinds(unsigned int state);

        // Methods
        void handleInput(const float& dT);
        void handleInput(Entity &entity, const float& dT);
        void handleInput(Player &player, const float& dT);
        void updateMousePositions(sf::RenderWindow &window);

  private:
        sf::Vector2i mMousePosScreen;
        sf::Vector2i mMousePosWindow;
        sf::Vector2f mMousePosView;
        sf::Vector2i mMousePosGrid;

        SupportedKeys mSupportedKeys;
        KeyBinds mKeyBinds;

        // Commands
        std::unique_ptr<Command> mBtnAtWalkLeft = nullptr;
        std::unique_ptr<Command> mBtnAtWalkRight = nullptr;
        std::unique_ptr<Command> mBtnAtWalkUp = nullptr;
        std::unique_ptr<Command> mBtnAtWalkDown = nullptr;

        // TODO: REMOVE MAYBE UNUSED WHEN FIXED =========================================
        //[[maybe_unused]] std::unique_ptr<Command> mBtnAtUndo = nullptr;
    };

}// namespace gcb


#endif//ENGINE_BASE_INPUTHANDLER_HPP
