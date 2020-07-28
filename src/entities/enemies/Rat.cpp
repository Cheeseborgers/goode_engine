//
// Created by fason on 15/07/2020.
//

#include "Rat.hpp"

namespace gcb
{
// ---------------------------------------------------------------------------------------
void Rat::initVariables()
{
}
// ---------------------------------------------------------------------------------------
void Rat::initAnimations()
{
    mAnimation->addAnimation(
      "idle", 25.f, 0,0,
      3, 0, 60, 64);
    mAnimation->addAnimation(
      "walk_down", 11.f, 0,1,
      3, 1, 60, 64);
    mAnimation->addAnimation(
      "walk_left", 11.f, 0, 2,
      3, 2, 60, 64);
    mAnimation->addAnimation(
      "walk_right", 11.f, 0, 3,
      3, 3, 60, 64);
    mAnimation->addAnimation(
      "walk_up", 11.f, 0, 4,
      3, 4, 60, 64);
    mAnimation->addAnimation(
      "attack", 5.f, 0, 2,
      1, 2, 60, 64);
}
// ---------------------------------------------------------------------------------------
Rat::Rat(float posX, float posY, sf::Texture& textureSheet)
{
    initVariables();

    setTexture(textureSheet);

    createHitboxComponent(mSprite, 13.0F, 39.0F,
      30.0F, 30.0F);

    createMovementComponent(
      50.0F, 1600.0F, 1000.0F);

    createAnimationComponent(textureSheet);

    initAnimations();
    setPosition(posX, posY);

}
// ---------------------------------------------------------------------------------------
Rat::~Rat()
{

}
// ---------------------------------------------------------------------------------------
void Rat::updateAnimation(const float &dT)
{
    if (mMovement->getState(gcb::MovementStates::IDLE))
    {
        mAnimation->play("idle", dT);
    }
    else if (mMovement->getState(gcb::MovementStates::MOVING_LEFT))
    {
        mAnimation->play("walk_left", dT,
          mMovement->getVelocity().x, mMovement->getMaxVelocity());
    }
    else if (mMovement->getState(gcb::MovementStates::MOVING_RIGHT))
    {
        mAnimation->play("walk_right", dT,
          mMovement->getVelocity().x, mMovement->getMaxVelocity());
    }
    else if (mMovement->getState(gcb::MovementStates::MOVING_UP))
    {
        mAnimation->play("walk_up", dT,
          mMovement->getVelocity().y, mMovement->getMaxVelocity());
    }
    else if (mMovement->getState(gcb::MovementStates::MOVING_DOWN))
    {
        mAnimation->play("walk_down", dT,
          mMovement->getVelocity().y, mMovement->getMaxVelocity());
    }

    /*if (damageTimer.getElapsedTime().asMilliseconds() <= damageTimerMax)
    {
        mSprite.setColor(sf::Color::Red);
    }
    else
        mSprite.setColor(sf::Color::White);*/
}
// ---------------------------------------------------------------------------------------
void Rat::update([[maybe_unused]] const float &dT)
{
    mMovement->update(dT);

    updateAnimation(dT);

    mHitbox->update();
}
// ---------------------------------------------------------------------------------------
void Rat::render([[maybe_unused]] sf::RenderTarget &target)
{
    target.draw(mSprite);

    if (mHitbox && isShowHitbox())
    {
        mHitbox->render(target);
    }
}
// ---------------------------------------------------------------------------------------

}// namespace gcb

