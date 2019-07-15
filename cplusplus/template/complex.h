// 加入防卫式声明
#ifndef __COMPLEX__
#define __COMPLEX__

// 前置声明


// 类声明
template<typename T>
class complex
{
public:
    complex (T r = 0, T i = 0)
        : re (r), im (i)
    { }
    complex& operator += (const complex&);
    T real () const { return re; }
    T imag () const { return im; }

private:
    T re, im;
    friend complex& __doapl (complex*, const complex&);
};


// 类定义

#endif