//
// Created by fason on 16/07/2020.
//

#ifndef ENGINE_BASE_SLIDER_HPP
#define ENGINE_BASE_SLIDER_HPP

#include "../pch.hpp"


namespace gcb::gui
{
class Slider
{
  private:
    sf::RectangleShape mContainer;
    sf::RectangleShape mBar;
    sf::CircleShape mSlider;

    sf::CircleShape mTest;

    // Initializers
    void initBar(const sf::Color &barColor);
    void initSlider(float sliderRadius, float sliderStartX, const sf::Color sliderColor);

  public:
    Slider(sf::Vector2u position, sf::Vector2f size, float sliderStartX,
           float sliderRadius, const sf::Color &barColor, const sf::Color &sliderColor);
    Slider(float positionX, float positionY, float width, float height,
           float sliderStartX, float sliderRadius,
           const sf::Color &barColor, const sf::Color &sliderColor);
    Slider(sf::Vector2u position, sf::Vector2f size, float sliderStartX,
           float sliderRadius, const sf::Color &barColor, const sf::Color &sliderColor,
           const sf::Color &containerColor);
    Slider(sf::Vector2u position, float width, float height, float sliderStartX,
           float sliderRadius, const sf::Color &barColor, const sf::Color &sliderColor);
    Slider(sf::Vector2u position, float width, float height, float sliderStartX,
           float sliderRadius, const sf::Color &barColor,
           const sf::Color &sliderColor, const sf::Color &containerColor);

    // Methods
    bool intersects(const sf::CircleShape &circle, const sf::Vector2f &mousePos) const;
    void update(const sf::Vector2f &mousePos, const float &dT);
    void render(sf::RenderTarget &target);

    // Debug =================================================================
    int counter{0};
};


}// namespace gcb::gui



#endif//ENGINE_BASE_SLIDER_HPP
