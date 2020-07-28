//////////////////////////////////////////////////////////////////////////////////////////
//      file: game.cpp
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

#include "Game.hpp"
#include "states/SplashState.hpp"


namespace gcb
{
// Initializers --------------------------------------------------------------------------
void Game::initVariables()
{
    /**********************************************************************
     * @brief Initializes the mData (state data) unique pointers for assets and
     * input.
     *
     * @Return Void
     **********************************************************************/

    mData = std::make_shared<GameData>();
    mData->textures = std::make_unique<TextureManager>();
    mData->input    = std::make_unique<InputHandler>();
    mData->fonts    = std::make_unique<FontManager>();
    mData->sounds   = std::make_unique<SoundManager>();
    mData->music    = std::make_unique<MusicManager>();
}
// ---------------------------------------------------------------------------------------
void Game::initKeyBinds()
{
    /**********************************************************************
     * @brief Initializes the supported keys into the input manager
     *
     * @Return Void
     **********************************************************************/

    mData->input->loadSupportedKeys();
}
// ---------------------------------------------------------------------------------------
void Game::initWindow()
{
    /**********************************************************************
     * @brief Creates an SFML window from a text file
     *
     * Sets some temp variables to read in settings from the file
     * Reads in the display settings file.
     * Creates an SFML window instance.
     *
     * @Return Void
     **********************************************************************/

    std::ifstream ifs("config/display.txt");

    mWindowSize = {Definitions::WINDOW_WIDTH, Definitions::WINDOW_HEIGHT};
    unsigned int framerateLimit{ Definitions::DEFAULT_FRAMERATE_LIMIT };
    bool verticalSyncEnabled{ Definitions::DEFAULT_VERT_SYNC };
    bool fullscreen{Definitions::DEFAULT_FULLSCREEN};
    unsigned int modeBitsPerPixel{Definitions::MODE_BITS_PER_PIXEL};

    if (ifs.is_open())
    {
        ifs >> mWindowSize.x >> mWindowSize.y;
        ifs >> framerateLimit;
        ifs >> verticalSyncEnabled;
        ifs >> fullscreen;
        ifs >> modeBitsPerPixel;
    } else
    {
        std::cout << "ERROR::GAME::INITWINDOW::COULD NOT OPEN WINDOW SETTINGS FILE\n";
    }

    ifs.close();

    mData->window = std::make_unique<gcb::window::WindowManager>(
        Definitions::GAME_TITLE,
        sf::Vector2u(mWindowSize.x, mWindowSize.y),
        fullscreen, modeBitsPerPixel);

    // TODO: MAKE A FRAME RATE SET FUNCTIONALITY INTO THE WINDOW MANAGER
    //mData->window->getRenderWindow()->setFramerateLimit(framerateLimit);
    mData->window->getRenderWindow()->setVerticalSyncEnabled(verticalSyncEnabled);
}
// ---------------------------------------------------------------------------------------
void Game::initStates()
{
    /*************************************************************************
     * @brief Initialises and Pushes a new SPLASHSTATE onto the StateMachine
     * stack.
     *
     * @param None
     *
     * @Return Void
     ************************************************************************/

    mData->machine.addState(
        StateRef(std::make_unique<SplashState>(this->mData)));

}
// Constructors --------------------------------------------------------------------------
Game::Game()
{
    /********************************************************************
     * @brief Default constructor, Constructs a new Game object.
     *
     * @param None
     *******************************************************************/

    initVariables();

    initKeyBinds();

    initWindow();

    initStates();

    run();
}
// ---------------------------------------------------------------------------------------
Game::Game(const std::string &title, unsigned int width, unsigned int height)
{
    /********************************************************************
     * @brief Constructs a new Game class.
     * Initialises mData's pointers
     * Creates an SFML window, using the params width and height.
     * Sets the the frame rate limit and vertical sync
     *
     * @param title: The Game/ Window title.
     * @Param width: Window width.
     * @Param height: Window Height.
     *******************************************************************/

    initVariables();

    mData->window = std::make_unique<gcb::window::WindowManager>(
        title, sf::Vector2u (width, height));

    mData->window->getRenderWindow()->setFramerateLimit(
        Definitions::DEFAULT_FRAMERATE_LIMIT);

    mData->window->getRenderWindow()->setVerticalSyncEnabled(
        Definitions::DEFAULT_VERT_SYNC);

    initStates();

    run();
}
// Methods -------------------------------------------------------------------------------
void Game::run()
{

    /********************************************************************
     * @brief Runs the game
     *
     * @param None
     *
     * @return void
     *******************************************************************/

    // TODO FIX APPLICATION END ==================================================
    float t{0.0F};
    float dt{0.01F};

    float currentTime = mClock.getElapsedTime().asSeconds();
    float accumulator{0.0F};

    while (mData->window->getRenderWindow()->isOpen())
    {
        mData->machine.processStateChanges();
        mData->input->updateMousePositions(*mData->window->getRenderWindow());

        // Update the key time to stop keyboard multi click.
        mData->machine.getActiveState()->updateKeyTime(dt);
        mData->machine.getActiveState()->handleInput(dt);

        float newTime = mClock.getElapsedTime().asSeconds();

        float  frameTime = newTime - currentTime;

        if ( frameTime > 0.25F)
        {
            frameTime = 0.25F;
        }

        currentTime = newTime;
        accumulator += frameTime;

        while ( accumulator >= dt )
        {
            // Update the active state
            if (!this->mData->machine.getActiveState()->getQuit())
            {
                mData->machine.getActiveState()->update(dt);
                t += dt;
                accumulator -= dt;
            }
            else
            {
                mData->machine.removeState();
                mData->window->close();
                //endApplication();
            }

        }

        mData->machine.getActiveState()->render(dt);
    }

    endApplication();
}
// ---------------------------------------------------------------------------------------


}// namespace gcb
