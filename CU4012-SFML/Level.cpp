#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	

	// initialise game objects
	circle.setRadius(25);
	circle.setPosition(150, 75);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);
	speed = 150.0f;
	

	player.setSize(sf::Vector2f(25, 25));
	player.setPosition(300, 300);
	player.setFillColor(sf::Color::Red);
	playerspeed = 150.0f;

	circle1.setRadius(30);
	circle1.setPosition(150, 75);
	circle1.setFillColor(sf::Color::Blue);
	circle1.setOutlineColor(sf::Color::Green);
	circle1.setOutlineThickness(2.f);
	circlespeed = 150.f;
	bouncingspeedx = 200.f;
	bouncingspeedy = 200.f;
	


}

Level::~Level()
{
}

// handle user input
void Level::handleInput(float dt)
{
	circle.move(speed * dt, 0);
	if (circle.getPosition().x + 40 <= window->getSize().x)
	{
		speed = speed;
	}
	else
		speed = -speed;
	 if (circle.getPosition().x <= 0)
	{
		speed = -speed;
	}
	 circle.move(0, speed * dt);
	 if (circle.getPosition().y  <= window->getSize().y)
	 {
		 speed = speed;
		
	 }
	 else
		 speed = -speed;
	 if (circle.getPosition().y <= 0)
	 {
		 speed = -speed;
	 }
	 //break
	 if (input->isKeyDown(sf::Keyboard::W))
	 {
		 //input->setKeyUp(sf::Keyboard::W);
			 player.move(0, -playerspeed * dt);

	}
	 if (input->isKeyDown(sf::Keyboard::S))
	 {
		 //input->setKeyUp(sf::Keyboard::S);
		 player.move(0, playerspeed * dt);

	 }
	 if (input->isKeyDown(sf::Keyboard::A))
	 {
		 //input->setKeyUp(sf::Keyboard::A);
		 player.move(-playerspeed * dt, 0);

	 }
	 if (input->isKeyDown(sf::Keyboard::D))
	 {
		 //input->setKeyUp(sf::Keyboard::D);
		 player.move(playerspeed * dt, 0);
	 }
	 if (input->isKeyDown(sf::Keyboard::L))
	 {
		 input->setKeyUp(sf::Keyboard::L);
		 bouncingspeedx += 100.f;
		 bouncingspeedy += 100.f;
	 }
}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2f pos = player.getPosition();
	sf::Vector2f size = player.getSize();

	if (pos.x > window->getSize().x - size.x) {
		pos.x = window->getSize().x - size.x;
	}

	if (pos.x < 0) {
		pos.x = 0;
	}

	if (pos.y > window->getSize().x - size.y) {
		pos.y = window->getSize().x - size.y;
	}

	if (pos.y < 0) {
		pos.y = 0;
	}

	player.setPosition(pos);
	//circle1.move(circlespeed * dt, 0);
	//circle1.move(0, circlespeed * dt);
	circle1.move(bouncingspeedx * dt, bouncingspeedy * dt);

	if (circle1.getPosition().y <= 0 ||
		circle1.getPosition().y >= window->getSize().y - circle1.getRadius() * 2)
	{
		bouncingspeedy = -bouncingspeedy;
	}
	if (circle1.getPosition().x <= 0 ||
		circle1.getPosition().x >= window->getSize().x - circle1.getRadius() * 2)
	{
		bouncingspeedx = -bouncingspeedx;
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window -> draw (circle);
	window->draw(player);
	window->draw(circle1);


	endDraw();
}

