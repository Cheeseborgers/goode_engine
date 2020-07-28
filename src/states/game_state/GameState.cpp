//////////////////////////////////////////////////////////////////////////////////////////
//      file: GameState.cpp
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

#include "GameState.hpp"
#include "../MainMenuState.hpp"

namespace gcb
{
// Initializers --------------------------------------------------------------------------
void GameState::initVariables()
{
    /********************************************************************
    * @brief Initializes any variables to their default state as
    * required by the game state/scene
    *
    * @param None
    *
    * @return void
    ********************************************************************/

    mWorldTime.setTimeOfDay(0.0, 0.0);
}
// ---------------------------------------------------------------------------------------
void GameState::initTextures()
{
    /********************************************************************
     * @brief Initializes any textures required by the game scene
     *
     * @param None
     *
     * @return void
     ********************************************************************/

    // Player
    mData->textures->load(
      Definitions::PLAYER_TEXTURE_SHEET_NAME,
      Definitions::PLAYER_TEXTURE_SHEET_FILEPATH);

    // Rat
    mData->textures->load(
      Definitions::RAT_TEXTURE_SHEET_NAME,
      Definitions::RAT_TEXTURE_SHEET_FILEPATH);
}
// ---------------------------------------------------------------------------------------
void GameState::initFonts()
{
    /**************************************************************************
    * @brief Loads any fonts needed into the Font manager if not already
    * loaded.
    *
    * @param None
    *
    * @return void
    **************************************************************************/

    if (!mData->fonts->isLoaded(Definitions::PRIMARY_FONT_NAME))
    {
        mData->fonts->load(
          Definitions::PRIMARY_FONT_NAME,
          Definitions::PRIMARY_FONT_FILEPATH);
    }
}
// ---------------------------------------------------------------------------------------
void GameState::initMap()
{
    /********************************************************************
     * @brief Creates a tilemap.
     *
     * TODO: Move this to somewhere else more appropriate.
     *
     * @param None
     *
     * @return void
     ********************************************************************/

    mMap = std::make_unique<gcb::tilemap::TileMap>();

    mLevelSize = {10, 10};
    mTileSizeU = {10, 10};
    mTileSizeF = {
        static_cast<float>(mLevelSize.x),
        static_cast<float>(mLevelSize.y)};

    mPLevelData = std::make_shared<std::vector<gcb::tilemap::Tile>>();
    mPLevelData->reserve(mLevelSize.x * mLevelSize.y);

    for (std::size_t i = 0; i < mLevelSize.x; ++i)
    {
        for (std::size_t j = 0; j < mLevelSize.y; ++j)
        {
            gcb::tilemap::Tile tileTemp = gcb::tilemap::Tile(
                sf::Vector2f(
                    static_cast<float>(i % mLevelSize.x * mLevelSize.x),
                    static_cast<float>(j % mLevelSize.y * mLevelSize.y)),
                sf::Vector2f(64.0F, 64.0F),
              mData->fonts->get(Definitions::PRIMARY_FONT_NAME)
            );

            mPLevelData->push_back(tileTemp);
        }
    }

    mMap->setLevel(mPLevelData);

#ifndef NDEBUG // Level size
    std::cout << mPLevelData->size() << "\n";
#endif
}
// ---------------------------------------------------------------------------------------
void GameState::initPlayer()
{
    /**************************************************************************
    * @brief Creates and initializes a Player object
    *
    * @param None
    *
    * @return void
    **************************************************************************/

    mPlayer = std::make_shared<Player>(20.0F, 20.0F,
      mData->textures->get(
        Definitions::PLAYER_TEXTURE_SHEET_NAME));

    std::cout << mPlayer->getInventory()->getItemsAsString();
}
// ---------------------------------------------------------------------------------------
void GameState::initPauseMenu()
{
    /**************************************************************************
    * @brief Creates and initializes a Pause menu object.
    *
    * Creates a unique ptr to a pause menu.
    * Adds buttons to the Pause menu.
    *
    * @param None
    *
    * @return void
    **************************************************************************/

    mPauseMenu = std::make_unique<gui::PauseMenu>(
        *mData->window->getRenderWindow(),
      mData->fonts->get(Definitions::PRIMARY_FONT_NAME));

    mPauseMenu->addButton("unpause", 500.0F, "Unpause");
    mPauseMenu->addButton("back", 700.0F, "Back");
    mPauseMenu->addButton("quit", 800.0F, "Quit");

}
// ---------------------------------------------------------------------------------------
void GameState::initDebug()
{
    /**************************************************************************
    * @brief Creates and initializes any debug stuff
    *
    * FPS debug.
    *
    * @param None
    *
    * @return void
    **************************************************************************/

    // FPS Debug
    mFps = std::make_unique<debug::FPS>(sf::Vector2f(100.0F, 20.0F),
       mData->fonts->get(Definitions::PRIMARY_FONT_NAME),
       sf::Color(sf::Color::White),
       16, true, 60, 100);
}
// Constructor ---------------------------------------------------------------------------
GameState::GameState(GameDataRef data)  : mData(data){}
// Destructor ----------------------------------------------------------------------------
GameState::~GameState() {}
// Methods -------------------------------------------------------------------------------
void GameState::init()
{
    initVariables();
    initTextures();
    initFonts();
    initMap();
    initPlayer();
    initPauseMenu();

    // Slider Tests
    mSlider = std::make_unique<gcb::gui::Slider>(
      sf::Vector2u(100, 100),
      sf::Vector2f(250.0F, 50.0F),
      0.0F,
      15.0F,
      sf::Color::Cyan, sf::Color::Red, sf::Color::White);

    mData->machine.setCurrentState(States::GAME_STATE);

    /* Create the particle system and give it some fuel */
    mParticleSystem = std::make_unique<ParticleSystem>(
      mData->window->getRenderWindow()->getSize());
    mParticleSystem->fuel(1000);
    mParticleSystem->setDissolutionRate(3);


    // Rat test
    for (std::size_t i = 0; i < 20; ++i)
    {
       mEnemies.emplace_back(std::make_unique<Rat>(
          static_cast<float>(i) * 70.0F, 50.0F,
          mData->textures->get(Definitions::RAT_TEXTURE_SHEET_NAME)));
    }

#ifndef NDEBUG
    initDebug();
#endif
}
// ---------------------------------------------------------------------------------------
void GameState::handlePlayerInput(const float& dT)
{
    /**************************************************************************
    * @brief Handles player input
    *
    * @param None
    *
    * @return void
    **************************************************************************/

    mData->input->handleInput(*mPlayer, dT);
}
// ---------------------------------------------------------------------------------------
void GameState::handleInput(const float& dT)
{
    /********************************************************************************
    * @brief Polls SF events to handle keyboard key and window close control
    * functionality.
     *
    * Calls the Player input handler.
    *
    * @param None
    *
    * @return void
    *********************************************************************************/

    //TODO been fucking around with input, moving all to a window update method within
    // State.hpp and updating the whole lot within. maybe think input manager function?

    sf::Event ev;

    while (mData->window->getRenderWindow()->pollEvent(ev))
    {
        switch (ev.type)
        {
        case (sf::Event::Closed): // Close game/ window
        {
            mData->window->close();
            break;
        }
        case (sf::Event::KeyPressed):
        {
            if (ev.key.code == sf::Keyboard::Escape) // Pause game
            {
                if (!isPaused())
                {
                    setPause();
                }
                else
                {
                    resume();
                }
            }

            if (ev.key.code == sf::Keyboard::F5)  // Toggle fullscreen
            {
                mData->window->toggleFullScreen();
            }

            if (ev.key.code == sf::Keyboard::F6) // Display hitbox
            {
                mPlayer->setShowHitbox(!mPlayer->isShowHitbox());

                for (auto& it : mEnemies)
                {
                    it->setShowHitbox(!it->isShowHitbox());
                }
            }

            // PARTICLE TEST ==================================================
            if (ev.key.code == sf::Keyboard::Space) // Set Dissolve on/off
            {
                mParticleSystem->setDissolve();
            }

            if (ev.key.code == sf::Keyboard::A) // Dissolve Minus
            {
                if(mParticleSystem->getDissolutionRate() > 0)
                {
                    mParticleSystem->setDissolutionRate(
                      static_cast<unsigned char>(
                        mParticleSystem->getDissolutionRate() - 1));
                }
            }

            if (ev.key.code == sf::Keyboard::S) // Dissolve Plus
            {
                mParticleSystem->setDissolutionRate(
                  static_cast<unsigned char>(
                    mParticleSystem->getDissolutionRate() + 1));
            }


            if (ev.key.code == sf::Keyboard::W) // Speed Plus
            {
                mParticleSystem->setParticleSpeed(
              mParticleSystem->getParticleSpeed()
                    + mParticleSystem->getParticleSpeed() * 0.1);
            }

            if (ev.key.code == sf::Keyboard::Q && mParticleSystem->getParticleSpeed() > 0)
            {
                mParticleSystem->setParticleSpeed( // Speed Minus
                  mParticleSystem->getParticleSpeed()
                     - mParticleSystem->getParticleSpeed() * 0.1);
            }

            if(ev.key.code == sf::Keyboard::E) // Set Shape/Distribution
            {
                mParticleSystem->setDistribution();
            }
            // PARTICLE TEST END =============================================

            break;
        }
        default:
            break;
        }
    }

    handlePlayerInput(dT);

    for (auto& it : mEnemies)
    {
        mData->input->handleInput(*it, dT);
    }

}
// ---------------------------------------------------------------------------------------
void GameState::handlePauseMenuButtons()
{
    /*********************************************************************
     * @brief Handles the Pause menu buttons and their functionality.
     *
     * If 'back' is pressed go back to main menu state.
     * If 'quit' button is pressed, quit game.
     * If 'unpause' is pressed, set pause or resume
     *
     * @param None
     *
     * @return void
     *********************************************************************/

    if (mPauseMenu->isButtonPressed("back"))
    {
        mData->machine.addState(StateRef(
         std::make_unique<MainMenuState>(mData)), true);
    }

    if (mPauseMenu->isButtonPressed("quit"))
    {
        setQuit(true);
    }

    if (mPauseMenu->isButtonPressed("unpause"))
    {
        if (!isPaused())
        {
            setPause();
        }
        else
        {
            resume();
        }
    }
}
// ---------------------------------------------------------------------------------------
void GameState::handleWindowInput()
{
    // TODO SEE IF WE CAN REMOVE THIS FUNCTION FROM ALL STATES... COULD BE VIRTUAL
}
// ---------------------------------------------------------------------------------------
void GameState::updateParticleTest(const float &dT)
{
    // Mouse Input
    // Set the position to match the mouse location.
    sf::Vector2<double> mousePos = {
        static_cast<double>(sf::Mouse::getPosition(
          *mData->window->getRenderWindow()).x),
        static_cast<double>(sf::Mouse::getPosition(
          *mData->window->getRenderWindow()).y)};

      static_cast<sf::Vector2f>(
        sf::Mouse::getPosition(*mData->window->getRenderWindow()));

    // Update Particle Emitter to Mouse Position.
    if(mousePos.x > 0
       || mousePos.y > 0
       || mousePos.x < static_cast<double>(mData->window->getRenderWindow()->getSize().x)
       || mousePos.y < static_cast<double>(mData->window->getRenderWindow()->getSize().y))
    {
        mParticleSystem->setPosition(mousePos);
    }

    // Mouse Clicks
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) // Emit Particles
    {
        mParticleSystem->fuel(25);
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) // Set Gravity +
    {
        sf::Vector2<double> newGravity = {
            mLastMousePos.x - mousePos.x,
            mLastMousePos.y - mousePos.y,};

        newGravity *= 0.75;
        mParticleSystem->setGravity(newGravity);
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Middle)) // Set Gravity Zero
    {

        mParticleSystem->setGravity(0.0, 0.0);
    }

    // Update Last Mouse Position.
    mLastMousePos = mousePos;

    // Update particle system
    mParticleSystem->update(dT / 1000);
    //std::cout << mParticleSystem->getNumberOfParticlesString() << "\n";
}
// ---------------------------------------------------------------------------------------
void GameState::update(const float &dT)
{
    /*****************************************************************
     * @brief Updates the Game state.
     *
     * If not paused, updates the world time, updates the player
     * and tile map.
     *
     * If Paused updates the Pause menu and its buttons
     *
     * @param dT: delta time/ interpolation since
     * last update and render cycle
     *
     * @return void
     ****************************************************************/

    if (!isPaused()) // Not paused
    {
        // Update the world time
        mWorldTime.update(dT);
        //std::cout << mWorldTime.getTimeAsMinsHoursSecs() << "\n";

        // Update the player
        mPlayer->update(dT);

        // Update Enemies
        for(auto& it : mEnemies)
        {
            it->update(dT);
        }

        // Slider test update =========================================
        //mSlider->update(mData->input->getMousePosView(), dT);
    }
    else  // Paused menu update
    {
        mPauseMenu->update(mData->input->getMousePosView(), dT);
        handlePauseMenuButtons();
    }

    updateParticleTest(dT);

#ifndef NDEBUG
    // FPS DEBUG
    mFps->update();
#endif

}

