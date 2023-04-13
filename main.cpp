#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "BorderRect.h"
#include "Player.h"
#include "ScoreCounter.h"
#include <windows.h>
using namespace std;


int main() {
    float windowWidth = 1920;
    float windowHeight = 1080;
    sf::RenderWindow window(sf::VideoMode(windowWidth , windowHeight, 32), "Pong");
    window.setFramerateLimit(60);
    Ball circle;
    BorderRect border;
    Player player;
    Player player1(border.getLeft() + 100.f, windowHeight/2.f - player.getLength()/2.f);
    Player player2(border.getRight() - 100.f, windowHeight/2.f - player.getLength()/2.f);
    ScoreCounter count1(100, 100);
    ScoreCounter count2(1700, 100);
    int playerSpeed = 10;
    int ballSpeedX = 9;
    int ballSpeedY = 8;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        circle.move(ballSpeedX,ballSpeedY);
        if(circle.getPositionX() > border.getRight()-circle.getRadius()*2) //ball hits right wall
        {

            player1.setPosition(border.getLeft() + 100.f, border.getBottom()/2.f - player.getLength()/2.f);
            player2.setPosition(border.getRight() - 100.f, border.getBottom()/2.f - player.getLength()/2.f);
            circle.setPosition(player1.getX() + 100, windowHeight/2);
            circle.move(ballSpeedX, ballSpeedY);
            Sleep(2000);
            count1.addScore();
        }

        if(circle.getPositionX() < border.getLeft()) //ball hits left wall
        {

            player1.setPosition(border.getLeft() + 100.f, border.getBottom()/2.f - player.getLength()/2.f);
            player2.setPosition(border.getRight() - 100.f, border.getBottom()/2.f - player.getLength()/2.f);
            circle.setPosition(player2.getX() - 100, windowHeight/2);
            circle.move(-ballSpeedX, ballSpeedY);
            Sleep(2000);
            count2.addScore();

        }
        if(circle.getPositionY() < border.getTop()) //ball hits top
        {
            ballSpeedY = -ballSpeedY;
            //circle.setFillColor(sf::Color::Magenta);
        }
        if(circle.getPositionY() > border.getBottom()-circle.getRadius()*2) //ball hits bottom
        {
            ballSpeedY = -ballSpeedY;
            //circle.setFillColor(sf::Color::Yellow);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){ //player1 control
            player1.move(sf::Vector2f(0, -playerSpeed));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){ //player1 control
            player1.move(sf::Vector2f(0, playerSpeed));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //player2 control
            player2.move(sf::Vector2f(0, -playerSpeed));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ //player2 control
            player2.move(sf::Vector2f(0, playerSpeed));
        }
        if(player1.getY() < border.getTop()){ //stop player 1 from leaving top
            player1.setPosition(player1.getX(), border.getTop());
        }
        else if(player1.getY()+player1.getLength() > border.getBottom()){ //stop player 1 from leaving bottom
            player1.setPosition(player1.getX(), border.getBottom()-player1.getLength());
        }
        else{
        }
        if(player2.getY() < border.getTop()){ //stop player 2 from leaving top
            player2.setPosition(player2.getX(), border.getTop());
        }
        else if(player2.getY() + player2.getLength() > border.getBottom()){ //stop player 2 from leaving bottom
            player2.setPosition(player2.getX(), border.getBottom() - player2.getLength());
        }
        else{
        }
        if(player1.getY() < circle.getPositionY()+circle.getRadius()) { //bounce ball off player1
            if ((player1.getY()+player1.getLength()) > circle.getPositionY()+circle.getRadius()) {
                if((player1.getX()+player1.getWidth())> circle.getPositionX()){
                    if(player1.getX() < circle.getPositionX()) {
                        ballSpeedX = -ballSpeedX;
                    }
                }
            }
        }
        else{
        }
        if(player2.getY() < circle.getPositionY()+circle.getRadius()) { //bounce ball off player2
            if ((player2.getY()+player2.getLength()) > circle.getPositionY()+circle.getRadius()) {
                if(player2.getX() > circle.getPositionX()+circle.getRadius()){
                    if((player2.getX()-player2.getWidth()) < circle.getPositionX()+circle.getRadius()) {
                        ballSpeedX = -ballSpeedX;
                    }
                }
            }
        }
        else{
        }


        window.clear(sf::Color::Black);
        border.draw(window);
        circle.draw(window);
        player1.draw(window);
        player2.draw(window);
        count1.draw(window);
        count2.draw(window);
        window.display();
    }
    return 0;
}