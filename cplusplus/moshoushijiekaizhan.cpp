#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define WARRIOR_NUM 5
#define WEAPON_NUM 3

int Time = 0, K = 0, N = 0;

class City;
class Headquarter;
class Weapon;

class Warrior{
public:
	int idNumber;    // 武士种类，生命值
	int weaponNum;
	int curIndexWeapon;
	Weapon *pWeapon[10];
	
public:
	bool liveFlag;
	int health, attack, idKind;
	int swordNum, bombNum, arrowNum;
	Headquarter *pHeadquarter;                          // 属于哪个司令部
	static string warriorName[WARRIOR_NUM];             // 存放对应种类的武士名
	static string weaponName[WEAPON_NUM];
	static int warriorHealth[WARRIOR_NUM];              // 存放对应种类的武士生命值
	static int warriorAttack[WARRIOR_NUM];
	Warrior(Headquarter *head_, int id_, int health_, int weaponNum_);  // 构造函数，初始化武士，需指明所属的司令部，种类，生命值
	//~Warrior();
	virtual void Print();                               // 打印当前武士的信息
	void Attack(Warrior *p);
	void Hurt(int strength);
	virtual void GoAhead();
	void Report();
	virtual void Cheer(){};
	virtual void Rob(Warrior *p){};
	void GetWeapon(Warrior *p);
};

class Headquarter{
private:
	int color;                                 // 司令部的颜色
	int eachWarriorNum[WARRIOR_NUM];           // 各类武士的数量
	int curSeqIndex;                           // 该武士处于当前序列的第几个
	Warrior *pWarrior[1000];                   // 存放各个武士的指针

	
public:
	City *pCity;
	int totalHealth;                           // 生命元总数
    int totalWarriorNum;                       // 战士总数
	bool stopState;                            // 制造武士的状态
	static int madeOrder[2][WARRIOR_NUM];      // 武士的制造顺序
	Headquarter(int totalHealth_, int color_, City *p); // 构造函数，使用总生命值和颜色初始化
	~Headquarter();                            // 析构函数，清理司令部中各个战士的内存
	void ProduceWarrior();            // 制造武士
	friend class Warrior;                      // 声明友元类，使得在可以访问当前武士的司令部的私有成员的信息
	void Report();
	string GetColor();                         // 获得当前司令部的颜色
	
};

class Weapon{
public:
	int useTimes;
public:
	int idWeaponKind;
	Weapon(int kind);
	static string weaponName[WEAPON_NUM];
	bool operator < (const Weapon & temp) const {
		return (this ->idWeaponKind < temp.idWeaponKind || this->useTimes < temp.useTimes);
	}
};

class Sword:public Weapon{
public:
	Sword(): Weapon(0) {}
};

class Bomb:public Weapon{
public:
	Bomb(): Weapon(1) {}
};

class Arrow:public Weapon{
public:
	Arrow(): Weapon(2) {}
};

class City{
public:
	int id;
	bool isFighted;
	Warrior *pRedWarrior, *pBlueWarrior;
	
	City(int id_);
	int Fighting();
};

Weapon::Weapon(int kind):idWeaponKind(kind), useTimes(0) {}



bool cmp1(const Weapon *pWeapon1, const Weapon *pWeapon2){
	return (pWeapon1->idWeaponKind < pWeapon2->idWeaponKind) && (pWeapon1->useTimes < pWeapon2->useTimes);
}

bool cmp2(const Weapon *pWeapon1, const Weapon *pWeapon2){
	return (pWeapon1->idWeaponKind < pWeapon2->idWeaponKind) && (pWeapon1->useTimes > pWeapon2->useTimes);
}

City::City(int id_): id(id_) {
	pRedWarrior = NULL;
	pBlueWarrior = NULL;
	isFighted = false;
}

