//
//      Player.cpp
//      Created by Goodecheeseburgers on 09/07/2020.
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

#include "Player.hpp"

namespace gcb
{
// Private Methods -----------------------------------------------------------------------
void Player::initVariables()
{
    /**********************************************************
     * @return void
     *
     * @brief Initializes the Players variables as default.
     *
     * @param None
     * ********************************************************/

    mAttacking = false;
}
// ---------------------------------------------------------------------------------------
void Player::initAnimations()
{
    /**********************************************************
     * @return void
     *
     * @brief Initializes the Players animations.
     *
     * @Note: float animationTimer, less = faster.
     *
     * @param None
     * ********************************************************/

    mAnimation->addAnimation(
        "idle", 8.0F,
        0,0,
        13, 0,
        192, 192);

    mAnimation->addAnimation(
        "walk", 10.0F,
        0,1,
        11, 1,
        192, 192);

    mAnimation->addAnimation(
        "attack", 5.0F,
        0,2,
        13, 2,
        192 * 2, 192);
}
// ---------------------------------------------------------------------------------------
void Player::initInventory()
{
    mInventory = std::make_unique<Inventory>();

    auto item = std::make_unique<Weapon>("Sword", "A big ass sword.", ItemType::WEAPON);
    mInventory->addItem(std::move(item));
}
// Constructor ---------------------------------------------------------------------------
Player::Player(float positionX, float positionY, sf::Texture& textureSheet)
{
    initVariables();

    setPosition(positionX, positionY);

    setTexture(textureSheet);

    // Hitbox ========================================================================
    createHitboxComponent(mSprite,
        86.0F, 74.0F, 80.0F, 111.0F);

    // Movement =====================================================================
    createMovementComponent(200.0F, 6.0F, 4.0F);

    // Animations ===================================================================
    createAnimationComponent(textureSheet);
    initAnimations();

    // Inventory
    initInventory();
}
// Methods -------------------------------------------------------------------------------
void Player::updateAttack()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        mAttacking = true;
    }
}
// ---------------------------------------------------------------------------------------
void Player::updateAnimations(const float &deltaTime)
{
    // Attacking
    if (mAttacking)
    {
        // TODO GO THROUGH ALL THIS LOT AND SPLIT INTO LOGICAL FUNCTIONS ===============
        //Set origin depending on direction
        if (mSprite.getScale().x > 0.f) //Facing left
        {
            mSprite.setOrigin(96.f, 0.f);
        }
        else //Facing right
        {
            mSprite.setOrigin(258.f + 96.f, 0.f);
        }

        // TODO UPDATE THE HITBOX WHEN ATTACKING =====================================
        //Animate and check for animation end
        if (mAnimation->play("attack", deltaTime, true))
        {
            mAttacking = false;

            // Reset origin depending on direction, for non attack.
            if (mSprite.getScale().x > 0.f) //Facing left
            {
                mSprite.setOrigin(0.f, 0.f);
            }
            else //Facing right
            {
                mSprite.setOrigin(258.f, 0.f);
            }
        }
    }

    if (mMovement->getState(gcb::MovementStates::IDLE))
    {
        mAnimation->play("idle", deltaTime);
    }
    else if (mMovement->getState(gcb::MovementStates::MOVING_LEFT))
    {
        if (mSprite.getScale().x < 0.f)
        {
            mSprite.setOrigin(0.f, 0.f);
            mSprite.setScale(1.f, 1.f);
        }

        mAnimation->play(
            "walk", deltaTime,
          mMovement->getVelocity().x, mMovement->getMaxVelocity());
    }
    else if (mMovement->getState(gcb::MovementStates::MOVING_RIGHT))
    {
        if (mSprite.getScale().x > 0.f)
        {
            mSprite.setOrigin(258.f, 0.f);
            mSprite.setScale(-1.f, 1.f);
        }

        mAnimation->play(
            "walk", deltaTime,
          mMovement->getVelocity().x, mMovement->getMaxVelocity());
    }
    else if (mMovement->getState(gcb::MovementStates::MOVING_UP))
    {
        mAnimation->play(
            "walk", deltaTime,
          mMovement->getVelocity().y, mMovement->getMaxVelocity());
    }
    else if (mMovement->getState(gcb::MovementStates::MOVING_DOWN))
    {
        mAnimation->play(
            "walk", deltaTime,
          mMovement->getVelocity().y, mMovement->getMaxVelocity());
    }
}
// ---------------------------------------------------------------------------------------
void Player::update(const float &deltaTime)
{
    /*********************************************************
     * @return void
     *
     * @brief Updates the movement component.
     *
     * :Checks for left click mouse event
     * :Updates and plays the animation of player depending
     * on the current movement state/action.
     *
     * @param const float& deltaTime: delta time between frame updates.
     **********************************************************/

    mMovement->update(deltaTime);

    updateAttack();

    updateAnimations(deltaTime);

    mHitbox->update();
}
// ---------------------------------------------------------------------------------------
void Player::render(sf::RenderTarget &target)
{
    target.draw(mSprite);

    if (mHitbox && mShowHitbox)
    {
        mHitbox->render(target);
    }
}
const std::unique_ptr<Inventory> &Player::getInventory() const
{
    return mInventory;
}
// ---------------------------------------------------------------------------------------


}// namespace gcb


