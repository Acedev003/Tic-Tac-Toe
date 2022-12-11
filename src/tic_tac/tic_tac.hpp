#pragma once


class TicTac
{  
    public:
        void draw_board();
        void ai_play(char player_char,char enemy_char,bool is_simple,bool isMax=true);

        bool place_char(int row,int col,char player_char,bool& error_bit);
        bool match_draw();
        bool player_won(char player_character);
    private:
        class TicTacState
        {
            int row;
            int col;
            int score;
        };
        
        TicTacState minimax(int depth,int alpha,int beta,bool isMax);


        int  simple_depth  = 2;
        int  complex_depth = 10;

        char board[3][3] = {'1','2','3','4','5','6','7','8','9'};
};