int City::Fighting(){
	int result = 0;
	if (pRedWarrior != NULL && pBlueWarrior != NULL) {
		isFighted = true;
		// pRedWarrior->Sort();
		
		sort(pRedWarrior->pWeapon, pRedWarrior->pWeapon + pRedWarrior->weaponNum, cmp1);
		sort(pBlueWarrior->pWeapon, pBlueWarrior->pWeapon + pBlueWarrior->weaponNum, cmp1);
		// pBlueWarrior->Sort();
		while (true) {
			if (pRedWarrior->weaponNum == 0 && pBlueWarrior->weaponNum == 0) {
				printf("%03d:40 both red %s %d and blue %s %d were alive in city %d\n",
						Time, Warrior::warriorName[pRedWarrior->idKind].c_str(), pRedWarrior->idNumber,
						Warrior::warriorName[pBlueWarrior->idKind].c_str(), pBlueWarrior->idNumber, id);
				result = 0;
				//cerr << "I only want to know what problem happened!138\n" ;
				break;
			}
				if (pRedWarrior->health <= 0 && pBlueWarrior->health > 0) {
					printf("%03d:40 blue %s %d killed red %s %d in city %d remaining %d elements\n",
							Time, Warrior::warriorName[pBlueWarrior->idKind].c_str(), pBlueWarrior->idNumber,
							Warrior::warriorName[pRedWarrior->idKind].c_str(), pRedWarrior->idNumber, id, pBlueWarrior->health);
					//cerr << "err1\n";
					//delete pRedWarrior;
					sort(pRedWarrior->pWeapon, pRedWarrior->pWeapon + pRedWarrior->weaponNum, cmp2);
					//sort(pBlueWarrior->pWeapon, pBlueWarrior->pWeapon + pBlueWarrior->weaponNum, cmp2);
					cerr << "err\n";
					pBlueWarrior->GetWeapon(pRedWarrior);
					pRedWarrior = NULL;
					result = -1;
					break;
				}
				if (pRedWarrior->health > 0 && pBlueWarrior->health <= 0) {
					printf("%03d:40 red %s %d killed blue %s %d in city %d remaining %d elements\n",
							Time, Warrior::warriorName[pRedWarrior->idKind].c_str(), pRedWarrior->idNumber,
							Warrior::warriorName[pBlueWarrior->idKind].c_str(), pBlueWarrior->idNumber, id, pRedWarrior->health);
					//cerr << "err3\n";
					//delete pBlueWarrior;
					//sort(pRedWarrior->pWeapon, pRedWarrior->pWeapon + pRedWarrior->weaponNum, cmp1);
					sort(pBlueWarrior->pWeapon, pBlueWarrior->pWeapon + pBlueWarrior->weaponNum, cmp1);
					cerr << "err4\n";
					pRedWarrior->GetWeapon(pBlueWarrior);
					//cerr << "err5\n";
					pBlueWarrior = NULL;
					result = 1;
					break;
				}
				if (pRedWarrior->health <= 0 && pBlueWarrior->health <= 0) {
					printf("%03d:40 both red %s %d and blue %s %d died in city %d\n",
						Time, Warrior::warriorName[pRedWarrior->idKind].c_str(), pRedWarrior->idNumber,
						Warrior::warriorName[pBlueWarrior->idKind].c_str(), pBlueWarrior->idNumber, id);
					//delete pRedWarrior;
					pRedWarrior = NULL;
					//delete pBlueWarrior;
					pBlueWarrior = NULL;
					result = 2;
					break;
				}
			//printf("forever\n");
			if (id % 2 == 1) {
				//cerr << "I only want to know what problem happened!1385\n" ;
				pRedWarrior->Attack(pBlueWarrior);
				//cerr << "I only want to know what problem happened!1384\n" ;
				if (pBlueWarrior->health <= 0) continue;
				cerr << "I only want to know what problem happened!1380\n" ;
				pBlueWarrior->Attack(pRedWarrior);
				//cerr << "I only want to know what problem happened!1385\n" ;
			} else {
				//cerr << "I only want to know what problem happened!1386\n" ;
				pBlueWarrior->Attack(pRedWarrior);
				//cerr << "I only want to know what problem happened!1388\n" ;
				if (pRedWarrior->health <= 0) continue;
				cerr << "I only want to know what problem happened!1389\n" ;
				pRedWarrior->Attack(pBlueWarrior);
				//cerr << "I only want to know what problem happened!1387\n" ;
				cerr << "I only want to know what problem happened!1386\n" ;
			}
		}
		
		if (isFighted && pRedWarrior != NULL && pRedWarrior->idKind == 0) {
			printf("%03d:40 %s dragon %d yelled in city %d\n", 
				Time, pRedWarrior->pHeadquarter->GetColor().c_str(), pRedWarrior->idNumber, id);
		}
		//cerr << "in the line Fighting start2!\n";
		if (isFighted && pBlueWarrior != NULL && pBlueWarrior->idKind == 0) {
			printf("%03d:40 %s dragon %d yelled in city %d\n", 
				Time, pBlueWarrior->pHeadquarter->GetColor().c_str(), pBlueWarrior->idNumber, id);
		}
		isFighted = false;
	}
	return result;
}


