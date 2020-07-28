//
// Created by fason on 14/07/2020.
//

#ifndef ENGINE_BASE_EFFECT_H
#define ENGINE_BASE_EFFECT_H

#include "../pch.hpp"

#include <cassert>
#include <string>

namespace gcb
{
class Effect : public sf::Drawable
{
    public:
        virtual ~Effect(){}

        const std::string& getName() const {return m_name; }
        void load(){ m_isLoaded = sf::Shader::isAvailable() && onLoad();}

        void update(float time, float x, float y)
        {
            if (m_isLoaded)
            {
                onUpdate(time, x, y);
            }
        }

        void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            if (m_isLoaded)
            {
                onDraw(target, states);
            }
            else
            {
                //sf::Text error("Shader not\nsupported");
                //error.setPosition(320.f, 200.f);
                //error.setCharacterSize(36);
                //target.draw(error, states);
            }
        }

    protected:
        Effect(const std::string& name, const sf::Vector2u& windowSize) :
            m_windowSizeI(windowSize), m_name(name), m_isLoaded(false)
        {
            m_windowSizeF = {
                static_cast<float>(m_windowSizeI.x),
                static_cast<float>(m_windowSizeI.y)};
        }

        // Variables
        sf::Vector2i m_windowSizeI;
        sf::Vector2f m_windowSizeF;

    private:
        std::string m_name;
        bool m_isLoaded;

        // Virtual functions to be implemented in derived effects
        virtual bool onLoad() = 0;
        virtual void onUpdate(float time, float x, float y) = 0;
        virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};


}// namespace gcb


#endif//ENGINE_BASE_EFFECT_H
