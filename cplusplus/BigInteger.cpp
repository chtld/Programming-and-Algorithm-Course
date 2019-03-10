#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>
using namespace std;


class BigInteger{
public:
	bool flag;          // 标识正负数
	string value;       // 存储大整数
	
public:
	explicit BigInteger();               // 不能在隐式转换中使用这个构造函数
	BigInteger(const int i);
	BigInteger(const string & str);
	BigInteger(const BigInteger & temp); // 复制构造函数
	~BigInteger();                       // 析构函数
	
	
public:
	bool inline isPositive() {return flag;};              // 判断大数的正负号
	int compareBigInteger(const BigInteger & temp) const; // 比较两个数的大小
	const BigInteger absolute () const;                   // 取绝对值
	void setValue(const string & str);
	BigInteger & operator = (const BigInteger & temp);    // 重载赋值号
	BigInteger & operator = (const string & str);
	const BigInteger operator + (const BigInteger & temp);// 重载四则运算
	const BigInteger operator - (const BigInteger & temp);
	const BigInteger operator * (const BigInteger & temp);
	const BigInteger operator / (const BigInteger & temp);
	const BigInteger operator % (const BigInteger & temp);
	friend ostream & operator << (ostream & os, const BigInteger &temp);// 重载左移运算符
	friend istream & operator >> (istream & is, BigInteger &temp);// 重载右移运算符
};

ostream & operator << (ostream & os, const BigInteger &temp);
istream & operator >> (istream & is, const BigInteger &temp);

BigInteger::BigInteger() : value(""), flag(true) {}

BigInteger::BigInteger(const int i){
	value.clear();
	if (i > 0) flag = true;
	else flag = false;
	int v = abs(i);
	while (v) {
		value.push_back(char('0' + (v % 10)));
		v /= 10;
	}
	reverse(value.begin(), value.end());
	if (value.empty()){
		value.push_back('0');
		flag = true;
	}
}

void BigInteger::setValue(const string & str){
	value.clear();
	string tmpstr(str.begin() + str.find_first_not_of(' '), str.end());
	if(tmpstr.empty()) {
		value.push_back('0');
		flag = true;
		return;
	}
	if (tmpstr.at(0) == '-') flag = false;
	else flag = true;
	int i = tmpstr.find_first_of("0123456789");
	int j = tmpstr.find_last_of("0123456789");
	value = tmpstr.substr(i, j - i + 1);
}

BigInteger::BigInteger(const string & str){
	setValue(str);
}

BigInteger::BigInteger(const BigInteger & temp) : value(temp.value), flag(temp.flag){} //私有成员是否可以访问

BigInteger::~BigInteger(){}

int BigInteger::compareBigInteger(const BigInteger & temp) const {
	// 异号情况
	if (flag && !temp.flag) return 1;
	if (!flag && !temp.flag) return -1;
	// 同号情况
	int ret = 0;
	if (value.length() > temp.value.length()) ret = 1;
	else if (value.length() < temp.value.length()) ret = -1;
	else ret = value.compare(temp.value);
	
	if (flag) return ret;
	return -ret;
}

const BigInteger BigInteger::absolute() const {
	BigInteger ret(*this);
	ret.flag = true;
	return ret;
}

BigInteger & BigInteger::operator = (const BigInteger &temp){
	flag = temp.flag;
	value = temp.value;
	return *this;
}

BigInteger & BigInteger::operator = (const string & str) {
	setValue(str);
}

const BigInteger BigInteger::operator + (const BigInteger & temp){
	BigInteger ret;
	if(flag == temp.flag){
		string lvalue(value), rvalue(temp.value);
		// 先相加，然后进位
		reverse(lvalue.begin(), lvalue.end());
		reverse(rvalue.begin(), rvalue.end());
		int i = 0;
		for ( ; i < lvalue.length() && i < rvalue.length(); ++i) {
			ret.value.push_back(lvalue.at(i) + rvalue.at(i) - '0');
		}
		if (i < lvalue.length()) {
			for (; i < lvalue.length(); ++i) {
				ret.value.push_back(lvalue.at(i));
			}
		} else {
			for (; i < rvalue.length(); ++ i) {
				ret.value.push_back(rvalue.at(i));
			}
		}
		int carry = 0;
		for (int i = 0; i < ret.value.length(); ++i) {
			int newValue = ret.value.at(i) - '0' + carry;
			carry = newValue / 10;
			ret.value.at(i) = newValue - carry * 10 + '0';
		}
		if (carry) ret.value.push_back(carry + '0');
		ret.flag = flag;
	} else {
		BigInteger absL = this->absolute();
		BigInteger absR = temp.absolute();
		int compFlag = absL.compareBigInteger(absR);
		if (compFlag == 0) {
			ret = "0";
			ret.flag = true;
			return ret;
		} else {
			if (compFlag == -1) {
				BigInteger tmp(absL);
				absL = absR;
				absR = tmp;
			}
			reverse(absL.value.begin(), absL.value.end());
			reverse(absR.value.begin(), absR.value.end());
			int i = 0;
			for (; i < absL.value.length() && i < absR.value.length(); ++i) {
				ret.value.push_back(absL.value.at(i) - absR.value.at(i) + '0');
			}
/* 			cout << absL << endl;
			cout << absR << endl; */
			if (i < absL.value.length()){
				for (; i < absL.value.length(); ++i) {
					ret.value.push_back(absL.value.at(i));
				}
			}
			
			
			int give = 0;
			for(i = 0; i < ret.value.length(); ++i){
				int newValue = ret.value.at(i) - '0' - give;
				if (newValue < 0) give = 1;
				else give = 0;
				ret.value.at(i) = newValue + give * 10 + '0';
			}
			if (compFlag > 0) ret.flag = flag;
			else ret.flag = temp.flag;
		}
	}
	reverse(ret.value.begin(), ret.value.end());
	int i = ret.value.find_first_not_of("0");
	if (i == string:: npos) {
		ret = "0";
		ret.flag = true;
		return ret;
	}
	ret.value = string(ret.value.begin() + ret.value.find_first_not_of("0"), ret.value.end());
	return ret;
}