class dragon: public Warrior {
private:
	double morale;
public:
	dragon(Headquarter *head_, int id_, int health_):Warrior(head_, id_, health_, 1){
		morale = (double)head_->totalHealth / Warrior::warriorHealth[id_];
	}
	
/* 	virtual void Attack(Warrior *p) {
		if (weaponNum <= 0) return;
		switch(pWeapon[0]->idWeaponKind){
			case 0:
				p->Hurt(this->attack * 2 / 10);
				break;
			case 1:
				p->Hurt(this->attack * 4 / 10);
				this->Hurt((this->attack * 4 / 10) / 2);
				weaponNum--;
				bombNum--;
				pWeapon[0] = NULL;
				break;
			case 2:
				if(pWeapon[0]->useTimes >= 2) {
					weaponNum--;
					arrowNum--;
					pWeapon[0] = NULL;
				} else {
					p->Hurt(this->attack * 3 / 10);
					pWeapon[0]->useTimes++;
				}
				break;	
			default:;
		}
	} */

};

class ninja: public Warrior {
public:
	ninja(Headquarter *head_, int id_, int health_):Warrior(head_, id_, health_, 2){}
	
/* 	virtual void Attack(Warrior *p) {
		if (weaponNum <= 0) return;
		int i = curIndexWeapon;
		switch(pWeapon[i]->idWeaponKind){
			case 0:
				p->Hurt(this->attack * 2 / 10);
				if (weaponNum == 2) curIndexWeapon = (curIndexWeapon + 1)%2;
				break;
			case 1:
				p->Hurt(this->attack * 4 / 10);
				if (weaponNum == 2) curIndexWeapon = (curIndexWeapon + 1)%2;
				weaponNum--;
				bombNum--;
				pWeapon[i] = NULL;
				break;
			case 2:
				p->Hurt(this->attack * 3 / 10);
				pWeapon[i]->useTimes++;
				if (weaponNum == 2) curIndexWeapon = (curIndexWeapon + 1)%2;
				if(pWeapon[i]->useTimes >= 2) {
					weaponNum--;
					arrowNum--;
					pWeapon[i] = NULL;
				}
				break;	
			default:;
		}
		
	} */

	
};

class iceman: public Warrior {
public:
	iceman(Headquarter *head_, int id_, int health_):Warrior(head_, id_, health_, 1){}
	
/* 	virtual void Attack(Warrior *p) {
		if (weaponNum <= 0) return;
		switch(pWeapon[0]->idWeaponKind){
			case 0:
				p->Hurt(this->attack * 2 / 10);
				break;
			case 1:
				p->Hurt(this->attack * 4 / 10);
				this->Hurt((this->attack * 4 / 10) / 2);
				weaponNum--;
				bombNum--;
				pWeapon[0] = NULL;
				break;
			case 2:
				if(pWeapon[0]->useTimes >= 2) {
					weaponNum--;
					arrowNum--;
					pWeapon[0] = NULL;
				} else {
					p->Hurt(this->attack * 3 / 10);
					pWeapon[0]->useTimes++;
				}
				break;	
			default:;
		}
	} */
	
	virtual void GoAhead(){
		health = health - (int)((double)health/10.0); 
	}
};

