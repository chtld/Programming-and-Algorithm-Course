/*
 * University: 	peking(coursera) 
 * Course: 	practice on programming.
 * Assignment: 	WoW(Warriors of War) final version. 
 * 
 */ 
 
#include <iostream>
#include <iterator>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std; 
 
/******************* enum definitions ********************************/
enum COLOR{ RED, BLUE, NONE}; 
enum WEAPON_TYPE{ SWORD, BOMB, ARROW}; 
enum WARRIOR_TYPE { DRAGON, NINJA,  ICEMAN, LION, WOLF}; 
const string color_names[] = { "red", "blue", "none"};
/********************* 	Timer class 	*****************************/
class Timer{ 
public: 
	explicit Timer(int limit); 
	int getTimeInMins() const; 
	int getTime() const; 
	void increaseTime(); 
	string getTimeInString() const; 
 	bool isOver() const; 
private: 
	int minutes_, limit_; 
}; 
 
Timer::Timer(int limit) : limit_(limit), minutes_(0) 
{
 
} 
 
void Timer::increaseTime()
{ 
	++minutes_; 
}
 
int Timer::getTimeInMins() const  
{
	return minutes_ % 60; 
}
 
int Timer::getTime() const 
{ 
	return minutes_; 
}
 
bool Timer::isOver() const 
{ 
	return minutes_ > limit_; 
}
 
string Timer::getTimeInString() const
{ 
	stringstream time;
	time << setw(3) << setfill('0') << minutes_ / 60 << ":" << setw(2) << setfill('0') << minutes_ % 60; 
	return time.str(); 
} 
 
/*************************** 	Util class 	**********************************/
class Util 
{
public: 
	static void split(const string& message, const string& delim, vector<string>& results); 
};
 
void Util::split(const string& message, const string& delim, vector<string>& results) 
{ 
	string::size_type prev_pos = 0, pos = 0; 
	while( (pos = message.find(delim, pos)) != string::npos) 
	{ 
		results.push_back(message.substr(prev_pos, pos - prev_pos));  
		prev_pos = ++pos; 
	}
	results.push_back(message.substr(prev_pos, string::npos));
} 
 
/************************ 	Global class 	***********************************/
class Global { 
public: 
	enum COMBINE_VALUE { M, N, R, K , T}; 
public:
	static Global* getInstance();  
	static void destroy();
	const vector<int>& getCombined() const 
	{ 
		return combined_; 
	} 
	const vector<int>& getAttackForce() const 
	{ 
		return attackForce_;
	}
	const vector<int>& getHealth() const
	{ 
		return health_;
	} 
	const Timer* getTimer() const 
	{ 
		return timer_; 
	}
	void setCombined(const vector<int>&  combined) 
	{ 
		combined_ = combined; 
	}
	void setAttackForce(const vector<int>& attackForce) 
	{ 
		attackForce_ = attackForce; 
	}
	void setHealth(const vector<int>& health) 
	{ 
		health_ = health; 
	}
	void setTimer(Timer* timer) 
	{ 
		timer_ = timer; 
	} 
	 
private: 
	vector<int> combined_;
	vector<int> attackForce_; 
	vector<int> health_; 
	Timer* timer_;
	static Global* instance_;
};
 
Global* Global::instance_ = NULL;
Global* Global::getInstance() 
{ 
	if(instance_ == NULL) 
		instance_ = new  Global(); 
	return instance_; 
}
 
void Global::destroy()  
{ 
	if(instance_ != NULL)
	{
		delete instance_; 
		instance_ = NULL; 
	}
}
 
/*****************************	Weapon classes 	********************************/
class Weapon
{
public:
	static const string weapon_names[];  
	explicit Weapon(WEAPON_TYPE, int); 
	virtual ~Weapon(); 
	virtual bool isValid() const = 0; 
	virtual void updateAfterUse() = 0; 
	virtual int getAttackForce() const;
	virtual string getWeaponInfo() const = 0;  
	WEAPON_TYPE getType() const; 
protected: 
	int attackForce_; 
	WEAPON_TYPE type_; 
}; 
const string Weapon::weapon_names[3] = { "sword", "bomb", "arrow" }; 
Weapon::Weapon(WEAPON_TYPE type, int force) : type_(type), attackForce_(force) 
{
}
 
Weapon::~Weapon()
{
}
 
int Weapon::getAttackForce() const
{ 
	return attackForce_; 
}
WEAPON_TYPE Weapon::getType() const
{ 
	return type_;
} 
class Arrow : public Weapon  
{ 
public:
	explicit Arrow(WEAPON_TYPE, int); 
	virtual string getWeaponInfo() const;
	virtual bool isValid() const;
	virtual void updateAfterUse();
private:
	int count_; 
}; 
 
Arrow::Arrow(WEAPON_TYPE type, int force) : Weapon(type, force), count_(3) 
{ 
} 
 
string Arrow::getWeaponInfo() const
{ 
	if(isValid()) 
	{ 
		stringstream arrow;
		arrow << "arrow(" << count_ << ")"; 
		return arrow.str(); 
	}
	return ""; 
}
 
void Arrow::updateAfterUse() 
{ 
	--count_; 
}
 
bool Arrow::isValid() const
{ 
	return count_ > 0; 
}
class Sword : public Weapon 
{ 
public:
	explicit Sword(WEAPON_TYPE, int); 
	virtual string getWeaponInfo() const;
	virtual bool isValid() const;
	virtual void updateAfterUse(); 
}; 
 
Sword::Sword(WEAPON_TYPE type, int force) : Weapon(type, force) 
{ 
}
 
string Sword::getWeaponInfo() const
{ 
	if(isValid()) 
	{ 
		stringstream sword; 
		sword << "sword(" << attackForce_ << ")";
		return sword.str(); 
	}
	return "";
}
 
void Sword::updateAfterUse() 
{ 
	attackForce_ = static_cast<int>(attackForce_ * 0.8); 
}
 
bool Sword::isValid() const
{ 
	return attackForce_ > 0; 
}
 
class Bomb : public Weapon
{ 
public:
	explicit Bomb(WEAPON_TYPE, int); 
	virtual string getWeaponInfo() const;
	virtual bool isValid() const;
	virtual void updateAfterUse(); 
private:
	bool valid_; 
};
 
Bomb::Bomb(WEAPON_TYPE type, int force) : Weapon(type, force), valid_(true) 
{
} 
 
