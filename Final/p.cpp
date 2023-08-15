#include <iostream>

void primeFactorization(int n) {
    while (n % 2 == 0) {
        std::cout << 2 << " ";
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            std::cout << i << " ";
            n /= i;
        }
    }

    if (n > 2)
        std::cout << n << " ";
}

int main() {
    int number;
    std::cout << "양의 정수를 입력하세요: ";
    std::cin >> number;

    std::cout << number << "의 소인수 분해 결과: ";
    primeFactorization(number);

    return 0;
}