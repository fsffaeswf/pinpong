#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
#include <ctime>

void initBat(sf::RectangleShape& bat, const sf::Color batColor, const sf::Vector2f batPosition) {
	bat.setSize(batSize);
	bat.setFillColor(batColor);
	bat.setPosition(batPosition);
}
void initBall(sf::CircleShape& ball, const sf::Color ballColor, const sf::Vector2f ballPosition) {
	ball.setRadius(r);
	ball.setFillColor(ballColor);
	ball.setPosition(ballPosition);
}
//void initText(sf::Text& scoreText,int score, Font& font, const int charSize,const sf::Vector2f textPos) {
//
//}