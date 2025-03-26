#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * print_winner_symbol - Prints the winner's symbol in large format
 * @symbol: The winner's symbol (X or O)
 */
void print_winner_symbol(char symbol)
{
    if (symbol == 'X')
    {
        printf("\n");
        printf("X   X\n");
        printf(" X X \n");
        printf("  X  \n");
        printf(" X X \n");
        printf("X   X\n");
    }
    else if (symbol == 'O')
    {
        printf("\n");
        printf("  OOO  \n");
        printf(" O   O \n");
        printf(" O   O \n");
        printf(" O   O \n");
        printf("  OOO  \n");
    }
    printf("\n");
}

/**
 * display_logo - Displays the game logo and welcome message
 */
void display_logo(void)
{
    printf("\n");
    printf("  _    _       _     _             \n");
    printf(" | |  | |     | |   (_)            \n");
    printf(" | |__| |_   _| |__  _ _ __   __ _ \n");
    printf(" |  __  | | | | '_ \\| | '_ \\ / _` |\n");
    printf(" | |  | | |_| | | | | | | | | (_| |\n");
    printf(" |_|  |_|\\__,_|_| |_|_|_| |_|\\__, |\n");
    printf("                               __/ |\n");
    printf("                              |___/ \n");
    printf("\nWelcome to Holberton & Tuwaiq Tic-Tac-Toe! or XO\n\n");
    printf("  _______                   _     \n");
    printf(" |__   __|                 (_)    \n");
    printf("    | | ___ _ __ _ __  _   _ _ ___\n");
    printf("    | |/ _ \\ '__| '_ \\| | | | / __|\n");
    printf("    | |  __/ |  | | | | |_| | \\__ \\\n");
    printf("    |_|\\___|_|  |_| |_|\\__,_|_|___/\n");
    printf("\n\n");
}

/**
 * struct Player - Represents a player in the game
 * @name: Player's name
 * @symbol: Player's symbol (X or O)
 */
typedef struct Player
{
    char name[50];
    char symbol;
} Player;

/**
 * display_board - Displays the current game board
 * @board: 3x3 game board array
 */
void display_board(char board[3][3])
{
    int i, j;

    printf("\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---+---+---\n");
    }
    printf("\n");
}

/**
 * check_winner - Checks if a player has won
 * @board: 3x3 game board array
 * @symbol: Player's symbol to check
 *
 * Return: true if player has won, false otherwise
 */
bool check_winner(char board[3][3], char symbol)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
            return true;
    }

    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return true;

    return false;
}

/**
 * is_full - Checks if the board is full
 * @board: 3x3 game board array
 *
 * Return: true if board is full, false otherwise
 */
bool is_full(char board[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return false;
        }
    }
    return true;
}

/**
 * main - Entry point for the Tic-Tac-Toe game
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    Player players[2];
    int turn = 0, choice, row, col;
    bool winner_found = false;

    display_logo();

    if (argc > 2)
    {
        snprintf(players[0].name, 50, "%s", argv[1]);
        snprintf(players[1].name, 50, "%s", argv[2]);
    }
    else
    {
        snprintf(players[0].name, 50, "Player 1");
        snprintf(players[1].name, 50, "Player 2");
    }

    players[0].symbol = 'X';
    players[1].symbol = 'O';

    while (!winner_found && !is_full(board))
    {
        display_board(board);
        printf("%s's turn (%c). Enter a number (1-9): ", players[turn].name, players[turn].symbol);

        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 9)
        {
            printf("Invalid input. Please enter a number between 1 and 9.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (board[row][col] >= '1' && board[row][col] <= '9')
        {
            board[row][col] = players[turn].symbol;
            if (check_winner(board, players[turn].symbol))
            {
                display_board(board);
                printf("%s wins!\n", players[turn].name);
                print_winner_symbol(players[turn].symbol);
                winner_found = true;
            }
            else
            {
                turn = 1 - turn;
            }
        }
        else
        {
            printf("Invalid move. The cell is already occupied.\n");
        }
    }

    if (!winner_found)
    {
        display_board(board);
        printf("It's a draw!\n");
    }

    return (0);
}
