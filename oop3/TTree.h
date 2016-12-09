#ifndef TTREE_H
#define TTREE_H
#include <memory>
#include "Octagon.h"
#include "Hexagon.h"
#include "Triangle.h"
#include "TTreeItem.h"
#include "Titerator.h"
template <class T> class TTree {
public:
    TTree() : head(nullptr) {
    }
    TTree(const TTree<T>& orig) {
        head = orig.head;
    }
    bool empty() {
        return head == nullptr;
    }

    void push(const std::shared_ptr<T> &&TTupe) {
        std::shared_ptr<TTreeItem<T>> other = (std::shared_ptr<TTreeItem<T>>)new TTreeItem<T>(TTupe);
        if (empty())this->head = (std::shared_ptr<TTreeItem<T>>) new TTreeItem<T>(std::shared_ptr<T>(new T()));
        std::shared_ptr<TTreeItem<T>> old = this->head;
        this->head->Gettreerihgt() = old->Setnext(other);
    }
    void pop() {
        T result;
        if (head != nullptr) {
            std::shared_ptr<TTreeItem<T>> old_head = head->Getnext();
            head->delite();
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const TTree<T>& tree) {
        std::shared_ptr<TTreeItem<T>> item = tree.head->Gettreerihgt();
        std::shared_ptr<TTreeItem<T>> item1;
        while (item != nullptr)
        {
            if (item->Gettreerihgt() != nullptr){
                item1 = item->Gettreerihgt();
                os << *item1;
            }
            os << *item;
            item = item->Gettreeleft();
        }
        return os;
    }
    virtual ~TTree(){
    }
    TIterator<TTreeItem<T>, T> begin(){
        return TIterator<TTreeItem<T>, T>(head);
    }
    TIterator<TTreeItem<T>, T> end(){
        return TIterator<TTreeItem<T>, T>(nullptr);
    }
    std::shared_ptr<TTreeItem<T>> head;
};
#endif