string Bomb::getWeaponInfo() const
{ 
	if(isValid()) 
	{ 
		return "bomb"; 
	} 
	return ""; 
}
 
 
bool Bomb::isValid() const 
{ 
	return valid_;
}
 
void Bomb::updateAfterUse() 
{ 
	valid_ = false; 
}
class WeaponFactory 
{ 
public: 
	static Weapon* createWeapon(WEAPON_TYPE, int); 
};  
 
/**************************** City, Headquarter, Warrior declarations  ****************************/
class Headquarter;
class City; 
class Warrior
{ 
public:  
	static const string warrior_names[5]; 
public:	
	explicit Warrior(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual ~Warrior(); 
	int getID() const;
	bool isAlive() const; 
	COLOR getColor() const; 
	WARRIOR_TYPE getType() const; 
	int getHealth() const; 
	void setHealth(int); 
	int getAttackForce() const; 
	int getSwordForce() const;
	void setAttackForce(int); 
	vector<Weapon*>&  getWeapons(); 
	City* getCity() const; 
	Headquarter* getHeadquarter() const; 
	void marchCity(City*);
	void collectHealth(int); 		//collect health for its headquarter. 
	void shotByArrow(); 			//shot by enemy's arrow.
	void updateSword(); 
	void updateArrow(); 
	void updateBomb();
	bool hasSword() const;
	bool hasArrow() const;
	bool hasBomb() const;
	string getFullName(); 
	void reportWeapons();
	bool canBeKilled(Warrior* enemy); 
	virtual void getReady(); 		//generate weapons right after initialized. 
	virtual void printCreation(); 		//print message after being created. 
	virtual void startBattle(Warrior* enemy);
	virtual void attack(Warrior*);
	virtual void fightback(Warrior*);   
	virtual bool escape(); 			//overridden by lion.  
	virtual void yell();   			//overridden by dragon.
	virtual void captureWeapons(Warrior*);  //overridden by wolf.
	virtual void updateMove();              //overridden by iceman. 
protected:
	virtual void  printAttack(Warrior*);
	virtual void  printFightback(Warrior*); 
protected:  
	Headquarter* pHeadquarter_; 
	City* pCity_; 
	vector<Weapon*> weapons_; 
	WARRIOR_TYPE type_; 
	int health_; 
	int attackForce_; 
	int id_; 
	string fullName_;
}; 
const string Warrior::warrior_names[5] = { "dragon", "ninja", "iceman", "lion", "wolf" }; 
 
class Ninja : public Warrior 
{ 
public:
	explicit Ninja(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual void fightback(Warrior*);
	virtual void printFightback(Warrior*);
	virtual void getReady(); 
}; 
 
class Dragon : public Warrior 
{ 
public:
	explicit Dragon(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual void getReady();
	virtual void printCreation(); 
	virtual void attack(Warrior* enemy);
	virtual void fightback(Warrior* enemy);
	virtual void yell(); 
	void setMorale(double morale);
	double getMorale() const; 
	void increaseMorale();
	void decreaseMorale(); 
private: 
	float morale_; 
}; 
 
class Wolf : public Warrior
{ 
public:
	explicit Wolf(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual void captureWeapons(Warrior*); 
}; 
 
class Iceman : public Warrior 
{ 
public:
	explicit Iceman(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual void getReady();
	virtual void updateMove(); 
private:
	int moves_; 
}; 
 
class Lion : public Warrior
{ 
public:
	explicit Lion(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual void attack(Warrior* enemy);
	virtual void fightback(Warrior* enemy); 
	virtual void getReady();
	virtual bool escape(); 
	virtual void printCreation(); 
 	void decreaseLoyalty(); 
	void setLoyalty(int loyalty); 
private:
	int loyalty_; 
};
 
class WarriorFactory
{ 
public:
	static Warrior* createWarrior(WARRIOR_TYPE type, Headquarter* pHead, int id, int health, int attackForce); 
}; 
 
class City
{ 
public:
	explicit City(int); 
	int getID() const; 
	int getHealth() const;
	void setHealth(int); 
	void visitedByRed(Warrior*); 
	void visitedByBlue(Warrior*); 
	COLOR getFlag() const;
	Warrior* getBlue() const; 
	Warrior* getRed() const; 
	void generateHealth();
	void lionEscape(); 
	void useBomb(); 
	void collectHealth();
	void reportWarrior(COLOR);
	void attackByArrow(Warrior*); 
	void battle(); 
 
private: //actions related to a battle.
 	void changeFlag(); 
	void updateAfterBattle();
	void resetAfterBattle(); 
	void startBattle();
	void yell(); 
	void collectTrophy();
	void captureWeapons();
	//void printKilled(); 
	void transferHealth();
	Warrior* identifyAttacker(); 
	
private: 
	Warrior* pRed_;
	Warrior* pBlue_; 	
	int id_;  
	int health_;  
	COLOR flag_; 
private:   //aux variables used in a battle. 
	Warrior* winner_;
	Warrior* attacker_; 
	COLOR previous_won_;
	bool isBattle_; 
	bool changeFlag_; 
	bool killedByArrow_;
	int redLionHealth_; 
	int blueLionHealth_;  
}; 
 
class Headquarter
{ 
public: 
	explicit Headquarter(int health, COLOR color); 
	virtual ~Headquarter(); 
	bool isTaken() const;
	COLOR getColor() const;
	int getHealth() const; 
	void collectHealth(int health); 
	void mergeHealth(); 
	void createWarrior(); 
	void addRewardWarrior(Warrior*);
	void rewardWarrior(); 
	void invaded(Warrior*); 
	void lionEscape();  
	void reportHealth(); 
	virtual void reportWarrior(COLOR) = 0; 
	Warrior* getCurrentWarrior(); 
	void clearCurrentWarrior(); 
protected: 
	vector<Warrior*> enemies_; 
	Warrior* pCurrentWarrior_; 
	vector<Warrior*> rewardList_; 
	vector<Warrior*> warriors_; 
	vector<WARRIOR_TYPE> warriorTypeOrder_; 
	int totalWarrior_; 
	int health_; 
	COLOR color_; 
	int collectedHealth_; 
};
 
class Redquarter : public Headquarter
{ 
public: 	
	explicit Redquarter(int, COLOR color= RED); 
	virtual void reportWarrior(COLOR); 
 
}; 
 
class Bluequarter : public Headquarter
{ 
public:
	explicit Bluequarter(int, COLOR color = BLUE); 
	virtual void reportWarrior(COLOR); 
}; 
/*********************		Comparator classes  		*******************************/
class RewardOrder 
{ 
public:
	bool operator()(Warrior* rhs, Warrior* lhs) 
	{
		if(rhs->getColor() == RED) 
		{ 
			return lhs->getCity()->getID() > rhs->getCity()->getID();
		} 
		else
		{
			return rhs->getCity()->getID() < lhs->getCity()->getID();
		}		
	}
};
 
class WeaponOrder
{ 
public:
	bool operator()(Weapon* rhs, Weapon* lhs) 
	{ 
		return rhs->getType() > lhs->getType();
	}
}; 
 
/*********************		Warrior implementation 		*******************************/
Warrior::Warrior(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type) 
:pHeadquarter_(headquarter), id_(id), health_(health), attackForce_(attackForce), type_(type), pCity_(NULL), fullName_("")
{
}
 
bool Warrior::isAlive() const
{ 
	return getHealth() > 0;
}
 
int Warrior::getID() const
{ 
	return id_; 
}
 
COLOR Warrior::getColor() const
{ 
	return getHeadquarter()->getColor();
}
 
WARRIOR_TYPE Warrior::getType() const 
{ 
	return type_; 
}
 
vector<Weapon*>& Warrior::getWeapons() 
{
	return weapons_; 
}  
 
int Warrior::getHealth() const
{ 
	return health_; 
}
 
void Warrior::setHealth(int health) 
{ 
	health_ = health; 
}
 
int Warrior::getAttackForce() const
{
	return attackForce_; 
}
 
void Warrior::setAttackForce(int force)
{ 
	attackForce_ = force;
}
 
void Warrior::getReady() 
{ 
}
 
void Warrior::reportWeapons() 
{ 
	sort(weapons_.begin(), weapons_.end(), WeaponOrder());
	stringstream weapons;
	for(int i = 0; i < weapons_.size(); ++i) 
	{ 
		string weapon = weapons_.at(i)->getWeaponInfo(); 
		if(weapon != "")
		{ 
			weapons << weapon << ","; 
		}
	}
	string result = weapons.str();
	if(result[result.length() - 1] == ',') 
	{ 
		result.erase(result.length() - 1);
	}
	if(result == "")
	{ 
		result = "no weapon";
	}
	printf("%s %s has %s\n",Global::getInstance()->getTimer()->getTimeInString().c_str(),\
		getFullName().c_str(), result.c_str()); 
	
} 
string Warrior::getFullName()  
{ 
	if(fullName_ == "") 
	{ 
		stringstream name;
		name << color_names[getColor()] << " " << warrior_names[type_] << " " << id_; 
		fullName_ = name.str(); 
	} 
	return fullName_;
}
void Warrior::printCreation() 
{		
	string color = color_names[getColor()]; 
	printf("%s %s born\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), getFullName().c_str());
}
void Warrior::startBattle(Warrior* enemy) 
{ 
	printAttack(enemy);
	attack(enemy);
	if(enemy->isAlive()) 
	{ 
		enemy->printFightback(this);
		enemy->fightback(this);
	}
}
 
void Warrior::attack(Warrior* enemy)
{ 
	enemy->setHealth( enemy->getHealth() - (getAttackForce() + getSwordForce()) ); 
	updateSword();
	if(!enemy->isAlive())	
		printf("%s %s was killed in city %d\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
				enemy->getFullName().c_str(), getCity()->getID()); 
}
 
void Warrior::fightback(Warrior* enemy) 
{ 
	enemy->setHealth(enemy->getHealth() - (getAttackForce() / 2  + getSwordForce()) );
	updateSword();
	if(!enemy->isAlive())	
		printf("%s %s was killed in city %d\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
				enemy->getFullName().c_str(), getCity()->getID()); 
}
 
void Warrior::printAttack(Warrior* enemy)
{ 
	printf("%s %s attacked %s in city %d with %d elements and force %d\n",\
		Global::getInstance()->getTimer()->getTimeInString().c_str(),\
		getFullName().c_str(), enemy->getFullName().c_str(), getCity()->getID(),\
		getHealth(), getAttackForce());
}
 
void Warrior::printFightback(Warrior* enemy)
{ 
	printf("%s %s fought back against %s in city %d\n",\
		Global::getInstance()->getTimer()->getTimeInString().c_str(),\
		getFullName().c_str(), enemy->getFullName().c_str(), getCity()->getID()); 
}
 
int Warrior::getSwordForce() const 
{ 
	int force = 0; 
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{
		if((*it)->getType() == SWORD && (*it)->isValid()) 
		{ 
			force += (*it)->getAttackForce(); 
		}
	}
	return force;
}
 
bool Warrior::canBeKilled(Warrior* enemy) 
{ 		
	bool beKilled = false; 
	if(enemy && enemy->isAlive() && enemy->getType() != NINJA ) 
	{
		if((getAttackForce() + getSwordForce() < enemy->getHealth()) \
			&& (enemy->getAttackForce() / 2 + enemy->getSwordForce() >= getHealth())) 
		{ 
			beKilled = true;
		}
	}
	return beKilled; 
}
 
Headquarter* Warrior::getHeadquarter() const
{ 
	return pHeadquarter_;
}
 
City* Warrior::getCity() const 
{ 
	return pCity_;
}
 
void Warrior::marchCity(City* city) 
{
	pCity_ = city;
}
 
void Warrior::updateSword()
{ 
	//Not clear which sword will be used, so just update all available swords. 
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == SWORD && (*it)->isValid())
		{
			(*it)->updateAfterUse(); 
		}
	}
}
 
void Warrior::updateArrow()
{ 
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == ARROW  && (*it)->isValid())
		{
			(*it)->updateAfterUse(); 
		}
	}
}
 
//It maybe not neccessary to update bomb since bomb will kill both warriors. 
void Warrior::updateBomb()
{
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == BOMB && (*it)->isValid())
		{
			(*it)->updateAfterUse(); 
		}
	}
}
 
bool Warrior::hasSword() const
{
	bool hasSword = false;
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == SWORD && (*it)->isValid())
		{
			hasSword = true;
			break;
		}
	}
	return hasSword; 
}
 
