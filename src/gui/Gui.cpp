//
// Created by fason on 17/07/2020.
//

#include "Gui.hpp"

namespace gcb::gui
{
// Initializers --------------------------------------------------------------------------
void Gui::init()
{

}
// ---------------------------------------------------------------------------------------
Gui::Gui()
{
    /*****************************************************************************
     * @brief Default constructor
     * If you use this constructor then you will still have to call the
     * setTarget yourself.
     ****************************************************************************/

    init();
}
// ---------------------------------------------------------------------------------------
Gui::Gui(sf::RenderTarget &target)
: mTarget(&target)
{
    /**********************************************************************************
    * @brief Constructs the gui and set the window on which the gui should be drawn
    *
    * @param window  The sfml window that will be used by the gui
    *
    * If you use this constructor then you will no longer have to call setTarget
    * yourself.
    **********************************************************************************/

    init();
}
// Setters -------------------------------------------------------------------------------
void Gui::setTarget(sf::RenderTarget &target)
{
    /**********************************************************************************
    * @brief Sets the target on which the gui should be drawn.
    *
    * @param target  The render target (typically sf::RenderWindow) that will be
    * used by the gui.
    **********************************************************************************/

    mTarget = &target;

    setView(target.getDefaultView());
}
// ---------------------------------------------------------------------------------------
void Gui::setView([[maybe_unused]]const sf::View &view)
{
    /**********************************************************************************
    * @brief Changes the view that is used by the gui
    *
    * @param view  The new view
    **********************************************************************************/

    /*if ((mView.getCenter() != view.getCenter()) || (mView.getSize() != view.getSize())) {
        mView = view;


    }
    else
    {   // Set it anyway in case something changed that we didn't care to check
        mView = view;
    }*/
}
// Getters--------------------------------------------------------------------------------
const sf::View &Gui::getView() const
{
    return mView;
}
// ---------------------------------------------------------------------------------------
sf::RenderTarget* Gui::getTarget() const
{
    return mTarget;
}
// ---------------------------------------------------------------------------------------
void Gui::update()
{
}
// ---------------------------------------------------------------------------------------
void Gui::render()
{
}
// ---------------------------------------------------------------------------------------


}// namespace gcb::gui
