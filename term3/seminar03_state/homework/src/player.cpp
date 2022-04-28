#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "player.hpp"
#include "player_states.hpp"

void Player::setState(PlayerState* newState)
{
    delete mpState;
    mpState = newState;
}

Player::Player(sf::Vector2f position)
{
    if (!mTexture.loadFromFile("./hero.png"))
    {
        std::cout << "Can't load image ./hero.png for Player class" << std::endl;
        exit(1);
    }
    mSprite.setTexture(mTexture);
    mSprite.setPosition(position);

    mScaleFactor = 5;
    mSprite.setScale(mScaleFactor, mScaleFactor);
    mpState = new Idle(this);
}

sf::Vector2f Player::getCenter() const
{
    return {mSprite.getPosition().x + mpState->getSize().x * mScaleFactor / 2,
            mSprite.getPosition().y + mpState->getSize().y * mScaleFactor / 2};
}

void Player::update(float dt)
{
    mVelocity.y += 60;
    mpState->update(this, dt);
    mSprite.setPosition(mSprite.getPosition() + mVelocity * dt);
}

void Player::draw(sf::RenderWindow& window)
{
    mpState->setSprite(mSprite, mIsFacedRight);
    window.draw(mSprite);
}

void Player::jump()
{
    mSprite.move({0, -10});
    mVelocity.y = -kJumpingVelocity;
    mpState = new Falling(this);
}

void Player::handleEvents(const sf::Event& event) 
{
    mpState->handleEvents(this, event);
}

bool Player::handleCollision(const sf::FloatRect& rect)
{
    sf::FloatRect playerRect = { mSprite.getPosition().x,               mSprite.getPosition().y, 
                                 mpState->getSize().x * mScaleFactor,   mpState->getSize().y * mScaleFactor};
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
                mSprite.move({-overlapx1, 0});
                mVelocity.x = 0;
                if (mVelocity.y > 0 && playerRect.top < rect.top + Hooked::kMaxHookOffset && playerRect.top > rect.top - Hooked::kMaxHookOffset)
                {
                    mpState->hook(this, {rect.left - playerRect.width, rect.top - Hooked::kHookDisplacement});
                }
                break;
            case 1:
                mSprite.move({overlapx2, 0});
                mVelocity.x = 0;
                if (mVelocity.y > 0 && playerRect.top < rect.top + Hooked::kMaxHookOffset && playerRect.top > rect.top - Hooked::kMaxHookOffset)
                {
                    mpState->hook(this, {rect.left + rect.width, rect.top - Hooked::kHookDisplacement});
                }
                break;
            case 2:
                mSprite.move({0, -overlapy1});
                mVelocity.y = 0;
                mpState->hitGround(this);
                break;
            case 3:
                mSprite.move({0, overlapy2});
                if (mVelocity.y < 0)
                    mVelocity.y = 0;
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
        mpState->startFalling(this);
}


Player::~Player()
{
    delete mpState;
}