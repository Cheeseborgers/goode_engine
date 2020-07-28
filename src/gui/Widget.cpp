//
// Created by fason on 19/07/2020.
//


#include "Widget.hpp"

namespace gcb::gui
{
Widget::Widget(){}
// ---------------------------------------------------------------------------------------
Widget::~Widget(){}
// Accessors -----------------------------------------------------------------------------
sf::String Widget::getWidgetName() const
{
    /*****************************************************************************
    * @brief Returns the name of a widget
    *
    * @return Name of the widget or an empty string when wasn't given a name
    ******************************************************************************/

    return mName;
}
// Setters -------------------------------------------------------------------------------
void Widget::setWidgetName(const sf::String &name)
{
    /*****************************************************************************
    * @brief Changes the name of a widget
    *
    * @param name  New name for the widget
     *
    * @warning This name is overwritten when adding the widget to its parent.
    * You should only set it afterwards.
    ******************************************************************************/

    if (mName != name)
    {
        mName = name;
    }

}
// ---------------------------------------------------------------------------------------
Widget::WidgetPtr gcb::gui::Widget::clone() const
{
    /*****************************************************************************
    * @brief Makes a copy of the widget if you don't know its exact type
    *
    * This function should only be used when you don't know the type of the widget.
    * If you know what kind of widget you are copying, you should use the copy
    * function.
    *
    * @return Copy of the widget
    ********************************************************************************/

    return gcb::gui::Widget::WidgetPtr();
}
// ---------------------------------------------------------------------------------------
void Widget::update([[maybe_unused]]
        const sf::Vector2f &mousePos, [[maybe_unused]]  const float &dT){}
// ---------------------------------------------------------------------------------------
void Widget::render( [[maybe_unused]]  sf::RenderTarget &target) const {}
// ---------------------------------------------------------------------------------------


}// namespace gcb::gui



