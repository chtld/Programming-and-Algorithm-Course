template<class T>
class CMyistream_iterator{
public:
	T temp;
	CMyistream_iterator(istream & is){
		is >> temp;
	}
	T& operator * () {
		return temp;
	}
	void operator ++ (int) {
		cin >> temp;
	}
};
