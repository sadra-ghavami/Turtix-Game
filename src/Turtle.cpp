#include "Turtle.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

Turtle::Turtle(std::string picture_of_running_left){
	turtle_x = MIDDLE_LINE_NUM;
	turtle_y = START_LINE_NUM;
	turtle_height = BASE_LEVEL_HEIGHT;
	is_turtle_rising = false;
	is_turtle_falling = false;

	previous_move = NO_MOVE;
	num_left_picture = 0;
	num_right_picture = 0;
	frame_without_keypress = 0;
	run_pictures = new sf::Texture;
    run_pictures->loadFromFile(picture_of_running_left);
    no_move_left = new sf::Sprite;
    no_move_left->setTexture(*run_pictures);
    no_move_left->setTextureRect(sf::IntRect(0,0,TURTLE_SIZE,TURTLE_SIZE));
    last_move = no_move_left;
    no_move_right = new sf::Sprite;
    *no_move_right = *no_move_left;
 	no_move_right->setTextureRect(sf::IntRect(TURTLE_SIZE,0,-TURTLE_SIZE,TURTLE_SIZE));
    for(int j=0 ; j<TURTLE_NUM_IN_COL ; j++){
    	int row_turtle_num = TURTLE_NUM_IN_ROW;
    	if(j == TURTLE_NUM_IN_COL-1)
    		row_turtle_num = LAST_ROW_TURTLE_NUM;
    	for(int i=0 ; i<row_turtle_num ; i++){
    		sf::Sprite *left_running_turtle = new sf::Sprite;
    		left_running_turtle->setTexture(*run_pictures);
    		left_running_turtle->setTextureRect(sf::IntRect(TURTLE_SIZE*i,TURTLE_SIZE*j,TURTLE_SIZE,TURTLE_SIZE));
    		left_running.push_back(left_running_turtle);
    		sf::Sprite *right_running_turtle = new sf::Sprite;
    		*right_running_turtle = *left_running_turtle;
    		right_running_turtle->setTextureRect(sf::IntRect(TURTLE_SIZE*(i+1),TURTLE_SIZE*j,-TURTLE_SIZE,TURTLE_SIZE));
    		right_running.push_back(right_running_turtle);
   		}
   	}
    
}


sf::Sprite Turtle::get_next_move_pic(int move){
	if(move == NO_MOVE){
		frame_without_keypress++;
		if(frame_without_keypress >= MAX_FRAME_WITHOUT_ACTIVITY && num_right_picture == 0){
			last_move = no_move_left;
			frame_without_keypress = 0;
		}
		else if(frame_without_keypress >= MAX_FRAME_WITHOUT_ACTIVITY && num_left_picture == 0){
			last_move = no_move_right;
			frame_without_keypress = 0;
		}
		return *last_move;
	}
	else if(move == MOVE_LEFT){
		frame_without_keypress = 0;
		num_right_picture = 0;
		num_left_picture++;
		if(num_left_picture >= TURTLE_NUM_IN_PIC)
			num_left_picture = 0;
		last_move = left_running[num_left_picture];
		return *left_running[num_left_picture];
	}
	else if(move == MOVE_RIGHT){
		frame_without_keypress = 0;
		num_left_picture = 0;
		num_right_picture++;
		if(num_right_picture >= TURTLE_NUM_IN_PIC)
			num_right_picture = 0;
		last_move = right_running[num_right_picture];
		return *right_running[num_right_picture];
	}
	return *last_move;
}


void Turtle::update_horizontal_pos(int move){
	if(move == MOVE_LEFT)
		turtle_x--;
	else if(move == MOVE_RIGHT)
		turtle_x++;

}

void Turtle::update_vertical_pos(int move){
	if(is_turtle_rising){
		turtle_height += EACH_FRAME_JUMP_HEIGHT;
		turtle_y += EACH_FRAME_JUMP_HEIGHT;
		if(turtle_height >= JUMP_MAX_HEIGHT+BASE_LEVEL_HEIGHT){
			is_turtle_rising = false;
			is_turtle_falling = true;
		}
	}
	else if(is_turtle_falling){
		turtle_height -= EACH_FRAME_JUMP_HEIGHT;
		turtle_y -= EACH_FRAME_JUMP_HEIGHT;

		// if(turtle_height == BASE_LEVEL_HEIGHT){
		// 	is_turtle_falling = false;
		// 	is_turtle_rising = false;
		// }
	}
	else if(move == MOVE_UP) {
		is_turtle_rising = true;
		is_turtle_falling = false;
		turtle_height += EACH_FRAME_JUMP_HEIGHT;
		turtle_y += EACH_FRAME_JUMP_HEIGHT;
	}
}

void Turtle::update_pos(int move){
	update_horizontal_pos(move);
	check_turtle_is_falling(MAP_LEFT_BOUNDRY,MAP_RIGHT_BOUNDRY);
	update_vertical_pos(move);
}

void Turtle::check_turtle_is_falling(int left_boundry, int right_boundry){
	if(turtle_x > right_boundry || turtle_x < left_boundry){
		is_turtle_falling = true;
		is_turtle_rising = false;
	}
	
}

void Turtle::finish_jump() {
	is_turtle_falling = false;
	is_turtle_rising = false;
}