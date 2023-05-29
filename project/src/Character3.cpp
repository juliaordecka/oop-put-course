#include "Character.h"
#include <iostream>
#pragma once

Character::Character(const std::string& Name) : name(Name), health(100), damage(10) {}

void Character::DamagePlayer()
{
    this->health = this->health - this->damage;
}

std::string Character::Name()
{
    return this->name;
}

int Character::HealthPlayer()
{
    return this->health;
}

void Character::Potion()
{
    std::cout << "You managed to drink a health potion while battling.\n";
    this->health = this->health + 20;
    std::cout << "The potion restored your health. Current health: " << this->HealthPlayer() << "\n";
}

bool Character::Dead()
{
    if (this->health <= 0)
        return true;
    else
        return false;
}