#include <iostream>
#include "Game.h"
#pragma once

int main()
{
    std::string characterName;
    std::cout << "Welcome to the text-based RPG game. Enter your character's name: ";
    std::cin >> characterName;
    Game game(characterName);
    game.Play();

    return 0;
}