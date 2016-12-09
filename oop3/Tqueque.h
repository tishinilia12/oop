#ifndef TQUEQUE_H
#define TQUEQUE_H
#include <cstdlib>
#include <memory>
#include <iostream>
template <class T> class Tnode{ // элемент очереди 
public:
    std::shared_ptr<Tnode<T>> next;
    T tmp;
    Tnode(T a){// конструктор класса элемент очереди 
        tmp = a;
        next = nullptr;
    }
};
template <class T> class Tqueque{ // голова очереди 
public:
    std::shared_ptr<Tnode<T>> first;
    std::shared_ptr<Tnode<T>> out;
    int size;
    Tqueque(){// конструктор класса голова очереди 
        size = 0;
        first = nullptr;
        out = nullptr;
    }
    void push(T tmp){// добавить элеминт в очередь 
        std::shared_ptr<Tnode<T>> node = (std::shared_ptr<Tnode<T>>)new Tnode<T>(tmp);
        if (first == nullptr){// если нету элементов обявляем их
            first = node;
            out = node;
        }
        else{
            out->next = node;
            out = node;
        }
        size++;
    }
    void pop(){// удалить элемента с начала очереди
        if (first == nullptr){
            return;
        }
        size--;
        if (first == out){
            first = nullptr;
            out = nullptr;
            return;
        }
        first = first->next;

    }
    T front(){//узнать первый элемент в очереди
        if (first != nullptr){
            return first->tmp;
        }
        exit(99);// выдать ошибку если нету элементов
    }
};
#endif 
