
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
int M, N, R, K, T;//基础数据
int SoldierBlood[5];
int SoldierAd[5];
int CurrentTime;

string toString(int t)
{
    char buf[10];
    sprintf(buf, "%d", t);
    string b = buf;
    return b;
}
string printNowTime()
{
    int t = CurrentTime;
    int h = t / 60;
    int m = t % 60;
    string s;
    s += h / 100 + '0';
    s += (h / 10) % 10 + '0';
    s += h % 10 + '0';
    s += ':';
    s += m / 10 + '0';
    s += m % 10 + '0';
    return s + ' ';
}

class Weapon
{
protected:
    int Attack;
    int Belong;//存放的soldier的uid
public:
    int getAttack()
    {
        return Attack;
    }
    void setBelong(int t)
    {
        Belong = t;
    }
    virtual void init() = 0;
    virtual int lose() = 0;//返回0的时候表示失去该武器
    virtual int getType() = 0;//0 sword 1 bomb 2 arrow
    virtual string getPrint() = 0;
    virtual ~Weapon() {};
};
class Sword:public Weapon
{
public:
    void init();
    int lose()
    {
        Attack *= 0.8;
        return Attack;
    }
    int getType()
    {
        return 0;
    }
    void setAttack(int t)
    {
        Attack = t*0.2;
    }
    string getPrint()
    {
        return "sword(" + toString(Attack) + ')';
    }
};
class Arrow :public Weapon
{
private:
    
public:
    int time;
    void init()
    {
        Attack = 0;
        time = 3;
    }
    int lose()
    {
        time--;
        return time;
    }
    int getType()
    {
        return 2;
    }
    string getPrint()
    {
        return "arrow(" + toString(time) + ')';
    }
};
class Bomb :public Weapon
{
public:
    void init()
    {
        Attack = 0;
    }
    int lose()//只能用一次,只要调用了就没了
    {
        return 0;
    }
    int getType()
    {
        return 1;
    }
    string getPrint()
    {
        return "bomb";
    }
};

class Soldier 
{
protected:
    
    int Attack;
    int Id;
    int uId;
    int Camp;//0:red,1:blue;
    
    
public:
    int Blood;//<=0即为死亡
    int BloodWin;//
    int isLive;//0 die 1 live -1 runaway
    int tArrow;//实现同时射箭的处理。先记录下中箭的数值，在战争开始时再结算中箭的伤害。
    Arrow* hasArrow;//没有即为NULL
    Bomb* hasBomb;//
    int dieByArrow;
    string getCampName()
    {
        if (Camp == 0) return "red";
        return "blue";
    }
    string getPrint()//return like this "red lion 2"
    {
        string s;
        s += getCampName() + ' ' + getName() + ' ' +toString(Id);
        return s;
    }
    Soldier()
    {
        isLive = 1;
        hasArrow = NULL;
        hasBomb = NULL;
        tArrow = 0;
        BloodWin = 0;
        dieByArrow = 0;
    }
    void attackByArrow(int t)
    {
        tArrow += t;
    }
    void loseByArrow()
    {
        loseBlood(tArrow);
        tArrow = 0;
    }
    void loseBlood(int t)//降低生命值
    {
        Blood -= t;
        if (Blood <= 0)
        {
            isLive = 0;
            //Todo
            die();
        }
    }
    int getBlood()
    {
        return Blood;
    }
    int getAttack()
    {
        return Attack;
    }
    void setId(int t)
    {
        Id = t;
    }
    int getId()
    {
        return Id;
    }
    void setuId(int t)
    {
        uId = t;
    }
    int getuId()
    {
        return uId;
    }
    void setCamp(int t)
    {
        Camp = t;
    }
    int getCamp()
    {
        return Camp;
    }
    virtual void init() = 0;//武士初始化，推迟到子类中实现
    virtual int fight() = 0;//返回攻击的攻击力
    virtual int fightback() = 0;//返回反击的攻击力
    virtual int getType() = 0;//返回该武士的类型编号，0： dragon 、1：ninja、2：iceman、3：lion、4：wolf
    virtual string getName() = 0;//返回该武士的类型
    virtual void die() = 0;//死亡
    virtual void winFight(Soldier* p,int t) = 0;//获胜
    virtual void loseFight(Soldier* p,int t) = 0;//输掉
    virtual void drawFight(Soldier* p,int t) = 0;//平局
    virtual void loseWeapon(int t) = 0;
    virtual void printWeapon() = 0;
    virtual ~Soldier() {}//虚函数析构
};

int getSwordAttack(Weapon* p)//fight时处理sword的事件，返回sword的攻击力
{
    if (!p) return 0;
    if (p->getType() != 0) return 0;//not sword,return 0
    int t = p->getAttack();
    //p->lose();//sword 变钝  // 对打时处理吧
    //if (p->getAttack() == 0)
    //{
    //    delete p;
    //    p = NULL;
    //}
    return t;
}
void getWeapon(Soldier * t,Weapon* &p, int code);//获得武器

class Dragon :public Soldier
{
private:
    
public:
    double Morale;
    Weapon* mWeapon;//NULL代表没有武器
    Dragon()
    {
        Blood = SoldierBlood[0];
        Attack = SoldierAd[0];
        mWeapon = NULL;
    }
    double getMorale()
    {
        return Morale;
    }
    int getWeaponType()//-1 no weapon,0 sword
    {
        if (mWeapon == NULL) return -1;
        return mWeapon->getType();
    }
    void init();
    
    void die()
    {
        //if (mWeapon != NULL) delete mWeapon;
        isLive = 0;
        Blood = 0;
    }
    int getType()
    {
        return 0;
    }
    string getName()
    {
        return "dragon";
    }
    void yell(int t);//judge whether to yell
    
    void winFight(Soldier* p,int t)
    {
        BloodWin += 8;
        Morale += 0.2;
        yell(t);
    }
    
