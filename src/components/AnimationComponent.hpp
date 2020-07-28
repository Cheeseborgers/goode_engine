//
// Created by fason on 12/07/2020.
//

#ifndef ENGINE_BASE_ANIMATIONCOMPONENT_HPP
#define ENGINE_BASE_ANIMATIONCOMPONENT_HPP

#include "../pch.hpp"

namespace gcb
{
class AnimationComponent
{
  private:
    class Animation
    {
      public:
        sf::Sprite& mSprite;
        sf::Texture& mTextureSheet;

        float mAnimationTimer;
        float mTimer;
        bool mDone;

        int mWidth;
        int mHeight;

        sf::IntRect mStartRect;
        sf::IntRect mCurrentRect;
        sf::IntRect mEndRect;

        Animation(sf::Sprite &sprite, sf::Texture &textureSheet,
                  const float &animationTimer,
                  const int &startFrameX, const int &startFrameY,
                  const int &framesX, const int &framesY,
                  const int &width, const int &height)
            : mSprite(sprite), mTextureSheet(textureSheet),
              mAnimationTimer(animationTimer), mTimer(0.0F), mDone(false),
              mWidth(width), mHeight(height)
        {
            mStartRect = sf::IntRect(
                startFrameX * width,
              startFrameY * height,
              width, height);

            mCurrentRect = mStartRect;
            mEndRect = sf::IntRect(
                framesX * width,
                framesY * height,
                width, height);

            mSprite.setTexture(mTextureSheet, true);
            mSprite.setTextureRect(mStartRect);
        }

        // Accessors
        const bool &isDone() const;

        // Methods
        const bool &play(const float &dT);
        const bool &play(const float &dt, float modPercent);
        void reset();
    };

    sf::Sprite& mSprite;
    sf::Texture& mTextureSheet;
    std::unordered_map<std::string, std::unique_ptr<Animation>> mAnimations;
    std::string mLastAnimation;
    std::string mPriorityAnimation;

    public:
        // Constructor
        AnimationComponent(sf::Sprite &sprite, sf::Texture &textureSheet);
        virtual ~AnimationComponent();

        // Modifiers
        void addAnimation(const std::string &key, float animationTimer,
              int startFrameX, int startFrameY,
              int framesX, int framesY,
              int width, int height);

        // Accessors
        const bool &isDone(const std::string &key);

        // Methods
        const bool &play(
            const std::string &key,
            const float &dT,
            const bool priority = false);

        const bool &play(const std::string &key, const float &dT,
             float modifier, float modifierMax, const bool priority = false);
};

}// namespace gcb


#endif//ENGINE_BASE_ANIMATIONCOMPONENT_HPP
