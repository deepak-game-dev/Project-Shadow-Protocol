#include "Player.h"
#include "enemy.h"
Player::Player(int damage)
{
	this->damage = damage;
}
void Player::TakeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
	}
}
int Player::GetHealth() const
{
	return health;
}
void Player::SetHealth(int value)
{
	if (value >= 0 && value <= maxHealth)
	{
		health = value;
	}
}
void Player::Heal(int value)
{
	if (health < maxHealth)
	{

		health += value;

		if (health > maxHealth)
		{
			health = maxHealth;
		}
	}
}
bool Player::IsAlive() const
{
	return health > 0;
}
void Player::Attack(Enemy& enemy)
{
	if(IsAlive() && enemy.IsAlive())
	{
		enemy.TakeDamage(damage);
	}
	
}