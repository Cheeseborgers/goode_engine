//////////////////////////////////////////////////////////////////////////////////////////
//      file: Utilities.cpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 27/07/2020.
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

#include "Utilities.hpp"

namespace gcb::gui
{
// Methods -------------------------------------------------------------------------------
float p2Px(const float percent, const sf::VideoMode& videoMode)
{
    /*******************************************************************************
     * @brief Converts a percentage value to pixels relative to the
     * current resolution in the x-axis.
     *
     * @param   float percent	              The percentage value.
     * @param	sf::VideoMode& videoMode      The current videomode of the
     *                                        window (resolution).
     *
     * @return	float			      The calculated pixel value.
     ******************************************************************************/

    return std::floor(static_cast<float>(videoMode.width) * (percent / 100.F));
}
// ---------------------------------------------------------------------------------------
float p2Py(const float percent, const sf::VideoMode& videoMode)
{
    /*****************************************************************************
     * @brief Converts a percentage value to pixels relative to the
     * current resolution in the y-axis.
     *
     * @param	float percent		        The percentage value.
     * @param	sf::VideoMode& videoMode	The current videomode of the
     *                                          window (resolution).
     *
     * @return	float			        The calculated pixel value.
     *****************************************************************************/

    return std::floor(static_cast<float>(videoMode.height) * (percent / 100.F));
}
// ---------------------------------------------------------------------------------------
unsigned calcCharSize(const sf::VideoMode& videoMode)
{
    /********************************************************************************
     * @brief Calculates the character size for text using the current
     * resolution and a constant (fixedModifier).
     *
     * @param	sf::VideoMode& videoMode      The current videomode of the
     *                                        window (resolution).
     *
     * @return	unsigned	              The calculated character size value.
     *******************************************************************************/

    const int fixedModifier{60};
    return ((videoMode.width + videoMode.height) / fixedModifier);
}
// ---------------------------------------------------------------------------------------
unsigned calcCharSize(const sf::VideoMode& videoMode, const unsigned modifier)
{
    /******************************************************************************
     * @brief Calculates the character size for text using the current
     * resolution and a constant.
     *
     * @param	sf::VideoMode& videoMode      The current videomode of the window
     *                                        (resolution).
     * @param	unsigned modifier             Used to modify the character size
     *                                        in a more custom way.
     *
     * @return	unsigned	              The calculated character size value.
     *******************************************************************************/

    return ((videoMode.width + videoMode.height) / modifier);
}
// ---------------------------------------------------------------------------------------

}// namespace gcb
