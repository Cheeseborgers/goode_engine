//
// Created by fason on 19/07/2020.
//

#ifndef ENGINE_BASE_CONTAINER_HPP
#define ENGINE_BASE_CONTAINER_HPP

#include <memory>
#include <vector>
#include <assert.h>

#include "Widget.hpp"

namespace gcb::gui
{
class Container : public Widget
{
public:
    using WidgetPtr =  std::shared_ptr<Container>; // Shared widget pointer
    using ConstWidgetPtr  = std::shared_ptr<const Container>; // Shared constant widget pointer

    Container() = delete; // Default constructor
    Container(const Container& copy); // Copy constructor
    Container(Container&& copy) noexcept ; // Move constructor
    ~Container(); // Destructor
    Container& operator= (const Container& right); // Overload of copy assignment operator
    Container& operator= (Container&& right); // @brief Overload of move assignment operator

    virtual void add(const Widget::WidgetPtr& widgetPtr, const sf::String& widgetName = "");

protected:
    friend class Gui; // Required to let Gui access protected members from container and Widget

    std::vector<Widget::WidgetPtr> mWidgets;

};


}// namespace gcb::gui



#endif//ENGINE_BASE_CONTAINER_HPP
