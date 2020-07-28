//
//      Entity.cpp
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

#include "Entity.hpp"


namespace gcb
{
// Constructor ---------------------------------------------------------------------------
Entity::Entity()
    : mShowHitbox {false}, mHitbox(nullptr), mMovement(nullptr), mAnimation(nullptr) {}
// Component functions -------------------------------------------------------------------
void Entity::createHitboxComponent(sf::Sprite &sprite,
    float offsetX, float offsetY, float width, float height)
{
    /****************************************************
    * @brief Creates an Hitbox component to the Entity.
    *
    * @param &sprite: Reference to the Entities sprite.
    * @param offsetX: X offset of the Hitbox from Entity sprite.
    * @param offsetY: Y offset of the Hitbox from Entity sprite.
    * @param width: Width of the Entities Hitbox.
    * @param height: Height of the Entities Hitbox.
    *
    * @return void
    *****************************************************/

    mHitbox = std::make_unique<HitboxComponent>(sprite,
        offsetX, offsetY, width, height);
}
// ---------------------------------------------------------------------------------------
void Entity::createMovementComponent(
    float velocityMax, float acceleration, float deceleration)
{
    // TODO FIX THESE COMMENTS =================================================
    /***************************************************
     * @brief Creates an Movement component to the entity.
     *
     * @param velocityMax
     * @param acceleration
     * @param deceleration
     *
     * @return void
     ***************************************************/

    mMovement = std::make_unique<MovementComponent>(
      mSprite, velocityMax, acceleration, deceleration);
}
// ---------------------------------------------------------------------------------------
void Entity::createAnimationComponent(sf::Texture &textureSheet)
{
    /***************************************************
     * @return void
     *
     * @brief Creates an Animation component to the entity.
     *
     * @param textureSheet: A reference to the Entities
     * texture sheet.
     ***************************************************/

    mAnimation = std::make_unique<AnimationComponent>(mSprite, textureSheet);
}
// Getters -----------------------------------------------------------------------------
const std::unique_ptr<MovementComponent> &Entity::getMovementComponent() const
{
    /*****************************************************************
     * @brief Returns a const ref of the Movement Component for
     * the InputHandler and Commands.
     *
     * @param None
     *
     * @return const std::unique_ptr<MovementComponent>
     ******************************************************************/

    return mMovement;
}
// ---------------------------------------------------------------------------------------
bool Entity::isShowHitbox() const
{
    /*****************************************************************
    * @brief Returns the the boolean state to say if the
    * Entities hitbox should display.
    *
    * @return void
    *******************************************************************/

    return mShowHitbox;
}
// Setters -----------------------------------------------------------------------------
void Entity::setTexture(sf::Texture& texture)
{
    /*************************************************
    * @brief Sets the entity's sprite texture.
    *
    * @param sf::Texture& texture: A reference to the Entities
    * texture sheet.
    *
    * @return void
    **************************************************/

    mSprite.setTexture(texture);
}
// ---------------------------------------------------------------------------------------
void Entity::move(float directionX, float directionY, const float& dT)
{
    /**************************************************************
     * @brief Moves the entity in the directions x and y
     * if there is a movement component attached to this Entity.
     *
     * @param float directionX: X Direction to move by.
     * @param float directionY: Y Direction to move by.
     *
     * @return void
     *************************************************************/

    if (mMovement)
    {
        mMovement->move(directionX, directionY, dT);
    }
}
// ---------------------------------------------------------------------------------------
void Entity::setPosition(float positionX, float positionY)
{
    /************************************************************8
    * @brief Sets the entity's initial position.
    *
    * @param float positionX: The Entities initial X position.
    * @param float positionY: The Entities initial Y position.
    *
    * @return void
    ************************************************************/

    mSprite.setPosition(positionX, positionY);
}
// ---------------------------------------------------------------------------------------
void Entity::setShowHitbox(bool showHitbox)
{
    /***************************************************
    * @brief Sets the entity's hitbox display bool
    *
    * @param bool showHitbox: Display hitbox or not.
    *
    * @return void
    ****************************************************/

    mShowHitbox = showHitbox;
}
// Methods -------------------------------------------------------------------------------
void Entity::update([[maybe_unused]]const float &dT) {}
// ---------------------------------------------------------------------------------------
void Entity::render(sf::RenderTarget &target)
{
    /******************************************************
     * @brief Draws the entity to the render target and
     * hitbox (if enabled and present) to the screen.
     *
     * draws the entities hitbox if the component is
     * present.
     *
     * @param &target: Current framebuffer.
     *
     * @return void
     ******************************************************/

    target.draw(mSprite);

    if (mHitbox)
    {
        mHitbox->render(target);
    }
}
// ---------------------------------------------------------------------------------------


}// namespace gcb

