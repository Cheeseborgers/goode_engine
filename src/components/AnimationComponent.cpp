//
// Created by fason on 12/07/2020.
//

#include "AnimationComponent.hpp"

namespace gcb
    {
// Private Methods -----------------------------------------------------------------------
// Constructor ---------------------------------------------------------------------------
AnimationComponent::AnimationComponent(sf::Sprite &sprite, sf::Texture &textureSheet)
: mSprite(sprite), mTextureSheet(textureSheet)
{
    mLastAnimation = "";
    mPriorityAnimation = "";
}
// Destructor ----------------------------------------------------------------------------
AnimationComponent::~AnimationComponent()
{

}
// Accessors -----------------------------------------------------------------------------
const bool &AnimationComponent::isDone(const std::string &key)
{
    return mAnimations[key]->isDone();
}
// Modifiers -----------------------------------------------------------------------------
void AnimationComponent::addAnimation(const std::string &key, float animationTimer,
int startFrameX, int startFrameY, int framesX, int framesY,int width, int height)
{
    mAnimations[key] = std::make_unique<Animation>(
      mSprite, mTextureSheet, animationTimer,
        startFrameX, startFrameY,
        framesX, framesY,
        width, height);
}
// Methods -------------------------------------------------------------------------------
const bool &AnimationComponent::play(
    const std::string &key, const float &dT, const bool priority)
{

    if (mPriorityAnimation != "") //If there is a priority animation
    {
        if (mPriorityAnimation == key)
        {
            if (mLastAnimation != key)
            {
                if (mLastAnimation == "")
                    mLastAnimation = key;
                else
                {
                    mAnimations[mLastAnimation]->reset();
                    mLastAnimation = key;
                }
            }

            //If the priority animation is done, remove it
            if (mAnimations[key]->play(dT))
            {
                mPriorityAnimation = "";
            }
        }
    }
    else //Play animation of no other priority animation is set
    {
        //If this is a priority animation, set it.
        if (priority)
        {
            mPriorityAnimation = key;
        }

        if (mLastAnimation != key)
        {
            if (mLastAnimation == "")
                mLastAnimation = key;
            else
            {
                mAnimations[mLastAnimation]->reset();
                mLastAnimation = key;
            }
        }

        mAnimations[key]->play(dT);
    }

    return mAnimations[key]->isDone();
}
// ---------------------------------------------------------------------------------------
const bool & AnimationComponent::play(const std::string &key, const float &dT,
    float modifier, float modifierMax, const bool priority)
{
    if (mPriorityAnimation != "") //If there is a priority animation
    {
        if (mPriorityAnimation == key)
        {
            if (mLastAnimation != key)
            {
                if (mLastAnimation == "")
                    mLastAnimation = key;
                else
                {
                    mAnimations[mLastAnimation]->reset();
                    mLastAnimation = key;
                }
            }

            //If the priority animation is done, remove it
            if (mAnimations[key]->play(dT,
                    std::abs(modifier / modifierMax)))
            {
                mPriorityAnimation = "";
            }
        }
    }
    else //Play animation if no other priority animation is set
    {
        //If this is a priority animation, set it.
        if (priority)
        {
            mPriorityAnimation = key;
        }

        if (mLastAnimation != key)
        {
            if (mLastAnimation == "")
                mLastAnimation = key;
            else
            {
                mAnimations[mLastAnimation]->reset();
                mLastAnimation = key;
            }
        }

        mAnimations[key]->play(dT, std::abs(modifier / modifierMax));
    }

    return mAnimations[key]->isDone();
}
// Animation =============================================================================
//========================================================================================
const bool &AnimationComponent::Animation::play(const float &dT)
{
    mDone = false;
    mTimer += 100.0F * dT;     // Update Timer

    if (mTimer >= mAnimationTimer)
    {
        mTimer = 0.0F;    // Reset the timer

        // Animate
        if (mCurrentRect != mEndRect)
        {
            mCurrentRect.left += mWidth;
        }
        else // Reset
        {
            mCurrentRect.left = mStartRect.left;
            mDone = true;
        }

        mSprite.setTextureRect(mCurrentRect);
    }

    return mDone;
}
// ---------------------------------------------------------------------------------------
const bool &AnimationComponent::Animation::play(const float &dT, float modPercent)
{
    mDone = false;

    if (modPercent < 0.5F)
    {
        modPercent = 0.5F;
    }

    mTimer += modPercent * 100.0F * dT; // Update Timer

    if (mTimer >= mAnimationTimer)
    {
        // Reset the timer
        mTimer = 0.0F;

        // Animate
        if (mCurrentRect != mEndRect)
        {
            mCurrentRect.left += mWidth;
        }
        else // Reset
        {
            mCurrentRect.left = mStartRect.left;
            mDone = true;
        }

        mSprite.setTextureRect(mCurrentRect);
    }

    return mDone;
}
// ---------------------------------------------------------------------------------------
void AnimationComponent::Animation::reset()
{
    mTimer = mAnimationTimer;
    mCurrentRect = mStartRect;
}
// ---------------------------------------------------------------------------------------
const bool &AnimationComponent::Animation::isDone() const
{
    return mDone;
}
// ---------------------------------------------------------------------------------------


}// namespace gcb
