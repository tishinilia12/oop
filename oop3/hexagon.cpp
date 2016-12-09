#include "Hexagon.h"
#include <iostream>
#include <cmath>
Hexagon::Hexagon() {
    side_a = 0;
}
Hexagon::Hexagon(size_t i) : side_a(i) {
    std::cout << "Hexagon created: " << side_a << std::endl;
}
Hexagon::Hexagon(std::istream &is) {
    std::cout << "enter a\n";
    is >> side_a;
}
Hexagon::Hexagon(const Hexagon& orig) {
    std::cout << "Hexagon copy created" << std::endl;
    side_a = orig.side_a;
}
double Hexagon::Square() {
    return double(side_a * side_a)*3*sqrt(3)/2;
}
void Hexagon::Print() {
    std::cout << "a=" << side_a <<
        std::endl;
}
Hexagon& Hexagon::operator=(const Hexagon& right) {
    if (this == &right) return *this;
    std::cout << "Hexagon copied" << std::endl;
    side_a = right.side_a;
    return *this;
}
std::ostream& operator<<(std::ostream& os, const Hexagon& obj) {
    os << "Hexagon    "<<"a=" << obj.side_a<<std::endl;
    return os;
}
Hexagon::~Hexagon() {
    std::cout << "Hexagon deleted" << std::endl;
}