#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"

std::string TileMap[] = {
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
"0ssssssssgwrrwwwhbbbbgwrwwwhssssssg    bbbbbbbWWWWWWWWWWWhbbbbbbwrrwrrrrwrrrwwwrrrrwrwwwWWWWE                      QWWWRRRWrrwrwrwrwe    qrwwwrwwrwww0",
"0sssssssssssssssd    zxxxxxxxsssssd           assssssssssd      zsssssxxxsssssssssssssssssssd                     asssssssssssssssssd    asssssssssss0",
"0xxxxxxxxxxxxxxxc           zxxxxxc           zxxxxxxxxxxc       zxxxc   zxxxxxxxxxxxxxxxxxxc                QWWWWusssssssssssssssssd    assssxxxxxxx0",
"0d                                                                                                       QWWusssssssssssssssssssssssd    assxc      a0",
"0d                                                                                                    QWWussssssssssssssssssssssssssd    zxc        a0",
"0d                                                                                                 QWWusssssssssssssssssssssssssssssd               a0",
"0d                                                                                              QWWussssssssssssssssssssssssssssssssd               a0",
"0d                                                                                           QWWussssssssssssssssssssssssssssssssxxxc               a0",
"0d                                                   QWWE                                 QWWussssssssssssssssssssssssssssssssxxc                   a0",
"0d                                                   assd                              QWWussssssssssssssssssssssssssssssssxxc                      a0",
"0d                                                   auxc                            QWusssssssssssssssssssssssssssssssssxc                         a0",
"0d                                                   zc                   QWWWWWWWWWWExxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                           a0",
"0d                                                     QWWWhbbbbbbbbbbbbbassssssssssc                                                               a0",
"0d                                     QWWWWWWWWWWWWWWWusssE                asssssssd                                                               a0",
"0d                                     zxxxxxxxxxxxxxxxxxxxc                zxxxxxxxc                                                               a0",
"0d                                                                                                                                                  a0",
"0sWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                             qrwrwrwwrwrrrwrwrrwrwrwrrwrwrwrwrrwrwrwrwrrwrwrwrrwrwrwrw0",
"0sssssssssssssssssssssssssssssssssssssssssssssd                                            qsssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
"0sssssssssssssssssssssssssssssssssssssssssssssd                                           qssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
"0sssssssssssssssssssssssssssssssssssssssssssssswrrwrwrwrrwrwrwrwrrwrwrwrrwrwrwrrwrwrrwrwrwsssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
"0ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
"0ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
"0ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0",
}; 

int main () 
{

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Platformer");
    window.setFramerateLimit(60);
    window.setSize(sf::Vector2u(2.5*window_width, 2.5*window_height));

    Game game(40, 150, TileMap);
    game.set_player_position(550, 250);

    sf::Clock clock;
    while (window.isOpen()) 
    {
        float time = clock.getElapsedTime().asMicroseconds()*time_speed;
        if (time > 0.03*1e6*time_speed) 
            time = 0.03*1e6*time_speed;
        clock.restart();

        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            {
                window.close();
            }

        }
        game.update(time);
        game.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}