//
// Created by fason on 14/07/2020.
//

#ifndef ENGINE_BASE_SHADER_HPP
#define ENGINE_BASE_SHADER_HPP


////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Effect.hpp"

namespace gcb
{

////////////////////////////////////////////////////////////
// "Pixelate" fragment shader
////////////////////////////////////////////////////////////
class Pixelate : public Effect
{
  public:

    Pixelate(sf::Vector2u windowSize) : Effect("pixelate", windowSize)
    {
    }

    bool onLoad()
    {
        // Load the texture and initialize the sprite
        if (!m_texture.loadFromFile("../../assets/res/sprites/backgrounds/sky.png"))
            return false;
        m_sprite.setTexture(m_texture);

        // Load the shader
        if (!m_shader.loadFromFile("../../assets/shaders/pixelate.frag", sf::Shader::Fragment))
            return false;
        m_shader.setUniform("texture", sf::Shader::CurrentTexture);

        return true;
    }

    void onUpdate(float, float x, float y)
    {
        m_shader.setUniform("pixel_threshold", (x + y) / 30);
    }

    void onDraw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.shader = &m_shader;
        target.draw(m_sprite, states);
    }

  private:

    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Shader m_shader;
};


////////////////////////////////////////////////////////////
// "Storm" vertex shader + "blink" fragment shader
////////////////////////////////////////////////////////////
class StormBlink : public Effect
{
  public:

    StormBlink(sf::Vector2<unsigned int> windowSize, float radius)
        : Effect("storm + blink", windowSize), mRadius(radius) {}

    bool onLoad()
    {
        // Create the points
        mPoints.setPrimitiveType(sf::Points);

        for (int i = 0; i < 40000; ++i)
        {
            float x = static_cast<float>(std::rand() % m_windowSizeI.x);
            float y = static_cast<float>(std::rand() % m_windowSizeI.y);

            sf::Uint8 r = static_cast<sf::Uint8>(std::rand() % 255);
            sf::Uint8 g = static_cast<sf::Uint8>(std::rand() % 255);
            sf::Uint8 b = static_cast<sf::Uint8>(std::rand() % 255);

            mPoints.append(sf::Vertex(sf::Vector2f(x, y), sf::Color(r, g, b)));
        }

        // Load the shader
        return mShader.loadFromFile("../../assets/shaders/storm.vert",
          "../../assets/shaders/blink.frag");
    }

    void onUpdate(float time, float x, float y)
    {
        float radius = mRadius + std::cos(time) * 150;
        mShader.setUniform(
            "storm_position",
            sf::Vector2f(x * m_windowSizeF.x,y * m_windowSizeF.y));
        mShader.setUniform("storm_inner_radius", radius / 3);
        mShader.setUniform("storm_total_radius", radius);
        mShader.setUniform("blink_alpha", 0.5f + std::cos(time * 3) * 0.25f);
    }

    void onDraw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.shader = &mShader;
        target.draw(mPoints, states);
    }

  private:
    sf::VertexArray mPoints;
    sf::Shader mShader;
    float mRadius;

};


}// namespace gcb



#endif//ENGINE_BASE_SHADER_HPP
