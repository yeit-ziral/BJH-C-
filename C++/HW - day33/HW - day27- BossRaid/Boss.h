#pragma once

class Player;

class Boss : public Monster
{
public:
	struct AggroInfo
	{
		shared_ptr<Creature> attacker;
		int totalDamage;

		bool operator<(const AggroInfo& other) const
		{
			return totalDamage < other.totalDamage;
		}
		bool operator>(const AggroInfo& other) const
		{
			return totalDamage > other.totalDamage;
		}
	};

	Boss(int hp, int atk, string name);
	virtual ~Boss();

	virtual void Attack(shared_ptr<Creature> other) override;
	virtual void Damaged(int amount, shared_ptr<Creature> attacker = nullptr) override;

	void AttackPlayers();

private:
	vector<AggroInfo> _aggroTable;
	int _range = 4;
};

