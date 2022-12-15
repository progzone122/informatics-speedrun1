#include <iostream>


using namespace std;

class LinkedList
{
private:
    // structure to perform list node
    struct _Node {
        int value;           // element value
        struct _Node* prev;  // previous element pointer
    }; // global list variable

    void __print(_Node*tmp) {
        if(tmp != NULL) {
            __print(tmp->prev);
            cout << " " << tmp->value;
        }
    }
public:
    //LinkedList() {
    //}
    _Node* tail=NULL;

    // adds new element to the end of the list
    void append(int value) 
    {
        _Node* newNode = new _Node;
        newNode->prev = tail;
        newNode->value = value;
        tail = newNode;
    }

// adds new element before the element with `before` index
void insert(int before, int value)
{
    int len = this->length();
    if (before > -1 && before < len) {
        _Node* tmp = tail;
        if (!len) append(value);
        else {
            for (int i=len-1; i > before; i--, tmp=tmp->prev);
            _Node* newNode = new _Node;
            newNode->value = value;
            newNode->prev = tmp->prev;
            tmp->prev = newNode;
        }
    }
}

// removes last founded element with specified value
void removeLast(int value)
{
    _Node* tmp = tail;
    _Node* tmp2 = tail;
    if (tail != NULL) {
        while (tmp != NULL && tmp->value != value) {
            tmp2 = tmp;
            tmp = tmp->prev;
        }
        if (tmp != NULL) {
            tmp2->prev = tmp->prev;
            delete tmp;
        }
    }
}

    void del(int index) {
        int len = this->length();
        if (len == 1 && index == 0) {
            delete tail;
            tail = NULL;
        }
        if (index > -1 && index < len) {
            _Node *tmp, *tmp2;
            int i;
            for (tmp=tail, i=len-1; i>index+1; i--, tmp=tmp->prev);
            tmp2 = tmp->prev;
            tmp->prev = tmp->prev->prev;
            delete tmp2;
        }
    }


    int length() 
    {
        int counter = 0;
        if (tail != NULL) {
            _Node* tmp = tail;
            for (; tmp != NULL; counter++, tmp=tmp->prev);
        }
        return counter;
    }

    void printNormal() 
    {
        _Node*tmp = tail;
        __print(tmp);
    }
};