    void loseFight(Soldier * p,int t)
    {
        
    }
    void drawFight(Soldier * p,int t)
    {
        Morale -= 0.2;
        yell(t);
    }
    int fight()
    {
        int ad = Attack;
        ad += getSwordAttack(mWeapon);
        return ad;
    }
    int fightback()
    {
        int ad = Attack / 2;
        ad += getSwordAttack(mWeapon);
        return ad;
    }
    void loseWeapon(int t)//战斗后调用
    {
        if (mWeapon&&mWeapon->getType()==t)
        {
            if (mWeapon->lose() == 0)
            {
                //delete mWeapon;
                mWeapon = NULL;
            }
        }
    }
    void printWeapon()
    {
        string s = printNowTime() + getPrint() + " has ";
        if (mWeapon == NULL)
            s += "no weapon";
        else
            s += mWeapon->getPrint();
        puts(s.c_str());
    }
};
class Ninja :public Soldier
{
private:
    
public:
    Weapon *mWeapon1, *mWeapon2;
    Ninja()
    {
        Blood = SoldierBlood[1];
        Attack = SoldierAd[1];
        mWeapon1 = NULL;
        mWeapon2 = NULL;
    }
    int getWeaponType1()
    {
        if (mWeapon1 == NULL) return -1;
        return mWeapon1->getType();
    }
    int getWeaponType2()
    {
        if (mWeapon2 == NULL) return -1;
        return mWeapon2->getType();
    }
    int getType()
    {
        return 1;
    }
    string getName()
    {
        return "ninja";
    }
    void init()
    {
        getWeapon(this,mWeapon1, Id % 3);
        if (mWeapon1) mWeapon1->setBelong(getuId());//设置属于谁的
        getWeapon(this,mWeapon2, (Id+1) % 3);
        if (mWeapon2) mWeapon2->setBelong(getuId());//设置属于谁的
    }
    void die()
    {
        //if (mWeapon1) delete mWeapon1;
        //if (mWeapon2) delete mWeapon2;
        isLive = 0;
    }
    void winFight(Soldier *p, int t)
    {
        BloodWin += 8;
    }
    void loseFight(Soldier *p, int t)
    {

    }
    void drawFight(Soldier *p, int t)
    {

    }
    int fight()
    {
        int ad = Attack;
        if(mWeapon1)ad += getSwordAttack(mWeapon1);
        if(mWeapon2)ad += getSwordAttack(mWeapon2);
        return ad;
    }
    void loseWeapon(int t)//战斗后调用
    {
        if (mWeapon1&&mWeapon1->getType()==t)
        {
            if (mWeapon1->lose()==0)
            {
                //delete mWeapon1;
                mWeapon1 = NULL;
            }
        }
        if (mWeapon2&&mWeapon2->getType() == t)
        {
            if (mWeapon2->lose()==0)
            {
                //delete mWeapon2;
                mWeapon2 = NULL;
            }
        }
    }
    int fightback()//不反击，所以认为是0
    {
        return 0;
    }
    void printWeapon()
    {
        string s = printNowTime() + getPrint() + " has ";
        if (mWeapon1 == NULL && mWeapon2 == NULL)
            s += "no weapon";
        else if (mWeapon1 == NULL)
        {
            s += mWeapon2->getPrint();
        }
        else if (mWeapon2 == NULL)
        {
            s += mWeapon1->getPrint();
        }
        else 
        {
            if (mWeapon1->getType() == 2)
                s += mWeapon1->getPrint();
            if (mWeapon2->getType() == 2)
                s += mWeapon2->getPrint();
            if (mWeapon1->getType() == 1)
            {
                if (s[s.size() - 1] != ' ') s += ',';
                s += mWeapon1->getPrint();
            }
            if (mWeapon2->getType() == 1)
            {
                if (s[s.size() - 1] != ' ') s += ',';
                s += mWeapon2->getPrint();
            }
            if (mWeapon1->getType() == 0)
            {
                if (s[s.size() - 1] != ' ') s += ',';
                s += mWeapon1->getPrint();
            }
            if (mWeapon2->getType() == 0)
            {
                if (s[s.size() - 1] != ' ') s += ',';
                s += mWeapon2->getPrint();
            }
        }
        puts(s.c_str());
    }
};

