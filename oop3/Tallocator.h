#ifndef TALLOCATOR_H
#define TALLOCATOR_H
#include "Tqueque.h"
#include <cstdlib>
#include <iostream>
class TAllocator {
public:
    TAllocator(size_t size, size_t count) { // конструктор класса аллокатор
        _size = size;
        _count = count; 
        _used_blocks = (char*)malloc(_size*_count);//выделяем память
        _free_blocks = new Tqueque<void*>;

        for (size_t i = 0; i<_count; i++) _free_blocks->push(_used_blocks + i*_size);//заносим в очередь элементы
        _free_count = _count;
        std::cout << "TAllocationBlock: Memory init" << std::endl;
    }
    void *allocate() { // выделить память с аллокатора
        void *result = nullptr;

        if (_free_count>0)
        {
            result = _free_blocks->front();
            _free_blocks->pop();
            _free_count--;
            std::cout << "TAllocationBlock: Allocate " << (_count - _free_count) <<
                " of " << _count << std::endl;
        }
        else
        {
            std::cout << "TAllocationBlock: No memory exception :-)" <<
                std::endl;
        }

        return result;
    }
    void deallocate(void *pointer) {// освободить память с аллокатора
        std::cout << "TAllocationBlock: Deallocate block " << std::endl;

        _free_blocks->push( pointer);
        _free_count++;
    }
    bool has_free_blocks() {// посмотреть свободные блоки
        return _free_count>0;
    }

    virtual ~TAllocator(){//диструктор для класса аллокатор
        if (_free_count<_count) std::cout << "TAllocationBlock: Memory leak?" <<std::endl;
        else std::cout << "TAllocationBlock: Memory freed" <<std::endl;
        delete _free_blocks;
        delete _used_blocks;
    }
private:
    size_t _size;// длина типа в байтах
    size_t _count;// количество элементов

    char *_used_blocks;// используемые блоки
    Tqueque<void *> *_free_blocks;// ссылки на свободные блоки

    size_t _free_count;// соличество свободных блоков

};
#endif 