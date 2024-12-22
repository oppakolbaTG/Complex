#include "complex.h"
#include <iostream>
#include <vector>

int main() {

    complex z1(3.0L, 4.0L);  // 3 + 4i
    complex z2(1.0L, -1.0L); // 1 - i


    std::cout << "z1: " << z1 << "\n";
    std::cout << "z2: " << z2 << "\n";
    std::cout << "z1 + z2: " << (z1 + z2) << "\n";
    std::cout << "z1 - z2: " << (z1 - z2) << "\n";
    std::cout << "z1 * z2: " << (z1 * z2) << "\n";
    std::cout << "z1 / z2: " << (z1 / z2) << "\n";

    int power = 2;
    std::cout << "z1 ^ " << power << ": " << z1.Pow(power) << "\n";


    unsigned int n = 3;
    std::vector<complex> roots = z1.Rt(n);
    std::cout << n << "-th roots of z1: " << roots << "\n";

    std::cout << "Conjugate of z1: " << ~z1 << "\n";


    std::cout << "Abs(z1): " << z1.Abs() << "\n";
    std::cout << "Arg(z1): " << z1.Arg() << " radians\n";

    rewind(stdin);
    getchar();
    return 0;
}
