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

void DFS(
    std::vector<std::vector<int>> &adjust,
    std::vector<ll> &num_leaf_at_nodes,
    int parent,
    int cur_node
) {
    // it is node leaf
    if (adjust[cur_node].size() == 1 && adjust[cur_node][0] == parent) {
        num_leaf_at_nodes[cur_node] = 1;
        return;
    }

    num_leaf_at_nodes[cur_node] = 0;
    for (int i = 0;i < adjust[cur_node].size();i++) {
        int next_node = adjust[cur_node][i];
        if (next_node == parent) continue;
        DFS(
            adjust,
            num_leaf_at_nodes,
            cur_node,
            next_node
        );
        num_leaf_at_nodes[cur_node] += num_leaf_at_nodes[next_node];
    }
}

int main(){
    int t;
    std::cin >> t;
    while (t--) {
        int n, q;
        std::vector<std::vector<int>> adjust;
        std::vector<std::pair<int, int>> queries;
        std::vector<ll> num_leaf_at_nodes; // index is node value is number of leaf in this node
        std::cin >> n;
        adjust.resize(n);
        num_leaf_at_nodes.resize(n);
        for (int i = 0;i < n - 1;i++) {
            int u, v;
            std::cin >> u >> v;
            u--;
            v--;
            adjust[u].push_back(v);
            adjust[v].push_back(u);
        }

        std::cin >> q;
        for (int i = 0;i < q;i++) {
            int x, y;
            std::cin >> x >> y;
            x--;
            y--;
            queries.push_back({x, y});
        }

        DFS(
            adjust,
            num_leaf_at_nodes,
            -1,
            0
        );

        // for (int i = 0;i < n;i++) {
        //     std::cout << "Mumber node leaf of node " << i << ": " << num_leaf_at_nodes[i] << std::endl;
        // }

        for (int i = 0;i < q;i++) {
            int x = queries[i].first;
            int y = queries[i].second;
            std::cout << num_leaf_at_nodes[x] * num_leaf_at_nodes[y] << std::endl;
        }
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1843/problem/D
 */
