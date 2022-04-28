#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "animation.hpp"
#include "player.hpp"
#include "player_states.hpp"

using namespace std;

PlayerState::PlayerState() 
{
}

void PlayerState::handleEvents(Player* player, const sf::Event& event)
{
}

void PlayerState::update(Player* player, float dt)
{
    mAnimation.update(dt);
}

sf::Vector2i PlayerState::getSize()
{
    return mAnimation.getSize();
}

void PlayerState::setSprite(sf::Sprite& sprite, bool isFacedRight)
{
    mAnimation.setSprite(sprite, isFacedRight);
}

PlayerState::~PlayerState() 
{
}




Idle::Idle(Player* player) 
{
    player->mVelocity = {0, 0};
    mAnimation = Animation({0, 0, 19, 34}, 12, 12);
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
    mAnimation.update(dt);
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
    mRunningSpeed = 900;
    mAnimation = Animation({0, 64, 21, 34}, 8, 14);
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
    mAnimation.update(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player->mVelocity.x = -mRunningSpeed;
        player->mIsFacedRight = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player->mVelocity.x = mRunningSpeed;
        player->mIsFacedRight = true;
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
            player->mVelocity.x = 0;
        }

        if (event.key.code == sf::Keyboard::Right && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player->setState(new Idle(player));
            player->mVelocity.x = 0;
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
    player->mVelocity.x *= kVelocityMultiplier;
    mAnimation = Animation({0, 268, 40, 24}, 1, 12);
    player->mSprite.move({0, 12});
    cout << "Creating Sliding state" << endl;
    mCurrentTime = kSlidingTime;    
}

void Sliding::hook(Player* player, sf::Vector2f position)
{
}

void Sliding::attacked(Player* player)
{
}

void Sliding::update(Player* player, float dt)
{
    mAnimation.update(dt);
    player->mVelocity.x *= kVelocityDecay;
    mCurrentTime -= dt;
    if (mCurrentTime < 0 || std::abs(player->mVelocity.x) < 0.1)
    {
        player->mSprite.move({0, -12});
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
    mAnimation = Animation({0, 192, 20, 34}, 2, 12);
    cout << "Creating Falling state" << endl;
}

void Falling::hook(Player* player, sf::Vector2f position)
{
    player->mSprite.setPosition(position);
    player->setState(new Hooked(player));
}

void Falling::attacked(Player* player)
{
}

void Falling::update(Player* player, float dt)
{
    mAnimation.update(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player->mVelocity.x = -601;
        player->mIsFacedRight = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player->mVelocity.x = 600;
        player->mIsFacedRight = true;
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
    mAnimation = Animation({2, 124, 20, 38}, 6, 12, Animation::AnimationType::OneIteration);
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
    player->mVelocity = {0, 0};
    mAnimation.update(dt);
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
