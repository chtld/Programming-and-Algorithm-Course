#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

#define WARRIOR_NUM 5

class Headquarter;

class Warrior{
	private:
	int idKind, health;                                 // 武士种类，生命值
	Headquarter *pHeadquarter;                          // 属于哪个司令部
	
	public:
	static string warriorName[WARRIOR_NUM];             // 存放对应种类的武士名
	static int warriorHealth[WARRIOR_NUM];              // 存放对应种类的武士生命值	
	Warrior(Headquarter *head_, int id_, int health_);  // 构造函数，初始化武士，需指明所属的司令部，种类，生命值
	void Print(int time);                               // 打印当前武士的信息
};


class Headquarter{
	private:
	int totalHealth;                           // 生命元总数
    int totalWarriorNum;                       // 战士总数
	int color;                                 // 司令部的颜色
	int eachWarriorNum[WARRIOR_NUM];           // 各类武士的数量
	int curSeqIndex;                           // 该武士处于当前序列的第几个
	Warrior *pWarrior[1000];                   // 存放各个武士的指针
	string GetColor();                         // 获得当前司令部的颜色
	
	public:
	bool stopState;                            // 制造武士的状态
	static int madeOrder[2][WARRIOR_NUM];      // 武士的制造顺序
	Headquarter(int totalHealth_, int color_); // 构造函数，使用总生命值和颜色初始化
	~Headquarter();                            // 析构函数，清理司令部中各个战士的内存
	void ProduceWarrior(int time_);            // 制造武士
	friend class Warrior;                      // 声明友元类，使得在可以访问当前武士的司令部的私有成员的信息
	
};

Warrior::Warrior(Headquarter *head_, int id_, int health_):
					pHeadquarter(head_), idKind(id_), health(health_){
	pHeadquarter->pWarrior[pHeadquarter->totalWarriorNum] = this;
}

void Warrior::Print(int time_){
	char color_[10], name_[10];
	strcpy(color_, pHeadquarter->GetColor().c_str());
	strcpy(name_, warriorName[idKind].c_str());
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
			time_, color_, name_, time_ + 1, health, pHeadquarter->eachWarriorNum[pHeadquarter->curSeqIndex],
			name_, color_);
}

Headquarter::Headquarter(int totalHealth_, int color_){
	totalHealth = totalHealth_;
	color = color_;
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
	bool flag = false;
	for (int i = 0; i < WARRIOR_NUM; i++){
		curSeqIndex %= WARRIOR_NUM;
		int kind = madeOrder[color][curSeqIndex];
		if (totalHealth >= Warrior::warriorHealth[kind]){
			totalHealth -= Warrior::warriorHealth[kind];
			eachWarriorNum[curSeqIndex]++;
			int kind = Headquarter::madeOrder[color][curSeqIndex];
			int health_ = Warrior::warriorHealth[kind];
			pWarrior[totalWarriorNum] = new Warrior(this, kind, health_);
			pWarrior[totalWarriorNum]->Print(time_);
			totalWarriorNum++;
			flag = true;
		}
		curSeqIndex++;
		if (flag == true) break;
	}
	if (flag == false) {
		stopState = true;
		char color_[10];
        strcpy(color_, GetColor().c_str());
		printf("%03d %s headquarter stops making warriors\n", time_, color_);
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

int Headquarter::madeOrder[2][WARRIOR_NUM] = {{2, 3, 4, 1, 0},
                                              {3, 0, 1, 2, 4}};
string Warrior::warriorName[WARRIOR_NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int Warrior::warriorHealth[WARRIOR_NUM];

int main(){
	int n = 0, M = 0;
	cin >> n;
	int cases = 1;
	while (n--) {
		printf("Case:%d\n", cases);
		cin >> M;
		for (int i = 0; i < WARRIOR_NUM; i++) {
			cin >> Warrior::warriorHealth[i];
		}
		Headquarter red(M, 0), blue(M, 1);
		int time = 0;
		while (!red.stopState || !blue.stopState){
			red.ProduceWarrior(time);
			blue.ProduceWarrior(time);
			time++;
		}
		cases++;
	}
	return 0;
}