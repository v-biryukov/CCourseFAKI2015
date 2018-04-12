#include <stdlib.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;


const int window_width = 512;
const int window_height = 320;
const float screen_offset_start = 0.3;
const float gravity_acceleration = 10;
const int tile_size = 16;
const float time_speed = 0.00002;

enum PlayereState {IDLE, RUNNING, FALLING};
struct AnimationBox
{
    int offset_x, offset_y;
    int width, height;
};
const int player_animation_num_of_frames[3] = {12, 8, 2};
const AnimationBox player_animation_boxes[3] = {{0, 0, 19, 34}, {0, 64, 21, 34}, {0, 192, 20, 34}};

const float player_speed = 20;
const float player_jump = 45;



struct Screen
{
    float offset_x, offset_y;
    Screen(float offset_x, float offset_y) : offset_x(offset_x), offset_y(offset_y){}
};



class Player
{
private:
    int health;
    float x, y;
    float width, height;
    float vx, vy;
    int direction;
    sf::Sprite sprite;
    float current_frame;

    PlayereState state;


    void set_sprite()
    {
        if (current_frame > player_animation_num_of_frames[state])
            current_frame -= player_animation_num_of_frames[state];
        width = player_animation_boxes[state].width;
        height = player_animation_boxes[state].height;
        if (direction == 1)
        {
            sprite.setTextureRect(sf::IntRect(player_animation_boxes[state].offset_x + width*int(current_frame), 
                              player_animation_boxes[state].offset_y, 
                              width, height));
        }
        else
        {
            sprite.setTextureRect(sf::IntRect(player_animation_boxes[state].offset_x + width*int(current_frame) + width, 
                                  player_animation_boxes[state].offset_y, 
                                  -width, height));
        }
    }

public:
    Player(float x0, float y0, const sf::Texture& texture): x(x0), y(y0)
    {
        sprite.setTexture(texture);
        vx = vy = 0;
        current_frame = 0.0f;
        state = IDLE;
        width = player_animation_boxes[state].width;
        height = player_animation_boxes[state].height;
        direction = 1;
    }

    void set_vx(float vx) { this->vx = vx;}
    void set_vy(float vy) { this->vy = vy;}

    float get_x() { return x;}
    float get_y() { return y;}



    void update(float time, const std::string* tile_map, Screen& screen)
    {

        x += vx*time;
        handle_collision(tile_map, 0);
        vy += gravity_acceleration * time;
        y += vy*time;
        handle_collision(tile_map, 1);
        current_frame += time;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))  
        {
            if (state != FALLING)
            {
                y -= 5;
                vy -= player_jump; 
                state = FALLING;
            }   
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (state == IDLE)
            {
                state = RUNNING;
            }
            vx = -player_speed;
            direction = -1;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  
        {  
            if (state == IDLE)
            {
                state = RUNNING;
            }
            vx = player_speed;
            direction = 1;
        }
        else
        {
            if (state != FALLING)
            {
                state = IDLE;
                vx = 0;
            }
        }
        set_sprite();
        sprite.setPosition(x - screen.offset_x, y - screen.offset_y);
        screen.offset_x = x - window_width / 2;
        screen.offset_y = y - window_height / 1.5;
    }

    void handle_collision(const std::string* tile_map, int axis)
    {
        for (int i = x/tile_size; i < (x+width)/tile_size; i++)
            for (int j = y/tile_size; j < (y+height)/tile_size; j++)
            {
                if ((tile_map[j][i] != ' '))
                { 
                    if (vy > 0 && axis == 1)
                    { 
                        y = j*tile_size -  height;  
                        vy = 0;  
                        state = IDLE; 
                    }
                    if ((tile_map[j][i] != 'b'))
                    {
                        if (vy < 0 && axis == 1)
                        { 
                            y = j*tile_size + tile_size;   
                            vy = 0;
                        }
                        if (vx > 0 && axis == 0)
                        { 
                            x =  i*tile_size -  width; 
                        }
                        if (vx < 0 && axis == 0)
                        {
                            x =  i*tile_size + tile_size;
                        }
                    }
                }
            }
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(sprite);
    }
};


const int H = 40;
const int W = 150;

