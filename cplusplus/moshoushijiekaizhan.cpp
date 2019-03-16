#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

#define WARRIOR_NUM 5
#define WEAPON_NUM 3

class Headquarter;

class Warrior{
private:
	int idKind, health, idNumber, attack, weaponNum;                                 // 武士种类，生命值
	bool liveFlag;
	City **city;
	Headquarter *pHeadquarter;                          // 属于哪个司令部
	
public:
	static string warriorName[WARRIOR_NUM];             // 存放对应种类的武士名
	static string weaponName[WEAPON_NUM];
	static int warriorHealth[WARRIOR_NUM];              // 存放对应种类的武士生命值
	static int warriorAttack[WARRIOR_NUM];
	Warrior(Headquarter *head_, int id_, int health_);  // 构造函数，初始化武士，需指明所属的司令部，种类，生命值
	virtual void Print(int time);                               // 打印当前武士的信息
	virtual void Attack(Warrior *p) = 0;
	virtual void Hurt(Warrior *p, int strength) = 0;
	void GoAhead();
};

class Headquarter{
private:
	int color;                                 // 司令部的颜色
	int eachWarriorNum[WARRIOR_NUM];           // 各类武士的数量
	int cityNum;
	int curSeqIndex;                           // 该武士处于当前序列的第几个
	Warrior *pWarrior[1000];                   // 存放各个武士的指针
	string GetColor();                         // 获得当前司令部的颜色
	
public:
	int totalHealth;                           // 生命元总数
    int totalWarriorNum;                       // 战士总数
	bool stopState;                            // 制造武士的状态
	static int madeOrder[2][WARRIOR_NUM];      // 武士的制造顺序
	Headquarter(int totalHealth_, int color_); // 构造函数，使用总生命值和颜色初始化
	~Headquarter();                            // 析构函数，清理司令部中各个战士的内存
	void ProduceWarrior(int time_);            // 制造武士
	friend class Warrior;                      // 声明友元类，使得在可以访问当前武士的司令部的私有成员的信息
	void Print(int time);
	
};

class Weapon{
	int idWeaponKind;
	int useTimes;
public:
	Weapon(int kind, int num);
	static string weaponName[WEAPON_NUM];
};

class City{
	int idCity;
	Warrior *red, *blue;
	
	City(int id);
	void Fighting();
};

Weapon::Weapon(int kind):idWeaponKind(id), useTimes(0) {}

City::City(int id): idCity(id) {}

City::Fighting(){
	if (red != NULL && blue != NULL) {
		red->Sort();
		blue->Sort();
		if(idCity % 2 == 1) {
			while (true) {
				if (red == NULL && blue == NULL) break;
				if (red != NULL && blue != NULL && red->weaponNum == 0 && blue->weaponNum == 0) break;
				if (red == NULL && blue != NULL) break;
				if (red != NULL && blue == NULL) break;
				red->Attack(blue);
				blue->Attack(red);
			}
		} else {
			while (true) {
				if (red == NULL && blue == NULL) break;
				if (red != NULL && blue != NULL && red->weaponNum == 0 && blue->weaponNum == 0) break;
				if (red == NULL && blue != NULL) break;
				if (red != NULL && blue == NULL) break;
				red->Attack(blue);
				blue->Attack(red);
			}
		}
	}
}


class dragon: public Warrior {
private:
	int idWeapon;
	double morale;
	Weapon *weapon;
public:
	dragon(Headquarter *head_, int id_, int health_):Warrior(head_, id_, health_){
		idWeapon = (head_->totalWarriorNum + 1) % WEAPON_NUM;
		morale = (double)head_->totalHealth / warriorHealth[id_];
	}
	
	virtual void Print(int time){
		Warrior::Print(time);
		printf("It has a %s,and it's morale is %.2lf\n", 
				Warrior::weaponName[idWeapon].c_str(), morale);
	}
	
	virtual void Attack(Warrior *p) {
		switch(idWeapon){
			case 0:
				Hurt(p, p->attack * 2 / 10);
				break;
			case 1:
				Hurt(p, p->attack * 4 / 10);
				Hurt(this, (p->attack * 4 / 10) / 2);
				idWeapon = -1;
				break;
			case 2:
				if(weaponFlag >= 2) idWeapon = -1;
				else {
					Hurt(p, p->attack * 3 / 10);
					weaponFlag++;
				}
				break;	
			default:
		}
	}
	
	virtual void Hurt(Warrior *p, int strength){
		p->health -= strength;
	}
};

