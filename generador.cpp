#include <iostream>
#include <random>

int main() {
    int n;
    std::cin >> n;
    std::mt19937 mt(time(NULL));
    for(int i = 0; i < n; ++i) {
        std::cout << mt() % 100 << " ";
    }
}