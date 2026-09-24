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

        int n = _read<int>();
        auto array = _reads<int>(n);

        if (n % 2 == 1) {
            _println<std::string>("NO");
            continue;
        }

        int min_left = infinity, max_right = infinity;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (min_left == infinity) {
                    min_left = array[i];
                    continue;
                }
                min_left = min_left > array[i] ? array[i] : min_left;
            }
            else {
                if (max_right == infinity) {
                    max_right = array[i];
                    continue;
                }
                max_right = max_right < array[i] ? array[i] : max_right;
            }
        }

        if (min_left <= max_right) {
            _println<std::string>("NO");
            continue;
        }

        int allow_range = min_left - max_right - 1;
        if (allow_range > n) {
            _println<std::string>("YES");
            continue;
        }

        std::set<int> set_array;
        for (int i = 0; i < n; i++) {
            set_array.insert(array[i]);
        }

        bool found_valid = false;
        for (int i = max_right + 1; i < min_left; i++) {
            if (set_array.find(i) == set_array.end()) {
                found_valid = true;
                break;
            }
        }

        _println<std::string>(found_valid ? "YES" : "NO");

    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2250/problem/A
 */