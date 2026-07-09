#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i != n; ++i) {
        std::cin >> v[i];
    }
    if (n == 1) {                           //одна карта в колоде
        std::cout << "Deck looks good\n";
        return 0;
    }

    std::sort(v.begin(), v.end());          //нам не важно расположение карт, поэтому колоду сортируем
    for (int i = 0; i + 1 < n; ++i) {
        if (v[i + 1] - v[i] != 1) {
            std::cout << "Scammed\n";
            return 0;
        }
    }

    std::cout << "Deck looks good\n";
}