bool Warrior::hasArrow() const
{
	bool hasArrow = false;
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == ARROW && (*it)->isValid())
		{
			hasArrow = true;
			break;
		}
	}
	return hasArrow; 
}
 
bool Warrior::hasBomb() const
{
	bool hasBomb = false;
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == BOMB && (*it)->isValid())
		{
			hasBomb = true;
			break;
		}
	}
	return hasBomb;
}
 
//collect health for its headquarter. 
void Warrior::collectHealth(int health)
{ 
 	getHeadquarter()->collectHealth(health); 
}
 
void Warrior::shotByArrow() 
{ 
	setHealth(getHealth() - Global::getInstance()->getCombined()[Global::R]);
}
 
//mainly for dragon's surviving roar. 
void Warrior::yell()  
{ 
}
 
Warrior::~Warrior() 
{ 
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it) 
	{ 
		delete (*it);
	}
	weapons_.clear();
}
 
	
//Only lion will try to escape when its loyalty decrease to certain level. 
bool Warrior::escape() 
{ 
	return false;
}
//only wolf will try to capture enemy's weapons.
void Warrior::captureWeapons(Warrior* enemy) 
{ 
}
 
//only affect iceman's move. 
void Warrior::updateMove()
{ 
}
 
/**************		Ninja implementation 		***************************/
Ninja::Ninja(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type) 
:Warrior(headquarter, id, health, attackForce, type)
{ 
} 
 
