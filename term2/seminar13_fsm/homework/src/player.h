#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player_states.h"

class PlayerState;

class Player
{
public:

    Player(sf::Vector2f position);

    sf::Vector2f getCenter() const;

    void update(float dt);
    void draw(sf::RenderWindow& window);
    void jump();
    void handleEvents(const sf::Event& event);
    bool handleCollision(const sf::FloatRect& rect);
    void handleAllCollisions(const std::vector<sf::FloatRect>& blocks);

    ~Player();

    friend class PlayerState;
    friend class Idle;
    friend class Running;
    friend class Falling;
    friend class Sliding;
    friend class Hooked;


private:

    PlayerState*    mp_state;
    sf::Texture     m_texture;
    sf::Sprite      m_sprite;
    bool            m_isFacedRight;
    sf::Vector2f    m_velocity;
    float           m_scaleFactor;

    static constexpr float kJumpingVelocity = 1400;
    void setState(PlayerState* newState);
};