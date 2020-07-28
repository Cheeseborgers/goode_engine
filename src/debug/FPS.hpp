//
// Created by fason on 19/07/2020.
//

#ifndef ENGINE_BASE_FPS_HPP
#define ENGINE_BASE_FPS_HPP

#include "../pch.hpp"

namespace gcb::debug
{
struct FPS
{
public:
    FPS(const sf::Vector2f& position, const sf::Font &font,
        const sf::Color& labelColor, unsigned charSize)
    {
        init(position, font, labelColor, charSize,
          false, 50, 60);
    }

    FPS(const sf::Vector2f& position, const sf::Font &font,
        const sf::Color& labelColor, unsigned charSize, bool displayMean)
    {
        init(position, font, labelColor, charSize, displayMean, 50, 60);
    }

    FPS(const sf::Vector2f& position, const sf::Font &font,
        const sf::Color& labelColor, unsigned charSize, bool displayMean,
        unsigned int minFps, unsigned int idealFps)
    {
        init(position, font, labelColor, charSize, displayMean, minFps, idealFps);
    }

    FPS(const sf::Vector2f& position, const sf::Font &font,
        const sf::Color& labelColor, unsigned charSize, bool displayMean,
        unsigned int minFps, unsigned int idealFps, const sf::Color& minColor,
        const sf::Color& warnColor, const sf::Color& idealColor)
    :  mMinColor(minColor), mWarnColor(warnColor), mIdealColor(idealColor)
    {
        init(position, font, labelColor, charSize, displayMean, minFps, idealFps);
    }

    FPS(float posX, float posY, const sf::Font &font,
        const sf::Color& labelColor, unsigned charSize)
    {
        init(sf::Vector2f(posX, posY),
          font, labelColor, charSize, false, 50, 60);
    }

    FPS(float posX, float posY, const sf::Font &font,
        const sf::Color& labelColor, unsigned charSize, bool displayMean)
    {
        init(sf::Vector2f(posX, posY),
             font, labelColor, charSize, displayMean, 50, 60);
    }

    FPS(float posX, float posY, const sf::Font &font,
        const sf::Color& labelColor, unsigned charSize, bool displayMean,
        unsigned int minFps, unsigned int idealFps)
    {
        init(sf::Vector2f(posX, posY),
             font, labelColor, charSize, displayMean, minFps, idealFps);
    }

    FPS(float posX, float posY, const sf::Font &font,
        const sf::Color& labelColor, unsigned charSize, bool displayMean,
        unsigned int minFps, unsigned int idealFps, const sf::Color& minColor,
        const sf::Color& warnColor, const sf::Color& idealColor)
      :  mMinColor(minColor), mWarnColor(warnColor), mIdealColor(idealColor)
    {
        init(sf::Vector2f(posX, posY),
             font, labelColor, charSize, displayMean, minFps, idealFps);
    }

    void update()
    {
        if (mClock.getElapsedTime().asSeconds() >= 1.0F)
        {
            if (mFrame <= mMinFps)
            {
                mFps.setFillColor(mMinColor);
            }
            else if (mFrame <= mMinFps * (1 + 0.1))
            {
                mFps.setFillColor(mWarnColor);
            }
            else if (mFrame >= mIdealFps)
            {
                mFps.setFillColor(mIdealColor);
            }
            else
            {
                mFps.setFillColor(mLabelColor);
            }

            mFps.setString(std::to_string(mFrame));

            if (mDisplayMean)
            {
                if (mLastFrames.size() > 60)
                {
                    mLastFrames.erase(mLastFrames.begin());
                }

                mLastFrames.push_back(mFrame);

                std::size_t mean{std::accumulate(
                  mLastFrames.begin(),
                  mLastFrames.end(),
                  decltype(mLastFrames)::value_type(0)) / mLastFrames.size()};

                if (mean <= mMinFps)
                {
                    mMeanFps.setFillColor(mMinColor);
                }
                else if (static_cast<double>(mean) <= mMinFps * (1 + 0.1))
                {
                    mMeanFps.setFillColor(mWarnColor);
                }
                else if (mean >= mIdealFps)
                {
                    mMeanFps.setFillColor(mIdealColor);
                }
                else
                {
                    mMeanFps.setFillColor(mLabelColor);
                }

                mMeanFps.setString(std::to_string(mean));
            }

            mFrame = 0;
            mClock.restart();
        }

        ++mFrame;

    }

    //Setters
    void setDisplayMean(bool displayMean)
    {
        mDisplayMean = displayMean;
    }

    void setTextColors(const sf::Color& labelColor, const sf::Color& minColor,
      const sf::Color& warnColor, const sf::Color& idealColor)
    {
        mLabelColor = labelColor;
        mMinColor = minColor;
        mWarnColor = warnColor;
        mIdealColor = idealColor;
    }

    // Methods
    void render(sf::RenderTarget& target)
    {
        target.draw(mFpsLabelText);
        target.draw(mFps);

        if (mDisplayMean)
        {
            target.draw(mMeanFpsLabelText);
            target.draw(mMeanFps);
        }
    }

private:
    unsigned int mFrame{0};
    unsigned int mMinFps{0};
    unsigned int mIdealFps{0};

    std::vector<unsigned int> mLastFrames;

    sf::Clock mClock;
    sf::Text mFpsLabelText;
    sf::Text mFps; // frames per second
    sf::Text mMeanFpsLabelText;
    sf::Text mMeanFps; // Average fps per minute

    sf::Color mLabelColor{sf::Color::White};
    sf::Color mMinColor{sf::Color::Red};
    sf::Color mWarnColor{sf::Color::Orange};
    sf::Color mIdealColor{sf::Color::Green};

    bool mDisplayMean;

    //Initializer: called by all constructors
    void init(const sf::Vector2f& position, const sf::Font &font,
        const sf::Color& color, unsigned charSize, bool displayMean,
        unsigned int minFps, unsigned int idealFps)
    {
        mDisplayMean = displayMean;
        mMinFps      = minFps;
        mIdealFps    = idealFps;

        mLabelColor = color;

        if (mDisplayMean)
        {
            mLastFrames.reserve(60);
        }

        mFpsLabelText.setPosition(position);
        mFpsLabelText.setFont(font);
        mFpsLabelText.setFillColor(mLabelColor);
        mFpsLabelText.setCharacterSize(charSize);
        mFpsLabelText.setString("FPS: ");

        mFps.setPosition(
          position.x + mFpsLabelText.getGlobalBounds().width + 2.F,
          position.y);
        mFps.setFont(font);
        mFps.setFillColor(mLabelColor);
        mFps.setCharacterSize(charSize);
        mFps.setString("0");

        mMeanFpsLabelText.setPosition(
          mFps.getPosition().x + mFps.getGlobalBounds().width * 3,
          position.y);
        mMeanFpsLabelText.setFont(font);
        mMeanFpsLabelText.setFillColor(mLabelColor);
        mMeanFpsLabelText.setCharacterSize(charSize);
        mMeanFpsLabelText.setString("\\AVG: ");

        mMeanFps.setPosition(
          mMeanFpsLabelText.getPosition().x
            + mMeanFpsLabelText.getGlobalBounds().width,
          position.y);
        mMeanFps.setFont(font);
        mMeanFps.setFillColor(mLabelColor);
        mMeanFps.setCharacterSize(charSize);
        mMeanFps.setString("0");
    }

};

}// namespace gcb::debug


#endif//ENGINE_BASE_FPS_HPP
