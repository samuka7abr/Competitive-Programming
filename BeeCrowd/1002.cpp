#include <iostream>
#include <iomanip>

int main() {
    double pi = 3.14159;
    double raio;

    std::cin >> raio;

    double area = pi * (raio * raio);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "A=" << area << std::endl;

    return 0;
}
