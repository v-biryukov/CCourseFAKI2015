#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "animation.h"
#include "player.h"
#include "player_states.h"

using namespace std;

PlayerState::PlayerState() 
{
}

void PlayerState::handleEvents(Player* player, const sf::Event& event)
{
}

void PlayerState::update(Player* player, float dt)
{
    m_animation.update(dt);
}

sf::Vector2i PlayerState::getSize()
{
    return m_animation.getSize();
}

void PlayerState::setSprite(sf::Sprite& sprite, bool isFacedRight)
{
    m_animation.setSprite(sprite, isFacedRight);
}

PlayerState::~PlayerState() 
{
}




Idle::Idle(Player* player) : 
    PlayerState{}
{
    player->m_velocity = {0, 0};
    m_animation = Animation({4, 0, 19, 34}, 12, 12);
    cout << "Creating Idle state" << endl;
}

void Idle::attacked(Player* player)
{
}

void Idle::hook(Player* player, sf::Vector2f position) 
{  
}

void Idle::update(Player* player, float dt)
{
    m_animation.update(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player->setState(new Running(player));
    }
}

void Idle::handleEvents(Player* player, const sf::Event& event) 
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right) 
            player->setState(new Running(player));

        else if (event.key.code == sf::Keyboard::Space)
            player->jump();
    }
}

void Idle::startFalling(Player* player)
{
    player->setState(new Falling(player));
}

void Idle::hitGround(Player* player)
{
}









Running::Running(Player* player) : PlayerState()
{
    m_runningSpeed = 700;
    m_animation = Animation({0, 64, 21, 34}, 8, 12);
    cout << "Creating Running state" << endl;
}

void Running::hook(Player* player, sf::Vector2f position)
{
}

void Running::attacked(Player* player)
{
}

void Running::update(Player* player, float dt)
{
    m_animation.update(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player->m_velocity.x = -m_runningSpeed;
        player->m_isFacedRight = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player->m_velocity.x = m_runningSpeed;
        player->m_isFacedRight = true;
    }
}

void Running::handleEvents(Player* player, const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Space)
        {
            player->jump();
            return;
        }

        if (event.key.code == sf::Keyboard::LShift)
        {
            player->setState(new Sliding(player));
        }

    }
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Left && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player->setState(new Idle(player));
            player->m_velocity.x = 0;
        }

        if (event.key.code == sf::Keyboard::Right && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player->setState(new Idle(player));
            player->m_velocity.x = 0;
        }
    }
}

void Running::startFalling(Player* player)
{
    player->setState(new Falling(player));
}

void Running::hitGround(Player* player)
{
}







Sliding::Sliding(Player* player) : PlayerState()
{
    player->m_velocity.x *= kVelocityMultiplier;
    m_animation = Animation({0, 268, 40, 24}, 1, 12);
    player->m_sprite.move({0, 12});
    cout << "Creating Sliding state" << endl;
    m_currentTime = kSlidingTime;    
}

void Sliding::hook(Player* player, sf::Vector2f position)
{
}

void Sliding::attacked(Player* player)
{
}

void Sliding::update(Player* player, float dt)
{
    m_animation.update(dt);
    player->m_velocity.x *= kVelocityDecay;
    m_currentTime -= dt;
    if (m_currentTime < 0 || std::abs(player->m_velocity.x) < 0.1)
    {
        player->m_sprite.move({0, -12});
        player->setState(new Idle(player));
        return;
    }
}
void Sliding::handleEvents(Player* player, const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Space)
            player->jump();

        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
            player->setState(new Running(player));
    }
}

void Sliding::startFalling(Player* player)
{
}

void Sliding::hitGround(Player* player)
{
}







Falling::Falling(Player* player) : PlayerState()
{
    m_animation = Animation({0, 192, 20, 34}, 2, 12);
    cout << "Creating Falling state" << endl;
}

void Falling::hook(Player* player, sf::Vector2f position)
{
    player->m_sprite.setPosition(position);
    player->setState(new Hooked(player));
}

void Falling::attacked(Player* player)
{
}

void Falling::update(Player* player, float dt)
{
    m_animation.update(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player->m_velocity.x = -601;
        player->m_isFacedRight = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player->m_velocity.x = 600;
        player->m_isFacedRight = true;
    }
}

void Falling::handleEvents(Player* player, const sf::Event& event)
{
}

void Falling::startFalling(Player* player)
{
}

void Falling::hitGround(Player* player)
{
    player->setState(new Idle(player));
}







Hooked::Hooked(Player* player) : PlayerState()
{
    m_animation = Animation({2, 124, 20, 38}, 6, 12, Animation::AnimationType::OneIteration);
    cout << "Creating Hooked state" << endl;
}

void Hooked::hook(Player* player, sf::Vector2f position)
{
}

void Hooked::attacked(Player* player)
{
}

void Hooked::update(Player* player, float dt)
{
    player->m_velocity = {0, 0};
    m_animation.update(dt);
}

void Hooked::handleEvents(Player* player, const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Space)
            player->jump();

        else if (event.key.code == sf::Keyboard::Down)
            player->setState(new Falling(player));
    }
}

void Hooked::startFalling(Player* player)
{
}

void Hooked::hitGround(Player* player)
{
    player->setState(new Idle(player));
}
