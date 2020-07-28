//
// Created by fason on 15/07/2020.
//

#ifndef ENGINE_BASE_PARTICLESYSTEM_HPP
#define ENGINE_BASE_PARTICLESYSTEM_HPP

#include <numeric>

#include "../pch.hpp"

#include "../utilities/Random.hpp"

namespace gcb
{

namespace Shape { enum { Circle, Square }; } // Particle distribution types

struct Particle : public sf::Drawable
{
    /* ******************************************************
     * @brief Particle Structure
     *
     * ******************************************************/

    // Data members
    sf::Vertex drawVertex; // To replace mStartPos
    //sf::Vector2f velocity;
    sf::Vector2<double> velocity;

    // Member Functions
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    { target.draw(&drawVertex, 1, sf::Points, states); }
};

// Type definitions
using ParticlePtr = std::unique_ptr<Particle>;

class ParticleSystem : public sf::Drawable
{
public:
    // Constructors/Destructor
    ParticleSystem(sf::Vector2u canvasSize);
    ~ParticleSystem(void);

    // Getters
    int getDissolutionRate(void) const { return mDissolutionRate; }
    unsigned long getNumberOfParticles(void) const { return mParticles.size(); }
    double getParticleSpeed(void) const { return mParticleSpeed; }
    const std::string getNumberOfParticlesString(void) const;

    //Setters
    void setCanvasSize(sf::Vector2f newSize) { mCanvasSize = newSize; }
    void setDissolutionRate(sf::Uint8 rate) { mDissolutionRate = rate; }
    void setDissolve(void) { mDissolve = !mDissolve; }
    void setDistribution(void) { mShape = static_cast<sf::Uint8>((mShape + 1) % 2); }
    void setGravity(double x, double y) {mGravity.x = x; mGravity.y = y; }
    void setGravity(sf::Vector2<double> gravity) { mGravity = gravity; }
    void setParticleSpeed(double speed) { mParticleSpeed = speed; }
    void setPosition(float x, float y) { mStartPos.x = static_cast<double>(x); mStartPos.y = static_cast<double>(y); }
    void setPosition(sf::Vector2f position) { mStartPos = { static_cast<double>(position.x), static_cast<double>(position.y)}; }
    void setPosition(double x, double y) { mStartPos.x = x; mStartPos.y = y; }
    void setPosition(sf::Vector2<double> position) { mStartPos = position; }
    void setShape(sf::Uint8 shape) { mShape = shape; }

    // Member Functions
    void fuel(std::size_t particles);           // Adds new particles.
    void update(const float& dT);       // Updates particles.

    // Virtual Member Functions
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    // Data members
    bool mDissolve;                     // Dissolution enabled?
    double mParticleSpeed;               // Pixels per second (at most).

    int mDissolutionRate;               // Rate at particles dissolve.
    sf::Uint8 mShape;                   // Shape of distribution.

    sf::Vector2<double> mGravity;              // Influences particle velocities.
    sf::Vector2<double> mStartPos;             // Particle origin.
    sf::Vector2f mCanvasSize;           // TODO : SET TO VIEW SIZE.

    std::vector<ParticlePtr> mParticles; // Particle Container

};


}// namespace gcb




#endif//ENGINE_BASE_PARTICLESYSTEM_HPP
