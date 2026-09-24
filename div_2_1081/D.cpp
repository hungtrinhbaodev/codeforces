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

template<typename T>
void _prints(std::vector<T> &inputs, std::function<void(const T&)> func) {
    for (int i = 0; i < inputs.size(); i++) {
        func(inputs[i]);
    }
}

// ------------------------ excution contexct field ---------------------------

struct Node {
    int deep;
    ll sum_cost;
    ll subtree_value;
    ll subtree_ans_value; // best ans subtree value when use at most one operation
};

bool is_leaf(std::vector<std::vector<int>> &adjusts, int cur, int parent) {
    return adjusts[cur].size() == 1 && adjusts[cur][0] == parent;
};

void loop_child_node(
    std::vector<std::vector<int>> &adjusts,
    int cur,
    int parent,
    std::function<void(int, int)> func
) {

    for (int i = 0; i < adjusts[cur].size(); i++) {
        if (adjusts[cur][i] == parent) {
            continue;
        }
        func(adjusts[cur][i], cur);
    }
}

int get_num_child_node(
    std::vector<std::vector<int>> &adjusts,
    int cur,
    int parent
) {
    if (is_leaf(adjusts, cur, parent)) {
        return 0;
    }

    int num_child = 0;
    loop_child_node(
        adjusts,
        cur,
        parent,
        [&num_child](int cur, int parent) {
            num_child++;
        }
    );

    return num_child;
}

void dfs(
    std::vector<std::vector<int>> &adjusts,
    std::vector<ll> &costs,
    std::vector<Node> &nodes,
    int cur,
    int parent
) {

    if (is_leaf(adjusts, cur, parent)) {
        nodes[cur].deep = 1;
        nodes[cur].sum_cost = costs[cur];
        nodes[cur].subtree_value = 0;
        nodes[cur].subtree_ans_value = 0;
        return;
    }

    loop_child_node(
        adjusts,
        cur,
        parent,
        [&adjusts, &costs, &nodes](int cur, int parent) {
            dfs(adjusts, costs, nodes, cur, parent);
        }
    );

    ll sum_cost = 0;
    loop_child_node(
        adjusts,
        cur,
        parent,
        [&sum_cost, &nodes](int cur, int parent) {
            sum_cost += nodes[cur].sum_cost;
        }
    );
    nodes[cur].sum_cost = sum_cost + costs[cur];

    ll subtree_value = 0;
    loop_child_node(
        adjusts,
        cur,
        parent,
        [&subtree_value, &nodes](int cur, int parent) {
            subtree_value += nodes[cur].subtree_value + nodes[cur].sum_cost;
        }
    );
    nodes[cur].subtree_value = subtree_value;

    int deep = 0;
    loop_child_node(
        adjusts,
        cur,
        parent,
        [&deep, &nodes](int cur, int parent) {
            deep = std::max(deep, nodes[cur].deep);
        }
    );
    nodes[cur].deep = deep + 1;

    // calculate ans subtree value

    // case 1: use node child to execute oparation
    ll subtree_ans_value = nodes[cur].subtree_value;
    int num_child = get_num_child_node(adjusts, cur, parent);
    if (num_child > 1) {
        std::priority_queue<int> qp_deep;
        loop_child_node(
            adjusts,
            cur,
            parent,
            [&qp_deep, &nodes](int cur, int parent) {
                qp_deep.push(nodes[cur].deep);
            }
        );
        int primary_deep = qp_deep.top();
        qp_deep.pop();
        int secondary_deep = qp_deep.top();
        loop_child_node(
            adjusts,
            cur,
            parent,
            [&subtree_ans_value, &nodes, &primary_deep, &secondary_deep](int cur, int parent) {
                ll local_ans = nodes[parent].subtree_value - nodes[cur].sum_cost;
                int max_deep = nodes[cur].deep == primary_deep ? secondary_deep : primary_deep;
                local_ans += (max_deep + 1) * nodes[cur].sum_cost;
                subtree_ans_value = std::max(subtree_ans_value, local_ans);
            }
        );
    }

    // case 2: other child subtree already take oparation before 
    loop_child_node(
        adjusts,
        cur,
        parent,
        [&subtree_ans_value, &nodes](int cur, int parent) {
            ll local_ans = nodes[parent].subtree_value - nodes[cur].subtree_value + nodes[cur].subtree_ans_value;
            subtree_ans_value = std::max(subtree_ans_value, local_ans);
        }
    );

    nodes[cur].subtree_ans_value = subtree_ans_value;
}

int main() {

    int t = _read<int>();
    while(t--) {

        int n = _read<int>();
        std::vector<ll> costs = _reads<ll>(n);
        std::vector<std::vector<int>> adjusts = _read_adjusts(n, n - 1, 1);
        std::vector<Node> nodes(n);

        dfs(
            adjusts,
            costs,
            nodes,
            0,
            -1
        );

        _prints<Node>(
            nodes,
            [](const Node &node) {
                std::cout << node.subtree_ans_value << " ";
            }
        );
        
    }


    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2192/problem/D
 */