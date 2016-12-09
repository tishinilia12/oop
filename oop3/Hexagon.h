#ifndef HEXAGON_H
#define HEXAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
class Hexagon : public Figure{
public:
    Hexagon();
    Hexagon(std::istream &is);
    Hexagon(size_t i);
    Hexagon(const Hexagon& orig);
    friend std::ostream& operator<<(std::ostream& os, const Hexagon& obj);
    double Square() override;
    void Print() override;
    Hexagon& operator=(const Hexagon& right);
    virtual ~Hexagon();
private:
    size_t side_a;
};
#endif 