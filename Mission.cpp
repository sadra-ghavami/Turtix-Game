#include "Mission.hpp"
#include "Map.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>


Mission::Mission(std::string map_adrress, sf::RenderWindow *_window){
	this_map = new Map(map_adrress,_window);
	move = 0;
	window = _window;
}

void Mission::draw_frame(){
	this_map->draw_map_frame(WINDOW_X_SIZE, WINDOW_Y_SIZE, window, move);
}

void Mission::update_map_positions(int _move){
	move = _move;
	this_map->update_positions(move);
}