#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
#include "func.h"
using namespace sf;

int main()
{
	float midLeftx, midLefty, midRightx, midRighty, midDownx,midDowny;
	srand(time(nullptr));
	speedx = rand() % 11 - 5;
	speedy = rand() % 11 - 5;
	RectangleShape rect;
	RectangleShape rect1;
	CircleShape circle;

	initBat(rect, Left_Bat_Color, left_bat_startpos);
	initBat(rect1, Right_Bat_Color, right_bat_startpos);
	initBall(circle, Circle_Color, ball_startpos);
	
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(size, size), "SFML Works!");
	window.setFramerateLimit(FPS);

	int leftScore = 0;
	int rightScore = 0;

	Font font, font1;
	font.loadFromFile("DS-DIGIB.ttf");
	Text leftScoreText(std::to_string(leftScore), font, 64);
	font1.loadFromFile("DS-DIGIB.ttf");
	Text rightScoreText(std::to_string(rightScore), font1, 64);
	leftScoreText.setPosition(200, 10);
	rightScoreText.setPosition(580, 10);
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//обновление объектов игры
		circle.move(speedx, speedy);
		if (circle.getPosition().x + 2 * r > size)
		{
			speedx = -speedx;
			rightScore++;
			rightScoreText.setString(std::to_string(rightScore));
		}

		if (circle.getPosition().x < 0) {
			speedx = -speedx;
			leftScore++;
			leftScoreText.setString(std::to_string(leftScore));
		}

		if (circle.getPosition().y + 2 * r > size ||
			circle.getPosition().y < 0) {
			speedy = -speedy;
		}
		//двигаем ракетки
		//правая
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			rect1.move(0, -BatDy);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rect1.move(0, BatDy);
		}
		//левая
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			rect.move(0, -BatDy);
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			rect.move(0, BatDy);
		}

		//границы ракетки
		//левая
		if (rect.getPosition().y + ay > size) {
			rect.move(0, -BatDy);
		}
		if (rect.getPosition().y < 0) {
			rect.move(0, BatDy);
		}

		//правая
		if (rect1.getPosition().y + ay > size) {
			rect1.move(0, -BatDy);
		}
		if (rect1.getPosition().y < 0) {
			rect1.move(0, BatDy);
		}
		midLeftx = circle.getPosition().x,
		midLefty = circle.getPosition().y + r;

		midRightx = circle.getPosition().x + 2 * r,
		midRighty = circle.getPosition().y + r;

		midDownx = circle.getPosition().x + r;
		midDowny = circle.getPosition().y + 2 * r;
		
		//отскок от ракеток
		if ((midLeftx <= rect.getPosition().x + ax) &&
			(midLefty >= rect.getPosition().y && midLefty <= rect.getPosition().y + ay)) {
			speedx = -speedx;
		}

		if ((midRightx >= rect1.getPosition().x) &&
			(midRighty >= rect1.getPosition().y && midRighty <= rect1.getPosition().y + ay)) {
			speedx = -speedx;
		}
		//отскок от верхней стороны
		if ((midDownx >= rect.getPosition().x && midDownx <= rect.getPosition().x + ax) &&
			(midDowny >= rect.getPosition().y)) {
			speedy = -speedy;
		}
		if ((midDownx >= rect1.getPosition().x && midDownx <= rect1.getPosition().x + ax) &&
			(midDowny >= rect1.getPosition().y)) {
			speedy = -speedy;
		}

		// Отрисовка объектов и окна 
		window.clear();
		window.draw(rect);
		window.draw(rect1);
		window.draw(circle);
		window.draw(rightScoreText);
		window.draw(leftScoreText);
		window.display();

	}

	return 0;
}