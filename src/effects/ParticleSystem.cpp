//
// Created by fason on 15/07/2020.
//

#include "ParticleSystem.hpp"

namespace gcb
{
// ---------------------------------------------------------------------------------------
ParticleSystem::ParticleSystem(sf::Vector2u canvasSize)
    : mDissolve(false), mParticleSpeed(100.0), mDissolutionRate(4)
      ,mShape(Shape::Circle), mGravity(0.0,0.0)
{
    mCanvasSize = sf::Vector2f(
      static_cast<float>(canvasSize.x),
      static_cast<float>(canvasSize.y)
      );

    mStartPos = sf::Vector2<double>(
      static_cast<double>(mCanvasSize.x / 2),
      static_cast<double>(mCanvasSize.y / 2));
}
// ---------------------------------------------------------------------------------------
ParticleSystem::~ParticleSystem(void)
{
    /* Clear vector */
    mParticles.clear();
}
// ---------------------------------------------------------------------------------------
void ParticleSystem::draw(
  sf::RenderTarget& target, sf::RenderStates states) const
{
    for(const auto& it : mParticles)
    {
        target.draw(&it.get()->drawVertex, 1, sf::Points, states);
    }

    return;
}
// ---------------------------------------------------------------------------------------
void ParticleSystem::fuel(std::size_t particles)
{
    mParticles.reserve(mParticles.size() + particles);

    std::random_device rd;
    std::mt19937 gen(rd());

    for(std::size_t i = 0; i < particles; ++i)
    {
        // Generate a new particle and put it at the generation point.
        std::unique_ptr particle = std::make_unique<Particle>();
        particle->drawVertex.position.x = static_cast<float>(mStartPos.x);
        particle->drawVertex.position.y = static_cast<float>(mStartPos.y);

        switch(mShape)
        {
        case Shape::Circle:
        {
            // Generate a random angle.
            UniRealDist randomAngle(0.0, 2.0 * Definitions::PI);
            double angle = randomAngle(gen);

            // Use the random angle as a thrust vector for the particle.
            UniRealDist randomAngleCos(0.0, cos(angle));
            UniRealDist randomAngleSin(0.0, sin(angle));
            particle->velocity.x = randomAngleCos(gen);
            particle->velocity.y = randomAngleSin(gen);

            break;
        }
        case Shape::Square:
        {
            // Square generation
            UniRealDist randomSide(-1.0, 1.0);
            particle->velocity.x = randomSide(gen);
            particle->velocity.y = randomSide(gen);

            break;
        }
        default:
        {
            particle->velocity.x = 0.5; // Easily detected
            particle->velocity.y = 0.5; // Easily detected
        }
        }

        // We don't want lame particles. Reject, start over.
        if(particle->velocity.x == 0.0 && particle->velocity.y == 0.0 )
        {
            particle.reset();
        }

        // Randomly change the colors of the particles
        UniIntDist randomColor(0, 255);
        particle->drawVertex.color.r = static_cast<unsigned char>(randomColor(gen));
        particle->drawVertex.color.g = static_cast<unsigned char>(randomColor(gen));
        particle->drawVertex.color.b = static_cast<unsigned char>(randomColor(gen));
        particle->drawVertex.color.a = 255;

        mParticles.emplace_back(std::move(particle));
    }

    return;
}
// ---------------------------------------------------------------------------------------
const std::string ParticleSystem::getNumberOfParticlesString(void) const
{
    std::ostringstream oss;
    oss << mParticles.size();
    return oss.str();
}
// ---------------------------------------------------------------------------------------
void ParticleSystem::update(const float& dT)
{
    const double deltaTime = static_cast<double>(dT);

    /* Run through each particle and apply our system to it */
    for(auto it = mParticles.begin(); it != mParticles.end(); it++)
    {
        /* Apply Gravity */
        (*it)->velocity.x += mGravity.x * deltaTime;
        (*it)->velocity.y += mGravity.y * deltaTime;

        /* Apply thrust */
        (*it)->drawVertex.position.x
          += static_cast<float>((*it)->velocity.x * deltaTime * mParticleSpeed);
        (*it)->drawVertex.position.y
          += static_cast<float>((*it)->velocity.y * deltaTime * mParticleSpeed);

        /* If they are set to dissolve, dissolve */
        if(mDissolve)
        {
            (*it)->drawVertex.color.a
              = static_cast<unsigned char>((*it)->drawVertex.color.a
                   - tolower(mDissolutionRate));
        }

        // Remove any particles off the view/screen and any with an rgba,
        // Alpha of Zero.
        if((*it)->drawVertex.position.x > mCanvasSize.x
            || (*it)->drawVertex.position.x < 0
            || (*it)->drawVertex.position.y > mCanvasSize.y
            || (*it)->drawVertex.position.y < 0
            || (*it)->drawVertex.color.a <= 0)
        {
            it = mParticles.erase(it);
            if(it == mParticles.end()) return;
        }
    }

    return;
}
// ---------------------------------------------------------------------------------------


}// namespace gcb
