#include <iostream>
using namespace std;

template <typename T>

struct Element{
    T data;
    Element <T>* previous, next;
};

template <typename T>

struct Deque{
    Element <T>* front_p;
    Element <T>* back_p;
    int sz;

    Deque();
    ~Deque();

    bool empty();
    int size();

    T front();
    T back();

    void push_front(T);
    void push_back(T);

    void pop_front();
    void pop_back()

    void clear();
};

template <typename T>

Deque<T>::Deque() {
    front_p = nullptr;
    back_p = nullptr;
}

template <typename T>

Deque<T>::~Deque() {
    clear();
}

int main() {


    return 0;

}

