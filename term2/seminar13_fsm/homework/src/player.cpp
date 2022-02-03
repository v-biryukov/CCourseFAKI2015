#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "player.h"
#include "player_states.h"

void Player::setState(PlayerState* newState)
{
    delete mp_state;
    mp_state = newState;
}

Player::Player(sf::Vector2f position)
{
    if (!m_texture.loadFromFile("./hero.png"))
    {
        std::cout << "Can't load image ./hero.png for Player class" << std::endl;
        exit(1);
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(position);

    m_scaleFactor = 5;
    m_sprite.setScale(m_scaleFactor, m_scaleFactor);
    mp_state = new Idle(this);
}

sf::Vector2f Player::getCenter() const
{
    return {m_sprite.getPosition().x + mp_state->getSize().x * m_scaleFactor / 2,
            m_sprite.getPosition().y + mp_state->getSize().y * m_scaleFactor / 2};
}

void Player::update(float dt)
{
    m_velocity.y += 60;
    mp_state->update(this, dt);
    m_sprite.setPosition(m_sprite.getPosition() + m_velocity * dt);
}

void Player::draw(sf::RenderWindow& window)
{
    mp_state->setSprite(m_sprite, m_isFacedRight);
    window.draw(m_sprite);
}

void Player::jump()
{
    m_sprite.move({0, -10});
    m_velocity.y = -kJumpingVelocity;
    mp_state = new Falling(this);
}

void Player::handleEvents(const sf::Event& event) 
{
    mp_state->handleEvents(this, event);
}

bool Player::handleCollision(const sf::FloatRect& rect)
{
    sf::FloatRect playerRect = {m_sprite.getPosition().x, m_sprite.getPosition().y, 
                                 mp_state->getSize().x * m_scaleFactor, mp_state->getSize().y * m_scaleFactor};
    float overlapx1 = playerRect.left + playerRect.width - rect.left;
    float overlapx2 = rect.left + rect.width - playerRect.left;
    float overlapy1 = playerRect.top + playerRect.height - rect.top;
    float overlapy2 = rect.top + rect.height - playerRect.top;

    if (overlapx1 > 0 && overlapx2 > 0 && overlapy1 > 0 && overlapy2 > 0)
    {
        int minOverlapDirection = 0;
        float minOvelap = overlapx1;
        if (overlapx2 < minOvelap) {minOverlapDirection = 1; minOvelap = overlapx2;}
        if (overlapy1 < minOvelap) {minOverlapDirection = 2; minOvelap = overlapy1;}
        if (overlapy2 < minOvelap) {minOverlapDirection = 3; minOvelap = overlapy2;}

        switch (minOverlapDirection)
        {
            case 0:
                m_sprite.move({-overlapx1, 0});
                m_velocity.x = 0;
                if (m_velocity.y > 0 && playerRect.top < rect.top + Hooked::kMaxHookOffset 
                                   && playerRect.top > rect.top - Hooked::kMaxHookOffset)
                {
                    mp_state->hook(this, {rect.left - playerRect.width, rect.top - Hooked::kHookDisplacement});
                }
                break;
            case 1:
                m_sprite.move({overlapx2, 0});
                m_velocity.x = 0;
                if (m_velocity.y > 0 && playerRect.top < rect.top + Hooked::kMaxHookOffset 
                                   && playerRect.top > rect.top - Hooked::kMaxHookOffset)
                {
                    mp_state->hook(this, {rect.left + rect.width, rect.top - Hooked::kHookDisplacement});
                }
                break;
            case 2:
                m_sprite.move({0, -overlapy1});
                m_velocity.y = 0;
                mp_state->hitGround(this);
                break;
            case 3:
                m_sprite.move({0, overlapy2});
                if (m_velocity.y < 0)
                    m_velocity.y = 0;
                break;
        }
        return true;
    }
    else
    {
        return false;
    }
}

void Player::handleAllCollisions(const std::vector<sf::FloatRect>& blocks)
{
    bool isColiding = false;

    for (const sf::FloatRect& block : blocks)
    {
        if (handleCollision(block))
            isColiding = true;
    }

    if (!isColiding)
        mp_state->startFalling(this);
}


Player::~Player()
{
    delete mp_state;
}