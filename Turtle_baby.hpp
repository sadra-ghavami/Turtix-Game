#ifndef TURTLE_BABY_HEADER_FILE
#define TURTLE_BABY_HEADER_FILE

#include "Turtle.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

const std::string TURTLE_BABY_LEFT_RUN_PIC_ADRRESS = "Picture/turtle_baby_left_move.png";
const std::string TURTLE_BABY_BUBBLE_PIC_ADRRESS = "Picture/turtle_baby_bubble.png";
const int BUBBLE_IN_ROW = 5;
const int BUBBLE_IN_COL = 2;
const int BUBBLE_NUM = BUBBLE_IN_COL*BUBBLE_IN_ROW;
const int BUBBLE_SIZE = 150;
const int DELAY_FRAME = 7;

class Turtle_baby : public Turtle{
public:
	Turtle_baby(int init_x, int init_y, int init_height, int init_move);
	void update_baby_pos();
	virtual sf::Sprite get_baby_next_move_pic();
	void check_is_baby_free(Turtle* turtle);
protected:
	int initial_x;
	int initial_y;
	int initial_height;
	int initial_move;
	bool is_free;
	std::vector<sf::Sprite*> initial_states;
	int num_of_state;
	sf::Texture *turtle_in_bubble;
};


#endif