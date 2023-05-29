#include "Game.h"
#include <iostream>
#pragma once

Game::Game(const std::string& characterName) : character(characterName), monster() {}

void Game::Play()
{
    std::cout << "While exploring you enter a cave. Suddenly you see a monster emerging from the darkness. What do you do?\n";
    while (this->character.Dead() == false && this->monster.DeadMonster() == false)
    {
        std::cout << "Choose your action:\n";
        std::cout << "1. Attack the monster\n";
        std::cout << "2. Try to escape\n";
        std::cout << "3. Drink a potion\n";
        std::cout << "4. Show stats\n";
        std::cout << "5. Dance\n";
        try
        {
            int option;
            std::cout << "Choose one of these options: ";
            std::cin >> option;
            switch (option)
            {
            case 1:
                this->monster.AttackedByPlayer();
                this->character.DamagePlayer();
                break;
            case 2:
                std::cout << "While trying to escape the monster, you fell into a ditch and died. GAME OVER" << std::endl;
                return;
            case 3:
                this->character.Potion();
                break;
            case 4:
                std::cout << "Character name: " << this->character.Name() << std::endl;
                std::cout << "Your remaining HP: " << this->character.HealthPlayer() << std::endl;
                std::cout << "Monster's HP: " << this->monster.HealthMonster() << std::endl;
                break;

            case 5:
                std::cout << "The monster was scared by your dance moves and ran away" << std::endl;
                return;

            default:
                throw Exceptions();
            }
        }
        catch (const Exceptions& e)
        {
            std::cerr << "Caught an exception: " << e.what() << std::endl;
        }
    }
}