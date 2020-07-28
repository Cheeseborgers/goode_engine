//////////////////////////////////////////////////////////////////////////////////////////
//      file: WindowManger.cpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 03/07/2020.
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

#include "WindowManager.hpp"


namespace gcb::window
{
// Private Methods -----------------------------------------------------------------------
void WindowManager::setup(const std::string& title, const sf::Vector2u& size)
{
    mWindowTitle = title;
    mWindowSize = size;
    mIsFullscreen = {Definitions::DEFAULT_FULLSCREEN};
    mModeBitsPerPixel = {Definitions::MODE_BITS_PER_PIXEL};
    mCurrentVideoMode = { mWindowSize.x, mWindowSize.y, mModeBitsPerPixel };
    mVideoModes = sf::VideoMode::getFullscreenModes();
    mIsDone = false;
    create();
}
// ---------------------------------------------------------------------------------------
void WindowManager::setup()
{
    mCurrentVideoMode = { mWindowSize.x, mWindowSize.y, mModeBitsPerPixel };
    mVideoModes = sf::VideoMode::getFullscreenModes();
    mIsDone = false;
    create();
}
// ---------------------------------------------------------------------------------------
void WindowManager::create()
{
    auto style = (mIsFullscreen ? sf::Style::Fullscreen : sf::Style::Default);

    mWindow.create(mCurrentVideoMode,mWindowTitle, style);

    //mWindow.setKeyRepeatEnabled(false);

}
// ---------------------------------------------------------------------------------------
void WindowManager::destroy()
{
    mWindow.close();
}
// Constructors --------------------------------------------------------------------------
WindowManager::WindowManager()
{
    setup(
      Definitions::GAME_TITLE,
      sf::Vector2u(Definitions::WINDOW_WIDTH, Definitions::WINDOW_HEIGHT));
}
// ---------------------------------------------------------------------------------------
WindowManager::WindowManager(const std::string & title, const sf::Vector2u & size)
{
    setup(title, size);
}
// ---------------------------------------------------------------------------------------
WindowManager::WindowManager(const std::string &title,
    unsigned int width, unsigned int height)
{
    setup(title, sf::Vector2u(width, height));
}
// ---------------------------------------------------------------------------------------
WindowManager::WindowManager(const std::string& title, const sf::Vector2u& size,
    bool fullscreen, unsigned int modeBitsPerPixel)
    : mWindowSize(size), mWindowTitle(title),
      mModeBitsPerPixel(modeBitsPerPixel), mIsFullscreen(fullscreen)
{
    setup();
}
// Destructor ----------------------------------------------------------------------------
WindowManager::~WindowManager(){ destroy(); }
// Getters -----------------------------------------------------------------------------
bool WindowManager::isDone() { return mIsDone; }
// ---------------------------------------------------------------------------------------
bool WindowManager::isFullScreen() { return mIsFullscreen; }
// ---------------------------------------------------------------------------------------
sf::Vector2u WindowManager::getSize() { return mWindowSize; }
// ---------------------------------------------------------------------------------------
const sf::RenderWindow &WindowManager::getRenderWindow() const { return mWindow; }
// ---------------------------------------------------------------------------------------
sf::RenderWindow *WindowManager::getRenderWindow() { return &mWindow; }
// ---------------------------------------------------------------------------------------
const sf::VideoMode &WindowManager::getVideoMode() const {return mCurrentVideoMode; }
// ---------------------------------------------------------------------------------------
const std::vector<sf::VideoMode> &WindowManager::getVideoModes() const
{
    return mVideoModes;
}
// ---------------------------------------------------------------------------------------
unsigned int WindowManager::getFrameRateLimit() const { return mFrameRateLimit; }
// Setters -------------------------------------------------------------------------------
void WindowManager::toggleFullScreen()
{
    mIsFullscreen = !mIsFullscreen;
    destroy();
    create();
}
// ---------------------------------------------------------------------------------------
void WindowManager::setFrameRateLimit(unsigned int frameRateLimit)
{
    if (frameRateLimit >= 120 || frameRateLimit < 30)
    {
        frameRateLimit = Definitions::DEFAULT_FRAMERATE_LIMIT;
    }

    mFrameRateLimit = frameRateLimit;

    mWindow.setFramerateLimit(mFrameRateLimit);
}
// ---------------------------------------------------------------------------------------
void WindowManager::setVideoMode(const sf::VideoMode &videoMode)
{
    mCurrentVideoMode = videoMode;
    destroy();
    create();
}
// Methods -------------------------------------------------------------------------------
void WindowManager::beginDraw() { mWindow.clear(sf::Color::Black); }
// ---------------------------------------------------------------------------------------
void WindowManager::endDraw() { mWindow.display(); }
// ---------------------------------------------------------------------------------------
void WindowManager::draw(sf::Drawable& drawable){ mWindow.draw(drawable);}
// ---------------------------------------------------------------------------------------
void WindowManager::close() { destroy(); }
//----------------------------------------------------------------------------------------
void WindowManager::saveSettingsToFile(const std::string &path)
{
    std::ofstream ofs(path);

    if (ofs.is_open())
    {
        ofs << mCurrentVideoMode.width << " " << mCurrentVideoMode.height;
        ofs << mIsFullscreen;
        ofs << mFrameRateLimit;
        ofs << mVerticalSync;
        ofs << mContextSettings.antialiasingLevel;
    }
    else
    {
        std::cout << "ERROR::WindowManager::saveSettingsToFile::COULD "
             "NOT OPEN FILE: " << path << "\n";

    }

    ofs.close();
}
// ---------------------------------------------------------------------------------------
void WindowManager::loadSettingsFromFile(const std::string &path)
{
    std::ifstream ifs(path);

    if (ifs.is_open())
    {
        ifs >> mCurrentVideoMode.width >> mCurrentVideoMode.height;
        ifs >> mIsFullscreen;
        ifs >> mFrameRateLimit;
        ifs >> mVerticalSync;
        ifs >> mContextSettings.antialiasingLevel;
    }
    else
    {
        std::cout << "ERROR::gcb::WindowManager::loadSettingsFromFile::"
             "COULD NOT OPEN FILE: " << path << "\n";
    }

    std::cout << mCurrentVideoMode.width << " " << mCurrentVideoMode.height << "\n;";

    ifs.close();
}
// ---------------------------------------------------------------------------------------

}// namespace gcb::window
