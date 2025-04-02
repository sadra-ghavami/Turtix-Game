#include <SFML/Graphics.hpp>
#include "Mission.hpp"
#include "Constants.hpp"

#include <string>
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1025, 600), "game");
    Mission *first_mission = new Mission("Maps/map1.txt",&window);
    while (window.isOpen())
      {
        sf::Event event;
        int move = Const::Move::NONE;
        while (window.pollEvent(event))
        {
            switch(event.type){
            case sf::Event::Closed :
                window.close();
                break;
            case sf::Event::KeyPressed :
                if(event.key.code == sf::Keyboard::A)
                    move = Const::Move::LEFT;
                else if(event.key.code == sf::Keyboard::D)
                    move = Const::Move::RIGHT;
                else if(event.key.code == sf::Keyboard::W)
                    move = Const::Move::UP;
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