void Ninja::getReady()
{
	weapons_.push_back(WeaponFactory::createWeapon(static_cast<WEAPON_TYPE>(getID() % 3), getAttackForce()));
	weapons_.push_back(WeaponFactory::createWeapon(static_cast<WEAPON_TYPE>((getID() + 1) % 3), getAttackForce())); 
}
 
void Ninja::fightback(Warrior* enemy)
{
	//ninja does not fightback when being attacked. 
}
 
void Ninja::printFightback(Warrior* enemy) 
{ 
}
 
/************ 		Wolf implementation 		**************************/ 
Wolf::Wolf(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type) 
:Warrior(headquarter, id, health, attackForce, type)
{ 
} 
 
void Wolf::captureWeapons(Warrior* enemy) 
{
	if(!enemy->getWeapons().empty())
	{ 
		for(vector<Weapon*>::iterator it = enemy->getWeapons().begin(); \
					it != enemy->getWeapons().end(); ++it) 
		{ 
			if( (*it) && (*it)->isValid() && (*it)->getType() == SWORD && hasSword() == false) 
			{ 
				weapons_.push_back(*it); 
				(*it) = NULL; //set original weapons pointer to NULL. 
			}
			if( (*it) && (*it)->isValid() && (*it)->getType() == ARROW && hasArrow() == false) 
			{ 
				weapons_.push_back(*it); 
				(*it) = NULL; 
			}
			if( (*it) && (*it)->isValid() && (*it)->getType() == BOMB && hasBomb() == false) 
			{ 
				weapons_.push_back(*it); 
				(*it) = NULL; 
			}
		} 
	}
}
 
/*************** 	Dragon implementation		 ***********************/
Dragon::Dragon(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type) 
:Warrior(headquarter, id, health, attackForce, type), morale_(0.0) 
{ 
}
 
void Dragon::getReady()
{ 
	morale_ = static_cast<float>(pHeadquarter_->getHealth()) / Global::getInstance()->getHealth()[DRAGON];  
	weapons_.push_back(WeaponFactory::createWeapon(static_cast<WEAPON_TYPE>(getID() % 3), getAttackForce())); 
}
	
void Dragon::attack(Warrior* enemy)
{ 
	Warrior::attack(enemy);
	if(enemy->isAlive()) 
	{ 
		decreaseMorale();
	}
	else 
	{ 
		increaseMorale();
	}
} 
 
void Dragon::fightback(Warrior* enemy)
{ 
	Warrior::fightback(enemy);
	if(enemy->isAlive())
	{
		decreaseMorale();
	}
	else
	{ 
		increaseMorale();
	}
}
 
void Dragon::setMorale(double morale) 
{ 
	morale_ = morale;
}
 
void Dragon::printCreation()
{ 
	Warrior::printCreation();
	printf("Its morale is %0.2f\n", morale_); 
}
double Dragon::getMorale() const
{ 
	return morale_; 
}
 
void Dragon::increaseMorale()
{ 
	morale_ += 0.2; 
}
 
void Dragon::decreaseMorale()
{ 
	morale_ -= 0.2;
}
 
void Dragon::yell() 
{ 
	if(isAlive() && getMorale() > 0.8 ) 
	{ 
		printf("%s %s yelled in city %d\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
				getFullName().c_str(), getCity()->getID());
	}
}
 
/*************** 	Iceman implementation 		*********************/
Iceman::Iceman(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type)
:Warrior(headquarter, id, health, attackForce, type), moves_(0)
{ 
} 
 
void Iceman::getReady()
{ 
	weapons_.push_back(WeaponFactory::createWeapon(static_cast<WEAPON_TYPE>(getID() % 3), getAttackForce())); 	
}
 
void Iceman::updateMove()
{ 
	moves_ += 1; 
	if(moves_ > 0 && moves_ % 2 == 0) 
	{ 
		getHealth() > 9 ? setHealth(getHealth() - 9) : setHealth(1); 
		setAttackForce(getAttackForce() + 20); 
	}
}
 
 
/***************** 	Lion implementation 		******************/
Lion::Lion(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type) 
:Warrior(headquarter, id,  health, attackForce, type), loyalty_(0)  
{ 
} 
 
void Lion::getReady() 
{ 
	setLoyalty(pHeadquarter_->getHealth());
}
 
void Lion::decreaseLoyalty() 
{ 
	loyalty_ -= Global::getInstance()->getCombined()[Global::K];
}
 
void Lion::setLoyalty(int loyalty)
{
	loyalty_ = loyalty; 
}	
 