class ninja: public Warrior {
	int idWeapon[2];
	Weapon *weapon1, *weapon2;
public:
	ninja(Headquarter *head_, int id_, int health_):Warrior(head_, id_, health_){
		idWeapon[0] = (head_->totalWarriorNum + 1) % WEAPON_NUM;
		idWeapon[1] = (head_->totalWarriorNum + 2) % WEAPON_NUM;
	}
	void Print(int time){
		Warrior::Print(time);
		printf("It has a %s and a %s\n", 
				Warrior::weaponName[idWeapon[0]].c_str(), 
				Warrior::weaponName[idWeapon[1]].c_str());
	}
	
	virtual void Attack(Warrior *p) {
		for (int i = 0; i < 2; ++i) {
			switch(idWeapon[i]){
				case 0:
					Hurt(p, p->attack * 2 / 10);
					break;
				case 1:
					Hurt(p, p->attack * 4 / 10);
					idWeapon = -1;
					break;
				case 2:
					if(weaponFlag >= 2) idWeapon = -1;
					else {
						Hurt(p, p->attack * 3 / 10);
						weaponFlag++;
					}
					break;	
				default:
			}
		}
	}
	
	virtual void Hurt(Warrior *p, int strength){
		p->health -= strength;
		if (p->health <= 0) liveFlag = false;
	}
};

class iceman: public Warrior {
	Weapon *weapon;
public:
	iceman(Headquarter *head_, int id_, int health_):Warrior(head_, id_, health_){
		idWeapon = (head_->totalWarriorNum + 1) % WEAPON_NUM;
	}
	void Print(int time){
		Warrior::Print(time);
		printf("It has a %s\n", Warrior::weaponName[idWeapon].c_str());
	}
	
	virtual void Attack(Warrior *p) {
		switch(idWeapon){
			case 0:
				Hurt(p, p->attack * 2 / 10);
				break;
			case 1:
				Hurt(p, p->attack * 4 / 10);
				Hurt(this, (p->attack * 4 / 10) / 2);
				idWeapon = -1;
				break;
			case 2:
				if(weaponFlag >= 2) idWeapon = -1;
				else {
					Hurt(p, p->attack * 3 / 10);
					weaponFlag++;
				}
				break;	
			default:
		}
	}
	
	virtual void Hurt(Warrior *p, int strength){
		p->health -= strength;
		if (p->health <= 0) liveFlag = false;
	}
};

class lion: public Warrior {
	int loyalty;
	Weapon *weapon;
public:
	lion(Headquarter *head_, int id_, int health_):Warrior(head_, id_, health_){
		loyalty = head_->totalHealth;
	}
	void Print(int time){
		Warrior::Print(time);
		printf("It's loyalty is %d\n", loyalty);
	}
	virtual void Attack(Warrior *p) {
		switch(idWeapon){
			case 0:
				Hurt(p, p->attack * 2 / 10);
				break;
			case 1:
				Hurt(p, p->attack * 4 / 10);
				Hurt(this, (p->attack * 4 / 10) / 2);
				idWeapon = -1;
				break;
			case 2:
				if(weaponFlag >= 2) idWeapon = -1;
				else {
					Hurt(p, p->attack * 3 / 10);
					weaponFlag++;
				}
				break;	
			default:
		}
	}
	
	virtual void Hurt(Warrior *p, int strength){
		p->health -= strength;
		if (p->health <= 0) liveFlag = false;
	}
	
	void Runaway(int time){
		liveFlag = false;
		printf("%03d:05 %s %s %d ran away", time, pHeadquarter->color.c_str(),
				Warrior::warriorName[idKind].c_str(), idNumber);
	}
};

class wolf: public Warrior {
	int weaponNum;
	Weapon *pWeapon[10];
	
public:
	wolf(Headquarter *head_, int id_, int health_):Warrior(head_, id_, health_) {
		weaponNum = 0;
		idWeapon = memset(idWeapon, 0, 10 * sizeof(int));
	}
	virtual void Attack(Warrior *p) {
		for (int i = 0; i < weaponNum; ++i) {
			switch(idWeapon[i]){
				case 0:
					Hurt(p, p->attack * 2 / 10);
					break;
				case 1:
					Hurt(p, p->attack * 4 / 10);
					Hurt(this, (p->attack * 4 / 10) / 2);
					idWeapon = -1;
					break;
				case 2:
					if(weaponFlag >= 2) idWeapon = -1;
					else {
						Hurt(p, p->attack * 3 / 10);
						weaponFlag++;
					}
					break;	
				default:
			}
		}
	}
	
	virtual void Hurt(Warrior *p, int strength){
		p->health -= strength;
		if (p->health <= 0) liveFlag = false;
	}
};



