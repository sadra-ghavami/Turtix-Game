#ifndef TURTLE_HEADER_FILE
#define TURTLE_HEADER_FILE

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

#ifndef BASICS_CONSTANTS
#define BASICS_CONSTANTS
const int slice_sprite_num = 41;
const int slice_size = (slice_sprite_num-1)/2;
const int MIDDLE_LINE_NUM = 52;
const int START_LINE_NUM = 200;
const int MAP_LEFT_EDGE = 10;
const int MAP_RIGHT_EDGE = 94;
const int BASE_LEVEL_HEIGHT = 50;
const int MAP_LEFT_BOUNDRY = -1;
const int MAP_RIGHT_BOUNDRY = 103;
#endif

const int TURTLE_SIZE = 100;
const int TURTLE_NUM_IN_ROW = 6;
const int TURTLE_NUM_IN_COL = 3;
const int LAST_ROW_TURTLE_NUM = 4;
const int TURTLE_NUM_IN_PIC = 16;
const int JUMP_MAX_HEIGHT = 200;
const int EACH_FRAME_JUMP_HEIGHT = 4;


const int MAX_FRAME_WITHOUT_ACTIVITY = 10;

class Turtle{
public:
	Turtle(std::string picture_of_running_left);
	virtual sf::Sprite get_next_move_pic(int move);
	virtual void update_pos(int move);
	virtual int get_x(){return turtle_x;}
	virtual int get_y(){return turtle_y;}
	virtual int get_height(){return turtle_height;}
	virtual int get_head_y() {return turtle_y+(TURTLE_SIZE/2);}
	virtual int get_foot_y() {return turtle_y-(TURTLE_SIZE/2);}
	bool check_is_turtle_jumping(){return is_turtle_rising||is_turtle_falling;}
	void finish_jump();

protected:
	int turtle_x;
	int turtle_y;
	int turtle_height;
	bool is_turtle_rising;
	bool is_turtle_falling;
	int previous_move;
	sf::Texture* run_pictures;
	sf::Sprite* no_move_left;
	sf::Sprite* no_move_right;
	int frame_without_keypress;
	sf::Sprite* last_move;
	std::vector<sf::Sprite*>left_running;
	int num_left_picture;
	std::vector<sf::Sprite*>right_running;
	int num_right_picture;

	void update_vertical_pos(int move);
	void update_horizontal_pos(int move);
	void check_turtle_is_falling(int left_boundry, int right_boundry);
};




#endif