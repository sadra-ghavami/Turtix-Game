#ifndef MAP_HEADER_FILE
#define MAP_HEADER_FILE

#include "Turtle.hpp"
#include "Turtle_baby.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#ifndef MOVE_CONSTANTS
#define MOVE_CONSTANTS
const int NO_MOVE = 0;
const int MOVE_UP = 1;
const int MOVE_DOWN = 2;
const int MOVE_RIGHT = 3;
const int MOVE_LEFT = 4;
#endif

const std::string LEFT_RUN_PIC_ADRRESS = "Picture/Turtle_Left_move.png";
const std::string FIELD_PIC_ADRRESS = "Picture/D NB No Shadows.png";
const std::string GATE_PIC_ADRRESS = "Picture/Gate.png";

const int SLICE_LENGHT = 25;
const int GATE_PIC_START_X = 95;
const int GATE_PIC_LENGHT = 225;
const int GATE_PIC_START_Y = 30;
const int GATE_PIC_HEIGHT = 160;
const int GATE_DRAW_HEIGHT = 220;
const int GATE_SLICE_NUM = GATE_PIC_LENGHT/SLICE_LENGHT;

const int normal_field_start_x = 50;
const int normal_field_start_y = 0;
const int normal_field_lenght = 25;
const int normal_field_height = 150;

const int left_edge_start_x = 0;
const int left_edge_start_y = 0;
const int left_edge_lenght = 25;
const int left_edge_height = 150;

const int right_edge_start_x = 275;
const int right_edge_start_y = 0;
const int right_edge_lenght = 25;
const int right_edge_height = 150;

const int NUM_TURTLE_BABY = 1;
const std::vector<int> INITIAL_TURTLE_BABIES_X = {20};
const std::vector<int> INITIAL_TURTLE_BABIES_Y = {0};
const std::vector<int> INITIAL_TURTLE_BABIES_HEIGHT = {150};
const std::vector<int> INITIAL_TURTLE_BABIES_MOVE = {MOVE_RIGHT};

#ifndef BASICS_CONSTANTS
#define BASICS_CONSTANTS
const int slice_sprite_num = 41;
const int slice_size = (slice_sprite_num-1)/2;
const int MIDDLE_LINE_NUM = 52;
const int START_LINE_NUM = 0;
const int MAP_LEFT_EDGE = 10;
const int MAP_RIGHT_EDGE = 94;
const int BASE_LEVEL_HEIGHT = 50;
#endif



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