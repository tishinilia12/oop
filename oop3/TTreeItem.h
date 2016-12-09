#ifndef TTREEITEM_H
#define TTREEITEM_H
#include <memory>
#include "Octagon.h"
#include "Hexagon.h"
#include "Triangle.h"

template <class T> class TTreeItem {
public:
    TTreeItem(const std::shared_ptr<T>TTupe){
        this->TTupe = TTupe;
        this->left = nullptr;
        this->right = nullptr;
        std::cout << "Tree item: created" << std::endl;
    }
    TTreeItem(const TTreeItem& orig){
        this->TTape = orig.TTape;
        this->left = orig.left;
        this->right = orig.right;
        std::cout << "Tree item: copied" << std::endl;
    }
    std::shared_ptr<TTreeItem<T>> Setnext(std::shared_ptr<TTreeItem<T>> next) {
        std::shared_ptr<TTreeItem<T>> old = this->right;

        if (old == nullptr){
            this->right = next;
            return this->right;
        }
        while (old->left != nullptr){
            if (old->right == nullptr){
                old->right = next;
                return this->right;
            }
            old = old->left;
        }
        old->left = next;
        return this->right;
    }
    void TTreeItem<T>::delite(){
        std::shared_ptr<TTreeItem<T>> asd = this->right;
        while (asd->left != nullptr){
            if (asd->left->right == nullptr){
                asd->left = nullptr;
            }
            asd = asd->left;
            return;
        }
        if (asd->right != nullptr){
            asd->right = nullptr;
        }
    }
    std::shared_ptr<T> TTreeItem<T>::GetTTupe() const {
        return this->TTupe;
    }
    std::shared_ptr<TTreeItem<T>> TTreeItem<T>::Gettreeleft() {
        return this->left;
    }
    std::shared_ptr<TTreeItem<T>> TTreeItem<T>::Gettreerihgt(){
        return this->right;
    }
    TTreeItem<T>::~TTreeItem() {
        std::cout << "Tree item: deleted" << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const TTreeItem<T>& obj) {
        os << "---------------------" << std::endl << *obj.TTupe << std::endl << "----------------------" << std::endl;
        return os;
    }
    std::shared_ptr<TTreeItem> Getnext(){
        std::shared_ptr<TTreeItem<T>> old = this->right;

        if (old == nullptr){
            this->right = next;
            return this->right;
        }
        while (old->left != nullptr){
            if (old->right == nullptr){
                old->right = next;
                return this->right;
            }
            old = old->left;
        }
        old->left = next;
        return this->right;
    }
    std::shared_ptr<T>TTupe;
    std::shared_ptr<TTreeItem>  left;
    std::shared_ptr<TTreeItem> right;
};
#endif