class Iceman :public Soldier
{
private:
    
public:
    Weapon *mWeapon;
    int Step;
    Iceman()
    {
        Blood = SoldierBlood[2];
        Attack = SoldierAd[2];
        mWeapon = NULL;
        Step = 0;
    }
    int getWeaponType()
    {
        if (mWeapon == NULL) return -1;
        return mWeapon->getType();
    }
    int getType()
    {
        return 2;
    }
    string getName()
    {
        return "iceman";
    }
    void init()
    {
        getWeapon(this,mWeapon, Id % 3);
        if (mWeapon) mWeapon->setBelong(getuId());//设置属于谁的
    }
    void die()
    {
        //if (mWeapon) delete mWeapon;
        isLive = 0;
    }
    void winFight(Soldier *p, int t)
    {
        BloodWin += 8;
    }
    void loseFight(Soldier *p, int t)
    {

    }
    void drawFight(Soldier *p, int t)
    {

    }
    void loseWeapon(int t)//战斗后调用
    {
        if (mWeapon&&mWeapon->getType() == t)
        {
            if (mWeapon->lose()== 0)
            {
                //delete mWeapon;
                mWeapon = NULL;
            }
        }
    }
    void Move()
    {
        Step++;
        if (Step == 2)
        {
            Step = 0;
            Blood -= 9;
            Attack += 20;
            if (Blood <= 0) Blood = 1;
        }
    }
    int fight()
    {
        int ad = Attack;
        ad += getSwordAttack(mWeapon);
        return ad;
    }
    int fightback()
    {
        int ad = Attack / 2;
        ad += getSwordAttack(mWeapon);
        return ad;
    }
    void printWeapon()
    {
        string s = printNowTime() + getPrint() + " has ";
        if (mWeapon == NULL)
            s += "no weapon";
        else
            s += mWeapon->getPrint();
        puts(s.c_str());
    }
};
class Lion :public Soldier
{
private:
    int    Loyalty;
    int tBlood;//要转移的Blood
public:
    Lion()
    {
        Blood = SoldierBlood[3];
        Attack = SoldierAd[3];
    }
    void moveBlood()
    {
        tBlood = Blood-tArrow;
    }
    void init();
    void die()
    {
        isLive = 0;
    }
    int getLoyalty()
    {
        return Loyalty;
    }
    void loseLoyalty()
    {
        Loyalty -= K;
    }
    int fight()
    {
        return Attack;
    }
    int fightback()
    {
        return Attack / 2;
    }
    void winFight(Soldier *p, int t)
    {
        BloodWin += 8;
    }
    void loseFight(Soldier *p, int t)
    {
        if(dieByArrow==0)p->Blood += tBlood;
    }
    void drawFight(Soldier *p, int t)
    {
        loseLoyalty();
    }
    void loseWeapon(int t)
    {

    }
    int getType()
    {
        return 3;
    }
    string getName()
    {
        return "lion";
    }
    void runAway()
    {
        Blood = 0;
        isLive = 0;//暂时先设置为0吧，逃跑了就当他死了
    }
    void printWeapon()
    {
        string s = printNowTime() + getPrint() + " has ";
        s += "no weapon";
        puts(s.c_str());
    }
};
class Wolf :public Soldier
{
private:
    
public:
    //Weapon* mWeapon;
    Weapon* swordWeapon;
    Arrow* arrowWeapon;
    Bomb*  bombWeapon;
    Wolf()
    {
        Blood = SoldierBlood[4];
        Attack = SoldierAd[4];
    }
    /*int getWeaponType()
    {
        return WeaponType;
    }*/
    void init()
    {
        swordWeapon = NULL;
        arrowWeapon = NULL;
        bombWeapon = NULL;
    }
    void die()
    {
        //if (swordWeapon) delete swordWeapon;
        //if ()
        isLive = 0;
    }
    void winFight(Soldier *p, int t)
    {
        switch (p->getType())
        {
            case 0:
            {
                takeWeapon(((Dragon *)p)->mWeapon);
                break;
            }
            case 1:
            {
                takeWeapon(((Ninja *)p)->mWeapon1);
                takeWeapon(((Ninja *)p)->mWeapon2);
                break;
            }
            case 2:
            {
                takeWeapon(((Iceman *)p)->mWeapon);
                break;
            }
            case 4:
            {
                takeWeapon(((Wolf *)p)->swordWeapon);
                takeWeapon(((Wolf *)p)->bombWeapon);
                takeWeapon(((Wolf *)p)->arrowWeapon);
                break;
            }
        }
        BloodWin += 8;
    }
    void loseFight(Soldier *p, int t)
    {

    }
    void drawFight(Soldier *p, int t)
    {

    }
    void takeWeapon(Weapon *p)//缴获武器
    {
        if (p == NULL) return;
        if (p->getType() == 0&&swordWeapon==NULL)
        {
            swordWeapon = p;
        }
        if (p->getType() == 1 && bombWeapon == NULL)
        {
            bombWeapon =(Bomb *) p;
            hasBomb = (Bomb *)p;
        }
        if (p->getType() == 2 && arrowWeapon == NULL)
        {
            arrowWeapon = (Arrow *)p;
            hasArrow = (Arrow *)p;
        }
    }
    int fight()
    {
        int ad = Attack;
        ad += getSwordAttack(swordWeapon);
        return ad;
    }
    int fightback()
    {
        int ad = Attack / 2;
        ad += getSwordAttack(swordWeapon);
        return ad;
    }
    void loseWeapon(int t)//战斗后调用
    {
        if (swordWeapon&&t==0)
        {
            if (swordWeapon->lose() == 0)
            {
                //delete swordWeapon;
                swordWeapon = NULL;
            }
        }
        if (bombWeapon&&t == 1)
        {
            if (bombWeapon->lose() == 0)
            {
                //delete bombWeapon;
                bombWeapon = NULL;
            }
        }
        if (arrowWeapon&&t == 2)
        {
            if (arrowWeapon->lose() == 0)
            {
                //delete arrowWeapon;
                arrowWeapon = NULL;
            }
        }
    }
    int getType()
    {
        return 4;
    }
    string getName()
    {
        return "wolf";
    }
    void printWeapon()
    {
        string s = printNowTime() + getPrint() + " has ";
        if (swordWeapon == NULL && bombWeapon == NULL && arrowWeapon ==NULL)
            s += "no weapon";
        else
        {
            if (arrowWeapon != NULL) s += arrowWeapon->getPrint();
            if (bombWeapon != NULL)
            {
                if (s[s.size() - 1] != ' ') s += ',';
                s += bombWeapon->getPrint();
            }
            if (swordWeapon != NULL)
            {
                if (s[s.size() - 1] != ' ') s += ',';
                s += swordWeapon->getPrint();
            }
        }
        puts(s.c_str());
    }
};
vector<Soldier *> mAllSoldier;//全部武士集合

class Base
{
public:
    int Blood;
    int BloodWin;
    int SoidierNum;//从1开始编号
    vector<Soldier*> mSoldier;//武士集合
    int occupied;//0 no,1 
    void init()//初始化大本营
    {
        Blood = M;
        SoidierNum = 0;
        /*for (int i = 0; i <= mSoldier.size(); i++)
        {
        delete mSoldier[i];
        }*/
        mSoldier.clear();
        //mSoldier.push_back(NULL);
        occupied = 0;
    }
    void tackBloodWin()
    {
        Blood += BloodWin;
        BloodWin = 0;
    }
    virtual int creatwho(int t) = 0;
    virtual int getCamp() = 0;
    virtual string getCampName() = 0;
    Soldier* CreatSoldier();//返回指向soldier的指针，创建失败的时候的返回null
};


