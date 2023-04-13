//
// Created by firehero1416 on 5/26/2020.
//

#ifndef PONG_BORDERRECT_H
#define PONG_BORDERRECT_H
#include <iostream>
#include <SFML/Graphics.hpp>

class BorderRect {
public:
    BorderRect();
    void draw(sf::RenderWindow &window);
    float getRight();
    float getLeft();
    float getTop();
    float getBottom();
private:
    sf::RectangleShape rectangle;
};


#endif //PONG_BORDERRECT_H
