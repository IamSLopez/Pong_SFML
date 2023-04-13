//
// Created by firehero1416 on 5/28/2020.
//

#include "Player.h"


Player::Player(){
 player.setSize(sf::Vector2f(10.f,125.f));
 player.setFillColor(sf::Color::Cyan);
}
Player::Player(float a, float b){
    player.setSize(sf::Vector2f(10.f,125.f));
    player.setFillColor(sf::Color::Cyan);
    player.setPosition(sf::Vector2f(a, b));

}
void Player::move(sf::Vector2f direction){
    player.move(direction);
}
float Player::getX(){
    return player.getPosition().x;
}
float Player::getY(){
    return player.getPosition().y;
}
void Player::draw(sf::RenderWindow &window) {
    window.draw(player);
}
float Player::getLength() {
    return player.getSize().y;
}
float Player::getWidth() {
    return player.getSize().x;
}
void Player::setPosition(float a, float b) {
    player.setPosition(a, b);
}