// ---------------------------------------------------------------------------------------
void GameState::render([[maybe_unused]] const float &dT)
{
    /*************************************************************
     * @brief Draws the game state scene to the render window.
     *
     * Clears the window framebuffer.
     * Draws the Tile map.
     * Draws player and its elements (if toggled).
     * If paused, draws the Pause menu.
     * Draws the framebuffer to the window.
     *
     * @param dT: delta time/ interpolation since
     * last update and render cycle
     *
     * @return void
     **************************************************************/

    mData->window->beginDraw();

    // Tilemap
    //mMap->render(*mData->window->getRenderWindow());

    //Player
    mPlayer->render(*mData->window->getRenderWindow());

    // Enemies
    for (const auto& it : mEnemies)
    {
        it->render(*mData->window->getRenderWindow());
    }

    mData->window->draw(*mParticleSystem);

    // Slider =========================================================
    //mSlider->render(*mData->window->getRenderWindow());

    if (isPaused()) // Pause menu
    {
        mPauseMenu->render(*mData->window->getRenderWindow());
    }


#ifndef NDEBUG
    // Debug
    mMousePosition.render(*mData->window->getRenderWindow(),
                          *mData->input);

    mFps->render(*mData->window->getRenderWindow());
#endif

    mData->window->endDraw();
}
// ---------------------------------------------------------------------------------------

}// namespace gcb