const BigInteger BigInteger::operator - (const BigInteger & temp){
	BigInteger tmp(temp);
	tmp.flag = !tmp.flag;
	return (*this + tmp);
}

const BigInteger BigInteger::operator * (const BigInteger & temp){
	BigInteger ret;
	int flag1 = this->compareBigInteger(BigInteger(0));
	int flag2 = temp.compareBigInteger(BigInteger(0));
	if (flag1 == 0 || flag2 == 0) {
		ret = "0";
		ret.flag = true;
		return ret;
	}
	if (flag == temp.flag) ret.flag = true;
	else ret.flag = false;
	string lvalue(value), rvalue(temp.value);
	reverse(lvalue.begin(), lvalue.end());
	reverse(rvalue.begin(), rvalue.end());
	ret.value.resize(lvalue.size() + rvalue.size(), '0');
	for (int i = 0; i < lvalue.size(); ++i)
		for (int j = 0; j < rvalue.size(); ++j) {
			int newValue = ret.value[i + j] + (lvalue[i] - '0') * (rvalue[j] - '0') - '0';
			int carry = newValue / 10;
			ret.value[i + j] = newValue % 10 + '0';
			for (int k = i + j + 1; carry != 0 && k < ret.value.size(); ++k) {
				ret.value[k - 1] = newValue % 10 + '0';
				newValue = ret.value[k] + carry - '0';
				ret.value[k] = newValue % 10 + '0';
				carry = newValue / 10;
			}
		}
	reverse(ret.value.begin(), ret.value.end());
	ret.value = string(ret.value.begin() + ret.value.find_first_not_of("0"), ret.value.end());
	return ret;
}

const BigInteger BigInteger::operator / (const BigInteger & temp){
	BigInteger ret;
	assert(temp.compareBigInteger(BigInteger(0)) != 0);
	ret = "0";
	BigInteger absL(this->absolute());
	BigInteger absR(temp.absolute());
	int compareFlag = absL.compareBigInteger(absR);
	if (compareFlag < 0) return ret;
	if (compareFlag == 0) {
		ret = "1";
		if (flag == temp.flag) ret.flag = true;
		else ret.flag = false;
		return ret;
	}
	int movCount = absL.value.size() - absR.value.size();
	const BigInteger ten(10);
	do{
		BigInteger tmp(absR);
		for (int i = 0; i < movCount; ++i) {
			tmp = tmp * ten;
		}
		int addNum = 0;
		while (absL.compareBigInteger(tmp) >= 0){
			absL = absL - tmp;
			addNum++;
		}
		ret = ret * ten;
		ret = ret + BigInteger(addNum);
		movCount--;
	} while(movCount >= 0);
	if (flag == this->flag) ret.flag = true;
	else ret.flag = false;
	return ret;
}

const BigInteger BigInteger::operator % (const BigInteger & temp){
	BigInteger divTmp = (*this) / temp;
	return (*this - divTmp * temp);
}

ostream & operator << (ostream & os, const BigInteger &temp){
	if(!temp.flag) os << "-";
	os << temp.value;
	return os;
}

istream & operator >> (istream & is, BigInteger &temp){
	string str;
	is >> str;
	temp = str;
	return is;
}

int main(){
	BigInteger a, b;
	char oper;
	cin >> a >> oper >> b;
	switch(oper){
		case '+':
		cout << a + b << endl;
		break;
		case '-':
		cout << a - b << endl;
		break;
		case '*':
		cout << a * b << endl;
		break;
		case '/':
		cout << a / b << endl;
		break;
		default:
		cout << "This is an error!" << endl;
	}
	return 0;
}








