#pragma once
class Creature
{
public:
	Creature(int hp, int atk, string name);
	virtual ~Creature();

	void SetInfo(int hp, int atk, string name);

	void PrintInfo();

	virtual void Attack(shared_ptr<Creature> creature) abstract;

	virtual void Damaged(int amount, shared_ptr<Creature> attack = nullptr);

	bool IsAlive() const;

	const int GetHp() { return _hp; }

	const int GetAtk() { return _atk; }

	const string& Getname() { return _name; }

	const CreatureType& GetType() { return _type; }


protected:
	int _hp;
	int _atk;
	string _name;
	CreatureType _type;
};

