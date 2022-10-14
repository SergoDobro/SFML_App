#pragma once
#include <SFML/Graphics.hpp>  
#include "Selectable.cpp"
#include "TextureManager.h"
using namespace sf;

class Unit : public  Selectabled {

public:
	Vector2f aim = Vector2f(0, 0);
	sf::RectangleShape shape; 
	sf::Sprite sprite;
	Unit() {
		position.x = 10;
		position.y = 10;
		shape.setPosition(position);
		shape.setSize(Vector2f(40, 40));
		Color clr(0, 255, 0, 125);
		shape.setFillColor(clr);
		shape = RectangleShape(Selectabled::position);
		sprite.setTexture(*TextureManager::main_text);
		sprite.setColor(clr);
	}
	virtual void SetPosition(Vector2f position) {
		float dx = this->position.x - position.x;
		float dy = this->position.y - position.y;
		
		sprite.setRotation(atan(dy/dx)*180/3.14-90);
		Selectabled::SetPosition(position);
		shape.setPosition(position - Vector2f(5, 5));
		sprite.setPosition(position - Vector2f(5, 5));
	}
	virtual void SelectionChanged() {
		if (Selectabled::isSelected)
		{
			Color clr(255, 0, 0, 125);
			shape.setFillColor(clr);
			sprite.setColor(clr);
		}
		else {
			Color clr(0, 255, 0, 125);
			shape.setFillColor(clr);
			sprite.setColor(clr);
		}
	}
	void update(sf::RenderWindow* window) {
		if (isSelected)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				aim.x = Mouse::getPosition(*window).x;
				aim.y = Mouse::getPosition(*window).y;
			}
			Vector2f vec = (aim - position);
			vec /= 400.0f;/*
			vec.x += ((rand() % 100) - 50) / 50.0f;
			vec.y += ((rand() % 100) - 50) / 50.0f;*/
			SetPosition(position + vec);
		}
	}
	void draw(sf::RenderWindow* window) {

		window->draw(sprite);
	}

};
static Texture* texturet = NULL;