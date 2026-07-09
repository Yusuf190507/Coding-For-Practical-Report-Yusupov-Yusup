//Задача A. Запуск зонда

#include <iostream>
#include <vector>

long long NOD(long long n1, long long n2) {  //функция нахождения наибольшего общего делителя 
    while (n1 != n2) {
        if (n1 > n2) {
            if (n1 % n2 != 0) {
                n1 -= n1 / n2 * n2;
            } else {
                n1 = n2;
            }
        } else {
            if (n2 % n1 != 0) {
                n2 -= n2 / n1 * n1;
            } else {
                n2 = n1;
            }
        }
    }
    return n1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i != n; ++i) {
        std::cin >> v[i];
    }
    long long res = v[0];
    for (int i = 1; i < n; ++i) {
        long long div = NOD(res, v[i]);
        long long n1 = NOD(div, res);         //это сделано для устранения проблем с самыми большими краевыми числами
        long long n2 = div / n1;
        res = res / n1 * (v[i] / n2);
    }
    std::cout << res << "\n";
} 
