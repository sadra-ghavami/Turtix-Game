#include "Map.hpp"

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>


void initialize_fields(sf::Sprite *normal_field, sf::Sprite *left_edge_field, sf::Sprite *right_edge_field, sf::Texture *green_field_texture){
	normal_field->setTexture(*green_field_texture);
	normal_field->setTextureRect(sf::IntRect(Const::Field::PIC_NORMAL_FIELD_START_X, Const::Field::PIC_NORMAL_FIELD_START_Y, Const::Field::PIC_NORMAL_FIELD_LENGHT, Const::Field::PIC_NORMAL_FIELD_HEIGHT));
	left_edge_field->setTexture(*green_field_texture);
	left_edge_field->setTextureRect(sf::IntRect(Const::Field::PIC_LEFT_EDGE_START_X, Const::Field::PIC_LEFT_EDGE_START_Y, Const::Field::PIC_LEFT_EDGE_LENGHT, Const::Field::PIC_LEFT_EDGE_HEIGHT));
	right_edge_field->setTexture(*green_field_texture);
    right_edge_field->setTextureRect(sf::IntRect(Const::Field::PIC_RIGHT_EDGE_START_X, Const::Field::PIC_RIGHT_EDGE_START_Y, Const::Field::PIC_RIGHT_EDGE_LENGHT, Const::Field::PIC_RIGHT_EDGE_HEIGHT));
}

Map::Map(std::string map_adrress, sf::RenderWindow *window){
	
	map_center_x = Const::Map::MIDDLE_LINE_NUM;
	map_center_y = Const::Map::START_LINE_NUM;
	for(int i=0 ; i<Const::Turtle_Baby::NUM ; i++){
		Turtle_baby* new_baby = new Turtle_baby(Const::Turtle_Baby::INITIAL_X[i], Const::Turtle_Baby::INITIAL_Y[i], Const::Turtle_Baby::INITIAL_HEIGHT[i], Const::Turtle_Baby::INITIAL_MOVE[i]);
		turtle_babies.push_back(new_baby);
	}
	turtle = new Turtle(Const::Pic_Addresses::LEFT_RUN_PIC_ADDRESS);
	std::ifstream map_file;
	map_file.open(map_adrress);
	std::string line;
	while(getline(map_file,line))
		line_code.push_back(line);
	map_file.close();

	green_field_texture = new sf::Texture;
    if (green_field_texture->loadFromFile(Const::Pic_Addresses::FIELD_PIC_ADDRESS)){
    	normal_field = new sf::Sprite;
    	left_edge_field = new sf::Sprite;
    	right_edge_field = new sf::Sprite;
	    initialize_fields(normal_field, left_edge_field, right_edge_field, green_field_texture);
    }
    gate_texture = new sf::Texture;
    if(gate_texture->loadFromFile(Const::Pic_Addresses::GATE_PIC_ADDRESS, sf::IntRect(Const::Gate::PIC_START_X, Const::Gate::PIC_START_Y, Const::Gate::PIC_LENGHT, Const::Gate::PIC_HEIGHT)))
    	for(int i=0 ; i < Const::Gate::SLICE_NUM ; i++){
	    	sf::Sprite *new_gate_slice = new sf::Sprite;
	    	new_gate_slice->setTexture(*gate_texture);
	    	new_gate_slice->setTextureRect( sf::IntRect(i*Const::Map::SLICE_LENGHT, 0, Const::Map::SLICE_LENGHT, Const::Gate::PIC_HEIGHT) );
	    	gate_slices.push_back(new_gate_slice);
    	}
}


void Map::update_positions(int move){

	if(turtle->get_foot_y() <= Const::Field::PIC_NORMAL_FIELD_HEIGHT){
		// std::cout << turtle->get_foot_y() << std::endl;
		turtle->finish_jump();
	}

	turtle->update_pos(move);

	for(int i=0 ; i<Const::Turtle_Baby::NUM ;i++){
		turtle_babies[i]->check_is_baby_free(turtle);
		turtle_babies[i]->update_baby_pos();
	}

	if(turtle->get_x() >= Const::Map::LEFT_EDGE && turtle->get_x() <= Const::Map::RIGHT_EDGE){
		if(move == Const::Move::LEFT)
			this->map_center_x--;
		else if(move == Const::Move::RIGHT)
			this->map_center_x++;
	}

}


void Map::draw_slice_in_window(std::string line, sf::RenderWindow *window, int window_x_size, int window_y_size){
	int slice_num = 0;
	bool is_gate_drawable = true;
	for(int i=0 ; i < Const::Map::SLICE_SPRITE_NUM ; i++){
		sf::Sprite slice;
		if(line[i+map_center_x-Const::Map::SLICE_SIZE] == '.' || line[i+map_center_x-Const::Map::SLICE_SIZE] == '$' )
			slice = *normal_field;
		else if(line[i+map_center_x-Const::Map::SLICE_SIZE] == '<')
			slice = *left_edge_field;
		else if(line[i+map_center_x-Const::Map::SLICE_SIZE] == '>')
			slice = *right_edge_field;
		slice.setPosition(Const::Field::PIC_NORMAL_FIELD_LENGHT*i, window_y_size - Const::Field::PIC_NORMAL_FIELD_HEIGHT);
		window->draw(slice);
		if(line[i+map_center_x-Const::Map::SLICE_SIZE] == '$' ){
			if(slice_num == 0 && i == 0)
				is_gate_drawable = false;
			slice = *gate_slices[slice_num];
			if(is_gate_drawable){
				slice.setPosition(Const::Field::PIC_NORMAL_FIELD_LENGHT*i,Const::Window::Y_SIZE - Const::Gate::DRAW_HEIGHT);
				window->draw(slice);
			}
			slice_num++;
			}
	}
	if(!is_gate_drawable)
		for(int i=0 ; i<slice_num ; i++){
			sf::Sprite gate_slice;
			gate_slice = *gate_slices[i + Const::Gate::SLICE_NUM - slice_num] ;
			gate_slice.setPosition(Const::Map::SLICE_LENGHT*i, Const::Window::Y_SIZE - Const::Gate::DRAW_HEIGHT);
			window->draw(gate_slice);
		}
}

void Map::draw_map_frame(int window_x_size, int window_y_size, sf::RenderWindow *window, int move){
	for(int j=0 ; j<line_code.size() ; j++){
		this->draw_slice_in_window(line_code[j], window, window_x_size, window_y_size);
		for(int i=0 ; i<Const::Turtle_Baby::NUM ; i++){
			sf::Sprite baby_turtle_run = turtle_babies[i]->get_baby_next_move_pic();
			baby_turtle_run.setPosition(Const::Field::PIC_NORMAL_FIELD_LENGHT*(turtle_babies[i]->get_x()-map_center_x+Const::Map::SLICE_SIZE),window_y_size-turtle_babies[i]->get_y());
			window->draw(baby_turtle_run);
		}

		sf::Sprite turtle_run = turtle->get_next_move_pic(move);
		turtle_run.setPosition(Const::Field::PIC_NORMAL_FIELD_LENGHT*(turtle->get_x() - map_center_x + Const::Map::SLICE_SIZE), window_y_size - turtle->get_y());
		window->draw(turtle_run);
	}
}

