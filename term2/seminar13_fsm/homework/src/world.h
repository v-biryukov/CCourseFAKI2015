#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "player.h"
#include "player_states.h"




class World
{
private:
    Player m_player;
    std::vector<sf::FloatRect> m_blocks;
    sf::View m_view;
    float m_time;

public:

    World() : 
        m_player(Player({400, 400})), 
        m_view(sf::FloatRect(0, 0, 1200, 900)), 
        m_time(0)
    {
        
    }

    void addBlock(sf::FloatRect block)
    {
        m_blocks.push_back(block);
    }

    void setView()
    {
        sf::Vector2f playerCenter = m_player.getCenter();
        float m_viewRatio = 0.6;
        if (playerCenter.x > m_view.getCenter().x + m_viewRatio * m_view.getSize().x / 2)
            m_view.move({playerCenter.x - m_view.getCenter().x - m_viewRatio * m_view.getSize().x / 2, 0});

        else if (playerCenter.x < m_view.getCenter().x - m_viewRatio * m_view.getSize().x / 2)
            m_view.move({playerCenter.x - m_view.getCenter().x + m_viewRatio * m_view.getSize().x / 2, 0});


        if (playerCenter.y > m_view.getCenter().y + m_viewRatio * m_view.getSize().y / 2)
            m_view.move({0, playerCenter.y - m_view.getCenter().y - m_viewRatio * m_view.getSize().y / 2});

        else if (playerCenter.y < m_view.getCenter().y - m_viewRatio * m_view.getSize().y / 2)
            m_view.move({0, playerCenter.y - m_view.getCenter().y+ m_viewRatio * m_view.getSize().y / 2});

    }

    void update(float dt)
    {   
        m_time += dt;
        setView();
        m_player.update(dt);
        m_player.handleAllCollisions(m_blocks);
    }

    void draw(sf::RenderWindow& window)
    {
        static sf::RectangleShape blockShape;
        blockShape.setFillColor(sf::Color(58, 69, 55));

        window.setView(m_view);

        for (const sf::FloatRect& b : m_blocks)
        {
            blockShape.setPosition(b.left, b.top);
            blockShape.setSize({b.width, b.height});
            window.draw(blockShape);
        }
        m_player.draw(window);
    }

    void handleEvents(const sf::Event& event)
    {
        m_player.handleEvents(event);
    }
};