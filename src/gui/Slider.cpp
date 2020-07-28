//
// Created by fason on 16/07/2020.
//

#include "Slider.hpp"

namespace gcb::gui
{
// Initializers --------------------------------------------------------------------------
void Slider::initSlider(float sliderRadius, [[maybe_unused]]  float sliderStartX,
  const sf::Color sliderColor)
{
    mSlider.setRadius(sliderRadius);
    //mSlider.setPosition(sliderStartX, mBar.getPosition().y);
    mSlider.setFillColor(sliderColor);

    // DEBUG REMOVE =============================================== and used
    mSlider.setPosition(mBar.getPosition().x,
      mBar.getPosition().y - mSlider.getRadius());


    mTest.setRadius(50.0F);
    mTest.setFillColor(sf::Color::Red);
    mTest.setPosition(0.0F, 0.0F);

}
// ---------------------------------------------------------------------------------------
void Slider::initBar(const sf::Color &barColor)
{
    mBar.setFillColor(barColor);
    mBar.setSize(sf::Vector2f(mContainer.getSize().x, 1.0F));
    mBar.setPosition(mContainer.getPosition().x,
      mContainer.getPosition().y + mContainer.getGlobalBounds().height / 2);
}
// Constructors --------------------------------------------------------------------------
Slider::Slider(sf::Vector2u position, sf::Vector2f size, float sliderStartX,
  float sliderRadius, const sf::Color &barColor, const sf::Color &sliderColor)
{
    mContainer.setPosition(
      static_cast<float>(position.x),
      static_cast<float>(position.y));
    mContainer.setSize(size);
    mContainer.setFillColor(sf::Color::Transparent);

    initBar(barColor);

    initSlider(sliderRadius, sliderStartX, sliderColor);

}
// ---------------------------------------------------------------------------------------
Slider::Slider(float positionX, float positionY, float width, float height,
  float sliderStartX, float sliderRadius,
  const sf::Color &barColor, const sf::Color &sliderColor)
{
    mContainer.setPosition(positionX, positionY);
    mContainer.setSize(sf::Vector2f(width, height));
    mContainer.setFillColor(sf::Color::Transparent);

    initBar(barColor);

    initSlider(sliderRadius, sliderStartX, sliderColor);
}
// ---------------------------------------------------------------------------------------
Slider::Slider(sf::Vector2u position, sf::Vector2f size, float sliderStartX,
  float sliderRadius, const sf::Color &barColor, const sf::Color &sliderColor,
  const sf::Color &containerColor)
{
    mContainer.setPosition(
      static_cast<float>(position.x),
      static_cast<float>(position.y));
    mContainer.setSize(size);
    mContainer.setFillColor(containerColor);

    initBar(barColor);

    initSlider(sliderRadius, sliderStartX, sliderColor);
}
// ---------------------------------------------------------------------------------------
Slider::Slider(sf::Vector2u position, float width, float height, float sliderStartX,
  float sliderRadius, const sf::Color &barColor, const sf::Color &sliderColor)
{
    mContainer.setPosition(
      static_cast<float>(position.x),
      static_cast<float>(position.y));
    mContainer.setSize(sf::Vector2f(width, height));
    mContainer.setFillColor(sf::Color::Transparent);

    initBar(barColor);

    initSlider(sliderRadius, sliderStartX, sliderColor);
}
// ---------------------------------------------------------------------------------------
Slider::Slider(sf::Vector2u position, float width, float height, float sliderStartX,
  float sliderRadius, const sf::Color &barColor,
  const sf::Color &sliderColor, const sf::Color &containerColor)
{
    mContainer.setPosition(
      static_cast<float>(position.x),
      static_cast<float>(position.y));
    mContainer.setSize(sf::Vector2f(width, height));
    mContainer.setFillColor(containerColor);

    initBar(barColor);

    initSlider(sliderRadius, sliderStartX, sliderColor);
}
// ---------------------------------------------------------------------------------------
void Slider::update(const sf::Vector2f &mousePos, [[maybe_unused]] const float &dT)
{
    if (intersects(mTest, mousePos))
    {
        std::cout << "intersects! : " << counter << "\n";
        ++counter;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            std::cout << "clicked!\n";
            mSlider.move(mousePos.x, 0);

            /*
            if (mSlider.getPosition().x > mBar.getPosition().x || mSlider.getPosition().y > mBar.getPosition().y)
            {
                std::cout << "left?\n";
                mSlider.setPosition(mBar.getPosition().x, mBar.getPosition().y);
            }
            else if (mSlider.getPosition().x < mBar.getPosition().x || mSlider.getPosition().y < mBar.getPosition().y)
            {
                std::cout << "right?\n";
                mSlider.setPosition(mBar.getPosition().x + mBar.getGlobalBounds().width, 0);
            }*/
        }
    }
}
// ---------------------------------------------------------------------------------------
void Slider::render(sf::RenderTarget &target)
{
    target.draw(mContainer);
    target.draw(mBar);
    target.draw(mSlider);

    target.draw(mTest);
}
// ---------------------------------------------------------------------------------------
bool Slider::intersects(const sf::CircleShape &circle, const sf::Vector2f &mousePos) const
{

    // get distance between the mouse cursor and circle's center
    // using the Pythagorean Theorem
    const float distX = mousePos.x - circle.getPosition().x;
    const float distY = mousePos.y - circle.getPosition().y;
    const float distance =  std::sqrt( (distX*distX) + (distY*distY) );


    //std::cout << distance << "\n";

    return distance <= circle.getRadius();
}
// ---------------------------------------------------------------------------------------


}// namespace gcb::gui
