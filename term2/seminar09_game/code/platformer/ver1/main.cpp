#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"

std::string TileMap[40] = {
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

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Platformer");
    window.setFramerateLimit(60);
    window.setSize(sf::Vector2u(2.5*window_width, 2.5*window_height));

    Game game(40, 150, TileMap);
    game.set_player_position(500, 200);

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
        game.update(time);
        game.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}