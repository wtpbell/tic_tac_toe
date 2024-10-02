#include <iostream>
#include <vector>

void welcome()
{
    std::cout << "============================\n";
    std::cout << "Welcome to Tic-Tac-Toe Game!\n";
    std::cout << "============================\n";
}

void grid(std::vector<char> &fill)
{

    std::cout << "     |     |     \n";
    std::cout << "  " << fill[0] << "  |  " << fill[1] << "  |  " << fill[2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << fill[3] << "  |  " << fill[4] << "  |  " << fill[5] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << fill[6] << "  |  " << fill[7] << "  |  " << fill[8] << "  \n";
    std::cout << "     |     |     \n";
}

bool check_win(std::vector<char> &fill, char player_a, bool &is_win)
{

    // check rows
    for (int i = 0; i < 7; i += 3)
    {
        if (fill[i] == fill[i + 1] && fill[i + 1] == fill[i + 2])
        {
            is_win = true;
            std::cout << "The winner is player " << (fill[i] == player_a ? 'A' : 'B') << "\n";
            return true;
        }
    }

    // check cols
    for (int i = 0; i < 3; i++)
    {
        if (fill[i] == fill[i + 3] && fill[i + 3] == fill[i + 6])
        {
            is_win = true;
            std::cout << "The winner is player " << (fill[i] == player_a ? 'A' : 'B') << "\n";
            return true;
        }
    }

    // Check diagonals
    if (fill[0] == fill[4] && fill[4] == fill[8])
    {
        is_win = true;
        std::cout << "The winner is player " << (fill[0] == player_a ? 'A' : 'B') << "\n";
        return true;
    }
    if (fill[2] == fill[4] && fill[4] == fill[6])
    {
        is_win = true;
        std::cout << "The winner is player " << (fill[2] == player_a ? 'A' : 'B') << "\n";
        return true;
    }

    return false;
}

bool check_draw(std::vector<char> &fill)
{
    for (int i = 0; i < fill.size(); i++)
    {
        if (fill[i] != 'X' && fill[i] != 'O')
            return false;
    }
    return true;
}

void make_move(std::vector<char> &fill, char player_a, char player_b, bool &is_win)
{
    char input;
    int moveCount = 0; // Track the number of moves

    while (!is_win)
    {
        // Determine current player based on move count
        char current_player = (moveCount % 2 == 0) ? 'A' : 'B';
        std::cout << "Player " << current_player << ", please choose a number from 1 to 9: ";
        std::cin >> input;

        bool validMove = false;
        for (int i = 0; i < fill.size(); i++)
        {
            if (input == fill[i])
            {
                if (fill[i] != 'X' && fill[i] != 'O')
                {
                    fill[i] = (current_player == 'A') ? player_a : player_b; // Update the grid with the player's symbol
                    validMove = true;
                    moveCount++;
                    break;
                }
                else
                {
                    std::cout << "The number is chosen already, please enter another number.\n";
                    break;
                }
            }
        }

        if (!validMove)
        {
            std::cout << "Invalid move. Please choose a valid number.\n";
            continue; // Prompt for input again
        }

        grid(fill); // Display the updated grid
        if (check_win(fill, (current_player == 'A' ? player_a : player_b), is_win))
        {
            return; // Exit the function if there's a win
        }
        if (moveCount == 9)
        {
            std::cout << "It's a draw!\n";
            return; // Exit the function to end the game if it's a draw
        }
    }
}
