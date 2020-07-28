//
// Created by fason on 17/07/2020.
//

#ifndef ENGINE_BASE_MOUSEPOSITION_HPP
#define ENGINE_BASE_MOUSEPOSITION_HPP

#include "../pch.hpp"

#include "../input_handlers/InputHandler.hpp"

namespace gcb::debug
{
struct MousePosition
{
    MousePosition(const sf::Font &font) : mFont(font){}

  public:
    void render(sf::RenderTarget &target, const InputHandler& inputHandler)
    {
        mMouseText.setPosition(
          inputHandler.getMousePosView().x,
          inputHandler.getMousePosView().y - 50);

        mMouseText.setFont(mFont);
        mMouseText.setCharacterSize(16);
        std::stringstream ss;
        ss << "x: " << inputHandler.getMousePosView().x
           << "\ny: " << inputHandler.getMousePosView().y;
        mMouseText.setString(ss.str());
        target.draw(mMouseText);
    }
  private:
    sf::Text mMouseText;
    sf::Font mFont;

};

}// namespace gcb::debug

#endif//ENGINE_BASE_MOUSEPOSITION_HPP
