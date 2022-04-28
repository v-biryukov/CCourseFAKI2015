#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using std::cout, std::endl;


class Animation
{
public:
    enum class AnimationType {Repeat, OneIteration};

    Animation(AnimationType type = AnimationType::Repeat) : 
        mAnimationSpeed {1},
        mTextureRects {},
        mCurrentFrame {0},
        mType(type), 
        mTime(0)
    {
    }

    void addTextureRect(sf::IntRect rect)
    {
        mTextureRects.push_back(rect);
    }

    void setAnimationSpeed(float animationSpeed)
    {
        mAnimationSpeed = animationSpeed;
    }

    sf::Vector2i getSize()
    {
        return {mTextureRects[mCurrentFrame].width, mTextureRects[mCurrentFrame].height};
    }

    void update(float dt)
    {
        mTime += dt;
        mCurrentFrame = static_cast<int>(mAnimationSpeed * mTime);

        if (mCurrentFrame >= mTextureRects.size())
        {
            if (mType == AnimationType::Repeat)
            {
                mCurrentFrame = 0;
                mTime = 0;
            }
            else if (mType == AnimationType::OneIteration)
            {
                mCurrentFrame = mTextureRects.size() - 1;
                mTime = mCurrentFrame / mAnimationSpeed;
            }
        }
    }

    void updateSprite(sf::Sprite& sprite)
    {
        sprite.setTextureRect(mTextureRects[mCurrentFrame]);
    }

private:

    std::vector<sf::IntRect> mTextureRects;
    int mCurrentFrame;

    float           mAnimationSpeed;
    float           mTime;
    AnimationType   mType;
};