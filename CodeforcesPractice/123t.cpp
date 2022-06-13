#include <iostream>

int main() {
    int x;
    if (rand() % 2) {
        x = 5;
    }
    std::cout << x << std::endl;
    return 0;
}