#ifndef TQUEQUE_H
#define TQUEQUE_H
#include <cstdlib>
#include <memory>
#include <iostream>
template <class T> class Tnode{ // ������� ������� 
public:
    std::shared_ptr<Tnode<T>> next;
    T tmp;
    Tnode(T a){// ����������� ������ ������� ������� 
        tmp = a;
        next = nullptr;
    }
};
template <class T> class Tqueque{ // ������ ������� 
public:
    std::shared_ptr<Tnode<T>> first;
    std::shared_ptr<Tnode<T>> out;
    int size;
    Tqueque(){// ����������� ������ ������ ������� 
        size = 0;
        first = nullptr;
        out = nullptr;
    }
    void push(T tmp){// �������� ������� � ������� 
        std::shared_ptr<Tnode<T>> node = (std::shared_ptr<Tnode<T>>)new Tnode<T>(tmp);
        if (first == nullptr){// ���� ���� ��������� �������� ��
            first = node;
            out = node;
        }
        else{
            out->next = node;
            out = node;
        }
        size++;
    }
    void pop(){// ������� �������� � ������ �������
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
    T front(){//������ ������ ������� � �������
        if (first != nullptr){
            return first->tmp;
        }
        exit(99);// ������ ������ ���� ���� ���������
    }
};
#endif 
