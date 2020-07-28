//////////////////////////////////////////////////////////////////////////////////////////
//      file: InputHandler.cpp
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

#include "InputHandler.hpp"

namespace gcb
{
// Constructor ---------------------------------------------------------------------------
InputHandler::InputHandler()
{
    mBtnAtWalkLeft = std::make_unique<WalkLeft>();
    mBtnAtWalkRight = std::make_unique<WalkRight>();
    mBtnAtWalkUp = std::make_unique<WalkUp>();
    mBtnAtWalkDown = std::make_unique<WalkDown>();
    //mBtnAtUndo      = std::make_unique<Undo>();
}
// Accessors -----------------------------------------------------------------------------
bool InputHandler::isSpriteClicked(
    sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) const
{
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect tempRect(
            static_cast<int>(object.getPosition().x),
            static_cast<int>(object.getPosition().y),
            static_cast<int>(object.getGlobalBounds().width),
            static_cast<int>(object.getGlobalBounds().height));

        if (tempRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }

    return false;
}
// ---------------------------------------------------------------------------------------
void InputHandler::handleInput([[maybe_unused]] const float& dT)
{

}
// ---------------------------------------------------------------------------------------
void InputHandler::handleInput(Player &player, const float& dT)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mBtnAtWalkRight->execute(player, dT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        mBtnAtWalkLeft->execute(player, dT);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        mBtnAtWalkUp->execute(player, dT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mBtnAtWalkDown->execute(player, dT);
    }
}
// ---------------------------------------------------------------------------------------
void InputHandler::handleInput(Entity &entity, const float& dT)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        mBtnAtWalkRight->execute(entity, dT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        mBtnAtWalkLeft->execute(entity, dT);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        mBtnAtWalkUp->execute(entity, dT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        mBtnAtWalkDown->execute(entity, dT);
    }
}
// ---------------------------------------------------------------------------------------
const sf::Vector2i &InputHandler::getMousePosScreen() const
{
    return mMousePosScreen;
}
// ---------------------------------------------------------------------------------------
const sf::Vector2i &InputHandler::getMousePosWindow() const
{

    return mMousePosWindow;
}
// ---------------------------------------------------------------------------------------
const sf::Vector2f &InputHandler::getMousePosView() const
{
    return mMousePosView;
}
// ---------------------------------------------------------------------------------------
const sf::Vector2i &InputHandler::getMousePosGrid() const
{
    return mMousePosGrid;
}
// ---------------------------------------------------------------------------------------
void InputHandler::updateMousePositions(sf::RenderWindow &window)
{
    mMousePosScreen = sf::Mouse::getPosition();
    mMousePosWindow = sf::Mouse::getPosition(window);
    mMousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    // TODO FIX THIS TO ACCEPT GRID SIZE or move to separate update function?
    mMousePosGrid =
      sf::Vector2i(
        static_cast<int>(mMousePosView.x) / 64,
        static_cast<int>(mMousePosView.y) / 64
      );
}
// ---------------------------------------------------------------------------------------
void InputHandler::loadSupportedKeys(const std::string &path)
{
    std::ifstream ifs(path);

    if (ifs.is_open())
    {
        std::string key = "";
        int value{0};

        while (ifs >> key >> value)
        {
            mSupportedKeys[key] = value;
        }

    } else {
        std::cout << "ERROR::InputHandler::loadSupportedKeys "
             "Could not open" << path << "\n";
    }

    ifs.close();
}
// ---------------------------------------------------------------------------------------
void InputHandler::loadSupportedKeys()
{
    std::ifstream ifs(Definitions::SUPPORTED_KEY_FILEPATH);

    if (ifs.is_open())
    {
        std::string key = "";
        int value{0};

        while (ifs >> key >> value)
        {
            mSupportedKeys[key] = value;
        }

    } else {
        std::cout << "ERROR::InputHandler::loadSupportedKeys "
             "Could not open" << Definitions::SUPPORTED_KEY_FILEPATH << "\n";
    }

    ifs.close();
}
// ---------------------------------------------------------------------------------------
void InputHandler::loadKeybinds(const std::string &path)
{
    std::ifstream ifs(path);

    if (ifs.is_open())
    {
        std::string key = "";
        int value{0};

        while (ifs >> key >> value)
        {
            mSupportedKeys[key] = value;
        }

    } else {
        std::cout << "ERROR::InputHandler::loadKeybinds "
                     "Could not open" << path << "\n";
    }

    ifs.close();
}
// ---------------------------------------------------------------------------------------
void InputHandler::loadStateKeybinds(unsigned int state)
{
    std::string path{""};

    switch (state)
    {
    case (States::SPLASH_STATE):
        path = Definitions::GENERAL_KEYBINDS_FILEPATH;
        break;
    case (States::SETTINGS_STATE):
        path = Definitions::GENERAL_KEYBINDS_FILEPATH;
        break;
    case (States::GAME_OVER_STATE):
        path = Definitions::GENERAL_KEYBINDS_FILEPATH;
        break;
    case (States::EDITOR_STATE):
        path = Definitions::EDITORSTATE_KEYBINDS_FILEPATH;
        break;
    case (States::GAME_STATE):
        path = Definitions::GAMESTATE_KEYBINDS_FILEPATH;
        break;
    default:
        std::cout << "Error: No such key binds for State. Warning: Path not set."
             "Expect more problems\n";
        break;

    }

    loadKeybinds(path);
}
// ---------------------------------------------------------------------------------------

}// namespace gcb

