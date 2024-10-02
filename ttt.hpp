#include <iostream>
#include <string>
#include <vector>

void grid(std::vector<char>& fill);
void welcome();
void make_move(std::vector<char>& fill, char player_a, char player_b, bool& is_win);
bool check_win(std::vector<char>& fill, char player_a, bool& is_win);
void check_draw(std::vector<char>& fill);