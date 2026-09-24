#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
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

template<typename T>
void _println(T value) {
    std::cout << value << std::endl;
}

template<typename T>
void _print(T value) {
    std::cout << value << " ";
}

// ------------------------ excution contest field ---------------------------

int main() {

    int t = _read<int>();
    while(t--) {

        int n = _read<int>(), k = _read<int>();

        if (k + 2 > n) {
            _println<int>(-1);
            continue;
        }

        int num_zero = n / 2, num_one = n - num_zero;
        std::string ans;
        for (int i = 0; i < n - 2 - k; i++) {
            if (i % 2) {
                num_zero--;
                ans.push_back('0');
            }
            else {
                num_one--;
                ans.push_back('1');
            }
        } 

        auto appends_ans = [] (std::string &ans, int num, char val) {
            while(num--) ans.push_back(val);
        };
        if (ans.size() <= 0 || ans.back() == '0') {
            appends_ans(ans, num_one, '1');
            appends_ans(ans, num_zero, '0');
        }
        else {
            appends_ans(ans, num_zero, '0');
            appends_ans(ans, num_one, '1');
        }

        _println<std::string>(ans);

    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2250/problem/B
 */