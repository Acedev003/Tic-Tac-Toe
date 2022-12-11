#include <cstdio>

#include "tic_tac.hpp"
#include "../util/util.hpp"

void TicTac::draw_board()
{
    printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
}

void TicTac::ai_play(char player_char,char enemy_char,bool is_simple,bool isMax)
{

}


bool TicTac::place_char(int row,int col,char player_char,bool& error_bit)
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
