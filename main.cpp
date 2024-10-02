#include <iostream>
#include <vector>
#include "ttt.hpp"

int main()
{
    std::vector<char> fill = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool is_win = false;
    welcome();
    char player_a, player_b;
    std::cout << "\nPlayer A, please choose either X or O with capital letter to represent your move!  ";
    std::cin >> player_a;
    while (player_a != 'X' && player_a != 'O')
    {
        std::cout << "Invalid choice. Please choose either X or O: ";
        std::cin >> player_a;
    }
    (player_a == 'X') ? player_b = 'O' : player_b = 'X';
    std::cout << "Player A is playing with " << player_a << "\n";
    std::cout << "Player B is playing with " << player_b << "\n";
    grid(fill);

    while (!is_win)
    {
        make_move(fill, player_a, player_b, is_win);
    }
}
