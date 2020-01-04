#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Arrow.h"


using namespace std;
using namespace sf;

int main()
{
    RenderWindow window{ VideoMode{600,800}, "Archer game v 0.0" };
    window.setFramerateLimit(60);
    Event event;
    int indexArrow = NULL;
    Player player(300, 400);
    vector<Arrow> arrows;

    while (true)
    {
        window.clear(Color::White);
        window.pollEvent(event);
        player.update();
        

        if (event.type == Event::Closed)
        {
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Space))
        {
            arrows.emplace_back(player.getPosition().x,player.getPosition().y);
        }
        for (auto& arrow : arrows)
        {
            indexArrow+=1;
            if (arrow.getPosition().x < 0 || arrow.getPosition().x>600 || arrow.getPosition().y < 0 || arrow.getPosition().y>800)
            {
                arrows.erase(arrows.begin() + indexArrow-1);
            }
        }
        for (auto& arrow : arrows)
        {
            arrow.update();
            window.draw(arrow);
        }
        indexArrow = NULL;
        window.draw(player);
        window.display();
    }
}
