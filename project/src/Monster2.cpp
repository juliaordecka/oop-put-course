#include "Monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#pragma once

Monster::Monster() : healthm(50), damagem(20) {}

int Monster::HealthMonster()
{
    return this->healthm;
}

int Monster::DamageMonster()
{
    return this->damagem;
}

void Monster::AttackedByPlayer()
{
    loot = rand() % 4 + 1;
    srand(time(NULL));
    std::cout << "You attacked the monster.\n";
    this->healthm -= this->damagem;
    std::cout << "The monster has " << this->HealthMonster() << " hp points left.\n";
    if (this->healthm <= 0)
    {
        std::cout << "You have slain the monster.\n";
        switch (loot)
        {
        case 1:
            std::cout << "The monster loots stale bread.\n";
            break;
        case 2:
            std::cout << "The monster loots a dagger. \n";
            break;
        case 3:
            std::cout << "The monster loots rubble. \n";
            break;
        case 4:
            std::cout << "The monster loots a mysterious scroll. \n";
            break;
        }
    }
}

bool Monster::DeadMonster()
{
    if (this->healthm <= 0)
        return true;
    else
        return false;
}