//Задача A. Сложение

#include <iostream>
#include <algorithm>
#include <array>
 
std::array<long long, 200000> v{};          //используется статический массив для скорости
 
int main() {
    std::ios_base::sync_with_stdio(false);  //ускорение работы с выводом
    std::cin.tie(NULL);                     //и вводом
 
    int n, q;
    std::cin >> n >> q;
    for (int _ = 0; _ != q; ++_) {
        int l, r, value;
        std::cin >> l >> r >> value;
        --l;
        v[l] += value;                      //метод префиксных сумм
        v[r] -= value;
    }
 
    long long res = 0;
    for (int i = 0; i != n; ++i) {
        res += v[i];
        std::cout << res << " ";
    }
    std::cout << "\n";
} 
