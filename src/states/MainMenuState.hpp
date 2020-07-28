//////////////////////////////////////////////////////////////////////////////////////////
//      file: MainMenuState.hpp
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

#ifndef ENGINE_BASE_MAINMENUSTATE_HPP
#define ENGINE_BASE_MAINMENUSTATE_HPP

#include "State.hpp"
#include "game_state/GameState.hpp"

#include "../Game.hpp"

#include "../gui/Gui.hpp"

namespace gcb {
    class MainMenuState : public State {

    public:
        // Constructor / Destructor
        MainMenuState(GameDataRef data);
        ~MainMenuState();
        MainMenuState(const MainMenuState&) = delete; // non construction-copyable
        MainMenuState& operator=(const MainMenuState&) = delete; // non copyable

        // Virtual methods
        void init();
        void handleWindowInput();
        void handleInput(const float& dT);
        void update(const float &dT);
        void render(const float &dT);

    private:
        GameDataRef mData{nullptr};

        sf::Sprite mBackground;
        sf::Sprite mTitle;

        std::unordered_map<std::string, std::unique_ptr<gcb::gui::Button>> mButtons;

        sf::Text mFooterText;

        // Initializers
        void initTextures();
        void initFonts();
        void initButtons();

        // Private Methods
        void loadGameState();
        void loadEditorState();
        void loadSettingsState();
        void updateButtons(const sf::Vector2f &mousePos, const float &dT);
    };

}// namespace gcb




#endif//ENGINE_BASE_MAINMENUSTATE_HPP
