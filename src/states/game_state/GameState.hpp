//////////////////////////////////////////////////////////////////////////////////////////
//      file: GameState.hpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 14/06/2020.
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

#ifndef ENGINE_BASE_GAMESTATE_HPP
#define ENGINE_BASE_GAMESTATE_HPP

#include "../State.hpp"

#include "../../Game.hpp"

#include "../../entities/players/Player.hpp"

#include "../../gui/PauseMenu.hpp"
#include "../../gui/Slider.hpp"

#include "../debug/MousePosition.hpp"
#include "../debug/FPS.hpp"

#include "../../world/WorldTime.hpp"
#include "../../world/TileMap.hpp"

#include "../../effects/ParticleSystem.hpp"
#include "../../entities/enemies/Rat.hpp"


namespace gcb
{

class State;
struct Time;

using PLevel = std::shared_ptr<std::vector<gcb::tilemap::Tile>>;
using Enemies = std::vector<std::unique_ptr<Enemy>>;

class GameState : public State
{
private:
    GameDataRef mData{nullptr};

    // Pause menu
    std::unique_ptr<gui::PauseMenu> mPauseMenu;

    // Player
    std::shared_ptr<Player> mPlayer;

    // Enemies
    Enemies mEnemies;

    // WORLD =============================================================================
    // Tile Map
    sf::Vector2u mLevelSize;
    sf::Vector2u mTileSizeU;
    sf::Vector2f mTileSizeF;
    std::unique_ptr<gcb::tilemap::TileMap> mMap;
    PLevel mPLevelData;

    // Time
    WorldTime mWorldTime;
    //====================================================================================

    // Particle System =============================================
    std::unique_ptr<ParticleSystem> mParticleSystem;
    sf::Vector2<double> mLastMousePos;

    // Slider ======================================================
    std::unique_ptr<gcb::gui::Slider> mSlider;

#ifndef NDEBUG
    debug::MousePosition mMousePosition
      = (mData->fonts->get(Definitions::PRIMARY_FONT_NAME));
    std::unique_ptr<debug::FPS> mFps;
#endif

    // Initializers
    void initVariables();
    void initTextures();
    void initFonts();
    void initMap();
    void initPlayer();
    void initPauseMenu();

#ifndef NDEBUG
    void initDebug();
#endif

public:
    // Constructor / Destructor
    GameState(GameDataRef data);
    ~GameState();
    GameState(const GameState &) = delete; // non construction-copyable
    GameState & operator=(const GameState &) = delete; // non copyable

    // Methods
    void handlePauseMenuButtons();
    void updateParticleTest(const float &dT);

    // Virtual Methods
    void init();
    void handleWindowInput();
    void handleInput(const float& dT);
    void handlePlayerInput(const float& dT);
    void update(const float &dT);
    void render(const float &dT);
};

}// namespace gcb


#endif//ENGINE_BASE_GAMESTATE_HPP
