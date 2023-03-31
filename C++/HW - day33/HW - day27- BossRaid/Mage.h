#pragma once
class Mage : public Player, public enable_shared_from_this<Mage>
{
public:
	Mage(int hp, int atk, string name);
	virtual~Mage();

	virtual void Attack(shared_ptr<Creature> other) override;
private:
};