std::string TileMap[H] = {
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0sssssssd                                                                                                                                            0",
"0sssssssd                                                                                                                                            0",
"0sssssssd                                                                                                                                            0",
"0ssssstxx                qwwe                                                                                                                        0",
"0sssssd                  asuc                                                                                                     sssss             0",
"0sssxxc                  xc                                                                                                      qs  sss             0",
"0sdc                                                                                                                            qs     s             0",
"0sd                                                                                                                             as                   0",
"0sd                                                                                                                             as         s    s    0",
"0sd                                                                                                                             as        sss  sss   0",
"0sd                                                                                                                              zs    s   s    s    0",
"0sd                                                                                                                               zs  ss             0",
"0sd                           QWWWWbbbbbbbbbwwww                                                                                   sxxs              0",
"0sd                          qusssd                                                                                                                  0",
"0sgrre                      qussssd                                                                                                                  0",
"0ssssUrWWE                 qusssssd                                                                                                                  0",
"0ssssssssgwrrwwwhbbbbgwrwwwhssssssg    bbbbbbbWWWWWWWWWWWhbbbbbbwrrwrrrrwrrrwwwrrrrwrwwwWWWWE                      QWWWRRRWrrwrwrwrwrwwwwrwrwwwrwwrwwww0",
"0sssssssssssssssd    zxxxxxxxsssssd           assssssssssd      zsssssxxxsssssssssssssssssssd                     asssssssssssssssssssssssssssssssssss0",
"0sssssssssssssssc           zxxxxxc           zxxxxxxxxxxc       zxxxc   zxxxxxxxxxxxxxxxxxxc                QWWWWusssssssssssssssssssssssssssssssssss0",
"0                                                                                                        QWWussssssssssssssssssssssssssssssssss      0",
"0                                                                                                     QWWusssssssssssssssssssssssssssssssssss        0",
"0                                                                                                  QWWusssssssssssssssssssssssssssssssssss           0",
"0                                                                                               QWWusssssssssssssssssssssssssssssssssss              0",
"0                                                                                            QWWusssssssssssssssssssssssssssssssssss                 0",
"0                                                    QWWE                                 QWWusssssssssssssssssssssssssssssssssss                    0",
"0                                                    assd                              QWWusssssssssssssssssssssssssssssssssss                       0",
"0                                                    auxc                            QWusssssssssssssssssssssssssssssssssss                          0",
"0                                                    zc                   QWWWWWWWWWWEsssssssssssssssssssssssssssssssssss                            0",
"0                                                      QWWWhbbbbbbbbbbbbbasssssssxxxc                                                                0",
"0                                      QWWWWWWWWWWWWWWWusssE                asssssssd                                                                0",
"0                                      zxxxxxxxxxxxxxxxxxxxc                zxxxxxxxc                                                                0",
"0                                                                                                                                                    0",
"0WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                             sssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
"0ssssssssssssssssssssssssssssssssssssssssssssss                                            ssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
"0ssssssssssssssssssssssssssssssssssssssssssssss                                           sssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
"0ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
"0ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
"0ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
"0ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
}; 





