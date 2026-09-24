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

    friend std::ostream& operator<<(std::ostream& os, const Segment& p) {
        os << "{" << p.l << ", " << p.r << "}" << " ";
        return os; 
    }
};

void intersects(std::vector<Segment> &target, Segment &from, Segment &to) {
    target.clear();
    if (from.r < to.l) return;
    if (to.r < from.l) return;
    target.push_back({std::max(from.l, to.l), std::min(from.r, to.r)});
}

void outers(std::vector<Segment> &target, Segment &from, Segment &to) {
    target.clear();
    if (!(from.r < to.l || to.r < from.l) > 0) {

        if (to.l <= from.l && to.r >= from.r) {
            return;
        }

        if (from.l < to.l && from.r > to.r) {
            target.push_back({from.l, to.l - 1});
            target.push_back({to.r + 1, from.r});
        }
        
        if (from.r > to.r) {
            target.push_back({to.r + 1, from.r});
            return;
        }

        target.push_back({from.l, to.l - 1});
        return;
    }
    target.push_back(from);
}

bool contain_value(std::vector<Segment> &segments, int value) {
    for (Segment &segment : segments) {
        if (segment.l <= value && segment.r >= value) {
            return true;
        }
    }
    return false;
}

void append_sesgments(std::vector<Segment> &segments, const std::vector<Segment> &append) {
    for (Segment segment : append) {
        segments.push_back(segment);
    }
}

bool validate_member(int n, int validate_value, std::vector<Segment> &left_validates, std::vector<Segment> &right_validates) {

    if (validate_value <= 0) return true;

    std::vector<std::vector<Segment>> valid_semgents;
    std::vector<Segment> left_valid_segments{}, right_valid_segments{}, total_valid_segments{}, intersect_segments{};
    for (int i = 1; i <= n; i++) {

        int max_index_can_move = validate_value < i ? validate_value : i;
        Segment left_available{1, max_index_can_move}, right_available{validate_value - max_index_can_move + 1, validate_value};
        outers(left_valid_segments, left_available, left_validates[i - 1]);

        if (left_valid_segments.size() <= 0) {
            continue;
        }
        
        outers(right_valid_segments, right_available, right_validates[i - 1]);
        for (Segment &segment : right_valid_segments) {
            Segment transfrom{validate_value - segment.r + 1, validate_value - segment.l + 1};
            segment.l = transfrom.l;
            segment.r = transfrom.r;
        }
        if (right_valid_segments.size() <= 0) {
            continue;
        }

        for (Segment &left_segment : left_valid_segments) {
            for (Segment &right_segment : right_valid_segments) {
                intersects(intersect_segments, left_segment, right_segment);
                append_sesgments(total_valid_segments, intersect_segments);
            }
        }
        if (total_valid_segments.size() <= 0) {
            continue;
        }

        valid_semgents.push_back(total_valid_segments);
        total_valid_segments.clear();
    }
    
    int counter = 1;
    for (int i = 0; i < valid_semgents.size(); i++) {
        if (contain_value(valid_semgents[i], counter)) {
            counter++;
        }
    }

    return counter > validate_value;
}

int main() {

    int t = _read<int>();
    while(t--) {
        int n = _read<int>();

        std::vector<Segment> left_validates, right_validates;
        for (int  i = 0; i < n; i++) {
            int l = _read<int>(), r = _read<int>(), u = _read<int>(), v = _read<int>();
            left_validates.push_back({l, r});
            right_validates.push_back({u, v});
        }

        for (int i = n; i >= 0; i--) {
            if (validate_member(n, i, left_validates, right_validates)) {
                _println<int>(i);
                break;
            }
        }
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2250/problem/C
 */