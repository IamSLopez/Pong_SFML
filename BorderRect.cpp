//
// Created by firehero1416 on 5/26/2020.
//

#include "BorderRect.h"

BorderRect::BorderRect(){
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineColor(sf::Color::Blue);
    rectangle.setOutlineThickness(10.f);
    rectangle.setSize(sf::Vector2f(1300.f, 1060.f));
    rectangle.setPosition(sf::Vector2f(325.f, 10.f));
}
void BorderRect::draw(sf::RenderWindow &window){
    window.draw(rectangle);
}

float BorderRect::getRight(){
    return rectangle.getPosition().x + rectangle.getSize().x - rectangle.getOutlineThickness()/3;
}
float BorderRect::getLeft(){
    return rectangle.getPosition().x + rectangle.getOutlineThickness()/3;
}
float BorderRect::getTop(){
    return rectangle.getPosition().y + rectangle.getOutlineThickness()/3;
}
float BorderRect::getBottom(){
    return rectangle.getPosition().y + rectangle.getSize().y - rectangle.getOutlineThickness()/3;
}