int main () 
{
    float offsetX=0, offsetY=0;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Platformer");
    window.setFramerateLimit(60);
    window.setSize(sf::Vector2u(2.5*window_width, 2.5*window_height));

    sf::Texture tile_set;
    if (!tile_set.loadFromFile("./graphics/Foreground/Tileset.png"))
    {
        exit(1);
    }
    sf::Sprite tile(tile_set);


    sf::Texture background_texture[4];
    background_texture[0].loadFromFile("./graphics/Background/CloudsBack.png");
    background_texture[1].loadFromFile("./graphics/Background/CloudsFront.png");
    background_texture[2].loadFromFile("./graphics/Background/BGBack.png");
    background_texture[3].loadFromFile("./graphics/Background/BGFront.png");
    for (int i = 0; i < 4; ++i)
        background_texture[i].setRepeated(true);
    sf::Sprite backgrounds[4] = {sf::Sprite(background_texture[0]), sf::Sprite(background_texture[1]),
                                 sf::Sprite(background_texture[2]), sf::Sprite(background_texture[3])};

    float total_time = 0.0;

    sf::Texture hero_tiles;
    if (!hero_tiles.loadFromFile("./graphics/hero.png"))
    {
        exit(1);
    }
    Player hero(500, 200, hero_tiles);

    Screen screen(0, 0);

    sf::Clock clock;

    while (window.isOpen()) 
    {
        float time = clock.getElapsedTime().asMicroseconds()*time_speed;
        clock.restart();

        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            {
                window.close();
            }

        }
        backgrounds[1].setTextureRect(sf::IntRect(total_time/3, 0, window_width, window_height));
        backgrounds[2].setTextureRect(sf::IntRect(screen.offset_x/100, 0, window_width, window_height));
        backgrounds[3].setTextureRect(sf::IntRect(screen.offset_x/30, 0, window_width, window_height));
        for (int i = 0; i < 4; ++i)
        {
            window.draw(backgrounds[i]);
        }
        for (int i=0; i<H; i++)
        {
            for (int j=0; j<W; j++)
            { 
                if (TileMap[i][j]=='q' || TileMap[i][j]=='Q')       tile.setTextureRect( sf::IntRect( 0,  0, 16, 16) );
                if (TileMap[i][j]=='w' || TileMap[i][j]=='W')       tile.setTextureRect( sf::IntRect(16,  0, 16, 16) );
                if (TileMap[i][j]=='e' || TileMap[i][j]=='E')       tile.setTextureRect( sf::IntRect(32,  0, 16, 16) );
                if (TileMap[i][j]=='a')                             tile.setTextureRect( sf::IntRect( 0, 16, 16, 16) );
                if (TileMap[i][j]=='s')                             tile.setTextureRect( sf::IntRect(16, 16, 16, 16) );
                if (TileMap[i][j]=='d')                             tile.setTextureRect( sf::IntRect(32, 16, 16, 16) );
                if (TileMap[i][j]=='z')                             tile.setTextureRect( sf::IntRect( 0, 32, 16, 16) );
                if (TileMap[i][j]=='x')                             tile.setTextureRect( sf::IntRect(16, 32, 16, 16) );
                if (TileMap[i][j]=='c')                             tile.setTextureRect( sf::IntRect(32, 32, 16, 16) );
                if (TileMap[i][j]=='r'  || TileMap[i][j]=='R')      tile.setTextureRect( sf::IntRect(48,  0, 16, 16) );
                if (TileMap[i][j]=='t')                             tile.setTextureRect( sf::IntRect(64,  0, 16, 16) );
                if (TileMap[i][j]=='y')                             tile.setTextureRect( sf::IntRect(80,  0, 16, 16) );
                if (TileMap[i][j]=='u')                             tile.setTextureRect( sf::IntRect(96,  0, 16, 16) );
                if (TileMap[i][j]=='U')                             tile.setTextureRect( sf::IntRect(112, 0,-16 ,16) );
                if (TileMap[i][j]=='i')                             tile.setTextureRect( sf::IntRect(112, 0, 16, 16) );
                if (TileMap[i][j]=='f')                             tile.setTextureRect( sf::IntRect(48, 16, 16, 16) );
                if (TileMap[i][j]=='g')                             tile.setTextureRect( sf::IntRect(64, 16, 16, 16) );
                if (TileMap[i][j]=='h')                             tile.setTextureRect( sf::IntRect(80, 16, 16, 16) );
                if (TileMap[i][j]=='v')                             tile.setTextureRect( sf::IntRect(48, 32, 16, 16) );
                if (TileMap[i][j]=='b')                             tile.setTextureRect( sf::IntRect(112, 64, 16, 16) );
                if ((TileMap[i][j]==' ') || (TileMap[i][j]=='0'))   continue;

                tile.setPosition(j*tile_size - screen.offset_x, i*tile_size - screen.offset_y) ; 
                window.draw(tile);

                if (TileMap[i][j]=='W')                             tile.setTextureRect( sf::IntRect(112, 32, 16, 16) );
                if (TileMap[i][j]=='R')                             tile.setTextureRect( sf::IntRect(128, 32, 16, 16) );
                if (TileMap[i][j]=='Q')                             tile.setTextureRect( sf::IntRect(96, 32, 16, 16) );
                if (TileMap[i][j]=='E')                             tile.setTextureRect( sf::IntRect(144, 32, 16, 16) );
                window.draw(tile);

            }
        }

        hero.update(time, TileMap, screen);
        hero.draw(window);
        window.display();
        total_time += time;
    }

    return EXIT_SUCCESS;
}