#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "player.hpp"
#include "player_states.hpp"




class World
{
private:
    Player mPlayer;
    std::vector<sf::FloatRect> mBlocks;
    sf::View mView;
    float mTime;

public:

    World() : 
        mPlayer(Player({400, 400})), 
        mView(sf::FloatRect(0, 0, 1200, 900)), 
        mTime(0)
    {
        
    }

    void addBlock(sf::FloatRect block)
    {
        mBlocks.push_back(block);
    }

    void setView()
    {
        sf::Vector2f playerCenter = mPlayer.getCenter();
        float mViewRatio = 0.6;
        if (playerCenter.x > mView.getCenter().x + mViewRatio * mView.getSize().x / 2)
            mView.move({playerCenter.x - mView.getCenter().x - mViewRatio * mView.getSize().x / 2, 0});

        else if (playerCenter.x < mView.getCenter().x - mViewRatio * mView.getSize().x / 2)
            mView.move({playerCenter.x - mView.getCenter().x + mViewRatio * mView.getSize().x / 2, 0});


        if (playerCenter.y > mView.getCenter().y + mViewRatio * mView.getSize().y / 2)
            mView.move({0, playerCenter.y - mView.getCenter().y - mViewRatio * mView.getSize().y / 2});

        else if (playerCenter.y < mView.getCenter().y - mViewRatio * mView.getSize().y / 2)
            mView.move({0, playerCenter.y - mView.getCenter().y+ mViewRatio * mView.getSize().y / 2});

    }

    void update(float dt)
    {   
        mTime += dt;
        setView();
        mPlayer.update(dt);
        mPlayer.handleAllCollisions(mBlocks);
    }

    void draw(sf::RenderWindow& window)
    {
        static sf::RectangleShape blockShape;
        blockShape.setFillColor(sf::Color(58, 69, 55));

        window.setView(mView);

        for (const sf::FloatRect& b : mBlocks)
        {
            blockShape.setPosition(b.left, b.top);
            blockShape.setSize({b.width, b.height});
            window.draw(blockShape);
        }
        mPlayer.draw(window);
    }

    void handleEvents(const sf::Event& event)
    {
        mPlayer.handleEvents(event);
    }
};