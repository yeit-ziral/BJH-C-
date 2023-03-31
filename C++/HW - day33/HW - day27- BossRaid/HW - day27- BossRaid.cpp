#include "framework.h"

bool AllDead(vector<shared_ptr<Creature>> arr)
{
	int count = 0;

	
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->IsAlive() == false)
		{
			++count;
		}
	}

	if (count == arr.size())
		return true;
	else
		return false;
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	SoundManager::Create();

	vector<shared_ptr<Creature>> players;
	players.reserve(10);
	for (int i = 0; i < 10; i++)
	{
		switch (rand() % 3)
		{
			case 0:
			{
				shared_ptr<Creature> player = make_shared<Knight>( 150 + rand() % 50, 50 + rand() % 50, "knight" + to_string(i) );
				players.push_back(player);
			}
			case 1:
			{
				shared_ptr<Creature> player = make_shared<Archer>( 100 + rand() % 50, 100 + rand() % 50, "archer" + to_string(i) );
				players.push_back(player);
			}
			case 2:
			{
				shared_ptr<Creature> player = make_shared<Mage>( 50 + rand() % 50, 150 + rand() % 50, "mage" + to_string(i) );
				players.push_back(player);
			}
		}
	}

	shared_ptr<Creature> boss = make_shared<Boss>( 10000, 49, "BossMonster" );

	while(true)
	{
		for (auto& player : players)
		{
			player->Attack(boss);
		}

		dynamic_pointer_cast<Boss>(boss)->AttackPlayers();
	
		if (AllDead(players))
		{
			cout << "No one couldn't survive!!" << endl;
			break;
		}

		if (boss->IsAlive() == false)
		{
			cout << "Players Win!!" << endl;
			break;
		}

	}

	return 0;
}