#include<iostream>

using namespace std;

#ifndef LIST_H_

template< class T>
class List {
    void clear();
    bool isEmpty();
    bool append();
    bool insert();
    bool Delete();
    bool getValue();
    bool setValue();
    bool getPos();
};

#endif
