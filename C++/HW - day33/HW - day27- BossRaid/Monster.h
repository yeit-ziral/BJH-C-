#pragma once
class Monster : public Creature, enable_shared_from_this<Monster>
{
public:
	Monster(int hp, int atk, string name);
	virtual ~Monster();

	virtual void Attack(shared_ptr<Creature> other) override;

private:
};


