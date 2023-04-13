//
// Created by firehero1416 on 5/26/2020.
//

#include "Ball.h"
Ball::Ball(){
    circle.setFillColor(sf::Color::White);
    circle.setRadius(12.f);
    circle.setPosition(sf::Vector2f(600, 100));
}

void Ball::draw(sf::RenderWindow &window){
    window.draw(circle);
}

float Ball::move(int a, int b){
    circle.move(a, b);
}

float Ball::getPositionX(){
    return circle.getPosition().x;
}
float Ball::getPositionY(){
    return circle.getPosition().y;
}
float Ball::getRadius(){
    return circle.getRadius();
}
float Ball::setPosition(float a, float b) {
    circle.setPosition(a, b);
}