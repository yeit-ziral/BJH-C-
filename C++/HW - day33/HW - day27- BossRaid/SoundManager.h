#pragma once
class SoundManager
{
private:
	SoundManager();
	~SoundManager();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new SoundManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static SoundManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	void CreautureCreate() { cout << _creatureSound << endl; }

	void PlayerCreate() { cout << _playerSound << endl; }

	void MonsterCreate() { cout << _monsterSound << endl; }

	void PlayerAttack() { cout << _playerAtkSound << endl; }

	void MonsterAttack() { cout << _monsterAtkSound << endl; }

	void KnightAttack() { cout << _knightAtkSound << endl; }

	void MageAttack() { cout << _mageAtkSound << endl; }

	void ArcherAttack() { cout << _archerAtkSound << endl; }

	void BossAttack() { cout << _bossAtkSound << endl; }

private:
	static SoundManager* _instance;

	string _creatureSound;
	string _playerSound;
	string _monsterSound;
	string _playerAtkSound;
	string _monsterAtkSound;
	string _knightAtkSound;
	string _mageAtkSound;
	string _archerAtkSound;
	string _bossAtkSound;
};