#include <iostream>

int lider(int arr[], int x) {
    if(arr[x] == x) {
        return x;
    } else {
        int rx = lider(arr, arr[x]);
        arr[x] = rx;
        return rx;
    }
}

void une(int arr[], int x, int y) {
    int rx = lider(arr, x);
    int ry = lider(arr, y);
    if(rx != ry) {
        arr[rx] = ry;
    }
}

bool pregunta(int arr[], int x, int y) {
    return lider(arr, x) == lider(arr, y);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    for(int i = 0; i < m; ++i) {
        char c; int x, y;
        std::cin >> c >> x >> y;
        if(c ==  'U') {
            une(arr, x, y);
        } else if(c == 'P') {
            std::cout << pregunta(arr, x, y) << "\n";
        }
    }
}