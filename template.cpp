#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#define ll long long int
#define infinity -1

// ------------------------ utils field ---------------------------

template <typename T>
T _read() {
    T input;
    std::cin >> input;
    return input;
}

template <typename T>
std::vector<T> _reads(int size) {
    std::vector<T> inputs;
    T input;
    while (size--) {
        inputs.push_back(_read<T>());
    }
    return inputs;
}

template <typename T>
std::pair<T, T> _read_pair() {
    T a, b;
    std::cin >> a >> b;
    return {a, b};
}

template <typename T>
std::vector<std::pair<T, T>> _read_pairs(int size) {
    std::vector<std::pair<T, T>> inputs;
    while (--size) {
        inputs.push_back(_read_pair<T>());
    }
    return inputs;
}

template <typename T>
T _read_custom(std::function<void(T&)> read_func) {
    T input;
    read_func(input);
    return input;
}

std::vector<std::vector<int>> _read_adjusts(int num_node, int num_adjust, int minus_base = 0) {
    std::vector<std::vector<int>> adjusts(num_node);
    while (num_adjust--) {
        auto pair = _read_pair<int>();
        pair.first -= minus_base;
        pair.second -= minus_base;
        adjusts[pair.first].push_back(pair.second);
        adjusts[pair.second].push_back(pair.first);
    }
    return adjusts;
}

template <typename T>
void _prints(std::vector<T>& inputs, std::function<void(const T&)> func) {
    for (int i = 0; i < inputs.size(); i++) {
        func(inputs[i]);
    }
}

// ------------------------ excution context field ---------------------------

int main() {
    int t = _read<int>();
    while (t--) {
    }

    return 0;
}

/**
 * link context: https://codeforces.com/contest/...
 */