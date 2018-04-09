#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <cmath>
/*
 * Compile line: g++ -std=c++11 main.cpp -o arkanoid.out -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network
 *
 * g++ -std=c++11 -c main.cpp -I/home/agil5393/SFML/include
 * g++ -std=c++11 main.o -o arkanoid.out -L/home/agil5393/SFML/lib -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network
 */

// 'constexpr' define um valor imutável em tempo de compilação
constexpr int windowWidth{800}, windowHeight{600};
constexpr float ballRadius{10.f}, ballVelocity{8.f};
constexpr float paddleWidth{60.f}, paddleHeight{20.f}, paddleVelocity{6.f};
constexpr float blockWidth{60.f}, blockHeight{20.f};
constexpr int countBlocksX{11}, countBlocksY{4};

class Ball {
public:
    sf::CircleShape shape;

    // Vetor bidimensional que armazena a velocidade.
    sf::Vector2f velocity {-ballVelocity, -ballVelocity};

    Ball(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(sf::Color::Red);
        shape.setOrigin(ballRadius, ballRadius);
    }

    // Atualiza o objeto movendo com a velocidade atual;
    void update () { 
        shape.move (velocity); 

        // Pra manter a bola dentro da tela, precisamos testar se está nas 
        // extremidades da tela e inverter sua velocidade
        if (left() < 0 || right() > windowWidth) velocity.x *= -1;
        if (top() < 0 || bottom() > windowHeight) velocity.y *= -1;
    }

    // (0,0) é no topo da esquerda
    float x()               { return shape.getPosition().x; }
    float y()           {   return shape.getPosition().y; }
    float left()        { return x() - shape.getRadius();   }
    float right()   { return x() + shape.getRadius();   }
    float top()         {   return y() - shape.getRadius(); }
    float bottom () {   return y() + shape.getRadius(); }
};

class Paddle {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;

    Paddle(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setSize({paddleWidth, paddleHeight});
        shape.setFillColor(sf::Color::Red);
        shape.setOrigin(paddleWidth /2.f, paddleHeight /2.f );
    }

    void update () {
        shape.move(velocity);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)
                    && left() > 0) velocity.x = -paddleVelocity;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
                    && right() < windowWidth) velocity.x = paddleVelocity;
        
        else 
            velocity.x = 0;
    }

    float x()               { return shape.getPosition().x; }
    float y()           {   return shape.getPosition().y; }
    float left()        { return x() - shape.getSize().x / 2.f; }
    float right()   { return x() + shape.getSize().x / 2.f; }
    float top()         {   return y() - shape.getSize().y / 2.f;   }
    float bottom () {   return y() + shape.getSize().y / 2.f;   }
};

class Brick {
public:
    sf::RectangleShape shape;

    bool destroyed{false};

    Brick(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setSize({blockWidth, blockHeight});
        shape.setFillColor(sf::Color::Yellow);
        shape.setOrigin(blockWidth /2.f, blockHeight /2.f );
    }

    float x()               { return shape.getPosition().x; }
    float y()           {   return shape.getPosition().y; }
    float left()        { return x() - shape.getSize().x / 2.f; }
    float right()   { return x() + shape.getSize().x / 2.f; }
    float top()         {   return y() - shape.getSize().y / 2.f;   }
    float bottom () {   return y() + shape.getSize().y / 2.f;   }
};

// Checa se dois objetos estão se sobrepondo
template <class T1, class T2> bool isIntersecing (T1& mA, T2& mB) {
    return  mA.right() >= mB.left() && 
                    mA.left() <= mB.right() && 
                    mA.bottom() >= mB.top() && 
                    mA.top() <= mB.bottom();
}

void testCollision(Paddle& mPaddle, Ball& mBall) {
    if (!isIntersecing(mPaddle, mBall)) return;

    mBall.velocity.y = -ballVelocity;

    if (mBall.x() < mPaddle.x()) 
        mBall.velocity.x = -ballVelocity;
    else 
        mBall.velocity.x = ballVelocity;
}

void testCollision(Brick& mBrick, Ball& mBall) {

    // Se não está sobrepondo ou se já está destruido, faz nada
    if(!isIntersecing(mBrick, mBall) || mBrick.destroyed) return;

    //Destruindo o bloco
    mBrick.destroyed = true;

    // Calcula o quanto da bola sobrepôs o bloco e cada direção
    float overlapLeft{mBall.right() - mBrick.left()};
    float overlapRight{mBrick.right() - mBall.left()};
    float overlapTop{mBrick.bottom() - mBall.top()};
    float overlapBottom{mBrick.top() - mBall.bottom()};

    // Se a sobreposição da esquerda é menor que a direita, significa que a bola
    // sobrepos o bloco pela esquerda
    bool ballFromLeft{std::fabs(overlapLeft) < std::fabs(overlapRight)};
    // analogamente pode-se verificar sobre a direcao vertical
    bool ballFromTop{std::fabs(overlapTop) < std::fabs(overlapBottom)};

    float minOverlapX{ballFromLeft ? overlapLeft : overlapRight};
    float minOverlapY{ballFromTop ? overlapTop : overlapBottom};

  // Se o tamanho da sobreposição no eixo X é menor que o no eixo Y, pode-se
  // assumar que a bola atingiu o bloco horizontalmente, caso contrário, atingiu
  // verticalmente o bloco.
    if(std::fabs(minOverlapX) < std::fabs(minOverlapY))
        mBall.velocity.x *= -1;
    else
        mBall.velocity.y *= -1;
}

int main () {
    Ball ball{windowWidth / 2, windowHeight /2 };
    Paddle paddle {windowWidth / 2, windowHeight - 50};

    std::vector<Brick> bricks;

    for(int iX{0}; iX < countBlocksX; ++iX)
        for(int iY{0}; iY < countBlocksY; ++iY) 
            bricks.emplace_back((iX + 1) * (blockWidth + 3) +22,
                                                    (iY + 2) * (blockHeight +3));
        
        // { // Equivalente a emplace_back : C++11
        //  Brick umBrick{(iX + 1) * (blockWidth + 3) +22,
        //                                          (iY + 2) * (blockHeight +3)};
        //  bricks.push_back(umBrick);
        // }

    sf::RenderWindow window({windowWidth,windowHeight}, "Arkanoid - 5");
    window.setFramerateLimit(60);

    // Loop do jogo
    while (window.isOpen()) {

        // Monitora os eventos e reage de acordo
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed 
                    && event.key.code == sf::Keyboard::Key::Escape)) {
                window.close();
            }
        }

        // Limpa a tela 
        window.clear(sf::Color::Black);

        // Renderiza os objetos na tela
        ball.update();
        paddle.update();

        // testa colisão a cada ciclo
        testCollision(paddle, ball);

        // remove blocos colididos
        bricks.erase(
            remove_if(
                begin(bricks),
                end(bricks), 
                [](const Brick& mBrick){ return mBrick.destroyed; }),
            end(bricks)
        );

        // testa colisões entre bola e blocos
        for(auto& brick : bricks) testCollision(brick,ball);


        window.draw(ball.shape);
        window.draw(paddle.shape);

        // for(int i{0}; i < bricks.size(); ++i) // Equivalente
        for(auto& brick : bricks) // C++11
            window.draw(brick.shape);

        // Exibe os conteúdos da tela
        window.display();
    }

    return EXIT_SUCCESS;
}