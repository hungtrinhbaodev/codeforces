#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <chrono>
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
void _printsln(std::vector<T> &inputs, std::function<void(const T&)> func) {
    for (int i = 0; i < inputs.size(); i++) {
        func(inputs[i]);
    }
    std::cout << std::endl;
}

template<typename T>
void _println(T value) {
    std::cout << value << std::endl;
}

template<typename T>
void _print(T value) {
    std::cout << value << " ";
}

ll now() {
    // Get the current time point from the system clock
    auto now = std::chrono::system_clock::now();

    // Convert the time point to a duration since the epoch
    auto duration = now.time_since_epoch();

    // Cast the duration into milliseconds and extract the count
    return std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
}

// ------------------------ excution contest field ---------------------------

std::string bits(int a) {
    std:: string bit;
    do {
        if (a & 1) {
            bit.push_back('1');
        }
        else {
            bit.push_back('0');
        }
        a >>= 1;
    } while(a > 0);
    std::reverse(bit.begin(), bit.end());
    return bit;
} 

int main() {

    // int t = _read<int>();
    // while(t--) {
        
    // }

    // int n = 3000;
    // int max = -1;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         max = std::max(max, i ^ j);
    //     }
    // }
    // _println<int>(max);

    int a = 246, b = 875;
    std::cout << bits(a) << " " << bits(b) << " " << bits(a ^ b) << " " << bits((a + b) - 2 * (a & b)) << std::endl;

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2247/problem/D1
 */