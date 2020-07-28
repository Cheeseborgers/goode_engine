//
// Created by fason on 19/07/2020.
//

#include "Container.hpp"

namespace gcb::gui
{
Container::Container(const gcb::gui::Container &copy)
    : Widget(copy)
{
    /**********************************************************
     * @brief Copy constructor
     **********************************************************/

    // Copy all the widgets
    for (std::size_t i = 0; i < copy.mWidgets.size(); ++i)
        add(copy.mWidgets[i]->clone(), copy.mWidgets[i]->getWidgetName());
}
// ---------------------------------------------------------------------------------------
Container::Container([[maybe_unused]] gcb::gui::Container &&copy) noexcept
{
    /**********************************************************
     * @brief Move constructor
     *********************************************************/
}
// ---------------------------------------------------------------------------------------
Container::~Container()
{
    /**********************************************************
     * @brief Destructor
     *********************************************************/

    /*
    for (const auto& widget : mWidgets)
    {
        //if (widget->getParent() == this)
            //widget->setParent(nullptr);
    }*/
}
//----------------------------------------------------------------------------------------
Container &Container::operator=(const gcb::gui::Container &right)
{
    /**********************************************************
     * @brief Overload of copy assignment operator
     *********************************************************/

    // Make sure it is not the same widget
    if (this != &right)
    {
        Widget::operator=(right);

        //m_widgetBelowMouse = nullptr;
        //m_focusedWidget = nullptr;

        // Remove all the old widgets
        //Container::removeAllWidgets();

        // Copy all the widgets
        for (std::size_t i = 0; i < right.mWidgets.size(); ++i)
        {
            // Don't allow the 'add' function of a derived class to be called, since its members are not copied yet
            //Container::add(right.mWidgets[i]->clone(), right.m_widgets[i]->getWidgetName());
        }
    }

    return *this;
}
// ---------------------------------------------------------------------------------------
Container &Container::operator=(gcb::gui::Container &&right)
{
    /**********************************************************
     * @brief Overload of move assignment operator
     *********************************************************/

    // Make sure it is not the same widget
    if (this != &right)
    {
        Widget::operator=(std::move(right));
        mWidgets              = std::move(right.mWidgets);
        //m_widgetBelowMouse     = std::move(right.m_widgetBelowMouse);
        //m_focusedWidget        = std::move(right.m_focusedWidget);
        //m_handingMouseReleased = std::move(right.m_handingMouseReleased);

        //for (auto& widget : mWidgets)
        //widget->setParent(this);

        right.mWidgets = {};
    }

    return *this;
}
// ---------------------------------------------------------------------------------------
void Container::add(const Widget::WidgetPtr &widgetPtr, const sf::String &widgetName)
{
    /*****************************************************************************
     * @brief Adds a widget to the container
     *
     * @param widgetPtr   Pointer to the widget you would like to add
     * @param widgetName  You can give the widget a unique name to retrieve
     * it from the container later.
     *
     * @warning The widget name should not contain whitespace
     ****************************************************************************/

    assert(widgetPtr != nullptr);

    //if (widgetPtr->getParent())
        //widgetPtr->getParent()->remove(widgetPtr);

    //widgetPtr->setParent(this);
    mWidgets.push_back(widgetPtr);
    widgetPtr->setWidgetName(widgetName);

    /*
    if (m_fontCached != getGlobalFont())
        widgetPtr->setInheritedFont(m_fontCached);

    if (m_opacityCached < 1)
        widgetPtr->setInheritedOpacity(m_opacityCached);

    if (m_textSize != 0)
        widgetPtr->setTextSize(m_textSize);
    */
}
// ---------------------------------------------------------------------------------------


}// namespace gcb::gui

