class MyString:public string{
public:
    MyString():string() {};
    MyString(const string &str):string(str) {}; //类型转换构造函数
    MyString(const char* str):string(str) {};//char*是数据类型，而string是类，要弄清楚。
    MyString(MyString& myStr):string(myStr) {};//复制构造函数
    MyString operator()(int start, int length)
    {
        return this->substr(start, length);
    }
};