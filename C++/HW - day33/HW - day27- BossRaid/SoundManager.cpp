#include "framework.h"
#include "SoundManager.h"

SoundManager* SoundManager::_instance = nullptr;

SoundManager::SoundManager()
{
	cout << "사운드 매니저가 만들어졌습니다." << endl;

	_creatureSound = "Creature 생성!!!";
	_playerSound = "Player 생성!!!";
	_monsterSound = "Monster 생성!!!";
	_playerAtkSound = "Player 공격!!";
	_monsterAtkSound = "Monster 공격!!";
	_knightAtkSound = "Knight 공격!!";
	_mageAtkSound = "Mage 공격!!";
	_archerAtkSound = "Archer 공격!!";
	_bossAtkSound = "Boss 공격!!";
}

SoundManager::~SoundManager()
{
	cout << "사운드 매니저가 삭제되었습니다." << endl;
}
