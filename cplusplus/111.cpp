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