class lion: public Warrior {
public:
	int loyalty;
public:
	lion(Headquarter *head_, int id_, int health_):Warrior(head_, id_, health_, 1){
		loyalty = head_->totalHealth;
	}
/* 	virtual void Attack(Warrior *p) {
		if (weaponNum <= 0) return;
		switch(pWeapon[0]->idWeaponKind){
			case 0:
				p->Hurt(this->attack * 2 / 10);
				break;
			case 1:
				p->Hurt(this->attack * 4 / 10);
				this->Hurt((this->attack * 4 / 10) / 2);
				weaponNum--;
				bombNum--;
				pWeapon[0] = NULL;
				break;
			case 2:
				if(pWeapon[0]->useTimes >= 2) {
					weaponNum--;
					arrowNum--;
					pWeapon[0] = NULL;
				} else {
					p->Hurt(this->attack * 3 / 10);
					pWeapon[0]->useTimes++;
				}
				break;	
			default:;
		}
	} */
	
	virtual void GoAhead(){
		loyalty -= K; 
	}
	
	void Runaway(){
		liveFlag = false;
		printf("%03d:05 %s %s %d ran away", Time, pHeadquarter->GetColor().c_str(),
				Warrior::warriorName[idKind].c_str(), idNumber);
	}

	void Print(){
		Warrior::Print();
		printf("Its loyalty is %d\n", loyalty);
	}	
};

class wolf: public Warrior {
public:
	wolf(Headquarter *head_, int id_, int health_):Warrior(head_, id_, health_, 0) {
		memset(pWeapon, 0, 10 * sizeof(int));
	}
/* 	virtual void Attack(Warrior *p) {
		for (int i = 0; i < weaponNum; ++i) {
			switch(pWeapon[i]->idWeaponKind){
				case 0:
					p->Hurt(this->attack * 2 / 10);
					break;
				case 1:
					p->Hurt(this->attack * 4 / 10);
					this->Hurt((this->attack * 4 / 10) / 2);
					break;
				case 2:
					if(pWeapon[i]->useTimes >= 2) ;
					else {
						p->Hurt(this->attack * 3 / 10);
						pWeapon[i]->useTimes++;
					}
					break;	
				default:;
			}
		}
	}
	 */
	void Rob(Warrior *p){
			sort(p->pWeapon, p->pWeapon + p->weaponNum, cmp2);
					//sort(pBlueWarrior->pWeapon, pBlueWarrior->pWeapon + pBlueWarrior->weaponNum, cmp2);
			GetWeapon(p);
	}
};



Warrior::Warrior(Headquarter *head_, int id_, int health_, int weaponNum_):
					pHeadquarter(head_), idKind(id_), health(health_){
	pHeadquarter->pWarrior[pHeadquarter->totalWarriorNum] = this;
	idNumber = pHeadquarter->totalWarriorNum + 1;
	attack = Warrior::warriorAttack[idKind];
	weaponNum = weaponNum_;
	liveFlag = true;
	swordNum = 0;
	bombNum = 0;
	arrowNum = 0;
	curIndexWeapon = 0;
	int idWeaponKind[10];
	for (int i = 0; i < weaponNum; ++ i) {
		idWeaponKind[i] = (idNumber + i) % WEAPON_NUM;
		switch(idWeaponKind[i]) {
		case 0:
			pWeapon[i] = new Sword();
			swordNum++;
			break;
		case 1: 
			pWeapon[i] = new Bomb();
			bombNum++;
			break;
		case 2:
			pWeapon[i] = new Arrow();
			arrowNum++;
			break;
		default:;
		}
	}
	if (pHeadquarter->color == 0) {
		pHeadquarter->pCity->pRedWarrior = this;
	} else if (pHeadquarter->color == 1) {
		pHeadquarter->pCity->pBlueWarrior = this;
	}
}

/* Warrior::~Warrior() {
	for (int i = 0; i < weaponNum; ++ i) {
		if (pWeapon[i] != NULL) {
			delete pWeapon[i];
			pWeapon[i] = NULL;
		}
	}
} */

void Warrior::Print(){
	char color_[10], name_[10];
	strcpy(color_, pHeadquarter->GetColor().c_str());
	strcpy(name_, Warrior::warriorName[idKind].c_str()); 
	printf("%03d:00 %s %s %d born\n", Time, color_, name_, idNumber);
}

