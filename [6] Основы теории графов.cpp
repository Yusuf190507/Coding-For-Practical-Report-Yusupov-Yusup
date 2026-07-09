//Задача A. Поиск в ширину

#include <iostream>
#include <vector>
#include <queue>
 
int main() {
    std::ios_base::sync_with_stdio(false);        
    std::cin.tie(NULL);
 
    int n, m, k;
    std::cin >> n >> m >> k;
    --k;
 
    std::vector<std::vector<int>> g(n);          //список списков смежных узлов
    int row, col;
    for (int _ = 0; _ != m; _++) {
        std::cin >> row >> col;
        --row, --col;
        g[row].push_back(col);
        g[col].push_back(row);
    }
 
    std::vector<int> ways(n, -1);                //установление первоначального состояния узла
    std::queue<int> q;
    ways[k] = 0;                                 //начало исследования данного узла через очередь
    q.push(k);
 
    while (!q.empty()) {
        int v = q.front();
        q.pop();
 
        for (int neighbor : g[v]) {              //обработка смежного узла по отношению к переднему элементу очереди
            if (ways[neighbor] == -1) {
                ways[neighbor] = ways[v] + 1; 
                q.push(neighbor);    
            }
        }
    }
 
    for (int i = 0; i != n; ++i) {
        std::cout << ways[i] << " ";
    }
    std::cout << "\n";
}
