#ifndef CONSTANTS_HEADER_FILE
#define CONSTANTS_HEADER_FILE

#include <string>
#include <vector>

namespace Const {
    
    namespace Map {
        constexpr int SLICE_SPRITE_NUM = 41;
        constexpr int SLICE_SIZE = (Const::Map::SLICE_SPRITE_NUM-1)/2;
        constexpr int SLICE_LENGHT = 25;
        constexpr int MIDDLE_LINE_NUM = 52;
        constexpr int START_LINE_NUM = 200;
        constexpr int LEFT_EDGE = 10;
        constexpr int RIGHT_EDGE = 94;
        constexpr int BASE_LEVEL_HEIGHT = 50;
        constexpr int LEFT_BOUNDRY = -1;
        constexpr int RIGHT_BOUNDRY = 103;
    }


    namespace Move {
        constexpr int NONE = 0;
        constexpr int UP = 1;
        constexpr int DOWN = 2;
        constexpr int RIGHT = 3;
        constexpr int LEFT = 4;
    }

    namespace Window {
        constexpr int X_SIZE = 1026;
        constexpr int Y_SIZE = 600;
    }

    namespace Pic_Addresses {
        const std::string LEFT_RUN_PIC_ADDRESS = "Picture/Turtle_Left_move.png";
        const std::string FIELD_PIC_ADDRESS = "Picture/D NB No Shadows.png";
        const std::string GATE_PIC_ADDRESS = "Picture/Gate.png";
        const std::string TURTLE_BABY_LEFT_RUN_PIC_ADRRESS = "Picture/turtle_baby_left_move.png";
        const std::string TURTLE_BABY_BUBBLE_PIC_ADRRESS = "Picture/turtle_baby_bubble.png";
    }
    
    namespace Gate {
        constexpr int PIC_START_X = 95;
        constexpr int PIC_LENGHT = 225;
        constexpr int PIC_START_Y = 30;
        constexpr int PIC_HEIGHT = 160;
        constexpr int DRAW_HEIGHT = 220;
        constexpr int SLICE_NUM = Const::Gate::PIC_LENGHT/Const::Map::SLICE_LENGHT;
    }

    namespace Turtle {
        constexpr int SIZE = 100;
        constexpr int RUNNING_PIC_NUM_ROW = 6;
        constexpr int RUNNING_PIC_NUM_COL = 3;
        constexpr int RUNNING_PIC_LAST_ROW_NUM = 4;
        constexpr int RUNNING_PIC_TOTAL_NUM = 16;
        constexpr int JUMP_MAX_HEIGHT = 200;
        constexpr int EACH_FRAME_JUMP_HEIGHT = 4;
        constexpr int MAX_FRAME_WITHOUT_ACTIVITY = 10;
    }

    namespace Turtle_Baby {
        constexpr int BUBBLE_PIC_NUM_ROW = 5;
        constexpr int BUBBLE_PIC_NUM_COL = 2;
        constexpr int BUBBLE_PIC_TOTAL_NUM = 10;
        constexpr int BUBBLE_SIZE = 150;
        constexpr int DELAY_FRAME = 7;

        constexpr int NUM = 1;
        const std::vector<int> INITIAL_X = {20};
        const std::vector<int> INITIAL_Y = {0};
        const std::vector<int> INITIAL_HEIGHT = {150};
        const std::vector<int> INITIAL_MOVE = {Const::Move::RIGHT};
    }

    namespace Field {
        constexpr int PIC_NORMAL_FIELD_START_X = 50;
        constexpr int PIC_NORMAL_FIELD_START_Y = 0;
        constexpr int PIC_NORMAL_FIELD_LENGHT  = 25;
        constexpr int PIC_NORMAL_FIELD_HEIGHT  = 150;

        constexpr int PIC_LEFT_EDGE_START_X = 0;
        constexpr int PIC_LEFT_EDGE_START_Y = 0;
        constexpr int PIC_LEFT_EDGE_LENGHT  = 25;
        constexpr int PIC_LEFT_EDGE_HEIGHT  = 150;

        constexpr int PIC_RIGHT_EDGE_START_X = 275;
        constexpr int PIC_RIGHT_EDGE_START_Y = 0;
        constexpr int PIC_RIGHT_EDGE_LENGHT  = 25;
        constexpr int PIC_RIGHT_EDGE_HEIGHT  = 150;
    }
}



#endif