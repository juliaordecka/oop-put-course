#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#pragma once

class InterfaceCharacter
{
public:
    virtual std::string Name() = 0;
    virtual int HealthPlayer() = 0;
    virtual void DamagePlayer() = 0;
    virtual void Potion() = 0;
    virtual bool Dead() = 0;
    virtual ~InterfaceCharacter() {}
};
class Character : public InterfaceCharacter
{
private:
    std::string name;
    int health;
    int damage;
public:
    Character(const std::string& Name) : name(Name), health(100), damage(10) {}

    void DamagePlayer() override
    {
        this->health = this->health - this->damage;
    }

    std::string Name() override { return this->name; }
    int HealthPlayer() override { return this->health; }

    void Potion() override
    {
        std::cout << "You managed to drink a health potion while battling.\n";
        this->health = this->health + 20;
        std::cout << "The potion restored your health. Current health: " << this->HealthPlayer() << "\n";
    }
    bool Dead() override
    {
        if ((this->health) <= 0)
            return true;
        else
            return false;
    }
};

class InterfaceMonster
{
public:
virtual int HealthMonster() = 0;
virtual int DamageMonster() = 0;
virtual void AttackedByPlayer() = 0;
virtual bool DeadMonster() = 0;
virtual ~InterfaceMonster() {}
};

class Monster : public InterfaceMonster
{
private:
int healthm;
int damagem;

public:
    Monster() : healthm(50), damagem(20) {}
    int loot;

    int HealthMonster() override { return this->healthm; }
    int DamageMonster() override { return this->damagem; }
    void AttackedByPlayer() override
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
            case 1: std::cout << "The monster loots stale bread.\n";
                break;
            case 2: std::cout << "The monster loots a dagger. \n";
                break;
            case 3: std::cout << "The monster loots rubble. \n";
                break;
            case 4: std::cout << "The monster loots a mysterious scroll. \n";
                break;
            }
        }
    }
    bool DeadMonster() override
    {
        if ((this->healthm) <= 0)
            return true;
        else
            return false;
    }
};
class Exceptions : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Input a valid choice (1,2,3,4,5)";
    }
};

class Game
{
private:
    Character character;
    Monster monster;

public:
    Game(const std::string& characterName) : character(characterName), monster() {}
    void Play()
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
};
int main()
{
    std::string characterName;
    std::cout << "Welcome to the text-based RPG game. Enter your character's name: ";
    std::cin >> characterName;
    Game game(characterName);
    game.Play();

    return 0;
}
