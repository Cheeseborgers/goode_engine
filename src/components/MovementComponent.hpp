//
//      MovementComponent.h
//      Created by Goodecheeseburgers on 12/07/2020.
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

#ifndef ENGINE_BASE_MOVEMENTCOMPONENT_HPP
#define ENGINE_BASE_MOVEMENTCOMPONENT_HPP

#include "../pch.hpp"

namespace gcb
{
enum MovementStates : unsigned char {
    IDLE = 0,
    MOVING,
    MOVING_LEFT,
    MOVING_RIGHT,
    MOVING_DOWN,
    MOVING_UP };

class MovementComponent {
  private:
    // Variables
    sf::Sprite& mSpriteRef;

    float mMaxVelocity;
    float mAcceleration;
    float mDeceleration;

    sf::Vector2f mVelocity;

  public:
    // Constructor
    MovementComponent(sf::Sprite& sprite,
        float maxVelocity, float acceleration, float deceleration);
    virtual ~MovementComponent();

    // Accessors
    const sf::Vector2f& getVelocity() const;
    const float& getMaxVelocity() const;
    bool getState (short unsigned state) const;

    // Modifiers
    void move(const float dirX, const float dirY, const float& dT);

    // Methods
    void update(const float &dt);
};


}// namespace gcb


#endif//ENGINE_BASE_MOVEMENTCOMPONENT_HPP