void Warrior::GoAhead(){}

void Warrior::Report(){
	if (pHeadquarter == NULL) {
		printf("This is a error about pHeadquarter!\n");
		return;
	}
/* 			printf("0hello world!\n");
			printf("0hello world!\n");
			printf("0hello world!\n");
			printf("0hello world!\n"); */
	printf("%03d:55 %s %s %d has %d sword %d bomb %d arrow and %d elements\n", 
			Time, pHeadquarter->GetColor().c_str(), Warrior::warriorName[idKind].c_str(),
			idNumber, swordNum, bombNum, arrowNum, health);

}

void Warrior::GetWeapon(Warrior *p){
	for (int i = 0; weaponNum <= 10 && p->pWeapon[i] != NULL; ++ i) {
		pWeapon[weaponNum] = p->pWeapon[i];
		weaponNum++;
		switch (p->pWeapon[i]->idWeaponKind){
			case 0: swordNum++; break;
			case 1: bombNum++; break;
			case 2: arrowNum++; break;
			default:;
		}
	}
}

void Warrior::Attack(Warrior *p){
	if (p == NULL) cerr << "p is NULL" << endl;
	if (pWeapon[curIndexWeapon] == NULL) {
		cerr << "pwea is NULL" << weaponNum << "   " << curIndexWeapon<<endl; 
		return;
	}
	switch(pWeapon[curIndexWeapon]->idWeaponKind){
				case 0:
					cerr << "I only want to know what problem happened!1390\n" ;
					p->Hurt(this->attack * 2 / 10);
					curIndexWeapon = (curIndexWeapon + 1) % weaponNum;
					break;
				case 1:
					cerr << "I only want to know what problem happened!1382\n" ;
					p->Hurt(this->attack * 4 / 10);
					this->Hurt((this->attack * 4 / 10) / 2);
					weaponNum--;
					bombNum--;
					delete pWeapon[curIndexWeapon];
					
					if (weaponNum != 0) {
						//cerr << "I only want to know what problem happened!138\n" ;
						for (int i = curIndexWeapon; i < weaponNum; ++ i) {
							//cerr << "I only want to know what problem happened!138\n" ;
							pWeapon[i] = pWeapon[i + 1];
						}
					}
					//cerr << "I only want to know what problem happened!1382\n" ;
					pWeapon[weaponNum] = NULL;
					//cerr << "I only want to know what problem happened!1382\n" ;
					break;
				case 2:
					cerr << "I only want to know what problem happened!1383\n" ;
					p->Hurt(this->attack * 3 / 10);
					pWeapon[curIndexWeapon]->useTimes++;
					
					if(pWeapon[curIndexWeapon]->useTimes >= 2) {
						weaponNum--;
						arrowNum--;
						delete pWeapon[curIndexWeapon];
						if (weaponNum != 0) {
							for (int i = curIndexWeapon; i < weaponNum; ++ i) {
								pWeapon[i] = pWeapon[i + 1];
							}
						}
							//cerr << "I only want to know what problem happened!1383\n" ;
							pWeapon[weaponNum] = NULL;
					} else {
						curIndexWeapon = (curIndexWeapon + 1) % weaponNum;
					}
					//cerr << "I only want to know what problem happened!1383\n" ;
					break;	
				default:;
	}
}
void Warrior::Hurt(int strength){
	health -= strength;
	// printf("hahahahhah...\n");
	if (this->health <= 0) liveFlag = false;
}

Headquarter::Headquarter(int totalHealth_, int color_, City *p){
	pCity = p;
	totalHealth = totalHealth_;
	color = color_;
	totalWarriorNum = 0;
	curSeqIndex = 0;
	stopState = false;
	memset(eachWarriorNum, 0, sizeof(eachWarriorNum));
}

Headquarter::~Headquarter(){
	for (int i = 0; i < totalWarriorNum; i++){
		if(pWarrior[i] != NULL) delete pWarrior[i];
	}
}

