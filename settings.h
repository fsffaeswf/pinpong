#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
#include <ctime>

const float ax = 20.f;
const float ay = 80.f;

const float FPS = 60.f;

const float size = 800;

const float r = 15.f;

const float Bat_Ofset = 15.f;

float speedx = rand() % 20 - 10;
float speedy = rand() % 20 - 10;

const float BatDy = 10.f;

const int charSize = 64;

const sf::Color Left_Bat_Color{ sf::Color::Magenta };
const sf::Color Right_Bat_Color{ sf::Color::Red };
const sf::Color Circle_Color{ sf::Color::Yellow };

const sf::Vector2f left_bat_startpos(Bat_Ofset, size / 2 - ay / 2);
const sf::Vector2f right_bat_startpos(size - Bat_Ofset - ax, size / 2 - ay / 2);
const sf::Vector2f ball_startpos(size / 2 - r, size / 2 - r);
const sf::Vector2f batSize(20.f, 80.f);