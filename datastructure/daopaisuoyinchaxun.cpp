#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;

set<int> s[100];
int n,m;
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        int k;
        scanf("%d",&k);
        for(int j = 0; j < k; j++)
        {
            int x;
            scanf("%d",&x);
            s[i].insert(x);
        }
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++)
    {
        set<int> a,b;
        bool flag  = true;
        for(int j = 0; j < n; j++)
        {
            int f;
            scanf("%d",&f);
            if(f == 1&&flag)
            {
                flag = false;
                set<int>::iterator itr1 = s[j].begin();
                set<int>::iterator itr2 = s[j].end();
                while(itr1 != itr2)
                {
                    a.insert(*itr1);
                    itr1++;
                }
            }
            else if(f == 1&& !flag )
            {
                set<int>::iterator itr1 = a.begin();
                set<int>::iterator itr2 = a.end();
                while(itr1 != itr2)
                {
                    if(s[j].find(*itr1) == s[j].end())
                        //itr1 = a.erase(itr1);  这个地方有bug
                        a.erase(itr1++);
                    else
                        itr1++;
                }
                
            }
            else if(f == -1)
            {
                set<int>::iterator itr1 = s[j].begin();
                set<int>::iterator itr2 = s[j].end();
                while(itr1 != itr2)
                {
                    b.insert(*itr1);
                    itr1++;
                }
            }
        }
        set<int>::iterator itr1 = b.begin();
        set<int>::iterator itr2 = b.end();
        while(itr1 != itr2)
        {
            a.erase(*itr1);
            itr1++;
        }
        if(a.empty())
            printf("NOT FOUND\n");
        else
        {
            set<int>::iterator itr = a.begin();
            while(itr != a.end())
            {
                printf("%d ",*itr);
                itr++;
            }
            printf("\n");
        }
    }
    return 0;
}