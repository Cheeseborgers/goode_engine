//
// Created by fason on 19/07/2020.
//

#ifndef ENGINE_BASE_WIDGET_HPP
#define ENGINE_BASE_WIDGET_HPP

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/String.hpp>

#include <memory>

namespace gcb::gui
{

class Widget
{
  private:
    sf::String mName;

  protected:
  public:
    using WidgetPtr = std::shared_ptr<Widget>; // Shared widget pointer
    using WidgetConstPtr = std::shared_ptr<const Widget>; // Shared constant widget pointer

    Widget();
    virtual ~Widget();

    // Getters
    sf::String getWidgetName() const;

    // Setters
    void setWidgetName(const sf::String& name);

    // Virtual methods
    virtual Widget::WidgetPtr clone() const;
    virtual void update(const sf::Vector2f &mousePos, const float &dT);
    virtual void render(sf::RenderTarget& target) const;
};

}// namespace gcb


#endif//ENGINE_BASE_WIDGET_HPP
