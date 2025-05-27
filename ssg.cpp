#include <algorithm>
#include <queue>
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n + 2];
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    arr[0] = -1;
    arr[n + 1] = n + 1;
    std::vector<std::vector<int>> g(n + 1, std::vector<int>());
    for(int i = 1; i < n + 2; ++i) {
        int u, v;
        if(arr[i - 1] < 0) {
            u = (-1) * arr[i - 1] - 1;
        } else {
            u = arr[i - 1];
        }
        if(arr[i] < 0) {
            v = -arr[i];
        } else {
            v = arr[i] - 1;
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<bool> vistos(n + 1, 0);
    auto iter = vistos.begin();
    int componentes = 0;
    while(iter != vistos.end()) {
        componentes += 1;
        std::queue<int> cola;
        cola.push(iter - vistos.begin());
        do {
            int actual = cola.front(); cola.pop();
            for(int hijo : g[actual]) {
                if(vistos[hijo] == 0) {
                    vistos[hijo] = 1;
                    cola.push(hijo);
                }
            }
        } while(!cola.empty());
        iter = std::find(vistos.begin(), vistos.end(), 0);
    }
    printf("%d\n", n + 1 - componentes);
    return 0;
}