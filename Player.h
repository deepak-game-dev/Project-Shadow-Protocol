#pragma once
class Enemy;

class Player
{
private:
	int health = 100;
	int maxHealth = 100;
	int damage;
public:
	Player(int damage);
	void TakeDamage(int damage);
	int GetHealth() const;
	void SetHealth(int value);
	void Heal(int value);
	bool IsAlive() const;
	void Attack(Enemy& enemy);
};