//
// Created by firehero1416 on 5/28/2020.
//

#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Player {
public:
    Player();
    Player(float x, float y);
    void move(sf::Vector2f direction);
    float getX();
    float getY();
    void draw(sf::RenderWindow &window);
    float getLength();
    float getWidth();
    void setPosition(float a, float b);
private:
    sf::RectangleShape player;
};


#endif //PONG_PLAYER_H
