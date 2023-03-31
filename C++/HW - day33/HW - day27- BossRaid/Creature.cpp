#include "framework.h"

Creature::Creature(int hp, int atk, string name)
	: _hp(hp), _atk(atk), _name(name)
{
	SoundManager::GetInstance()->CreautureCreate();
	_type = CreatureType::NONE;
}

Creature::~Creature()
{
}

void Creature::SetInfo(int hp, int atk, string name)
{
	_hp = hp;
	_atk = atk;
	_name = name;
}

void Creature::PrintInfo()
{
	if (IsAlive() == false) return;
	cout << "�̸� : " << _name << endl;
	cout << "ü�� : " << _name << endl;
	cout << "���ݷ� : " << _name << endl;
}

void Creature::Attack(shared_ptr<Creature> creature)
{
	if (creature == nullptr)
		return;
	if (IsAlive() == false || creature->IsAlive() == false)
		return;
	creature->Damaged(this->_atk);

	cout << this->_name << " attacked " << creature->_name << endl;
	cout << "Now " << creature->_name << "'s hp is " << creature->_hp << endl;
}

void Creature::Damaged(int amount, shared_ptr<Creature> attack)
{
	if (amount <= 0 || IsAlive() == false)
		return;

	_hp -= amount;

	if (_hp <= 0)
	{
		cout << "�׾����ϴ�." << endl;
		_hp = 0;
	}

}

bool Creature::IsAlive() const
{
	return _hp > 0;
}
