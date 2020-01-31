#include "Entitiy.h"

Entity::Entity(float xPos, float yPos, std::string spriteFile, int lvl, float armorPerLvl, float damagePerLvl):
	GameObject(xPos, yPos, spriteFile)
{
	this->hp = 100;
	this->armorPerLvl = armorPerLvl;
	this->lvl = lvl;
	this->damagePerLvl = damagePerLvl;
	this->grounded = false;
	this->gravity = 20;
	this->yVel = 0;
}

void Entity::TakeDamage(int damage)
{
	damage = (damage - (int)(armorPerLvl * lvl));
	if (damage <= 0) {
		damage = 1;
	}
	hp -= damage;
}

int Entity::getHp() const
{
	return hp;
}

bool Entity::isDead() const
{
	return hp <= 0;
}

void Entity::gravityFunction(double dt)
{
	this->addPositionY(dt*this->gravity);
}
