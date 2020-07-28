//
//      MovementComponent.cpp
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

#include "MovementComponent.hpp"

namespace gcb
{
// Constructor ---------------------------------------------------------------------------
MovementComponent::MovementComponent(sf::Sprite &sprite, float maxVelocity,
     float acceleration, float deceleration)
    : mSpriteRef(sprite), mMaxVelocity(maxVelocity),
      mAcceleration(acceleration), mDeceleration(deceleration) {}
// ---------------------------------------------------------------------------------------
MovementComponent::~MovementComponent() {}
// Accessors -----------------------------------------------------------------------------
[[maybe_unused]] const sf::Vector2f &MovementComponent::getVelocity() const
{
    /* @return const sf::Vector2f
     * Returns the current velocity of the entity.
     */

    return mVelocity;
}
// ---------------------------------------------------------------------------------------
const float &MovementComponent::getMaxVelocity() const
{
    /* @return const &float
     * Returns the current Max velocity of the entity.
     */

    return mMaxVelocity;
}
// Modifiers -----------------------------------------------------------------------------
void MovementComponent::move(
  const float dirX, const float dirY, const float& dT)
{
    /* @return void
     * Accelerating a sprite until it reaches the max velocity.
     */

    mVelocity.x += mAcceleration * dirX * dT;
    mVelocity.y += mAcceleration * dirY * dT;
}
// Methods -------------------------------------------------------------------------------
void MovementComponent::update(const float &dT)
{
    /* @return Void
     * Decelerates the sprite and controls the maximum velocity
     * Moves sprite
     */

    if (mVelocity.x > 0.0F) // Check for Positive X (Right)
    {
        // Max velocity check X Positive (Right)
        if (mVelocity.x > mMaxVelocity)
        {
            mVelocity.x = mMaxVelocity;
        }

        // Deceleration X Positive (Right)
        mVelocity.x -= mDeceleration;
        if (mVelocity.x < 0.0F)
        {
            mVelocity.x = 0.0F;
        }

    }
    else if (mVelocity.x < 0.0F) // Check for Negative X (Left)
    {
        // Max velocity check X negative (Left)
        if (mVelocity.x < -mMaxVelocity)
        {
            mVelocity.x = -mMaxVelocity;
        }

        // Deceleration X Negative (Left)
        mVelocity.x += mDeceleration;

        if (mVelocity.x > 0.0F)
        {
            mVelocity.x = 0.0F;
        }
    }

    if (mVelocity.y > 0.0F) // Check for Positive Y (Down)
    {
        // Max velocity check Y Positive (Down)
        if (mVelocity.y > mMaxVelocity)
        {
            mVelocity.y = mMaxVelocity;
        }

        // Deceleration Y Positive (Down)
        mVelocity.y -= mDeceleration;
        if (mVelocity.y < 0.0F)
        {
            mVelocity.y = 0.0F;
        }
    }
    else if (mVelocity.y < 0.0F) // Check for Negative Y (Up)
    {
        // Max velocity check Y negative (Up)
        if (mVelocity.y < -mMaxVelocity)
        {
            mVelocity.y = -mMaxVelocity;
        }

        // Deceleration Y Negative (Up)
        mVelocity.y += mDeceleration;

        if (mVelocity.y > 0.0F)
        {
            mVelocity.y = 0.0F;
        }
    }

    // Final Move, Uses the Velocity
    mSpriteRef.move(mVelocity * dT);
}
// ---------------------------------------------------------------------------------------
bool MovementComponent::getState(unsigned short state) const
{
    switch (state)
    {
    case gcb::MovementStates::IDLE:
        return mVelocity.x == 0.0F && mVelocity.y == 0.0F;
    case gcb::MovementStates::MOVING:
        return mVelocity.x != 0.0F || mVelocity.y != 0.0F;
    case gcb::MovementStates::MOVING_LEFT:
        return mVelocity.x < 0.0F;
    case gcb::MovementStates::MOVING_RIGHT:
        return mVelocity.x > 0.0F;
    case gcb::MovementStates::MOVING_UP:
        return mVelocity.y < 0.0F;
    case gcb::MovementStates::MOVING_DOWN:
        return mVelocity.y > 0.0F;
    }

    return false;
}
// ---------------------------------------------------------------------------------------


}// namespace gcb

