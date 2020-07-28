//////////////////////////////////////////////////////////////////////////////////////////
//      file: WindowManger.hpp
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

#ifndef ENGINE_BASE_WINDOWMANAGER_HPP
#define ENGINE_BASE_WINDOWMANAGER_HPP

#include "../pch.hpp"


namespace gcb::window
{
class WindowManager {
public:
    // Constructors
    WindowManager();
    WindowManager(const std::string& title, const sf::Vector2u& size);
    WindowManager(const std::string &title, unsigned int width, unsigned int height);
    WindowManager(
        const std::string& title, const sf::Vector2u& size,
        bool fullscreen, unsigned int modeBitsPerPixel);

    WindowManager(const WindowManager &) = delete;  // non construction-copyable
    WindowManager & operator=(const WindowManager &) = delete; // non copyable
    ~WindowManager();

    // Getters
    bool isDone();
    bool isFullScreen();
    sf::RenderWindow* getRenderWindow();
    const sf::RenderWindow &getRenderWindow() const;
    sf::Vector2u getSize();
    const sf::VideoMode &getVideoMode() const;
    const std::vector<sf::VideoMode> &getVideoModes() const;

    // Setters
    void toggleFullScreen();
    void setVideoMode(const sf::VideoMode &videoMode);

    void beginDraw(); // Clear the window.
    void endDraw(); // Display the changes.
    void create(); // Creates a new window
    void close(); // closes window
    void draw(sf::Drawable&lDrawable);

private:
    sf::RenderWindow mWindow;
    sf::VideoMode mCurrentVideoMode;
    sf::Vector2u mWindowSize;
    std::string mWindowTitle;
    unsigned mModeBitsPerPixel;
    unsigned mFrameRateLimit;

  public:
    unsigned int getFrameRateLimit() const;
    void setFrameRateLimit(unsigned int frameRateLimit);
  private:
    sf::ContextSettings mContextSettings;

    bool mIsDone;
    bool mIsFullscreen;
    bool mVerticalSync;

    std::vector<sf::VideoMode> mVideoModes;

    //Functions
    void saveSettingsToFile(const std::string &path);
    void loadSettingsFromFile(const std::string &path);

    void setup(const std::string& title, const sf::Vector2u& size);
    void setup();
    void destroy();

};

}// namespace gcb::window

#endif//ENGINE_BASE_WINDOWMANAGER_HPP
