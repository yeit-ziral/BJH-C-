#include "framework.h"
#include "Monster.h"

Monster::Monster(int hp, int atk, string name)
	: Creature(hp, atk, name)
{
	SoundManager::GetInstance()->MonsterCreate();
	_type = CreatureType::MONSTER;
}

Monster::~Monster()
{
}

void Monster::Attack(shared_ptr<Creature> other)
{
	if (other == nullptr)
		return;
	if (!IsAlive() || !other->IsAlive())
		return;
	other->Damaged(_atk);
	SoundManager::GetInstance()->MonsterAttack();

	cout << _name << " attacked " << other->Getname() << endl;
	cout << "Now " << other->Getname() << "'s hp is " << other->GetHp() << endl;
}