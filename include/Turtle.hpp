#ifndef TURTLE_HEADER_FILE
#define TURTLE_HEADER_FILE

#include "Constants.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Turtle{
public:
	Turtle(std::string picture_of_running_left);
	virtual sf::Sprite get_next_move_pic(int move);
	virtual void update_pos(int move);
	virtual int get_x(){return turtle_x;}
	virtual int get_y(){return turtle_y;}
	virtual int get_height(){return turtle_height;}
	virtual int get_head_y() {return turtle_y+(Const::Turtle::SIZE/2);}
	virtual int get_foot_y() {return turtle_y-(Const::Turtle::SIZE/2);}
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