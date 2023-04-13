//
// Created by firehero1416 on 5/28/2020.
//

#include "ScoreCounter.h"

ScoreCounter::ScoreCounter(){
    score = 0;
    font.loadFromFile("Font/arial.tts");
    string1 = to_string(score);
    text.setFont(font);
    text.setString("hi");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(150);
    //text.setStyle(1);
}
ScoreCounter::ScoreCounter(float a, float b){
    score = 0;
    font.loadFromFile("Font/arial.ttf");
    string1 = to_string(score);
    text.setFont(font);
    text.setString(string1);
    text.setPosition(a, b);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(150);
    text.setScale(1,1);
    text.setStyle(0);
}
void ScoreCounter::addScore(){
    score = score+1;
}
void ScoreCounter::draw(sf::RenderWindow &window){
    string1 = to_string(score);
    text.setFont(font);
    text.setString(string1);
    window.draw(text);
}