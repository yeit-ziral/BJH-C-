#include "framework.h"
#include "Archer.h"

Archer::Archer(int hp, int atk, string name)
	:Player(hp, atk, name)
{
	SoundManager::GetInstance()->PlayerCreate();
	_type = CreatureType::PLAYER;
}

Archer::~Archer()
{
}

void Archer::Attack(shared_ptr<Creature> other)
{
	if (other == nullptr)
		return;
	if (!IsAlive() || !other->IsAlive())
		return;
	if (other->GetType() == CreatureType::AGGRO_ABLE)
	{
		other->Damaged(_atk, shared_from_this());
	}
	else
	{
		other->Damaged(_atk);
	}
	SoundManager::GetInstance()->ArcherAttack();

	cout << this->_name << " attacked " << other->Getname() << endl;
	cout << "Now " << other->Getname() << "'s hp is " << other->GetHp() << endl;
}