class RedBase :public Base
{
public:
    int creatwho(int t)
    {
        return t % 5;
    }
    int getCamp()
    {
        return 0;
    }
    string getCampName()
    {
        return "red";
    }
};
RedBase *RedBaseInstance;//红魔军实例
class BlueBase:public Base
{
public:
    int creatwho(int t)
    {
        int k = t % 5;
        switch (k)
        {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 0;
        case 4:
            return 2;
        }
    }
    int getCamp()
    {
        return 1;
    }
    string getCampName()
    {
        return "blue";
    }
};
BlueBase *BlueBaseInstance;//蓝魔军实例
class City
{
private:
    
public:
    int Id;
    Soldier* RedSoldier;
    Soldier* BlueSoldier;
    int Blood;
    int whoLastWin;//0 no 1 red 2 blue
    int Flag;//as up
    int FlagRaise;
    int lastPrintFlag;
    int whoFirst;//who first to attack,0 red,1 blue
    int redReward, blueReward;
    queue<string> output;
    City(int t)
    {
        lastPrintFlag = 0;
        Id = t;
        Blood = 0;
        whoLastWin = 0;
        Flag = 0;
        redReward = 0; 
        blueReward = 0;
        FlagRaise = 0;
        RedSoldier = NULL;
        BlueSoldier = NULL;
        while (!output.empty()) output.pop();
    }
    void addBlood()
    {
        Blood += 10;
    }
    int takeBlood(int who)//拿走所有的生命元
    {
        int t = Blood;
        Blood = 0;
        string s = printNowTime();
        if (who == 0)
        {
            s += RedSoldier->getPrint();
        }
        if (who == 1)
        {
            s += BlueSoldier->getPrint();
        }
        s += " earned " +toString(t)+ " elements for his headquarter";
        puts(s.c_str());
        return t;
    }
    int takeWinBlood(int c, int who)
    {
        int t = Blood;
        Blood = 0;
        string s = printNowTime();
        if (who == 0)
        {
            s += RedSoldier->getPrint();
        }
        if (who == 1)
        {
            s += BlueSoldier->getPrint();
        }
        s += " earned " + toString(t) + " elements for his headquarter";
        //puts(s.c_str());
        output.push(s);
        return t;
    }
    void printFlag(int p)
    {
        string s=printNowTime();
        if (Flag == 1)
        {
            s += "red flag raised in city " + toString(p);
        }
        else
        {
            s += "blue flag raised in city " + toString(p);
        }
        puts(s.c_str());
    }
    void changeFlag(int p,int t)//t 1 red win ,t 2 blue win
    {
        //if (Flag == t) return;
        if (t == 1)
        {
            if (whoLastWin == 1)
            {
                Flag = 1;
                FlagRaise = 1;
                //printFlag(p);
                whoFirst = 0;
            }
            else
            {
                whoLastWin = 1;
            }
        }
        else
        {
            if (whoLastWin == 2)
            {
                Flag = 2;
                FlagRaise = 2;
                //printFlag(p);
                whoFirst = 1;
            }
            else
            {
                whoLastWin = 2;
            }
        }
    }

};
vector <City*> mAllCity;

void Init()//游戏初始化
{
    cin >> M >> N >> R >> K >> T;
    cin >> SoldierBlood[0] >> SoldierBlood[1] >> SoldierBlood[2] >> SoldierBlood[3] >> SoldierBlood[4];
    cin >> SoldierAd[0] >> SoldierAd[1] >> SoldierAd[2] >> SoldierAd[3] >> SoldierAd[4];

    N++;//使得编号N为bluebase

    for (int i = 0; i < mAllSoldier.size(); i++)
    {
        delete mAllSoldier[i];
    }
    mAllSoldier.clear();
    //mAllSoldier.push_back(NULL);//放入一个空指针占位

    RedBaseInstance = new RedBase();
    RedBaseInstance->init();
    BlueBaseInstance = new BlueBase();
    BlueBaseInstance->init();

    for (int i = 0; i < mAllCity.size(); i++)
    {
        delete mAllCity[i];
    }
    mAllCity.clear();
    for (int i = 0; i <= N; i++)//0号city为redbase，N号为bluebase
    {
        
        mAllCity.push_back(new City(i));
        mAllCity[i]->whoFirst = (i+1) % 2;
    }
}

string printTime()
{
    int t = CurrentTime;
    int h = t / 60;
    int m = t % 60;
    string s;
    s += h / 100 + '0';
    s += (h / 10) % 10 + '0';
    s += h % 10 + '0';
    s += ':';
    s += m / 10 + '0';
    s += m % 10 + '0';
    return s;
}

