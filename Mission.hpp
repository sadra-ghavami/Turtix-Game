#ifndef MISSION_HEADER_FILE
#define MISSION_HEADER_FILE

#include "Map.hpp"
#include <SFML/Graphics.hpp>
#include <string>
const int WINDOW_X_SIZE = 1025;
const int WINDOW_Y_SIZE = 600;


class Mission {
public:
	Mission(std::string map_adrress, sf::RenderWindow *_window);
	void draw_frame();
	void update_map_positions(int move);
protected:
	int move;
	Map* this_map;
	sf::RenderWindow *window;
};




#endif