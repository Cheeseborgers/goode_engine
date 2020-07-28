//////////////////////////////////////////////////////////////////////////////////////////
//      file: EditorState.hpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 15/07/2020.
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

#ifndef ENGINE_BASE_EDITORSTATE_HPP
#define ENGINE_BASE_EDITORSTATE_HPP

#include "../gui/Gui.hpp"

#include "../pch.hpp"

#include "State.hpp"
#include "../Game.hpp"
#include "../gui/PauseMenu.hpp"


namespace gcb
{
class State;

class EditorState : public State
{
  private:
    GameDataRef mData{nullptr};

    sf::Sprite mBackground;

    // Initializers
    void initTextures();
    void initFonts();
    void initPauseMenu();
    void initGui();

    // Pause menu
    std::unique_ptr<gui::PauseMenu> mPauseMenu{nullptr};

    std::unique_ptr<gcb::gui::Gui> mGui;

  public:
    // Constructor / Destructor
    EditorState(GameDataRef data);
    ~EditorState();
    EditorState(const EditorState &) = delete; // non construction-copyable
    EditorState & operator=(const EditorState &) = delete; // non copyable

    // Virtual Methods
    void init();
    void handleWindowInput();
    void handleInput(const float& dT);
    void handlePauseMenuButtons();
    void update(const float &dT);
    void render(const float &dT);
};


}// namespace gcb



#endif//ENGINE_BASE_EDITORSTATE_HPP
