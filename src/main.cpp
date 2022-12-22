#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>

#include "util/util.hpp"
#include "tic_tac/tic_tac.hpp"

int main(int argc,char **argv)
{
    const int SINGLEPLAYER = 1;
    const int DUALPLAYER   = 2;
    const int AI_SIMPLE    = 3;
    const int AI_DIFFICULT = 4;

    int game_mode;
    int ai_difficulty;

    bool game_over = false;
    bool singleplayer = false;
    
    char ai_player_code;

    time_t t;

    TicTac game;
    
    reset_screen();

    printf(" 1. SinglePlayer\n 2. TwoPlayer\n\n");
    printf("Enter Mode (1 or 2) : ");

    if(!read_int(game_mode))
    {
        fprintf(stderr,"Invalid Input Entered\n");
        return EXIT_FAILURE;
    }

    printf("\n");

    switch (game_mode)
    {
        case SINGLEPLAYER : singleplayer = true;
                            reset_screen();
                            
                            printf(" 1.Simple\n 2.Impossible\n\n");
                            printf("Enter Difficulty (1 or 2) : ");

                            if(!read_int(ai_difficulty))
                            {
                                fprintf(stderr,"Invalid Input Entered\n");
                                return EXIT_FAILURE;
                            }

                            printf("\n");
                            switch(ai_difficulty)
                            {
                                case 1 : ai_difficulty = AI_SIMPLE;
                                         break;
                                case 2 : ai_difficulty = AI_DIFFICULT;
                                         break;
                                default: printf("Unknown option detected. Assuming Simple difficulty level\n");
                                         ai_difficulty = AI_SIMPLE;
                                         press_enter_to_continue();
                                         break;
                            }
                            break;

        case DUALPLAYER : singleplayer = false;
                          break;
    
        default: printf("Unknown option detected. Assuming Twoplayer mode\n");
                 singleplayer = false;
                 press_enter_to_continue();
                 break;
    }


    reset_screen();
    
    printf("Mode       : %s\n",(singleplayer)?"SinglePlayer":"TwoPlayer");
    if(singleplayer)
    {
        srand( (unsigned) time(&t) );
        float rand_val = (double ) rand()/RAND_MAX;

        ai_player_code = (std::round(rand_val))?'X':'O';

        printf("Difficulty : %s\n",(ai_difficulty == AI_SIMPLE)?"Simple":"Impossible");
        printf("AI Player  : %c\n",ai_player_code);
    }
    
    printf("\n");
    press_enter_to_continue();

    int x,o;
    while(true)
    {
        reset_screen();
        game.draw_board();

        //Player X Input

        if(singleplayer && ai_player_code=='X')
        {
            game.ai_play('X',(ai_difficulty == AI_SIMPLE)?true:false);
        }
        else
        {
            bool valid_input = false;
            while(!valid_input)
            {
                printf("\n");
                printf("Player X Choice : ");
                if (!read_int(x))
                {
                    fprintf(stderr, "Invalid Input Entered\n");
                    continue;
                }

                switch(x)
                {
                    case 1: game.place_char(0,0,'X',valid_input); break;
                    case 2: game.place_char(0,1,'X',valid_input); break;
                    case 3: game.place_char(0,2,'X',valid_input); break;
                    case 4: game.place_char(1,0,'X',valid_input); break;
                    case 5: game.place_char(1,1,'X',valid_input); break;
                    case 6: game.place_char(1,2,'X',valid_input); break;
                    case 7: game.place_char(2,0,'X',valid_input); break;
                    case 8: game.place_char(2,1,'X',valid_input); break;
                    case 9: game.place_char(2,2,'X',valid_input); break;
                    
                    default:
                        std::cout<<"Invalid Input\n";
                        press_enter_to_continue();
                }

                if(!valid_input)
                {
                    reset_screen();
                    game.draw_board();
                }
            }
        }

        reset_screen();
        game.draw_board();

        if(game.player_won('X'))
        {
            printf("\n");
            printf("\n-----------------------------\n");
            printf("\nPlayer X wins\n");
            printf("\n-----------------------------\n");
            break;
        }

        if(game.match_draw())
        {
            printf("\n");
            printf("\n-----------------------------\n");
            printf("\nDraw Game.....\n");
            printf("\n-----------------------------\n");
            break;
        }

        //Player O Input

        if(singleplayer && ai_player_code=='O')
        {
            game.ai_play('O',(ai_difficulty == AI_SIMPLE)?true:false);
        }
        else
        {
            bool valid_input = false;
            while(!valid_input)
            {   
                printf("\n");
                printf("Player O Choice : ");
                if (!read_int(o))
                {
                    fprintf(stderr, "Invalid Input Entered\n");
                    continue;
                }

                switch(o)
                {
                    case 1: game.place_char(0,0,'O',valid_input); break;
                    case 2: game.place_char(0,1,'O',valid_input); break;
                    case 3: game.place_char(0,2,'O',valid_input); break;
                    case 4: game.place_char(1,0,'O',valid_input); break;
                    case 5: game.place_char(1,1,'O',valid_input); break;
                    case 6: game.place_char(1,2,'O',valid_input); break;
                    case 7: game.place_char(2,0,'O',valid_input); break;
                    case 8: game.place_char(2,1,'O',valid_input); break;
                    case 9: game.place_char(2,2,'O',valid_input); break;
                    
                    default:
                        std::cout<<"Invalid Input\n";
                        press_enter_to_continue();
                }

                if(!valid_input)
                {
                    reset_screen();
                    game.draw_board();
                }
            }
        }

        reset_screen();
        game.draw_board();

        if(game.player_won('O'))
        {
            printf("\n");
            printf("\n-----------------------------\n");
            printf("\nPlayer O wins\n");
            printf("\n-----------------------------\n");
            break;
        }

        if(game.match_draw())
        {
            printf("\n");
            printf("\n-----------------------------\n");
            printf("\nDraw Game.....\n");
            printf("\n-----------------------------\n");
            break;
        }

    }

    printf("\n");
    return EXIT_SUCCESS;   
}