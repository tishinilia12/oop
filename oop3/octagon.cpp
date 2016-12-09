#include "Octagon.h"
#include <iostream>
#include <cmath>
Octagon::Octagon() {
    side_a = 0;
}
Octagon::Octagon(size_t i) : side_a(i){
    std::cout << "Octagon created: " << side_a << std::endl;
}
Octagon::Octagon(std::istream &is) {
    std::cout << "enter a\n";
    is >> side_a;
}
Octagon::Octagon(const Octagon& orig) {
    std::cout << "Octagon copy created" << std::endl;
    side_a = orig.side_a;
}
double Octagon::Square() {
    return 2.0*side_a*side_a*(1+sqrt(2));
}
void Octagon::Print() {
    std::cout << "a=" << side_a  <<
        std::endl;
}
Octagon& Octagon::operator=(const Octagon& right) {
    if (this == &right) return *this;
    std::cout << "Octagon copied" << std::endl;
    side_a = right.side_a;
    return *this;
}
std::ostream& operator<<(std::ostream& os, const Octagon& obj) {
    os <<"Octagon    "<< "a=" << obj.side_a<<std::endl;
    return os;
}
Octagon::~Octagon() {
    std::cout << "Octagon deleted" << std::endl;
}