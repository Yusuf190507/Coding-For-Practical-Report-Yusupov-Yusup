#include <iostream>

//достаточно было увидеть закономерность

int main() {
    long long n, k;
    std::cin >> n >> k;
    int count = 0;
    long long new_people = (n + count) * 4;
    unsigned long long sum = 0;
    while (k >= new_people) {
        sum += new_people * (count + 1);
        k -= new_people;
        ++count;
        new_people = (n + count) * 4;
    }
    sum += k * (count + 1);
    std::cout << sum << "\n";
}
