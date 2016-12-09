#ifndef OCTAGON_H
#define OCTAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
class Octagon : public Figure{
public:
    Octagon();
    Octagon(std::istream &is);
    Octagon(size_t i);
    Octagon(const Octagon& orig);
    friend std::ostream& operator<<(std::ostream& os, const Octagon& obj);
    double Square() override;
    void Print() override;
    Octagon& operator=(const Octagon& right);
    virtual ~Octagon();
private:
    size_t side_a;
};
#endif 