Warrior::Warrior(Headquarter *head_, int id_, int health_):
					pHeadquarter(head_), idKind(id_), health(health_){
	pHeadquarter->pWarrior[pHeadquarter->totalWarriorNum] = this;
	idNumber = pHeadquarter->totalWarriorNum + 1;
	attack = Warrior::warriorAttack[idKind];
	weaponFlag = 0;
	liveFlag = true;
	if (pHeadquarter->color == 0) city = 0;
	else if (pHeadquarter->color == 1) city = pHeadquarter->cityNum + 1;
}

void Warrior::Print(int time_){
	char color_[10], name_[10];
	strcpy(color_, pHeadquarter->GetColor().c_str());
	strcpy(name_, warriorName[idKind].c_str());
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
			time_, color_, name_, pHeadquarter->totalWarriorNum + 1, health,
			pHeadquarter->eachWarriorNum[pHeadquarter->curSeqIndex], name_, color_);
	printf("%03d:55 %s wolf %d has %d %s %d %s %d %s and %d elements", time,);
}

void Warrior::GoAhead(int time){
	if (pHeadquarter->color == 0) {
		city++;
		if (city == pHeadquarter->cityNum + 1) {
			if (pHeadquarter->color == 0) {
				char leaveColor[] = "red";
				char arriveColor[] = "blue";
			} else {
				char leaveColor[] = "blue";
				char arriveColor[] = "red";
			}
			printf("%03d:10 %s %s %d reached %s headquarter with %d elements and force %d",
					time, leaveColor, Warrior::warriorName[idKind].c_str(), idKind, arriveColor, health, attack);
			printf("%03d:10 %s headquarter was taken", time, leaveColor);
		}
	}
	else if (pHeadquarter->color == 1) city --;
	else printf("This may be a mistake!\n");
	
}

Headquarter::Headquarter(int totalHealth_, int color_, int cityNum_){
	totalHealth = totalHealth_;
	color = color_;
	cityNum = cityNum_;
	totalWarriorNum = 0;
	curSeqIndex = 0;
	stopState = false;
	memset(eachWarriorNum, 0, sizeof(eachWarriorNum));
}

Headquarter::~Headquarter(){
	for (int i = 0; i < totalWarriorNum; i++){
		delete pWarrior[i];
	}
}

void Headquarter::ProduceWarrior(int time_){
	if (stopState) {
		return;
	}
	bool weaponFlag = false;
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
			pWarrior[totalWarriorNum]->Print(time_);
			totalWarriorNum++;
			weaponFlag = true;
		}
		curSeqIndex++;
		if (weaponFlag == true) break;
	}
	if (weaponFlag == false) {
		stopState = true;
		char color_[10];
        strcpy(color_, GetColor().c_str());
		printf("%03d %s headquarter stops making warriors\n", time_, color_);
	}
	
	return;
}

void Headquarter::Print(int time) {
	string color_ = GetColor();
	printf("%03d:50 %d elements in %s headquarter", time, totalHealth, color_.c_str());
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

int Headquarter::madeOrder[2][WARRIOR_NUM] = {{2, 3, 4, 1, 0},
                                              {3, 0, 1, 2, 4}};
string Warrior::warriorName[WARRIOR_NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string Weapon::weaponName[WEAPON_NUM] = {"sword", "bomb", "arrow"};
int Warrior::warriorHealth[WARRIOR_NUM];
int Warrior::warriorAttack[WARRIOR_NUM];

int main(){
	int n = 0, M = 0;
	cin >> n;
	int cases = 1;
	while (n--) {
		printf("Case:%d\n", cases);
		cin >> M >> N >> K >> T;
		for (int i = 0; i < WARRIOR_NUM; i++) {
			cin >> Warrior::warriorHealth[i];
		}
		for (int i = 0; i < WARRIOR_NUM; i++) {
			cin >> Warrior::warriorAttack[i];
		}
		Headquarter red(M, 0, N), blue(M, 1, N);
		for (int time = 0; time <= T; ++time) {
			// 武士降生
			red.ProduceWarrior(time);
			blue.ProduceWarrior(time);
			// lion逃跑
			red.GoAway();
			blue.GoAway();
			// 武士前进，抵达司令部，司令部被占领
			red.GoAhead();
			blue.GoAhead();
			// wolf抢敌人武器
			red.Rob();
			blue.Rob();
			// 报告战斗情况
			red.Report();
			blue.Report();
			// 武士欢呼
			
			// 司令部报告生命元数量
			
			// 武士报告情况
		}
		cases++;
	}
	return 0;
}