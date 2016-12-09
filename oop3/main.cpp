#include <cstdlib>
#include <iostream>
#include <memory>
#include "TTreeItem.h"
#include "TTree.h"
#include "Triangle.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "Tallocator.h"
int main() {
    TAllocator allocator(sizeof(int), 3);// объявляем аллокатор
    TTree<Octagon> tree;
    int *a1 = nullptr;
    int *a2 = nullptr;
    int *a3 = nullptr;
    int *a4 = nullptr;
    int *a5 = nullptr;

    a1 = (int*)allocator.allocate(); *a1 = 1; std::cout << "a1 pointer value:" //выделяем память с аллокатора
        << *a1 << std::endl;
    a2 = (int*)allocator.allocate(); *a2 = 2; std::cout << "a2 pointer value:"
        << *a2 << std::endl;
    a3 = (int*)allocator.allocate(); *a3 = 3; std::cout << "a3 pointer value:"
        << *a3 << std::endl;

    allocator.deallocate(a1);//освобождаем память с аллокатора 
    allocator.deallocate(a3);
    a4 = (int*)allocator.allocate(); *a4 = 4; std::cout << "a4 pointer value:"// заново выделяем память с аллокатора
        << *a4 << std::endl;
    a5 = (int*)allocator.allocate(); *a5 = 5; std::cout << "a5 pointer value:"
        << *a5 << std::endl;
    std::cout << "a1 pointer value:" << *a1 << std::endl; // смотрем что получилось 
    std::cout << "a2 pointer value:" << *a2 << std::endl;
    std::cout << "a3 pointer value:" << *a3 << std::endl;
    tree.push(std::shared_ptr<Octagon>(new Octagon(std::cin))); // в струкура дерево заносим элементы
    tree.push(std::shared_ptr<Octagon>(new Octagon(std::cin)));
    tree.push(std::shared_ptr<Octagon>(new Octagon(std::cin)));
    for (auto i : tree) std::cout << *i << std::endl;// смотрим на них с итератора
    return 0;
}