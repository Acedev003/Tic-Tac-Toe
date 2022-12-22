#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#include "tic_tac.hpp"
#include "../util/util.hpp"

bool TicTac::place_char(int row, int col, char player_char, bool &error_bit)
{
    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        printf("Value already entered\n");
        press_enter_to_continue();
        error_bit = false;
        return false;
    }
    else
    {
        board[row][col] = player_char;
    }
    error_bit = true;
    return true;
}

bool TicTac::match_draw()
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X' || board[i][j] == 'O')
            {
                count++;
            }
        }
    }

    if (count == 9)
    {
        return true;
    }

    return false;
}

bool TicTac::player_won(char player_code)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player_code && board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return true;
        }

        if (board[0][i] == player_code && board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return true;
        }
    }

    if (board[0][0] == player_code && board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return true;
    }

    if (board[0][2] == player_code && board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return true;
    }

    return false;
}

void TicTac::draw_board()
{
    printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
}

void TicTac::ai_play(char player_char,bool simple)
{
    TicTacState state;
    this->game_tree_depth = ((simple)?2:100);
    std::vector<TicTacState> immediate_children;
    int val = ai_play(player_char,(int) -INFINITY,game_tree_depth,(int) -INFINITY,(int) +INFINITY,true,immediate_children);
    for(auto a : immediate_children)
    {
        if(a.score == val)
        {
            bool error;
            place_char(a.row,a.col,player_char,error);
            break;
        }
    }
}

int TicTac::ai_play(char player_char,int value, int depth, int alpha, int beta, bool isMax,std::vector<TicTacState>& immediate_children)
{
    logging("AI Function called");
    if(player_won(player_char))
    {
        logging("Player wins");
        return 10;
    }

    if(player_won(reverse_player(player_char)))
    {
        logging("Enemy wins");
        return -10;
    }

    if(match_draw())
    {
        logging("Draw match");
        return 0;
    }


    logging("Depth " + std::to_string(depth));
    if(depth == 0)
    {
        return -1;
    }

    if(isMax)
    {
        int val    =  (int) -INFINITY;
        logging("Maximizing Player " + std::string(1,player_char));
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] != 'X' && board[i][j] != 'O')
                {
                    logging("Child found at " + std::to_string(i) + "," + std::to_string(j));
                    char tmp    = board[i][j];
                    board[i][j] = player_char;
                    int tmpval  = ai_play(player_char,val,depth-1,alpha,beta,false,immediate_children);
                    board[i][j] = tmp;

                    val   = std::max(val,tmpval);
                    alpha = std::max(alpha,tmpval);
                    if(alpha >= beta)
                    {
                        break;
                    }
                    
                    if(depth == this->game_tree_depth)
                    {
                        TicTacState state;
                        state.row = i;
                        state.col = j;
                        state.score = val;

                        immediate_children.push_back(state);
                    }
                }
            }
        }
        return val;
    }
    else
    {
        int val    =  (int) +INFINITY;
        logging("Minimizing Player " + std::string(1,player_char));
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] != 'X' && board[i][j] != 'O')
                {
                    logging("Child found at " + std::to_string(i) + "," + std::to_string(j));
                    char tmp    = board[i][j];
                    board[i][j] = player_char;
                    int tmpval  = ai_play(player_char,val,depth-1,alpha,beta,true,immediate_children);
                    board[i][j] = tmp;

                    val   = std::min(val,tmpval);
                    alpha = std::min(beta,tmpval);
                    if(alpha >= beta)
                    {
                        break;
                    }
                }
            }
        }
        return val;
    }

    return 0;
}

char TicTac::reverse_player(char player)
{
    return (player == 'X')?'O':'X';
}