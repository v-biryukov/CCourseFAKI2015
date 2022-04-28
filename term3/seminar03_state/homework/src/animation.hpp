#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
    enum class AnimationType {Repeat, OneIteration};

    Animation() {}

    Animation(sf::IntRect textureRect, int numFrames, float animationSpeed, AnimationType type = AnimationType::Repeat) : 
        mNumFrames(numFrames), 
        mAnimationSpeed(animationSpeed), 
        mTextureRect(textureRect),
        mType(type), 
        mTime(0)
    {
    }



    sf::Vector2i getSize()
    {
        sf::Vector2i result = {mTextureRect.width, mTextureRect.height};
        return result;
    }

    void update(float dt)
    {
        mTime += dt;
        if (mTime > mNumFrames / mAnimationSpeed)
        {
            if (mType == AnimationType::Repeat)
                mTime -= mNumFrames / mAnimationSpeed;

            else if (mType == AnimationType::OneIteration)
                mTime = (mNumFrames - 0.5) / mAnimationSpeed;
        }
    }

    void setSprite(sf::Sprite& sprite, bool isFacedRight)
    {
        int currentFrame = static_cast<int>(mAnimationSpeed * mTime) % mNumFrames;
        if (isFacedRight)
        {
            mTextureRect.left = currentFrame * mTextureRect.width;
            sprite.setTextureRect(mTextureRect);
        }
        else
        {
            mTextureRect.left = (currentFrame + 1) * mTextureRect.width;
            mTextureRect.width *= -1;
            sprite.setTextureRect(mTextureRect);
            mTextureRect.width *= -1;
        }
    }


private:
    sf::IntRect     mTextureRect;
    int             mNumFrames;
    float           mAnimationSpeed;
    float           mTime;
    AnimationType   mType;
};