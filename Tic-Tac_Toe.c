#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display the board
void displayBoard()
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Check whether a player has won
int checkWinner()
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main()
{
    int choice;
    int row, col;
    char player = 'X';

    for (int turn = 0; turn < 9; turn++)
    {
        displayBoard();

        printf("Player %c, enter a number (1-9): ", player);
        scanf("%d", &choice);

        // Convert number into row and column
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if the position is valid
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("Invalid move! Try again.\n");
            turn--;
            continue;
        }

        board[row][col] = player;

        // Check winner
        if (checkWinner())
        {
            displayBoard();
            printf("Player %c wins! Congrats\n", player);
            return 0;
        }

        // Change player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    displayBoard();
    printf("It's a draw!\n");

    return 0;
}