void Headquarter::ProduceWarrior(){
	if (stopState) {
		return;
	}
	bool flag = false;
	for (int i = 0; i < WARRIOR_NUM; i++){
		curSeqIndex %= WARRIOR_NUM;
		int kind = madeOrder[color][curSeqIndex];
		if (totalHealth >= Warrior::warriorHealth[kind]){
			totalHealth -= Warrior::warriorHealth[kind];
			eachWarriorNum[curSeqIndex]++;
			int kind = Headquarter::madeOrder[color][curSeqIndex];
			int health_ = Warrior::warriorHealth[kind];
			switch (kind) {
				case 0:
					pWarrior[totalWarriorNum] = new dragon(this, kind, health_);
					break;
				case 1:
					pWarrior[totalWarriorNum] = new ninja(this, kind, health_);
					break;
				case 2:
					pWarrior[totalWarriorNum] = new iceman(this, kind, health_);
					break;
				case 3:
					pWarrior[totalWarriorNum] = new lion(this, kind, health_);
					break;
				case 4:
					pWarrior[totalWarriorNum] = new wolf(this, kind, health_);
					break;
				default:
					cout << "The warrior kind id is wrong!" << endl;
			}
			pWarrior[totalWarriorNum]->Print();
			totalWarriorNum++;
			flag = true;
		}
		curSeqIndex++;
		if (flag) break;
	}
	if (flag == false) {
		stopState = true;
		char color_[10];
        strcpy(color_, GetColor().c_str());
		printf("%03d %s headquarter stops making warriors\n", Time, color_);
	}
	
	return;
}

string Headquarter::GetColor(){
	if (color == 0) {
		return "red";
	} else if (color == 1) {
		return "blue";
	} else {
		return "This is an error!";
	}
}

void Headquarter::Report(){
	printf("%03d:50 %d elements in %s headquarter\n", Time, totalHealth, this->GetColor().c_str());
}

int Headquarter::madeOrder[2][WARRIOR_NUM] = {{2, 3, 4, 1, 0},
                                              {3, 0, 1, 2, 4}};
