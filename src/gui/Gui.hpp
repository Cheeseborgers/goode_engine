//
//      Created by Goodecheeseburgers on 22/06/2020.
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
//

#ifndef ENGINE_BASE_GUI_HPP
#define ENGINE_BASE_GUI_HPP

#include "Button.hpp"
#include "DropDownList.hpp"
#include "Slider.hpp"
#include "Utilities.hpp"

namespace gcb::gui
{

using Menu = std::unordered_map<std::string, std::string>;

class Gui
{

private:
    Menu mMenu;
    Buttons mButtons;

    void init(); // Initializer called by all constructors

protected:
    sf::RenderTarget* mTarget; // Current render target
    sf::View mView;            // Current view
    bool mWindowFocused{true};

public:
    Gui(); // Default constructor (needs target set with setTarget())
    Gui(sf::RenderTarget& target);
    Gui(const Gui& copy)             = delete; // Deleted copy constructor
    Gui& operator=(const Gui& right) = delete; // Deleted assignment operator overload

    // Setters
    void setTarget(sf::RenderTarget& target);
    void setView(const sf::View& view);

    // Getters
    const sf::View& getView() const;
    sf::RenderTarget* getTarget() const;

    // Methods
    void update();
    void render();
};


}// namespace gcb::gui

#endif//ENGINE_BASE_GUI_HPP
