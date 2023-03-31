#include "framework.h"
#include "Boss.h"

Boss::Boss(int hp, int atk, string name)
	:Monster(hp, atk, name)
{
	_type = CreatureType::AGGRO_ABLE;
}

Boss::~Boss()
{
}

void Boss::Attack(shared_ptr<Creature> other)
{
	if (!IsAlive() || !other->IsAlive())
		return;
	other->Damaged(_atk);
	SoundManager::GetInstance()->BossAttack();

	cout << _name << " attacked " << other->Getname() << endl;
	cout << "Now " << other->Getname() << "'s hp is " << other->GetHp() << endl;
}

void Boss::Damaged(int amount, shared_ptr<Creature> attacker)
{
	Creature::Damaged(amount);

	string name = attacker->Getname();
	auto iter = std::find_if(_aggroTable.begin(), _aggroTable.end(),
		[name](const AggroInfo& info)->bool
		{
			if (info.attacker->Getname() == name)
				return true;
			return false;
		});

	if (iter != _aggroTable.end())
	{
		iter->totalDamage += amount;
	}
	else
	{
		AggroInfo info;
		info.attacker = attacker;
		info.totalDamage = amount;

		_aggroTable.push_back(info);
	}
}

void Boss::AttackPlayers()
{
	auto iter = std::remove_if(_aggroTable.begin(), _aggroTable.end(), [](const AggroInfo& info)->bool
		{
			if (info.attacker->IsAlive() == false)
				return true;
			return false;
		});

	_aggroTable.erase(iter, _aggroTable.end());

	std::sort(_aggroTable.begin(), _aggroTable.end(), greater<AggroInfo>());

	int count = 0;
	for (auto info : _aggroTable)
	{
		if (count >= _range)
			break;

		Attack(info.attacker);

		count++;
	}
}
