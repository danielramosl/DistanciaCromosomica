#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <vector>

void inversion(int* ini, int* fin) {
    std::reverse(ini, fin);
    while(ini < fin) {
        *ini++ *= -1;
    }
}

void imprimeArreglo(const std::vector<int>& arr) {
    for(int p : arr) {
        std::cout << "[" << p << "]";
    }
    std::cout << "\n";
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::vector<int> identidad(n);
    for(int i = 1; i <= n; ++i) {
        identidad[i - 1] = i;
    }
    if(arr == identidad) {
        std::cout << "minimo de pasos " << 0 << "\n";
        return 0;
    }
    std::vector<int> defecto(n, 0);
    std::deque<std::vector<int>> cola = {arr};
    std::map<std::vector<int>, std::vector<int>> vistos;
    vistos[arr] = defecto;
    do {
        std::vector<int> actual = cola.front(); cola.pop_front();
        for(int u = 0; u < actual.size(); ++u) {
            for(int v = u + 1; v < actual.size(); ++v) {
                std::vector<int> hijo = actual;
                if(actual[u] + actual[v] == 1) {
                    inversion(&hijo[u], &hijo[v]);
                } else if(actual[u] + actual[v] == -1) {
                    inversion(&hijo[u + 1], &hijo[v + 1]);
                } else {
                    continue;
                }
                if(hijo == identidad) {
                    int p = 0;
                    std::vector<std::vector<int>> camino;
                    camino.push_back(hijo);
                    do {
                        camino.push_back(actual);
                        actual = vistos[actual];
                        ++p;
                    } while(actual != defecto);
                    std::reverse(camino.begin(), camino.end());
                    for(std::vector v : camino) {
                        imprimeArreglo(v);
                    }
                    std::cout << "Minimo de pasos: " << p << "\n";
                    return 0;
                }
                if(vistos.emplace(hijo, actual).second) {
                    cola.push_back(hijo);
                }
            }
        }
    } while(!cola.empty());
    std::cout << "No se pudo ):\n";
    return 0;
}