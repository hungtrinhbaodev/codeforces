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

template<typename T>
void _prints(std::vector<T> &inputs, std::function<void(const T&)> func) {
    for (int i = 0; i < inputs.size(); i++) {
        func(inputs[i]);
    }
}

// ------------------------ excution context field ---------------------------

int main() {

    int t = _read<int>();
    while(t--) {
        int n = _read<int>();
        std::vector<ll> arr = _reads<ll>(n);
        std::vector<ll> diffs(n, 0);
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            diffs[i] = 2 * (i + 1) - arr[i];
            sum += arr[i];
        }
        // index 0: already chose finish before i
        // index 1: chosing i
        std::vector<ll> dp(2, 0);
        dp[0] = std::max((ll)0, diffs[0]);
        dp[1] = diffs[0];
        for (int i = 1; i < n; i++) {
            std::vector<ll> cur_dp(2, 0);
            cur_dp[0] = std::max(dp[1], dp[0]);
            cur_dp[1] = std::max(dp[1] + diffs[i], diffs[i]);
            dp = cur_dp;
        }
        std::cout << sum + std::max(dp[0], dp[1]) << std::endl;
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2169/problem/C
 */