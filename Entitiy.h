#pragma once
#include "GameObject.h"

class Entity : public GameObject{
private:
	int hp;
	float damagePerLvl;
	int lvl;
	float armorPerLvl;
	float gravity;
protected:
	bool grounded;
	float yVel;
public:
	Entity(float xPos, float yPos, std::string spriteFile, int lvl, float armorPerLvl, float damagePerLvl);
	void TakeDamage(int damage);
	int getHp()const;
	bool isDead()const;
	void gravityFunction(double dt);
	virtual void update(double dt) = 0;
};