//
// Created by firehero1416 on 5/26/2020.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Ball {
public:
    Ball();
    void draw(sf::RenderWindow &window);
    float move(int a, int b);
    float setPosition(float a, float b);
    float getPositionX();
    float getPositionY();
    float getRadius();
private:
    sf::CircleShape circle;
    sf::FloatRect boundingBox = circle.getGlobalBounds();

};


#endif //PONG_BALL_H
