#include <SFML/Graphics.hpp>
#include <iostream>
#include "BorderSelection.cpp"
#include "Selectable.cpp"
#include "Unit.cpp"
#include <vector>
using namespace sf;
int main()
{
    TextureManager::LoadTexture();
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "SFML works!");
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);
    BorderSelection selection;


    std::vector<Unit*> units;
    int xAmmount = 100, yAmmount = 100, xd = 9, yd = 5;
    std::vector<Selectabled*> seletables;
    for (size_t i = 0; i < xAmmount; i++)
    {
        for (size_t j = 0; j < yAmmount; j++)
        {
            units.push_back(new Unit());
            seletables.push_back(units[i* xAmmount +j]);
            seletables[i * xAmmount + j]->SetPosition(Vector2f(5 * i* (xd), 5 * j* (yd)));
        }
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        shape.setPosition(Vector2f(1,1));
        selection.update(&window, seletables);
        for (size_t i = 0; i < units.size(); i++)
        {
            units[i]->update(&window);
        }

        window.clear();
        selection.draw(&window);
        for (size_t i = 0; i < units.size(); i++)
        {
            units[i]->draw(&window);
        } 
        //window.draw(shape);
        window.display();
    }

    return 0;
}