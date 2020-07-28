//////////////////////////////////////////////////////////////////////////////////////////
//      file: SettingsState.hpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 12/07/2020.
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

#ifndef ENGINE_BASE_SETTINGSSTATE_HPP
#define ENGINE_BASE_SETTINGSSTATE_HPP

#include <bits/stdc++.h>

#include "../pch.hpp"
#include "../Game.hpp"
#include "../gui/Button.hpp"
#include "../gui/DropDownList.hpp"

// DEBUG
#include "../debug/MousePosition.hpp"

namespace gcb {

class State;

enum SettingsMenuStates : unsigned char {
    GRAPHICS_SETTINGS = 0,
    AUDIO_SETTINGS,
    CONTROL_SETTINGS };

class SettingsState : public State{
  public:
    // Constructor / Destructor
    SettingsState(GameDataRef data);
    ~SettingsState();
    SettingsState(const SettingsState &) = delete;            // non construction-copyable
    SettingsState & operator=(const SettingsState &) = delete; // non copyable

    // Methods
    void handlePlayerInput(const float& dT);
    void updateGraphicsSettingsMenu();
    void updateAudioSettingsMenu();
    void updateControlSettingsMenu();
    void updateGui(const float &dT);
    void renderGraphicsSettingsMenu();
    void renderAudioSettingsMenu();
    void renderControlSettingsMenu();
    void renderGui();

    // Virtual methods
    void init();
    void handleWindowInput();
    void handleInput(const float& dT);
    void update(const float &dT);
    void render(const float &dT);

  private:
    GameDataRef mData{nullptr};

    sf::Sprite mBackground;
    sf::RectangleShape mContainer;

    sf::Text mHeaderText;

    unsigned short mCurrentMenu;

    gcb::gui::Buttons mButtons;
    gcb::gui::dropDownLists mDropDownLists;

    //DEBUG
    debug::MousePosition mMousePosition = (
      mData->fonts->get(Definitions::PRIMARY_FONT_NAME));

    // Initializers
    void initVariables();
    void initTextures();
    void initFonts();
    void initBackground();
    void initContainer();
    void initText();
    void initGui();
};

}// namespace gcb


#endif//ENGINE_BASE_SETTINGSSTATE_HPP
