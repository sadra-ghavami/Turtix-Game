#ifndef TURTLE_BABY_HEADER_FILE
#define TURTLE_BABY_HEADER_FILE

#include "Turtle.hpp"
#include "Constants.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

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