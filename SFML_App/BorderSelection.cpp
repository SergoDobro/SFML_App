#include <SFML/Graphics.hpp>
#include "Selectable.cpp"
using namespace sf;

class BorderSelection {
public:
    Vector2f startFromPos = Vector2f(0, 0);
    Vector2f endPos = Vector2f(0, 0);
    sf::RectangleShape shape = RectangleShape(startFromPos);
    bool isOn = false;
    BorderSelection() {
        Color clr(0, 255, 0, 125);
        shape.setFillColor(clr);
    }
    void update(sf::RenderWindow* window, std::vector<Selectabled*> selectables) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            endPos.x = Mouse::getPosition(*window).x - startFromPos.x;
            endPos.y = Mouse::getPosition(*window).y - startFromPos.y;
            shape.setSize(endPos);
            isOn = true; 
            for (size_t i = 0; i < selectables.size(); i++)
            {
                /*if ((selectables[i]->position.x - (startFromPos.x + endPos.x))*
                    (selectables[i]->position.x - (startFromPos.x + endPos.x))
                    +
                    (selectables[i]->position.y - (startFromPos.y + endPos.y))*
                    (selectables[i]->position.y - (startFromPos.y + endPos.y)) < 400)
                {
                    (selectables[i])->Select();
                }
                else {
                    if (selectables[i]->isSelected)
                        (selectables[i])->DeSelect();
                }*/
                if ((selectables[i]->position.x - (startFromPos.x)) *
                    (selectables[i]->position.x - (startFromPos.x + endPos.x)) < 0
                    &&
                    (selectables[i]->position.y - (startFromPos.y)) *
                    (selectables[i]->position.y - (startFromPos.y + endPos.y)) < 0)
                    (selectables[i])->Select();
                else {
                    if (selectables[i]->isSelected)
                        (selectables[i])->DeSelect();
                }
            }
        }
        else {
            isOn = false;
            startFromPos.x = Mouse::getPosition(*window).x;
            startFromPos.y = Mouse::getPosition(*window).y;
            shape.setPosition(startFromPos);
        }
    }
    void draw(sf::RenderWindow* window) {
        if (isOn)
        {
            window->draw(shape);
        }
    }
};