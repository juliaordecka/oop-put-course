#pragma once

#include "Character.h"
#include "Monster.h"
#include "Exceptions.h"

class Game
{
private:
    Character character;
    Monster monster;

public:
    Game(const std::string& characterName);
    void Play();
};