//
// Created by firehero1416 on 5/28/2020.
//

#ifndef PONG_SCORECOUNTER_H
#define PONG_SCORECOUNTER_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class ScoreCounter {
public:
    ScoreCounter();
    ScoreCounter(float a, float b);
    void addScore();
    void draw(sf::RenderWindow &window);
private:
    int score;
    sf::Text text;
    sf::Font font;
    string string1;
};


#endif //PONG_SCORECOUNTER_H
