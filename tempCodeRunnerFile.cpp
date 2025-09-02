#include <iostream>

int main() {
    double pi = 3.14159;
    double radius;
    std::cout << "Enter radius of circle: ";
    std::cin >> radius;

    double diameter = 2 * radius;
    std::cout << diameter;
    return 0;
}   