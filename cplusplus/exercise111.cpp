#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
template<class T1, class T2, class T3 = greater<T1> >
class MyMultimap:public multimap<T1, T2, T3 >{
public:
	void Set(const T1 s, T2 x ){
		for (typename multimap<T1, T2, T3>::iterator i = this->begin(); i != this->end(); ++ i) {
			if (i->first == s) i->second = x;
		}
	}
/* 	template<class T6, class T7, class T8 = >
	friend bool operator<(const pair<T6, T7>& p1, const pair<T6, T7>& p2); */
	template<class T4, class T5>
	friend ostream& operator<<(ostream& os, const pair<T4, T5 >& p);
};

template<class T4, class T5>
ostream& operator<<(ostream& os, const pair<T4, T5 >& p){
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

/* template<class T6, class T7, class T8 = less<T6> >
bool operator<(const MyMultimap<T6, T7, T8>& p1, const MyMultimap<T6, T7, T8>& p2){
	return p1.first > p2.first;
} */

struct Student
{
        string name;
        int score;
};
template <class T>
void Print(T first,T last) {
        for(;first!= last; ++ first)
                cout << * first << ",";
        cout << endl;
}
int main()
{

        Student s[] = { {"Tom",80},{"Jack",70},
                                        {"Jone",90},{"Tom",70},{"Alice",100} };
        MyMultimap<string,int> mp;
        for(int i = 0; i<5; ++ i)
                mp.insert(make_pair(s[i].name,s[i].score));
        Print(mp.begin(),mp.end()); //按姓名从大到小输出

        mp.Set("Tom",78); //把所有名为"Tom"的学生的成绩都设置为78
        Print(mp.begin(),mp.end());


        MyMultimap<int,string,less<int> > mp2;
        for(int i = 0; i<5; ++ i)
                mp2.insert(make_pair(s[i].score,s[i].name));

        Print(mp2.begin(),mp2.end()); //按成绩从小到大输出
        mp2.Set(70,"Error");          //把所有成绩为70的学生，名字都改为"Error"
        Print(mp2.begin(),mp2.end());
        cout << "******" << endl;

        mp.clear();
        
        string name;
        string cmd;
        int score;
        while(cin >> cmd ) {
                if( cmd == "A") {
                        cin >> name >> score;
                        if(mp.find(name) != mp.end() ) {
                                cout << "erroe" << endl;
                        }
                        mp.insert(make_pair(name,score));
                }
                else if(cmd == "Q") {
                        cin >> name;
                        MyMultimap<string,int>::iterator p = mp.find(name);
                        if( p!= mp.end()) {
                                cout << p->second << endl;
                        }
                        else {
                                cout << "Not Found" << endl;
                        }
                }
        }
        return 0;
}