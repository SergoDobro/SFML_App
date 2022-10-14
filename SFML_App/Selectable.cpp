#include <SFML/Graphics.hpp>
#pragma once
using namespace sf;

class Selectabled {
public:
	Selectabled() {}
	Vector2f position = Vector2f(0, 0);
	bool isSelected = false;
	virtual void SelectionChanged()  {};
	virtual void Select() {
		isSelected = true;
		SelectionChanged();
	}
	virtual void DeSelect() {
		isSelected = false;
		SelectionChanged();
	}
	virtual void Swap() {
		isSelected = !isSelected;
		SelectionChanged();
	}
	virtual void SetPosition(Vector2f position) {
		this->position = position;
	}
};