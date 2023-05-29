#pragma once

#include <string>

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
    Character(const std::string& Name);
    void DamagePlayer() override;
    std::string Name() override;
    int HealthPlayer() override;
    void Potion() override;
    bool Dead() override;
};