void printBorn(string s, Soldier* p)
{
    if (p == NULL) return;//表示没有创建
    s += ' ' + p->getPrint() + " born";
    puts(s.c_str());
    if (p->getType() == 0)//is dragon
    {
        double t = ((Dragon*)(p))->getMorale();
        //t = (double)((int)(t * 100 + 0.5)) / 100.0;//四舍五入
        //oj上的测试数据并没有四舍五入。。。直接截尾取得两位有效数字，坑啊
        printf("Its morale is %.2lf\n", t);
    }
    if (p->getType() == 3)//is lion
    {
        printf("Its loyalty is %d\n", ((Lion*)(p))->getLoyalty());
    }
}
void printLionRun(string s, Lion* p)//判断lion是否逃跑以及相应信息的输出
{
    p->runAway();
    s += " lion " + toString(p->getId()) + " ran away";
    puts(s.c_str());
}
int printMove(int c)
{
    Soldier *p = NULL;
    string s;
    int f = 0;

    p = mAllCity[c]->RedSoldier;//red
    if (p)
    {
        s = printNowTime() + p->getPrint();
        if (c == 0) 
            s += " reached red headquarter";
        else if (c == N) s += " reached blue headquarter";
        else s += " marched to city " + toString(c);
        s += " with " + toString(p->getBlood()) + " elements and force " + toString(p->getAttack());
        puts(s.c_str());

        if (BlueBaseInstance->occupied==2&&c == N)
        {
            f = 1;
            printf("%sblue headquarter was taken\n", printNowTime().c_str());
        }
    }
    
    
    p = mAllCity[c]->BlueSoldier;//blue
    if (p)
    {
        s = printNowTime() + p->getPrint();
        if (c == 0) 
            s += " reached red headquarter";
        else if (c == N) s += " reached blue headquarter";
        else s += " marched to city " + toString(c);
        s += " with " + toString(p->getBlood()) + " elements and force " + toString(p->getAttack());
        puts(s.c_str());

        if (RedBaseInstance->occupied==2&&c == 0)
        {
            f = 1;
            printf("%sred headquarter was taken\n", printNowTime().c_str());
        }
    }

    return f;
}
int checkBomb(Soldier *p,Soldier *q,int t)//返回1即使需要使用bomb
{
    //t 谁先攻击，这个应该在city中处理，0 red 1 blue
    if (q->getBlood() - q->tArrow <= 0) return 0;
    if (p->getBlood() - p->tArrow <= 0) return 0;
    int a = 0, b = 0,c = 0,d = 0;
    if (t == 0)//p 先攻击
    {
        a = p->fight();
        b = q->getBlood() - q->tArrow;
        
        if (a < b)//q 没死 反击
        {
            c = q->fightback();
            d = p->getBlood() - p->tArrow;
            if (c >= d) return 1;
        }
    }
    else//q 先攻击
    {
        a = q->fight();
        b = p->getBlood() - p->tArrow;
        
        if (a >= b) return 1;//q 打死了 p就返回1
    }
    return 0;
}
int checkBomb2(Soldier *p, Soldier *q, int t)
{
    //t 谁先攻击，这个应该在city中处理，0 red 1 blue
    if (q->getBlood() - q->tArrow <= 0) return 0;
    if (p->getBlood() - p->tArrow <= 0) return 0;
    int a = 0, b = 0, c = 0, d = 0;
    if (t == 0)
    {
        a = p->fight();
        b = q->getBlood() - q->tArrow;
        if (a >= b) return 1;
    }
    else
    {
        c = q->fight();
        d = p->getBlood() - p->tArrow;
        if (c < d)
        {
            a = p->fightback();
            b = q->getBlood() - q->tArrow;
            if (a >= b) return 1;
        }
    }
    return 0;
}
int checkArrow(Soldier* p)//结算arrow的伤害并检查是否被射死了,返回1是被射死了
{
    if (!p) return -1;
    p->loseBlood(p->tArrow);
    p->tArrow = 0;
    if (p->getBlood() <= 0)
    {
        p->dieByArrow = 1;
        p->die();
        return 1;
    }
    return 0;
}
int printFight(int i,Soldier *p,Soldier *q)//返回0，就是q死了
{
    int a = p->fight();
    int b = q->getBlood();
    p->loseWeapon(0);//武器损耗
    q->loseBlood(a);
    string s = printTime();
    string sp, sq;
    if (p->getCamp() == 0) sp = " red ";
        else sp = " blue ";
    if (q->getCamp() == 0) sq = " red ";
        else sq = " blue ";
    s += sp + p->getName() + ' ' + toString(p->getId()) + " attacked" + sq;
    s += q->getName() + ' ' + toString(q->getId()) + " in city " + toString(i);
    s += " with " + toString(p->getBlood()) + " elements and force " + toString(p->getAttack());
    //puts(s.c_str());
    mAllCity[i]->output.push(s);
    return q->isLive;
}
int printFightBack(int i, Soldier *p, Soldier *q)
{
    if (p->getType() == 1)//ninjia no fightback
        return 1;
    int a = p->fightback();
    int b = q->getBlood();
    p->loseWeapon(0);
    q->loseBlood(a);
    string s = printNowTime();
    s += p->getPrint() + " fought back against " + q->getPrint() + " in city " + toString(i);
    //puts(s.c_str());
    mAllCity[i]->output.push(s);
    return q->isLive;
}
void printKilled(int i,Soldier *p)
{
    string s = printTime() + ' ' + p->getCampName() + ' ';
    s += p->getName() + ' ' + toString(p->getId()) + " was killed in city " + toString(i);
    //puts(s.c_str());
    mAllCity[i]->output.push(s);
}
void afterbattle(int i, int t)//在city i 战斗结束后的事情，0 平局 1 red win 2 blue win
{
    if (t == 0)//平局
    {
        mAllCity[i]->RedSoldier->drawFight(mAllCity[i]->BlueSoldier, i);
        mAllCity[i]->BlueSoldier->drawFight(mAllCity[i]->RedSoldier, i);
        mAllCity[i]->whoLastWin = 0;
    }
    if (t == 1)//red win
    {
        
        mAllCity[i]->RedSoldier->winFight(mAllCity[i]->BlueSoldier, i);
        mAllCity[i]->BlueSoldier->loseFight(mAllCity[i]->RedSoldier, i);
        RedBaseInstance->BloodWin += mAllCity[i]->takeWinBlood(i, 0);
        mAllCity[i]->changeFlag(i,1);
    }
    if (t == 2)//blue win
    {
        
        mAllCity[i]->RedSoldier->loseFight(mAllCity[i]->BlueSoldier, i);
        mAllCity[i]->BlueSoldier->winFight(mAllCity[i]->RedSoldier, i);
        BlueBaseInstance->BloodWin += mAllCity[i]->takeWinBlood(i, 1);
        mAllCity[i]->changeFlag(i,2);
    }
}
void redReward()
{
    for (int i = N - 1; i > 0; i--)//red reward
    {
        if (!mAllCity[i]->RedSoldier) continue;
        while (mAllCity[i]->RedSoldier->BloodWin>0)
            if (RedBaseInstance->Blood >= 8)
            {
                RedBaseInstance->Blood -= 8;
                mAllCity[i]->RedSoldier->Blood += 8;
                mAllCity[i]->RedSoldier->BloodWin -= 8;
                mAllCity[i]->redReward = 1;
            }
        //mAllCity[i]->RedSoldier->BloodWin = 0;
    }
}
void blueReward()
{
    for (int i = 1; i < N; i++)//blue reward
    {
        if (!mAllCity[i]->BlueSoldier) continue;
        while (mAllCity[i]->BlueSoldier->BloodWin>0)
            if (BlueBaseInstance->Blood >= 8)
            {
                BlueBaseInstance->Blood -= 8;
                mAllCity[i]->BlueSoldier->Blood += 8;
                mAllCity[i]->BlueSoldier->BloodWin -= 8;
                mAllCity[i]->blueReward = 1;
            }
        //mAllCity[i]->BlueSoldier->BloodWin = 0;
    }
}


