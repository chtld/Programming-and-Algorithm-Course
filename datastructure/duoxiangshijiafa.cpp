#include <iostream>
using namespace std;
struct item{
    int k, ex;
    item *next;
};
item equalmark;

//用来在链表中查找ex与当前值相等的链表元素(The function is used to find the element of the chained table who has the same ex as the current value)

item *search(item *current, item *head)
{
    while (head->next != NULL)
    {
        if (current->ex == head->next->ex)
        {
            head->next->k += (current->k);
            delete current;
            return &equalmark;
        }
        if (current->ex > head->next->ex)
            break;
        head = head->next;
    }
    return head;
}

int main()
{
    int inputnum;
    cin >> inputnum;
    while (inputnum--)
    {
        item *head = NULL, *current = NULL;
        int k, ex;
        for (int i = 0; i <= 1; i++)
        {
             while (cin >> k >> ex, ex >= 0)
             {
                current = new item;
                 current->k = k, current->ex = ex, current->next = NULL;
                 if (head == NULL)
                     head = current;
                 else if (current->ex > head->ex)
                 {
                     current->next = head;
                     head = current;
                 }
                 else if (current->ex == head->ex)
                 {
                     head->k += current->k;
                     delete current;
                 }
                 else
                 {
                     item *temp = search(current, head);
                     if (temp != &equalmark)
                     {
                         current->next = temp->next;
                         temp->next = current;
                     }
                 }
             }
        }
        current = head;
//遍历加法之后得到的链表，输出结果(travese the chained table and output the result)
        while (current->next != NULL)
        {
            if (current->k != 0)
                cout << "[ " << current->k << ' ' << current->ex << " ] ";
            current = current->next;
        }
        if (current->k != 0)
            cout << "[ " << current->k << ' ' << current->ex << " ] ";
        if (inputnum > 0)
            cout << endl;
        while (head != NULL)
        {
            item *temp = head->next;
            delete head;
            head = temp;
        }
    }
    return 0;
}