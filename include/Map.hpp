#ifndef MAP_HEADER_FILE
#define MAP_HEADER_FILE

#include "Turtle.hpp"
#include "Turtle_baby.hpp"
#include "Constants.hpp"
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

class Map{
public:
	Map(std::string map_adrress, sf::RenderWindow *window);
	void update_positions(int move);
	void draw_map_frame(int window_x_size, int window_y_size, sf::RenderWindow* window, int move);

protected:
	std::vector<std::string>line_code;
	Turtle* turtle;
	std::vector<Turtle_baby*> turtle_babies;
	sf::Texture *green_field_texture;
	sf::Texture *gate_texture;
	sf::Sprite *normal_field;
	sf::Sprite *left_edge_field;
	sf::Sprite *right_edge_field;
	std::vector<sf::Sprite*>gate_slices;


	int map_center_x;
	int map_center_y;

	void draw_slice_in_window(std::string line, sf::RenderWindow *window, int window_x_size, int window_y_size);
};



#endif