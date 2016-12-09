#ifndef TITERATOR_H
#define TITERATOR_H
#include <memory>
#include <iostream>
template <class node, class T>
class TIterator
{
public:
    TIterator(std::shared_ptr<node> n) {
        node_ptr = n;
        if (n != nullptr){
            Ret = n->right;
        }
        else
        {
            Ret = nullptr;
        }
    }
    std::shared_ptr<T> operator * (){
        return Ret->TTupe;
    }
    std::shared_ptr<T> operator -> (){
        return Ret->TTupe;
    }
    void operator ++ (){
        std::shared_ptr<node> tmp = node_ptr->right;
        while (1){

            if (tmp->left == Ret){
                Ret = tmp->right;
                return;
            }
            if (tmp == Ret){
                Ret = Ret->left;
                return;
            }
            tmp = tmp->right;
        }
    }
    bool operator == (TIterator const& i){
        return Ret == i.Ret;
    }
    bool operator != (TIterator const& i){
        return !(*this == i);
    }
private:
    std::shared_ptr<node> node_ptr;
    std::shared_ptr<node> Ret;
};
#endif
