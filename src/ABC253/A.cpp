#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (std::min(a, c) <= b and b <= std::max(a, c))
        std::cout << "Yes" << '\n';
    else
        std::cout << "No" << '\n';
}






