void Game()//游戏进程
{
    CurrentTime = -1;
    Soldier *RedOccSoldier = NULL;
    Soldier *BlueOccSoldier = NULL;
    while (CurrentTime <= T)
    {
        CurrentTime++;
        if (CurrentTime > T) return;
        int CurrentMinute = CurrentTime % 60;
        string st = printTime();
        switch (CurrentMinute)
        {
            case 0:
            {
                string s = st;
                //red
                Soldier* p = RedBaseInstance->CreatSoldier();
                printBorn(s, p);

                //blue
                p = BlueBaseInstance->CreatSoldier();
                printBorn(s, p);

                break;
            }
            case 5:
            {
                for (int i = 0; i <= N; i++)//从西向东
                {
                    //red
                    if (mAllCity[i]->RedSoldier&&mAllCity[i]->RedSoldier->getType() == 3)//is lion
                        if (i != N)//not at bluebase
                        {
                            Lion *p = (Lion *)mAllCity[i]->RedSoldier;
                            string s = st;
                            s += " red";
                            if (p->getLoyalty() <= 0)
                            {
                                printLionRun(s, p);
                                mAllCity[i]->RedSoldier = NULL;
                            }    
                        }

                    //blue
                    if (mAllCity[i]->BlueSoldier&&mAllCity[i]->BlueSoldier->getType() == 3)//is lion
                        if (i != 0)//not at redbase
                        {
                            Lion *p = (Lion *)mAllCity[i]->BlueSoldier;
                            string s = st;
                            s += " blue";
                            if (p->getLoyalty() <= 0)
                            {
                                printLionRun(s, p);
                                mAllCity[i]->BlueSoldier = NULL;
                            }
                        }
                }
                break;
            }
            case 10:
            {
                int f = 0;//1即为占领了

                //red
                for (int i = N; i > 0; i--)
                {
                    if (i == N && mAllCity[N]->RedSoldier) RedOccSoldier = mAllCity[N]->RedSoldier;
                    mAllCity[i]->RedSoldier = mAllCity[i - 1]->RedSoldier;
                    if (mAllCity[i]->RedSoldier&&mAllCity[i]->RedSoldier->getType() == 2)
                    {
                        ((Iceman*)mAllCity[i]->RedSoldier)->Move();
                    }
                }
                mAllCity[0]->RedSoldier = NULL;
                if (mAllCity[N]->RedSoldier) { BlueBaseInstance->occupied++; }
                

                //blue
                for (int i = 0; i < N; i++)
                {
                    if (i == 0 && mAllCity[0]->BlueSoldier) BlueOccSoldier = mAllCity[0]->BlueSoldier;
                    mAllCity[i]->BlueSoldier = mAllCity[i + 1]->BlueSoldier;
                    if (mAllCity[i]->BlueSoldier&&mAllCity[i]->BlueSoldier->getType() == 2)
                    {
                        ((Iceman*)mAllCity[i]->BlueSoldier)->Move();
                    }
                }
                mAllCity[N]->BlueSoldier = NULL;
                if (mAllCity[0]->BlueSoldier) RedBaseInstance->occupied++;
                for (int i = 0; i <= N; i++)
                {
                    if (printMove(i)) f = 1;
                }

                //be occupied?
                if (f) return;
                break;
            }
            case 20:
            {
                for (int i = 1; i < N; i++)//不包括红蓝司令部
                {
                    mAllCity[i]->addBlood();
                }
                /*RedBaseInstance->Blood += 10;
                BlueBaseInstance->Blood += 10;*/
                break;
            }
            case 30:
            {
                for (int i = 1; i < N; i++)
                {
                    if (mAllCity[i]->RedSoldier != NULL&&mAllCity[i]->BlueSoldier == NULL)
                        RedBaseInstance->Blood += mAllCity[i]->takeBlood(0);
                    if (mAllCity[i]->RedSoldier == NULL&&mAllCity[i]->BlueSoldier != NULL)
                        BlueBaseInstance->Blood += mAllCity[i]->takeBlood(1);
                }
                break;
            }
            case 35:
            {
                //red
                for (int i = 1; i < N; i++)
                {
                    Soldier *p = mAllCity[i]->RedSoldier;
                    //if (!p) continue;
                    if (i < N-1)
                    {
                        if (p&&p->hasArrow)
                        {
                            Arrow *q = p->hasArrow;
                            if (mAllCity[i + 1]->BlueSoldier)
                            {
                                mAllCity[i + 1]->BlueSoldier->tArrow += R;

                                if (q->lose() == 0)//返回值为0说明arrow已经消失
                                {
                                    //delete q;
                                    int t = p->getType();
                                    switch (t)
                                    {
                                    case 0:
                                    {
                                        ((Dragon *)p)->mWeapon = NULL;
                                        break;
                                    }
                                    case 1:
                                    {
                                        if (((Ninja *)p)->mWeapon1 && ((Ninja *)p)->mWeapon1->getType() == 2) ((Ninja *)p)->mWeapon1 = NULL;
                                        if (((Ninja *)p)->mWeapon2 && ((Ninja *)p)->mWeapon2->getType() == 2) ((Ninja *)p)->mWeapon2 = NULL;
                                        break;
                                    }
                                    case 2:
                                    {
                                        ((Iceman *)p)->mWeapon = NULL;
                                        break;
                                    }
                                    case 4:
                                    {
                                        ((Wolf *)p)->arrowWeapon = NULL;
                                        break;
                                    }
                                    }
                                    p->hasArrow = NULL;
                                }
                                string s = st + " red ";
                                s += mAllCity[i]->RedSoldier->getName() + ' ' + toString(mAllCity[i]->RedSoldier->getId()) + " shot";
                                if (mAllCity[i + 1]->BlueSoldier&&mAllCity[i + 1]->BlueSoldier->getBlood() <= R)
                                    s += " and killed blue " + mAllCity[i + 1]->BlueSoldier->getName() + ' ' + toString(mAllCity[i + 1]->BlueSoldier->getId());
                                puts(s.c_str());
                            }
                        }                        
                    }
                    //blue
                    if (i > 1)
                    {
                        Soldier *p = mAllCity[i]->BlueSoldier;
                        //if (!p) continue;
                        if (p&&p->hasArrow)
                        {
                            Arrow *q = p->hasArrow;
                            if (mAllCity[i - 1]->RedSoldier)
                            {
                                mAllCity[i - 1]->RedSoldier->tArrow += R;
                                if (q->lose() == 0)//返回值为0说明arrow已经消失
                                {
                                    //delete q;
                                    int t = p->getType();
                                    switch (t)
                                    {
                                    case 0:
                                    {
                                        ((Dragon *)p)->mWeapon = NULL;
                                        break;
                                    }
                                    case 1:
                                    {
                                        if (((Ninja *)p)->mWeapon1 && ((Ninja *)p)->mWeapon1->getType() == 2) ((Ninja *)p)->mWeapon1 = NULL;
                                        if (((Ninja *)p)->mWeapon2 && ((Ninja *)p)->mWeapon2->getType() == 2) ((Ninja *)p)->mWeapon2 = NULL;
                                        break;
                                    }
                                    case 2:
                                    {
                                        ((Iceman *)p)->mWeapon = NULL;
                                        break;
                                    }
                                    case 4:
                                    {
                                        ((Wolf *)p)->arrowWeapon = NULL;
                                        break;
                                    }
                                    }
                                    p->hasArrow = NULL;
                                }
                                string s = st + " blue ";
                                s += mAllCity[i]->BlueSoldier->getName() + ' ' + toString(mAllCity[i]->BlueSoldier->getId()) + " shot";
                                if (mAllCity[i - 1]->RedSoldier&&mAllCity[i - 1]->RedSoldier->getBlood() <= R)
                                    s += " and killed red " + mAllCity[i - 1]->RedSoldier->getName() + ' ' + toString(mAllCity[i - 1]->RedSoldier->getId());
                                puts(s.c_str());
                            }
                        }
                    }
                }

                break;
            }
            case 38:
            {
                 for (int i = 1; i < N; i++)
                {
                    string s = st;
                    Soldier *p = mAllCity[i]->RedSoldier;
                    if (p&&p->hasBomb)
                    {
                        if (mAllCity[i]->BlueSoldier&&checkBomb(p,mAllCity[i]->BlueSoldier,mAllCity[i]->whoFirst))
                        {
                            p->loseWeapon(1);
                            s = st;
                            s += " red "+p->getName()+' '+toString(p->getId())+" used a bomb and killed blue ";
                            s += mAllCity[i]->BlueSoldier->getName()+' '+toString(mAllCity[i]->BlueSoldier->getId());
                            puts(s.c_str());
                            p->die();
                            mAllCity[i]->BlueSoldier->die();
                            mAllCity[i]->RedSoldier = NULL;
                            mAllCity[i]->BlueSoldier = NULL;
                        }
                    }

                    s = st;
                    p = mAllCity[i]->BlueSoldier;
                    if (p&&p->hasBomb)
                    {
                        if (mAllCity[i]->RedSoldier&&checkBomb2(mAllCity[i]->RedSoldier,p, mAllCity[i]->whoFirst))
                        {
                            p->loseWeapon(1);
                            s = st;
                            s += " blue " + p->getName() + ' ' + toString(p->getId()) + " used a bomb and killed red ";
                            s += mAllCity[i]->RedSoldier->getName() + ' ' + toString(mAllCity[i]->RedSoldier->getId());
                            puts(s.c_str());
                            p->die();
                            mAllCity[i]->RedSoldier->die();
                            mAllCity[i]->RedSoldier = NULL;
                            mAllCity[i]->BlueSoldier = NULL;
                        }
                    }

                }
                break;
            }
            case 40:
            {
                for (int i = 1; i < N; i++)//记录lion战斗前的blood
                {
                    if (mAllCity[i]->RedSoldier&&mAllCity[i]->RedSoldier->getType() == 3)
                        ((Lion *)mAllCity[i]->RedSoldier)->moveBlood();
                    if (mAllCity[i]->BlueSoldier&&mAllCity[i]->BlueSoldier->getType() == 3)
                        ((Lion *)mAllCity[i]->BlueSoldier)->moveBlood();
                }
                for (int i = 1; i < N; i++)
                {
                    //先处理arrow事件
                    int r = checkArrow(mAllCity[i]->RedSoldier);
                    int b = checkArrow(mAllCity[i]->BlueSoldier);
                    if (r == -1 || b == -1)
                    {
                        if (r==1) mAllCity[i]->RedSoldier = NULL;
                        if (b==1) mAllCity[i]->BlueSoldier = NULL;
                        continue;//no fight
                    }
                    if (r == 1 && b == 1) { mAllCity[i]->RedSoldier = NULL; mAllCity[i]->BlueSoldier = NULL; }//all die,no fight
                    if (r == 0 && b == 1) { afterbattle(i, 1); mAllCity[i]->BlueSoldier = NULL; redReward(); }//blue die,red win
                    if (r == 1 && b == 0) { afterbattle(i, 2); mAllCity[i]->RedSoldier = NULL; blueReward(); }//blue win

                    if (r == 0 && b == 0)//all not die,begin to fight
                    {
                        int t = mAllCity[i]->whoFirst;
                        if (t == 0)//red attack,blue fightback
                        {
                            int tmp = printFight(i, mAllCity[i]->RedSoldier, mAllCity[i]->BlueSoldier);
                            if (tmp)//没杀死，等待反击
                            {
                                int tmp2=printFightBack(i, mAllCity[i]->BlueSoldier, mAllCity[i]->RedSoldier);
                                if (tmp2)//反击没死，平局
                                {
                                    afterbattle(i, 0);
                                }
                                else// blue win
                                {
                                    printKilled(i, mAllCity[i]->RedSoldier);
                                    afterbattle(i, 2);
                                    mAllCity[i]->RedSoldier = NULL;
                                }
                            }
                            else//杀死了，red win
                            {
                                printKilled(i, mAllCity[i]->BlueSoldier);
                                afterbattle(i, 1);
                                mAllCity[i]->BlueSoldier = NULL;
                            }
                        }
                        else
                        {
                            int tmp = printFight(i, mAllCity[i]->BlueSoldier, mAllCity[i]->RedSoldier);
                            if (tmp)//没杀死，等待反击
                            {
                                int tmp2 = printFightBack(i, mAllCity[i]->RedSoldier, mAllCity[i]->BlueSoldier);
                                if (tmp2)//反击没死，平局
                                {
                                    afterbattle(i, 0);
                                }
                                else// red win
                                {
                                    printKilled(i, mAllCity[i]->BlueSoldier);
                                    afterbattle(i, 1);
                                    mAllCity[i]->BlueSoldier = NULL;
                                }
                            }
                            else//杀死了，blue win
                            {
                                printKilled(i, mAllCity[i]->RedSoldier);
                                afterbattle(i, 2);
                                mAllCity[i]->RedSoldier = NULL;
                            }
                        }
                    }
                }
                redReward();
                blueReward();
                RedBaseInstance->tackBloodWin();
                BlueBaseInstance->tackBloodWin();
                for (int i = 1; i < N; i++)//output
                {
                    while (!mAllCity[i]->output.empty())
                    {
                        puts(mAllCity[i]->output.front().c_str());
                        mAllCity[i]->output.pop();
                    }
                    /*if (mAllCity[i]->redReward)
                    {
                        mAllCity[i]->redReward = 0;
                        string s = printNowTime() + mAllCity[i]->RedSoldier->getPrint() + " earned 8 elements for his headquarter";
                        puts(s.c_str());
                    }
                    if (mAllCity[i]->blueReward)
                    {
                        mAllCity[i]->blueReward = 0;
                        string s = printNowTime() + mAllCity[i]->BlueSoldier->getPrint() + " earned 8 elements for his headquarter";
                        puts(s.c_str());
                    }*/
                    if (mAllCity[i]->FlagRaise == 1&& mAllCity[i]->lastPrintFlag!=1)
                    {
                        mAllCity[i]->FlagRaise = 0;
                        mAllCity[i]->lastPrintFlag = 1;
                        string s = printNowTime() + "red flag raised in city " + toString(i);
                        puts(s.c_str());
                    }
                    if (mAllCity[i]->FlagRaise == 2&& mAllCity[i]->lastPrintFlag!=2)
                    {
                        mAllCity[i]->FlagRaise = 0;
                        mAllCity[i]->lastPrintFlag = 2;
                        string s = printNowTime() + "blue flag raised in city " + toString(i);
                        puts(s.c_str());
                    }
                }
                break;
            }
            case 50:
            {
                string s = printNowTime() + toString(RedBaseInstance->Blood) + " elements in red headquarter";
                puts(s.c_str());
                s = printNowTime() + toString(BlueBaseInstance->Blood) + " elements in blue headquarter";
                puts(s.c_str());
                break;
            }
            case 55:
            {
                for (int i = 0; i <= N; i++)
                {
                    if (mAllCity[i]->RedSoldier)
                    {
                        mAllCity[i]->RedSoldier->printWeapon();
                    }
                }
                if (RedOccSoldier) RedOccSoldier->printWeapon();
                if (BlueOccSoldier) BlueOccSoldier->printWeapon();
                for (int i = 0; i <= N; i++)
                {
                    if (mAllCity[i]->BlueSoldier)
                    {
                        mAllCity[i]->BlueSoldier->printWeapon();
                    }
                }
                break;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    int c = 0;
    while (t--) 
    {
        cout << "Case " << ++c << ":" << endl;
        Init();
        Game();
    }
    system("pause");
    return 0;
}


void Sword::init()
{
    //Attack = mAllSoldier[Belong]->getAttack()*0.2;
}
void Lion::init()
{
    if (getCamp() == 0) {
        Loyalty = RedBaseInstance->Blood;
    }
    else {
        Loyalty = BlueBaseInstance->Blood;
    }
}
void getWeapon(Soldier * t,Weapon* &p, int code)
{
    switch (code)
    {
        case 0:
        {
            p = new Sword();
            ((Sword *)p)->init();
            ((Sword *)p)->setAttack(t->getAttack());
            if (p->getAttack() == 0)
            {
                delete p;
                p = NULL;
            }
            break;
        }
        case 1:
        {
            p = new Bomb();
            ((Bomb *)p)->init();
            t->hasBomb = ((Bomb *)p);
            break;
        }
        case 2:
        {
            p = new Arrow();
            ((Arrow *)p)->init();
            t->hasArrow = ((Arrow *)p);
            break;
        }
    }
    //p->setBelong(getuId());//设置属于谁的
}
void Dragon::init()
{
    getWeapon(this,mWeapon, Id % 3);
    if(mWeapon) mWeapon->setBelong(getuId());//设置属于谁的
    if (Camp == 0)//3.初始化morale
    {
        Morale = (double)RedBaseInstance->Blood / (double)SoldierBlood[0];
    }
    else
    {
        Morale = (double)BlueBaseInstance->Blood / (double)SoldierBlood[0];
    }
}
Soldier* Base::CreatSoldier()
{
    Soldier *tmp=NULL;
    switch (creatwho(SoidierNum))
    {
    case 0://iceman
        tmp = new Iceman();
        break;
    case 1://lion
        tmp = new Lion();
        break;
    case 2://wolf
        tmp = new Wolf();
        break;
    case 3://ninja
        tmp = new Ninja();
        break;
    case 4://dragon
        tmp = new Dragon();
        break;
    }
    if (tmp->getBlood() <= Blood)//可以制造出生命值为 m 的武士
    {
        Blood -= tmp->getBlood();
        SoidierNum++;
        tmp->setCamp(getCamp());
        tmp->setId(SoidierNum);
        tmp->init();
        mSoldier.push_back(tmp);
        mAllSoldier.push_back(tmp);

        if (getCamp() == 0)
        {
            mAllCity[0]->RedSoldier = tmp;
        }
        else
        {
            mAllCity[N]->BlueSoldier = tmp;
        }
        return tmp;
    }
    else
    {
        delete tmp;//
        return NULL;
    }
}

void Dragon::yell(int t)//judge whether to yell
{
    if (mAllCity[t]->whoFirst == Camp)//检测是否先攻击
    {
        if (Morale > 0.8)
        {
            string s = printTime();
            if (Camp == 0) s += " red ";
            if (Camp == 1) s += " blue ";
            s += getName() + ' ' + toString(getId())+" yelled in city "+toString(t);
            mAllCity[t]->output.push(s);
            //puts(s.c_str());
        }
    }
}