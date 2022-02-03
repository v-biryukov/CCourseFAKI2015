#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
    enum class AnimationType {Repeat, OneIteration};

    Animation() {}

    Animation(sf::IntRect textureRect, int numFrames, float animationSpeed, AnimationType type = AnimationType::Repeat) : 
        m_numFrames(numFrames), 
        m_animationSpeed(animationSpeed), 
        m_textureRect(textureRect),
        m_type(type), 
        m_time(0)
    {
    }



    sf::Vector2i getSize()
    {
        sf::Vector2i result = {m_textureRect.width, m_textureRect.height};
        return result;
    }

    void update(float dt)
    {
        m_time += dt;
        if (m_time > m_numFrames / m_animationSpeed)
        {
            if (m_type == AnimationType::Repeat)
                m_time -= m_numFrames / m_animationSpeed;

            else if (m_type == AnimationType::OneIteration)
                m_time = (m_numFrames - 0.5) / m_animationSpeed;
        }
    }

    void setSprite(sf::Sprite& sprite, bool isFacedRight)
    {
        int currentFrame = (int)(m_animationSpeed * m_time) % m_numFrames;
        if (isFacedRight)
        {
            m_textureRect.left = currentFrame * m_textureRect.width;
            sprite.setTextureRect(m_textureRect);
        }
        else
        {
            m_textureRect.left = (currentFrame + 1) * m_textureRect.width;
            m_textureRect.width *= -1;
            sprite.setTextureRect(m_textureRect);
            m_textureRect.width *= -1;
        }
    }



    void set_sprite(sf::Sprite& sprite, bool is_faced_right)
    {
        int current_frame = (int)(m_animation_speed * m_time) % m_num_frames;
        if (is_faced_right)
        {
            m_texture_rect.left = current_frame * m_texture_rect.width;
            sprite.setTextureRect(m_texture_rect);
        }
        else
        {
            m_texture_rect.left = (current_frame + 1) * m_texture_rect.width;
            m_texture_rect.width *= -1;
            sprite.setTextureRect(m_texture_rect);
            m_texture_rect.width *= -1;
        }
    }


private:
    sf::IntRect m_textureRect;
    int m_numFrames;
    float m_animationSpeed;
    float m_time;
    AnimationType m_type;
};