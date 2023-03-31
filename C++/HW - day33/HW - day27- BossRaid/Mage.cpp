#include "framework.h"
#include "Mage.h"

Mage::Mage(int hp, int atk, string name)
	: Player(hp, atk, name)
{
	SoundManager::GetInstance()->PlayerCreate();
	_type = CreatureType::PLAYER;
}

Mage::~Mage()
{
}

void Mage::Attack(shared_ptr<Creature> other)
{
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
	SoundManager::GetInstance()->MageAttack();

	cout << _name << " attacked " << other->Getname() << endl;
	cout << "Now " << other->Getname() << "'s hp is " << other->GetHp() << endl;
}
