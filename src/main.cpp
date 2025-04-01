#include <SFML/Graphics.hpp>
#include "Mission.hpp"
#include <string>
#include <iostream>

#ifndef MOVE_CONSTANTS
#define MOVE_CONSTANTS
const int NO_MOVE = 0;
const int MOVE_UP = 1;
const int MOVE_DOWN = 2;
const int MOVE_RIGHT = 3;
const int MOVE_LEFT = 4;
#endif

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1025, 600), "game");
    Mission *first_mission = new Mission("Maps/map1.txt",&window);
    while (window.isOpen())
      {
        sf::Event event;
        int move = NO_MOVE;
        while (window.pollEvent(event))
        {
            switch(event.type){
            case sf::Event::Closed :
                window.close();
                break;
            case sf::Event::KeyPressed :
                if(event.key.code == sf::Keyboard::A)
                    move = MOVE_LEFT;
                else if(event.key.code == sf::Keyboard::D)
                    move = MOVE_RIGHT;
                else if(event.key.code == sf::Keyboard::W)
                    move = MOVE_UP;
                break;
            default :
                break;
            }
        }

        window.clear(sf::Color::Black);
        first_mission->update_map_positions(move);
        first_mission->draw_frame();
        window.display();
    }

    return 0;
}
