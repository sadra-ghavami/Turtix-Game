#include "Turtle_baby.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

Turtle_baby::Turtle_baby(int init_x, int init_y, int init_height, int init_move) : Turtle(Const::Pic_Addresses::TURTLE_BABY_LEFT_RUN_PIC_ADRRESS){
	initial_x = init_x;
	initial_y = init_y;
	initial_height = init_height;
	initial_move = init_move;
	is_free = false;
	turtle_in_bubble = new sf::Texture;
	turtle_in_bubble->loadFromFile(Const::Pic_Addresses::TURTLE_BABY_BUBBLE_PIC_ADRRESS);
	for(int j=0 ; j<Const::Turtle_Baby::BUBBLE_PIC_NUM_COL; j++)
		for(int i=0 ; i<Const::Turtle_Baby::BUBBLE_PIC_NUM_ROW ; i++){
			sf::Sprite *baby_in_bubble = new sf::Sprite;
			baby_in_bubble->setTexture(*turtle_in_bubble);
			baby_in_bubble->setTextureRect(sf::IntRect(Const::Turtle_Baby::BUBBLE_SIZE*i, Const::Turtle_Baby::BUBBLE_SIZE*j, Const::Turtle_Baby::BUBBLE_SIZE, Const::Turtle_Baby::BUBBLE_SIZE));
			initial_states.push_back(baby_in_bubble);
		}
	num_of_state = 0;
}

void Turtle_baby::update_baby_pos(){
	if(is_free){
		int move = 0;
		if(num_of_state%Const::Turtle_Baby::DELAY_FRAME == 0){
			move = initial_move;
		}
		num_of_state++;
		this->update_pos(move);
	}
	else{
		turtle_x = initial_x;
		turtle_y = initial_y;
		turtle_height = initial_height;
	}
}

sf::Sprite Turtle_baby::get_baby_next_move_pic(){
	if(!is_free){
		num_of_state++;
		if(num_of_state >= Const::Turtle_Baby::DELAY_FRAME*Const::Turtle_Baby::BUBBLE_PIC_TOTAL_NUM)
			num_of_state = 0;
		return *initial_states[num_of_state/Const::Turtle_Baby::DELAY_FRAME];
	}
	else{
		int move = 0;
		if(num_of_state%Const::Turtle_Baby::DELAY_FRAME == 0){
			move = initial_move;
		}
		return this->get_next_move_pic(move);
	}
}


void Turtle_baby::check_is_baby_free(Turtle* turtle){
	if(turtle_x == turtle->get_x() && turtle->check_is_turtle_jumping()){
		is_free = true;
		turtle_height = Const::Map::BASE_LEVEL_HEIGHT;
	}
}