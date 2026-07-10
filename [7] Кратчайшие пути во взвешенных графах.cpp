// Задача A - Алгоритм Форда-Беллмана

#include <iostream>
#include <vector>

struct Edge {                 //структуры из Си - лучший вариант для хранения дуг
    int from;   
    int to;    
    int weight;
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL);

    int n, m, s;
    std::cin >> n >> m >> s;
    s--; 

    std::vector<Edge> edges(m);
    for (int i = 0; i != m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        edges[i] = {a - 1, b - 1, c};
    }

    const long long INF = 1e13;                 //выбираем число, которое точно будет больше наибольшой длины пути (исходя из максимальных вводных данных)
    std::vector<long long> distance(n, INF);
    
    distance[s] = 0;

    for (int i = 0; i < n - 1; ++i) {           //согласно теории графов, максимальный путь без циклов - это (кол-во вершин - 1) ед.
        for (const auto& edge : edges) {
            if (distance[edge.from] != INF && distance[edge.from] + edge.weight < distance[edge.to]) {
                distance[edge.to] = distance[edge.from] + edge.weight;
            }
        }
    }

    for (const auto& edge : edges) {            //здесь цикл точно есть, и если при нем нашелся более выгодный путь, значит цикл - отрицательный
        if (distance[edge.from] != INF && distance[edge.from] + edge.weight < distance[edge.to]) {
            std::cout << "Negative cycle" << "\n";
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (distance[i] == INF) {
            std::cout << "inf" << " ";
        } else {
            std::cout << distance[i] << " ";
        }
    }
    std::cout << "\n";
}
