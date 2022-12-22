#pragma once
#include<vector>

class TicTacState
{
    public:
        int row = 0;
        int col = 0;
        int score = 0;
};

class TicTac
{
public:
    int COMPLX_DEPTH = 100;

    void ai_play(char player_char,bool simple);
    void draw_board();

    bool place_char(int row, int col, char player_char, bool &error_bit);
    bool match_draw();
    bool player_won(char player_character);

private:
    int game_tree_depth;
 
    char reverse_player(char player);

    int ai_play(char player_char,int value, int depth, int alpha, int beta, bool isMax,std::vector<TicTacState>& immediate_children);
    int game_eval(char player);
    int place_char_at_score(char player,int score);

    char board[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
};