void Lion::attack(Warrior* enemy)
{ 
	Warrior::attack(enemy);
	if(enemy->isAlive()) 
	{ 
		decreaseLoyalty(); 
	}	
}
void Lion::fightback(Warrior* enemy) 
{ 
	Warrior::fightback(enemy);
	if(enemy->isAlive()) 
	{ 
		decreaseLoyalty();
	}
}
bool Lion::escape() 
{ 
	//print escape message and return true;
	if(loyalty_ <= 0) 
	{ 
		//print escape message and return true;
		printf("%s %s ran away\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			getFullName().c_str());
		return true; 
	}
	else 
	{ 
		return false;
	}
}
 
void Lion::printCreation()
{
	Warrior::printCreation();
	printf("Its loyalty is %d\n", loyalty_);
}
 
/*************** 	WeaponFactory implementation	 	*******************/
Weapon* WeaponFactory::createWeapon(WEAPON_TYPE type, int force)  
{
	switch(type) 
	{ 
		case SWORD: 
			return new Sword(type, force * 0.2); 
		case BOMB: 
			return new Bomb(type, 10000); 
		case ARROW:
			return new Arrow(type, Global::getInstance()->getCombined()[Global::R]);  
		defautl:
			break;
	}
	return NULL;
}
 
/*****************	 WarriorFactory implementation 		****************/
Warrior* WarriorFactory::createWarrior(WARRIOR_TYPE type, Headquarter* pHead, int id, int health, int attackForce ) 
{ 
	switch(type)  
	{ 
		case DRAGON:
			return new Dragon(pHead, id, health, attackForce, type);
		case LION:	
			return new Lion(pHead, id, health, attackForce, type);  
		case ICEMAN:
			return new Iceman(pHead, id, health, attackForce, type);  
		case NINJA:
			return new Ninja(pHead, id, health, attackForce, type);  
		case WOLF:
			return new Wolf(pHead, id, health, attackForce, type);  
		default:
			break;
	}
	return NULL;
}
 
 
/*****************	 City implementation 		************************/
City::City(int id): id_(id), pBlue_(NULL), pRed_(NULL),health_(0), flag_(NONE), winner_(NULL),\
		attacker_(NULL), previous_won_(NONE), isBattle_(false), changeFlag_(false), \
		killedByArrow_(false), redLionHealth_(0), blueLionHealth_(0) 
{ 
}
 
int City::getHealth() const
{
	return health_;
}
 
int City::getID() const
{ 
	return id_;
}
 
Warrior* City::getBlue() const
{ 
	return pBlue_; 
}
 
Warrior* City::getRed() const
{ 
	return pRed_;
}
 
void City::setHealth(int health)
{
	health_ = health;
}
 
void City::battle() 
{ 
 	startBattle();
	updateAfterBattle();
	transferHealth();   //transfer dead lion's health to its surviving opponent. 
	captureWeapons();   //surviving wolf captures weapons from its dead enemy. 
	yell();             //dragon try to yell. 
	collectTrophy();    //surviving warrior collect health for its headquarter.
	changeFlag();       //change the city's flag if necessary. 
	resetAfterBattle(); 
}
 
void City::changeFlag() 
{
	if(changeFlag_) 
	{ 
		if(flag_ != previous_won_) 
		{ 
			flag_ = previous_won_;
			//print out change flag message.
			printf("%s %s flag raised in city %d\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
				color_names[flag_].c_str(), id_);
		}	
		previous_won_ = NONE; 
	}
} 
void City::updateAfterBattle()
{
	if(isBattle_ && pRed_->isAlive() && pBlue_->isAlive()) 
	{ 
		winner_ = NULL; //no winner 
		previous_won_ = NONE; //reset winning record to NONE
	}
	else if(isBattle_ && pRed_->isAlive()) 
	{ 
		winner_ = pRed_;  
		if(previous_won_ == NONE || previous_won_ == BLUE) 
		{ 
			previous_won_ = RED; 
		}
		else  //won two battles, then notice to change the flag. 
		{ 
			changeFlag_ = true;
		}
	} 
	else if(isBattle_ && pBlue_->isAlive())
	{ 
		winner_ = pBlue_; 
		if(previous_won_ == NONE || previous_won_ == RED) 
		{ 
			previous_won_ = BLUE;
		}
		else 
		{
			changeFlag_ = true;
		}
	} 
	else  //both were killed by arrow or bomb.
	{ 
		winner_ = 0; 
	}
		
}
void City::resetAfterBattle()
{
	isBattle_ = false;
	killedByArrow_ = false;
	winner_ = NULL;
	attacker_ = NULL;
	redLionHealth_ = 0;
	blueLionHealth_ = 0;
	changeFlag_ = false;
} 
void City::startBattle()
{
	//requires two warriors to have a battle. 
	if(pRed_ && pBlue_) 
	{ 
		isBattle_ = true; 
		//Dead lion's health need to be transferred to the winner.
		if(pRed_->isAlive() && pRed_->getType() == LION)
			redLionHealth_ = pRed_->getHealth();
		if(pBlue_->isAlive() && pBlue_->getType() == LION)
			blueLionHealth_ = pBlue_->getHealth();
 
		attacker_  = identifyAttacker(); 	
		if(pRed_->isAlive() && pBlue_->isAlive()) 
		{
			Warrior* enemy = (attacker_ == pRed_) ? pBlue_ : pRed_; 
			attacker_->startBattle(enemy);
		} 
		else 
		{ //else one of them or both were killed by arrow five minutes ago.
			killedByArrow_ = true;	
		}
	}
}
 
//only dragon will yell.
void City::yell()
{	  
	//how to handle dragon's increase or decrease morale?
	if(attacker_ && attacker_->isAlive()) 
	{ 
		attacker_->yell();
	}	
}
 
//only wolf will capture weapons.
void City::captureWeapons()
{	
	if(winner_)
	{ 
		winner_->captureWeapons((winner_ == pBlue_) ? pRed_ : pBlue_); 
	}
} 
/*
void City::printKilled()
{
	if(winner_ && !killedByArrow_) 
	{ 
		if(winner_ == pRed_)
		{ 
			printf("%s %s was killed in city %d\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
				pBlue_->getFullName().c_str(), id_); 
		}
		if(winner_ == pBlue_) 
		{ 
			//print red warrior was killed.
			printf("%s %s was killed in city %d\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
				pRed_->getFullName().c_str(), id_); 
		}
	}
} */
void City::collectTrophy() 
{ 
	if(winner_) 
	{
		winner_->collectHealth(getHealth());
		printf("%s %s earned %d elements for his headquarter\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			winner_->getFullName().c_str(), getHealth());
		setHealth(0); //reset city's health to zero after health being collected. 
		winner_->getHeadquarter()->addRewardWarrior(winner_);  //winner asks for reward. 
	}
}
 
//only dead lion's health will be transferred. 
void City::transferHealth()
{ 
	if(winner_) 
	{ 
		if(winner_ == pRed_)
		{
			winner_->setHealth(winner_->getHealth() + blueLionHealth_); 
		}
		if(winner_ == pBlue_)
		{ 
			winner_->setHealth(winner_->getHealth() + redLionHealth_); 
		}
	} 
}
//Identify who is the attacker. 
Warrior* City::identifyAttacker()
{  
	Warrior* attacker = NULL;
	switch(flag_) 
	{ 
		case RED:
			attacker = pRed_; 
			break;	
		case BLUE:
			attacker = pBlue_;
			break;
		case NONE:
			if(id_ % 2)
			{ 
				attacker = pRed_;
			}
			else
			{ 
				attacker = pBlue_;
			}
			break;
		default:
			break;
	}
	return attacker;
}
 
void City::generateHealth() 
{ 
	health_ += 10; 
}
 
void City::visitedByRed(Warrior* red)
{
	if(red && red->isAlive())  
	{ 
		pRed_ = red; 
		pRed_->marchCity(this);
		pRed_->updateMove();
		printf("%s %s marched to city %d with %d elements and force %d\n",
			Global::getInstance()->getTimer()->getTimeInString().c_str(),
			red->getFullName().c_str(), id_, red->getHealth(), red->getAttackForce());
	} 
	else 
	{ 
		pRed_ = NULL;
	}
} 
 
void City::attackByArrow(Warrior* attacker) 
{ 
	if(attacker && attacker->hasArrow())
	{ 
		//red arrow
		if(attacker->getColor() == RED && pBlue_ && pBlue_->isAlive()) 
		{ 
			pBlue_->shotByArrow();
			attacker->updateArrow();
			if(!pBlue_->isAlive())
			{ 
				//print shot and kill message
				printf("%s %s shot and killed %s\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), 
				attacker->getFullName().c_str(), pBlue_->getFullName().c_str()); 
			} 
			else 
			{ 
				//print shot message
				printf("%s %s shot\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), 
					attacker->getFullName().c_str());
			}	 
		} 
		if(attacker->getColor() == BLUE && pRed_ && pRed_->isAlive())
		{ 
			pRed_->shotByArrow();
			attacker->updateArrow();
			if(!pRed_->isAlive())
			{ 
				//print shot and kill message
				printf("%s %s shot and killed %s\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), 
				attacker->getFullName().c_str(), pRed_->getFullName().c_str()); 
			}
			else
			{ 
				//print shot message.
				printf("%s %s shot\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), 
					attacker->getFullName().c_str());
			}
		}
	}	
} 
 
void City::visitedByBlue(Warrior* blue) 
{
	if(blue && blue->isAlive()) 
	{ 
		pBlue_ = blue; 
		pBlue_->marchCity(this);
		pBlue_->updateMove(); 
		printf("%s %s marched to city %d with %d elements and force %d\n",
			Global::getInstance()->getTimer()->getTimeInString().c_str(),
			blue->getFullName().c_str(), id_, blue->getHealth(), blue->getAttackForce());
	} 
	else 
	{ 
		pBlue_ = NULL;
	}
}
 
void City::collectHealth()
{ 
	//if only one warrior in the city, the warrior will collect city's health for its headquarter. 
	if(pBlue_ && pRed_) 
	{ 
		return;   
	} 
	else if(pBlue_ && pBlue_->isAlive()) 
	{
		pBlue_->collectHealth(getHealth());
		printf("%s %s earned %d elements for his headquarter\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			pBlue_->getFullName().c_str(), getHealth());
		setHealth(0);
	}
	else if(pRed_ && pRed_->isAlive())
	{ 
		pRed_->collectHealth(getHealth());
		printf("%s %s earned %d elements for his headquarter\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			pRed_->getFullName().c_str(), getHealth());
		setHealth(0);
	} 
	else
	{
		//no warroir in city so far. 
		return;  
	}
}
void City::reportWarrior(COLOR color) 
{ 
 	if(color == RED && pRed_ && pRed_->isAlive()) 
	{ 
		pRed_->reportWeapons(); 
	}
	if(color == BLUE && pBlue_ && pBlue_->isAlive())
	{ 
		pBlue_->reportWeapons();
	}
}
 
void City::lionEscape() 
{ 
	if(pRed_ && pRed_->isAlive() && pRed_->escape()) 
	{ 
		pRed_ = NULL;
	}
	if(pBlue_ && pBlue_->isAlive() && pBlue_->escape()) 
	{ 
		pBlue_ = NULL; 
	}
}
 
void City::useBomb() 
{ 
 
	if(pRed_ && pBlue_ && pRed_->isAlive() && pBlue_->isAlive())
	{ 
		Warrior* attacker = identifyAttacker();
		if(pRed_->hasBomb()) 
		{ 
			if( (attacker == pRed_ && pRed_->canBeKilled(pBlue_)) \
				|| (attacker != pRed_ && pRed_->getHealth() <= pBlue_->getAttackForce() + pBlue_->getSwordForce()))
			{ 
				pRed_->setHealth(-1000); //make sure it's not alive.
				pBlue_->setHealth(-1000); //make sure it's not alive.
				pRed_->updateBomb();
				//print use bomb message. 
				printf("%s %s used a bomb and killed %s\n", Global::getInstance()->getTimer()->getTimeInString().c_str(),\
					pRed_->getFullName().c_str(), pBlue_->getFullName().c_str());
				pRed_ = NULL;
				pBlue_ = NULL;
				return; //return to prevent  blue warrior to use bomb.
			}
		}
		//blue warrior try to use bomb.
		if(pBlue_->hasBomb())
		{ 
			if((attacker == pBlue_ && pBlue_->canBeKilled(pRed_)) \
				|| (attacker != pBlue_ && pBlue_->getHealth() <= pRed_->getAttackForce() + pRed_->getSwordForce())) 
			{ 
				pBlue_->setHealth(-1000);
				pRed_->setHealth(-1000);
				pBlue_->updateBomb();
				printf("%s %s used a bomb and killed %s\n", Global::getInstance()->getTimer()->getTimeInString().c_str(),\
					pBlue_->getFullName().c_str(), pRed_->getFullName().c_str());
				//print use bomb message
				pRed_ = NULL;
				pBlue_ = NULL;
				return; 
			}
		}
	}
} 
 
/*********************** 	Headquarter implementation 		****************************/
Headquarter::Headquarter(int health, COLOR color) 
:health_(health), color_(color), pCurrentWarrior_(NULL), totalWarrior_(0), collectedHealth_(0) 
{
 
}
 
Headquarter::~Headquarter() 
{ 
	for(vector<Warrior*>::const_iterator it = warriors_.begin();  it != warriors_.end(); ++it) 
	{ 
		delete (*it); 
	}
	warriors_.clear(); 
}
 
void Headquarter::createWarrior()
{
	int index = totalWarrior_ % 5; 
	WARRIOR_TYPE type = warriorTypeOrder_[index]; 
	int health = Global::getInstance()->getHealth()[type];
	if(health_ >= health ) 
	{ 
		int attackForce = Global::getInstance()->getAttackForce()[type]; 
		pCurrentWarrior_ = WarriorFactory::createWarrior(type, this, totalWarrior_ + 1, health, attackForce); 
		warriors_.push_back(pCurrentWarrior_);
		health_ -= health;
		totalWarrior_ += 1;
		pCurrentWarrior_->getReady();
		pCurrentWarrior_->printCreation();
	} 
	else
	{
		pCurrentWarrior_ = 0;
	}	
}
void Headquarter::addRewardWarrior(Warrior* warrior) 
{ 
	rewardList_.push_back(warrior); 
}
 
int Headquarter::getHealth() const
{ 
	return health_;
}	
 
void Headquarter::rewardWarrior() 
{ 	
	sort(rewardList_.begin(), rewardList_.end(), RewardOrder()); 
	for(vector<Warrior*>::const_iterator it = rewardList_.begin(); it != rewardList_.end(); ++it) 
	{ 
		if(health_ >= 8) 
		{
			(*it)->setHealth((*it)->getHealth() + 8); 
			health_  -= 8;
		}
		else
		{
			break;
		}
	}	
	rewardList_.clear(); 
}
 
bool Headquarter::isTaken() const  
{ 
	return enemies_.size() >= 2; 
}
 
void Headquarter::clearCurrentWarrior()
{ 
	pCurrentWarrior_ = NULL; 
}
 
void Headquarter::lionEscape() 
{ 
	if(pCurrentWarrior_ && pCurrentWarrior_->isAlive() &&  pCurrentWarrior_->escape()) 
	{ 
		pCurrentWarrior_ = NULL; 
	}
}
 
void Headquarter::invaded(Warrior* enemy)
{
	if(enemy && enemy->isAlive())
	{ 
		enemy->updateMove();
		printf("%s %s reached %s headquarter with %d elements and force %d\n", \
			Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			enemy->getFullName().c_str(), color_names[color_].c_str(), \
			enemy->getHealth(), enemy->getAttackForce());
		enemies_.push_back(enemy);
	}
	if(isTaken()) 
	{ 
		printf("%s %s headquarter was taken\n",
			Global::getInstance()->getTimer()->getTimeInString().c_str(), color_names[color_].c_str());
	}
}
 
void Headquarter::reportHealth() 
{ 
	printf("%s %d elements in %s headquarter\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			getHealth(), color_names[color_].c_str()); 
} 
 
Warrior* Headquarter::getCurrentWarrior() 
{ 
	return pCurrentWarrior_;
} 
 
void Headquarter::collectHealth(int health)
{ 
	collectedHealth_ += health;
}
 
void Headquarter::mergeHealth()
{ 
	health_ += collectedHealth_; 
	collectedHealth_ = 0; 
} 
 
COLOR Headquarter::getColor() const 
{ 
	return color_;
}
/*
void Headquarter::reportWarrior(COLOR color) 
{ 
}*/
 
 
/********************** 	Redquarter implementation 	********************/
Redquarter::Redquarter(int health, COLOR color) : Headquarter(health, color)
{
	warriorTypeOrder_.push_back(ICEMAN);
	warriorTypeOrder_.push_back(LION);
	warriorTypeOrder_.push_back(WOLF);
	warriorTypeOrder_.push_back(NINJA);
	warriorTypeOrder_.push_back(DRAGON);
} 
 
void Redquarter::reportWarrior(COLOR color) 
{ 
	if(color == RED && pCurrentWarrior_ && pCurrentWarrior_->isAlive()) 
	{ 
		pCurrentWarrior_->reportWeapons();
	} 
	if(color == BLUE && !enemies_.empty()) 
	{ 
		for(vector<Warrior*>::const_iterator it = enemies_.begin();\
				it != enemies_.end(); ++it)
		{ 
			(*it)->reportWeapons();
		}
	}
} 
 
 
/******************** 		Bluequarter implementation	*******************/
Bluequarter::Bluequarter(int health, COLOR color) : Headquarter(health, color)
{
	warriorTypeOrder_.push_back(LION);
	warriorTypeOrder_.push_back(DRAGON);
	warriorTypeOrder_.push_back(NINJA);
	warriorTypeOrder_.push_back(ICEMAN);
	warriorTypeOrder_.push_back(WOLF);
	
}
 
void Bluequarter::reportWarrior(COLOR color) 
{ 	
	if(color == BLUE && pCurrentWarrior_ && pCurrentWarrior_->isAlive()) 
	{ 
		pCurrentWarrior_->reportWeapons();
	} 
	if(color == RED && !enemies_.empty()) 
	{ 
		for(vector<Warrior*>::const_iterator it = enemies_.begin();\
				it != enemies_.end(); ++it)
		{ 
			(*it)->reportWeapons();
		}
	}
} 
 
/********************* 		Game implementation  		**********************/
class Game 
{ 
	enum   GAME_STATE
	{  
		CREATE_WARRIOR = 0,
		LION_ESCAPE = 5,   
		MOVE_WARROIR = 10, 
		GENERATE_HEALTH = 20, 
		COLLECT_HEALTH = 30, 
		SHOT_ARROW = 35,
		USE_BOMB = 38, 
		START_BATTLE = 40, 
		HEADQUARTER_REPORT = 50, 
		WARRIOR_REPORT = 55
	}; 
public: 
	Game();
	~Game(); 
	void start() 		
	{ 	
		string message;
		getline(cin, message);
		caseNumber_ = atoi(message.c_str());
		int caseNum = 0; 
		while(caseNum < caseNumber_) 
		{ 
			caseNum++;
			printf("Case %d:\n", caseNum);
			setUp();
			run();
			tearDown();
		} 
	}
	void setUp() 
	{ 
		getInput(); 
		initialize();  
	}
	void tearDown() 
	{ 
		dispose(); 
	}
private:
	void run()  
	{ 
		while(!pTimer_->isOver() && !pRed_->isTaken() && !pBlue_->isTaken())   
		{ 
			switch(pTimer_->getTimeInMins()) 
			{
				 
				case CREATE_WARRIOR:
					createWarrior(); 
					break;	
				case LION_ESCAPE:
					lionEscape();
					break;
				case MOVE_WARROIR:
					moveWarrior();
					break;
				
 				case GENERATE_HEALTH:
					generateHealth(); 
					break;
				case COLLECT_HEALTH:
					collectHealth(); 
					break;
				case SHOT_ARROW:
					shotArrow();
					break;
				case USE_BOMB:
					useBomb(); 
					break;
				case START_BATTLE:
					startBattle();
					break;
				case HEADQUARTER_REPORT:
					reportHeadquarter(); 
					break;
				case WARRIOR_REPORT:
					reportWarrior(); 
					break; 
				default:
					break;
			}
			pTimer_->increaseTime();	
		}  
	}
private: 
	void createWarrior()  
	{ 
 		pRed_->createWarrior();
		pBlue_->createWarrior(); 
	} 
	void lionEscape()
	{
		pRed_->lionEscape();
		for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
		{ 
			(*it)->lionEscape(); 
		} 
		pBlue_->lionEscape(); 
	} 
	//at least one city between two headquarters.
	void moveWarrior() 
	{ 
		Warrior* movedRed = pRed_->getCurrentWarrior();
		Warrior* movedBlue = NULL;
		Warrior* tempRed = NULL;
		pRed_->invaded(cities_.at(0)->getBlue());
		for(int index  = 0 ;  index < cities_.size(); ++index)  
		{ 			
			tempRed = cities_.at(index)->getRed(); 
			if( cities_.size() - 1 == index)  
			{ 
				movedBlue = pBlue_->getCurrentWarrior();
			} 
			else 
			{ 
				movedBlue = cities_.at(index + 1)->getBlue();
			}
			cities_.at(index)->visitedByRed(movedRed);
			cities_.at(index)->visitedByBlue(movedBlue);  	
			movedRed = tempRed; 
		} 
		pBlue_->invaded(movedRed);
		//set pCurrentWarrior pointer to NULL in headquarter.
		pRed_->clearCurrentWarrior();
		pBlue_->clearCurrentWarrior();
	}
 
	void generateHealth() 
	{
		for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
		{ 
			(*it)->generateHealth(); 
		} 
	} 
 
	void collectHealth()
	{ 
		for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
		{ 
			(*it)->collectHealth(); 
		} 
		pRed_->mergeHealth();
		pBlue_->mergeHealth();
	} 
 
	void shotArrow() 
	{  
		Warrior* redAttacker = NULL; 
		Warrior* blueAttacker = NULL;
		//make sure there are at least two cities between headquarters for arrow attack to occur. 
		if(cities_.size() > 1) 
		{ 
			for(int index = 0; index < cities_.size(); ++index) 
			{ 
				redAttacker = cities_.at(index)->getRed(); 
				blueAttacker = cities_.at(index)->getBlue(); 
				if( index == 0) 
				{ 
					cities_.at(index + 1)->attackByArrow(redAttacker); 
				} 
				else if ( index == cities_.size() - 1) 
				{ 
					cities_.at(index - 1)->attackByArrow(blueAttacker); 
				} 
				else 
				{ 
					cities_.at(index + 1)->attackByArrow(redAttacker); 
					cities_.at(index - 1)->attackByArrow(blueAttacker); 
				}
			}
		}	
	}
 
	void useBomb() 
	{ 
		for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
		{ 
			(*it)->useBomb(); 
		} 
	}
 
	void startBattle() 
	{ 	
		for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
		{ 
			(*it)->battle(); 
		} 
		pRed_->rewardWarrior();
		pRed_->mergeHealth();
		pBlue_->rewardWarrior();
		pBlue_->mergeHealth();
	}
 
	void reportWarrior()
	{ 
		pRed_->reportWarrior(RED); //red color
		for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
		{ 
			(*it)->reportWarrior(RED); 
		} 
		pBlue_->reportWarrior(RED); 
	
		pRed_->reportWarrior(BLUE); //blue color
		for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
		{ 
			(*it)->reportWarrior(BLUE); 
		} 
		pBlue_->reportWarrior(BLUE); 
	}
 
	void reportHeadquarter() 
	{ 
 		pRed_->reportHealth(); 
		pBlue_->reportHealth(); 
	}
private:
	void getInput() 
	{ 
		string message; 
		vector<int> combined; 
		vector<string> results; 
		getline(cin, message); 
		Util::split(message, " ", results); 
		for(vector<string>::const_iterator it = results.begin(); it != results.end(); ++it) 
		{ 
			combined.push_back(atoi(it->c_str())); 
		}
 
		getline(cin, message); 
		results.clear(); 
		Util::split(message, " ", results); 
		vector<int> health; 
		for(vector<string>::const_iterator it = results.begin(); it != results.end(); ++it) 
		{ 
			health.push_back(atoi(it->c_str())); 
		}
		
		getline(cin, message); 
		results.clear();
		Util::split(message, " ", results); 
		vector<int> forces; 	
		for(vector<string>::const_iterator it = results.begin(); it != results.end(); ++it) 
		{ 
			forces.push_back(atoi(it->c_str())); 
		}
	
		Global::getInstance()->setCombined(combined); 
		Global::getInstance()->setHealth(health); 
		Global::getInstance()->setAttackForce(forces); 
	} 
 
	void initialize() 
	{ 
		pTimer_ = new Timer(Global::getInstance()->getCombined()[Global::T]); 
		Global::getInstance()->setTimer(pTimer_); 
		
		//creates cities; 
		for(int i = 1; i <  Global::getInstance()->getCombined()[Global::N] + 1; ++i)  
		{ 
			cities_.push_back(new City(i)); 
		}
 
		pRed_ = new Redquarter(Global::getInstance()->getCombined()[Global::M]); 
		pBlue_ = new Bluequarter(Global::getInstance()->getCombined()[Global::M]);
	}
	void dispose() 
	{ 
		if(pTimer_)
		{ 
			delete pTimer_;
			pTimer_ = NULL;
		}
		if(pRed_)
		{ 
			delete pRed_;
			pRed_ = NULL;
		}
		if(pBlue_)
		{ 
			delete pBlue_;
			pBlue_ = NULL;
		}
		if(!cities_.empty()) 
		{ 
			for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
			{ 
				delete (*it);
			}
			cities_.clear();
		}
		Global::destroy(); 
	}
private: 
	Headquarter* pRed_; 
	Headquarter* pBlue_; 
	vector<City*> cities_; 
	Timer* pTimer_; 
	int caseNumber_;
};
 
Game::Game()
:pRed_(NULL), pBlue_(NULL),pTimer_(NULL), caseNumber_(0) 
{
}
 
Game::~Game()
{
} 
 
 
int main()
{ 
 	Game game;
	game.start();
	return 0;
} 
