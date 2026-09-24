#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <typeinfo>
#define ll long long int
#define infinity - 1
#define modulo (ll)(10e9 + 7)
#define MAX 5000

struct Point_Chunk {
    int index;
    int point;
    ll weight;
};

bool sort_weight(Point_Chunk &a, Point_Chunk &b) {
    return a.weight < b.weight;
}

bool sort_point(Point_Chunk &a, Point_Chunk &b) {
    return a.point < b.point;
}

int main(){
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::vector<Point_Chunk> point_chunks;
        std::cin >> n >> m;
        
        for (int i = 0; i < m;i++) {
            int point;
            ll weight;
            std::cin >> point >> weight;
            point_chunks.push_back({i + 1, point, weight});
        }

        std::sort(point_chunks.begin(), point_chunks.end() , sort_weight);
        std::vector<Point_Chunk> indices;
        ll sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            sum += point_chunks[i].weight;
            indices.push_back(point_chunks[i]);
        }

        std::sort(indices.begin(), indices.end(), sort_point);
        std::cout << sum << std::endl;
        for (int i = 0; i < n; i++) {
            int l = indices[i].index;
            int r = indices[2 * n - 1 - i].index;
            std::cout << l << " " << r << std::endl;
        }
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1650/problem/C
 */
