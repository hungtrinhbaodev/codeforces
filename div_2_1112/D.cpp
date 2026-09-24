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
#define moduler 998244353

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

struct Segment {

    int l;

    int r;

    Segment(int l, int r) {
        this->l = l;
        this->r = r;
    }

    int range() {
        return r -l + 1;
    }

    friend std::ostream& operator<<(std::ostream& os, const Segment& p) {
        os << "{" << p.l << ", " << p.r << "}" << " ";
        return os; 
    }
};

bool is_segment_valid(Segment &seg) {
    return seg.r != -1;
}

Segment merge(Segment &from, Segment &to) {
    return {std::min(from.l, to.l), std::max(from.r, to.r)};
}

int main() {

    int t = _read<int>();
    while(t--) {

        int n = _read<int>();
        std::vector<int> arr = _reads<int>(n - 1);
        std::vector<Segment> hash_arr(n + 1, {n + 1, -1});
        std::vector<ll> factor(n, 1);

        for (int i = 0; i < n - 1; i++) {
            int val = arr[i];
            Segment &seg = hash_arr[val];
            if (seg.l > i) {
                seg.l = i;
            }
            if (seg.r < i) {
                seg.r = i;
            }
        }

        if (is_segment_valid(hash_arr[n])) {
            _println<int>(0);
            continue;
        }

        if (!is_segment_valid(hash_arr[n - 1])) {
            _println<int>(0);
            continue;
        }

        std::vector<bool> visited(n, false);
        bool is_valid = true;
        for (int i = n - 1; i > 0; i--) {
            Segment &seg = hash_arr[i];
            if (!is_segment_valid(seg)) {
                continue;
            }
            for (int j = seg.l; j <= seg.r; j++) {
                if (visited[j]) {
                    is_valid = false;
                    break;
                }
                if (arr[j] != i) {
                    is_valid = false;
                    break;
                }
                visited[j] = true;
            }
            if (!is_valid) {
                break;
            }
        }

        if (!is_valid) {
            _println<int>(0);
            continue;
        }

        Segment merge_seg = hash_arr[n - 1];
        factor[n - 1] = 2;
        int finish_point = n - 1;
        for (int i = n - 2; i > 0; i--) {
            Segment &seg = hash_arr[i];
            if (is_segment_valid(seg)) {
                int range_seg = seg.range(), range_merge = merge_seg.range();
                merge_seg = merge(merge_seg, seg);
                if (merge_seg.range() != (range_seg + range_merge)) {
                    is_valid = false;
                    break;
                }
                factor[i] = 1;
            }
            else {
                int needed_slot = n - i + 1;
                int available_slot = merge_seg.range() + 1;
                if (available_slot < needed_slot) {
                    is_valid = false;
                    break;
                }
                factor[i] = available_slot - needed_slot + 1;
            }
            if (merge_seg.range() >= n - 1) {
                finish_point = i;
                break;
            } 
        }

        if (!is_valid || merge_seg.range() < n - 1) {
            _println<int>(0);
            continue;
        }
 
        ll ans = 1;
        for (int i = 1; i < finish_point; i++) {
            ans = (ans * i) % moduler;
        }
        for (int i = finish_point; i < n; i++) {
            ans = (ans * factor[i]) % moduler;
        }

        _println<int>(ans);

    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2250/problem/D
 */