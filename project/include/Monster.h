#pragma once

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
    int loot;

public:
    Monster();
    int HealthMonster() override;
    int DamageMonster() override;
    void AttackedByPlayer() override;
    bool DeadMonster() override;
};