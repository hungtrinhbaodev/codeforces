#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#define ll long long int
#define infinity -1

// ------------------------ utils field ---------------------------

template<typename T>
T _read() {
    T input;
    std::cin >> input;
    return input;
}

template<typename T>
std::vector<T> _reads(int size) {
    std::vector<T> inputs;
    T input;
    while (size--) {
        inputs.push_back(_read<T>());
    }
    return inputs;
}

template<typename T>
std::pair<T, T> _read_pair() {
    T a, b;
    std::cin >> a >> b;
    return {a, b};
}

template<typename T>
std::vector<std::pair<T, T>> _read_pairs(int size) {
    std::vector<std::pair<T, T>> inputs;
    while(--size) {
        inputs.push_back(_read_pair<T>());
    }
    return inputs;
}

template<typename T>
T _read_custom(std::function<void(T&)> read_func) {
    T input;
    read_func(input);
    return input;
}

std::vector<std::vector<int>> _read_adjusts(int num_node, int num_adjust, int minus_base = 0) {
    std::vector<std::vector<int>> adjusts(num_node);
    while(num_adjust--) {
        auto pair = _read_pair<int>();
        pair.first -= minus_base;
        pair.second -= minus_base;
        adjusts[pair.first].push_back(pair.second);
        adjusts[pair.second].push_back(pair.first);
    }
    return adjusts;
} 

template<typename T, typename F>
void _prints(std::vector<T> &inputs, F func) {
    for (int i = 0; i < inputs.size(); i++) {
        func(inputs[i]);
    }
    std::cout << std::endl;
}

// ------------------------ excution context field ---------------------------

struct Adjust {
    int adjust_node;
    int x;
    int y;
};

struct Node {
    // the order of node child chunk contain this node
    // a, b is node child of c
    // node child a contain chunk [e, a, d] (all it child, grand child,... and it)
    // node child b contain chunk [b, l, m]
    // when ordered_nodes is [b, c, a] => chunk as c [b, l, m, c, e, a, d]
    std::vector<int> ordered_nodes;
    int size;
    int offset;
};

bool is_leaf_node(
    std::vector<std::vector<Adjust>> &adjusts,
    int cur,
    int parent
) {
    return adjusts[cur].size() == 1 && adjusts[cur][0].adjust_node == parent;
}

void dfs_process(
    std::vector<std::vector<Adjust>> &adjusts,
    std::vector<Node> &nodes,
    int cur,
    int parent
) {

    if (is_leaf_node(adjusts, cur, parent)) {
        nodes[cur].ordered_nodes.push_back(cur);
        nodes[cur].size = 1;
        return;
    }

    for (int i = 0; i < adjusts[cur].size(); i++) {
        const Adjust &adjust = adjusts[cur][i];
        if (adjust.adjust_node == parent) {
            continue;
        }
        dfs_process(adjusts, nodes, adjust.adjust_node, cur);
    }

    std::vector<int> ordered_nodes, left_ordered_nodes, right_ordered_nodes;
    int size = 0;
    for (int i = 0; i < adjusts[cur].size(); i++) {
        const Adjust &adjust = adjusts[cur][i];
        if (adjust.adjust_node == parent) {
            continue;
        }
        auto nodes_need_append = &left_ordered_nodes;
        if (adjust.x < adjust.y) {
            nodes_need_append = &right_ordered_nodes;
        }
        nodes_need_append->push_back(adjust.adjust_node);
        size += nodes[adjust.adjust_node].size;
    }

    for (auto& node : left_ordered_nodes) {
        ordered_nodes.push_back(node);
    }
    ordered_nodes.push_back(cur);
    for (auto& node : right_ordered_nodes) {
        ordered_nodes.push_back(node);
    }

    nodes[cur].size = size + 1;
    nodes[cur].ordered_nodes = ordered_nodes;
}

void dfs_result(
    std::vector<std::vector<Adjust>> &adjusts,
    std::vector<Node> &nodes,
    std::vector<int> &ans,
    int cur,
    int parent
) {

    if (is_leaf_node(adjusts, cur, parent)) {
        ans[nodes[cur].offset] = cur;
        return;
    }

    // calculate offset
    int cur_offset = nodes[cur].offset;
    for (int i = 0;i < nodes[cur].ordered_nodes.size(); i++) {
        int node_in_order = nodes[cur].ordered_nodes[i];
        nodes[node_in_order].offset = cur_offset;
        if (node_in_order == cur) {
            ans[cur_offset] = cur;
            cur_offset += 1;
        }
        else {
            cur_offset += nodes[node_in_order].size;
        }
    }

    for (int i = 0;i < adjusts[cur].size(); i++) {
        const Adjust &adjust = adjusts[cur][i];
        if (adjust.adjust_node == parent) {
            continue;
        }
        dfs_result(adjusts, nodes, ans, adjust.adjust_node, cur);
    }
}

int main() {

    int t = _read<int>();
    while(t--) {

        int n = _read<int>();
        std::vector<std::vector<Adjust>> adjusts(n);
        std::vector<Node> nodes(n);
        
        for (int i = 0; i < n - 1; i++) {
            int u = _read<int>();
            int v = _read<int>();
            int x = _read<int>(); 
            int y = _read<int>();
            u--; v--;
            adjusts[u].push_back({v, x, y});
            adjusts[v].push_back({u, y, x});
        }

        dfs_process(
            adjusts,
            nodes,
            0,
            -1
        );

        std::vector<int> result(n);
        dfs_result(
            adjusts,
            nodes,
            result,
            0,
            -1
        );

        std::vector<int> ans(n);
        for (int i = 0; i < result.size(); i++) {
            int index = result[i];
            ans[index] = i + 1; // i + 1 is permu at node with index in sorted node final
        }

        _prints(ans, [] (const int& permu) {
            std::cout << permu << " ";
        });
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2143/problem/C
 */