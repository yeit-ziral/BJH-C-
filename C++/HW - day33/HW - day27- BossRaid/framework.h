#pragma once

#include<iostream>
#include<memory>
#include<unordered_map>
#include<map>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

enum class CreatureType
{
	NONE,
	PLAYER,
	MONSTER,
	AGGRO_ABLE
};

#include "SoundManager.h"
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "Knight.h"
#include "Mage.h"
#include "Archer.h"
#include "Boss.h"

#include "World.h"