string Warrior::warriorName[WARRIOR_NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string Weapon::weaponName[WEAPON_NUM] = {"sword", "bomb", "arrow"};
int Warrior::warriorHealth[WARRIOR_NUM];
int Warrior::warriorAttack[WARRIOR_NUM];

void Init(City *pCity[], int N){
	for (int i = 0; i <= N + 1; i++) {
		pCity[i] = new City(i);
		if (pCity[i] == NULL) cerr << "error happen!\n" << endl;
	}
}

void ProduceWarrior(Headquarter *pRed, Headquarter *pBlue) {
	pRed->ProduceWarrior();
	pBlue->ProduceWarrior();
}

void LionRunaway(City *pCity[], int N) {
	for (int i = 0; i <= N + 1; ++ i) {
		if (pCity[i]->pRedWarrior == NULL) return;
		if (pCity[i]->pRedWarrior->idKind == 3 && ((lion *)(pCity[i]->pRedWarrior))->loyalty <= 0) {
			pCity[i]->pRedWarrior = NULL;
		}
	}
}

int GoAhead(City *pCity[], int N) {
	
	for (int i = N; i >= 0; -- i) {
		if (pCity[i]->pRedWarrior != NULL && pCity[i + 1]->pRedWarrior == NULL) {
			pCity[i]->pRedWarrior->GoAhead();
			pCity[i + 1]->pRedWarrior = pCity[i]->pRedWarrior;
			pCity[i]->pRedWarrior = NULL;
		}
	}
	for (int i = 1; i <= N + 1; ++ i) {
		if (pCity[i - 1]->pBlueWarrior == NULL && pCity[i]->pBlueWarrior != NULL) {
			pCity[i]->pBlueWarrior->GoAhead();
			pCity[i - 1]->pBlueWarrior = pCity[i]->pBlueWarrior;
			pCity[i]->pBlueWarrior = NULL;
		}
	}
	for (int i = 0; i <= N + 1; ++ i) {
		
		if (pCity[i]->pRedWarrior != NULL) {
			//printf("你有没有到这啊？\n");
			printf("%03d:10 red %s %d marched to city %d with %d elements and force %d\n",
					Time, Warrior::warriorName[pCity[i]->pRedWarrior->idKind].c_str(), pCity[i]->pRedWarrior->idNumber,
					i, pCity[i]->pRedWarrior->health, pCity[i]->pRedWarrior->attack);
			//printf("你有没有到这啊？\n");
		}
		if (pCity[i]->pBlueWarrior != NULL) {
			//printf("你有没有到这啊？\n");
			printf("%03d:10 blue %s %d marched to city %d with %d elements and force %d\n",
					Time, Warrior::warriorName[pCity[i]->pBlueWarrior->idKind].c_str(), pCity[i]->pBlueWarrior->idNumber,
					i, pCity[i]->pBlueWarrior->health, pCity[i]->pBlueWarrior->attack);
			//printf("你有没有到这啊？\n");
		}
		
	}
	// printf("here!lll\n");
	if (pCity[0]->pBlueWarrior != NULL) {
		printf("%03d:10 blue %s %d reached red headquarter with %d elements and force %d\n",
				Time, Warrior::warriorName[pCity[0]->pBlueWarrior->idKind].c_str(), pCity[0]->pBlueWarrior->idNumber,
				pCity[0]->pBlueWarrior->health, pCity[0]->pBlueWarrior->attack);
		printf("%03d:10 red headquarter was taken\n", Time);
		return 1;
	}
	// printf("here!222\n");
	if (pCity[N + 1]->pRedWarrior != NULL) {
		printf("%03d:10 red %s %d reached blue headquarter with %d elements and force %d\n",
				Time, Warrior::warriorName[pCity[N + 1]->pRedWarrior->idKind].c_str(), pCity[N + 1]->pRedWarrior->idNumber,
				pCity[N + 1]->pRedWarrior->health, pCity[N + 1]->pRedWarrior->attack);
		printf("%03d:10 blue headquarter was taken\n", Time);
		return 1;
	}
	// printf("here!222\n");
	return 0;
}

void WolfRob(City *pCity[], int N) {
	for (int i = 1; i <= N; ++ i) {
		if ((pCity[i]->pRedWarrior != NULL 
			&& pCity[i]->pRedWarrior->idKind == 5) 
			&& (pCity[i]->pBlueWarrior != NULL 
			&& pCity[i]->pBlueWarrior->idKind != 5)) {
				
			pCity[i]->pRedWarrior->Rob(pCity[i]->pBlueWarrior);	
		}
		if ((pCity[i]->pRedWarrior != NULL 
			&& pCity[i]->pRedWarrior->idKind != 5) 
			&& (pCity[i]->pBlueWarrior != NULL 
			&& pCity[i]->pBlueWarrior->idKind == 5)) {
			pCity[i]->pBlueWarrior->Rob(pCity[i]->pRedWarrior);	
		}
	}
}

int Fight(City *pCity[], int N) {
	for (int i = 1; i <= N; ++ i) {
		if (pCity[i]->pRedWarrior != NULL && pCity[i]->pBlueWarrior != NULL) {
			pCity[i]->Fighting();
		}
	}
}

void DragonCheer(City *pCity[], int N){
	for (int i = 1; i <= N; ++ i) {
		if (pCity[i]->isFighted && pCity[i]->pRedWarrior != NULL && pCity[i]->pRedWarrior->idKind == 0) {
			printf("%03d:40 %s dragon %d yelled in city %d\n", 
				Time, pCity[i]->pRedWarrior->pHeadquarter->GetColor().c_str(), pCity[i]->pRedWarrior->idNumber, pCity[i]->id);
		}
		if (pCity[i]->isFighted && pCity[i]->pBlueWarrior != NULL && pCity[i]->pBlueWarrior->idKind == 0) {
			printf("%03d:40 %s dragon %d yelled in city %d\n", 
				Time, pCity[i]->pBlueWarrior->pHeadquarter->GetColor().c_str(), pCity[i]->pBlueWarrior->idNumber, pCity[i]->id);
		}
		pCity[i]->isFighted = false;
	}
}

void HeadquarterReport(Headquarter *pRed, Headquarter *pBlue){
	pRed->Report();
	pBlue->Report();
}

void WarriorReport(City *pCity[], int N){
	for (int i = 1; i <= N; ++ i) {
		if (pCity[i] == NULL) {
			printf("here may be a mistake!\n");
			return;
		}
		if (pCity[i]->pRedWarrior != NULL) {
			pCity[i]->pRedWarrior->Report();
		}
		if (pCity[i]->pBlueWarrior != NULL) {
			pCity[i]->pBlueWarrior->Report();
		}
	}
}

void Destory(City *pCity[], int N){
	for (int i = 0; i < N; ++ i) {
		if (pCity[i] != NULL) {
			if (pCity[i]->pRedWarrior != NULL) {
				for (int j = 0; j < pCity[i]->pRedWarrior->weaponNum; ++ j) {
					if (pCity[i]->pRedWarrior->pWeapon[j] != NULL) {
						delete pCity[i]->pRedWarrior->pWeapon[j];
						pCity[i]->pRedWarrior->pWeapon[j] = NULL;
					}
				}
				delete pCity[i]->pRedWarrior;
				pCity[i]->pRedWarrior = NULL;
			}
			if (pCity[i]->pBlueWarrior != NULL) {
				for (int j = 0; j < pCity[i]->pBlueWarrior->weaponNum; ++ j) {
					if (pCity[i]->pBlueWarrior->pWeapon[j] != NULL) {
						delete pCity[i]->pBlueWarrior->pWeapon[j];
						pCity[i]->pBlueWarrior->pWeapon[j] = NULL;
					}
				}
				delete pCity[i]->pBlueWarrior;
				pCity[i]->pBlueWarrior = NULL;
			}
			delete pCity[i];
			pCity[i] = NULL;
		}
	}
}



int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n = 0, M = 0, T = 0;
	cin >> n;
	int cases = 2;
	while (n--) {
		printf("Case %d:\n", cases);
		scanf("%d %d %d %d", &M, &N, &K, &T);
		for (int i = 0; i < WARRIOR_NUM; ++ i) {
			scanf("%d", &Warrior::warriorHealth[i]);
		}
		for (int i = 0; i < WARRIOR_NUM; ++ i) {
			scanf("%d", &Warrior::warriorAttack[i]);
		}
		City *pCity[23];
		Init(pCity, N);
		Headquarter red(M, 0, pCity[0]), blue(M, 1, pCity[N + 1]);

		for (Time = 0; Time <= T; ++ Time) {
			// 武士降生
			ProduceWarrior(&red, &blue);
			// lion逃跑
			LionRunaway(pCity, N);	
			// 武士前进，抵达司令部，司令部被占领
/* 			printf("00hello world!\n");
			printf("00hello world!\n");
			printf("00hello world!\n");
			printf("00hello world!\n"); */
			GoAhead(pCity, N);
/* 			printf("0hello world!\n");
			printf("0hello world!\n");
			printf("0hello world!\n");
			printf("0hello world!\n"); */
			// wolf抢敌人武器
			WolfRob(pCity, N);
/* 			printf("1hello world!\n");
			printf("1hello world!\n");
			printf("1hello world!\n");
			printf("1hello world!\n"); */
			// 报告战斗情况
			Fight(pCity, N);
/* 			printf("2hello world!\n");
			printf("2hello world!\n");
			printf("2hello world!\n");
			printf("2hello world!\n"); */
			// 武士欢呼
			// DragonCheer(pCity, N);
			// 司令部报告生命元数量
/* 			printf("3hello world!\n");
			printf("3hello world!\n");
			printf("3hello world!\n");
			printf("3hello world!\n"); */
			HeadquarterReport(&red, &blue);
			// 武士报告情况
/* 			printf("3hello world!\n");
			printf("3hello world!\n");
			printf("3hello world!\n");
			printf("3hello world!\n"); */
			WarriorReport(pCity, N);
/* 			printf("3hello world!\n");
			printf("3hello world!\n");
			printf("3hello world!\n");
			printf("3hello world!\n"); */
		}
		Destory(pCity, N);
		cases++;
	}
	return 0;
}