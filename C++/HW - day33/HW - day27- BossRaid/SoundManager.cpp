#include "framework.h"
#include "SoundManager.h"

SoundManager* SoundManager::_instance = nullptr;

SoundManager::SoundManager()
{
	cout << "���� �Ŵ����� ����������ϴ�." << endl;

	_creatureSound = "Creature ����!!!";
	_playerSound = "Player ����!!!";
	_monsterSound = "Monster ����!!!";
	_playerAtkSound = "Player ����!!";
	_monsterAtkSound = "Monster ����!!";
	_knightAtkSound = "Knight ����!!";
	_mageAtkSound = "Mage ����!!";
	_archerAtkSound = "Archer ����!!";
	_bossAtkSound = "Boss ����!!";
}

SoundManager::~SoundManager()
{
	cout << "���� �Ŵ����� �����Ǿ����ϴ�." << endl;
}
