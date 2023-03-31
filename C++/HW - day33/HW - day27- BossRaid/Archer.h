#pragma once
class Archer : public Player, public enable_shared_from_this<Archer>
{
public:
	Archer(int hp, int atk, string name);
	virtual~Archer();

	virtual void Attack(shared_ptr<Creature> other) override;
};

