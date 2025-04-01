#include "Map.hpp"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>


void initialize_fields(sf::Sprite *normal_field, sf::Sprite *left_edge_field, sf::Sprite *right_edge_field, sf::Texture *green_field_texture){
	normal_field->setTexture(*green_field_texture);
	normal_field->setTextureRect(sf::IntRect(normal_field_start_x, normal_field_start_y, normal_field_lenght, normal_field_height));
	left_edge_field->setTexture(*green_field_texture);
	left_edge_field->setTextureRect(sf::IntRect(left_edge_start_x, left_edge_start_y, left_edge_lenght, left_edge_height));
	right_edge_field->setTexture(*green_field_texture);
    right_edge_field->setTextureRect(sf::IntRect(right_edge_start_x, right_edge_start_y, right_edge_lenght, right_edge_height));
}

Map::Map(std::string map_adrress, sf::RenderWindow *window){
	
	map_center_x = MIDDLE_LINE_NUM;
	map_center_y = START_LINE_NUM;
	for(int i=0 ; i<NUM_TURTLE_BABY ; i++){
		Turtle_baby* new_baby = new Turtle_baby(INITIAL_TURTLE_BABIES_X[i],INITIAL_TURTLE_BABIES_Y[i],INITIAL_TURTLE_BABIES_HEIGHT[i],INITIAL_TURTLE_BABIES_MOVE[i]);
		turtle_babies.push_back(new_baby);
	}
	turtle = new Turtle(LEFT_RUN_PIC_ADRRESS);
	std::ifstream map_file;
	map_file.open(map_adrress);
	std::string line;
	while(getline(map_file,line))
		line_code.push_back(line);
	map_file.close();

	green_field_texture = new sf::Texture;
    if (green_field_texture->loadFromFile(FIELD_PIC_ADRRESS)){
    	normal_field = new sf::Sprite;
    	left_edge_field = new sf::Sprite;
    	right_edge_field = new sf::Sprite;
	    initialize_fields(normal_field,left_edge_field,right_edge_field,green_field_texture);
    }
    gate_texture = new sf::Texture;
    if(gate_texture->loadFromFile(GATE_PIC_ADRRESS, sf::IntRect(GATE_PIC_START_X, GATE_PIC_START_Y, GATE_PIC_LENGHT, GATE_PIC_HEIGHT)))
    	for(int i=0 ; i<GATE_SLICE_NUM ; i++){
	    	sf::Sprite *new_gate_slice = new sf::Sprite;
	    	new_gate_slice->setTexture(*gate_texture);
	    	new_gate_slice->setTextureRect( sf::IntRect(i*SLICE_LENGHT, 0, SLICE_LENGHT, GATE_PIC_HEIGHT) );
	    	gate_slices.push_back(new_gate_slice);
    	}
}


void Map::update_positions(int move){

	if(turtle->get_foot_y() <= normal_field_height){
		// std::cout << turtle->get_foot_y() << std::endl;
		turtle->finish_jump();
	}

	turtle->update_pos(move);

	for(int i=0 ; i<NUM_TURTLE_BABY ;i++){
		turtle_babies[i]->check_is_baby_free(turtle);
		turtle_babies[i]->update_baby_pos();
	}

	if(turtle->get_x() >= MAP_LEFT_EDGE && turtle->get_x() <= MAP_RIGHT_EDGE){
		if(move == MOVE_LEFT)
			this->map_center_x--;
		else if(move == MOVE_RIGHT)
			this->map_center_x++;
	}

}


void Map::draw_slice_in_window(std::string line, sf::RenderWindow *window, int window_x_size, int window_y_size){
	int slice_num = 0;
	bool is_gate_drawable = true;
	for(int i=0 ; i<slice_sprite_num ; i++){
		sf::Sprite slice;
		if(line[i+map_center_x-slice_size] == '.' || line[i+map_center_x-slice_size] == '$' )
			slice = *normal_field;
		else if(line[i+map_center_x-slice_size] == '<')
			slice = *left_edge_field;
		else if(line[i+map_center_x-slice_size] == '>')
			slice = *right_edge_field;
		slice.setPosition(normal_field_lenght*i,window_y_size-normal_field_height);
		window->draw(slice);
		if(line[i+map_center_x-slice_size] == '$' ){
			if(slice_num == 0 && i == 0)
				is_gate_drawable = false;
			slice = *gate_slices[slice_num];
			if(is_gate_drawable){
				slice.setPosition(normal_field_lenght*i,window_y_size-GATE_DRAW_HEIGHT);
				window->draw(slice);
			}
			slice_num++;
			}
	}
	if(!is_gate_drawable)
		for(int i=0 ; i<slice_num ; i++){
			sf::Sprite gate_slice;
			gate_slice = *gate_slices[i+GATE_SLICE_NUM-slice_num] ;
			gate_slice.setPosition(SLICE_LENGHT*i,window_y_size-GATE_DRAW_HEIGHT);
			window->draw(gate_slice);
		}
}

void Map::draw_map_frame(int window_x_size, int window_y_size, sf::RenderWindow *window, int move){
	for(int j=0 ; j<line_code.size() ; j++){
		this->draw_slice_in_window(line_code[j],window,window_x_size,window_y_size);
		for(int i=0 ; i<NUM_TURTLE_BABY ; i++){
			sf::Sprite baby_turtle_run = turtle_babies[i]->get_baby_next_move_pic();
			baby_turtle_run.setPosition(normal_field_lenght*(turtle_babies[i]->get_x()-map_center_x+slice_size),window_y_size-turtle_babies[i]->get_y());
			window->draw(baby_turtle_run);
		}

		sf::Sprite turtle_run = turtle->get_next_move_pic(move);
		turtle_run.setPosition(normal_field_lenght*(turtle->get_x()-map_center_x+slice_size),window_y_size-turtle->get_y());
		window->draw(turtle_run);
	}
}

