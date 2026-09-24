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
        int k = _read<int>();
        std::vector<int> max_cards = _reads<int>(n);
        auto make_dp = [] (int k) {
            std::vector<std::vector<int>> dp(k + 1);
            for (int i = 0; i <= k; i++) {
                std::vector<int> tmp(k + 1, -1);
                dp[i] = tmp;
            }
            return dp;
        };
        auto loop_dp = [] (std::vector<std::vector<int>>& dp, std::function<void(std::vector<std::vector<int>>&, int, int)> func) {
            for (int i = 0; i < dp.size(); i++) {
                for (int j = 0; j < dp[i].size(); j++) {
                    func(dp, i, j);
                }
            }
        };
        auto dp = make_dp(k);
        dp[0][k] = 0;
        for (int i = 0; i < n; i++) {

            auto cur_dp = dp;
            int max_card = max_cards[i];

            loop_dp(cur_dp, [] (std::vector<std::vector<int>>& dp, int i, int j) {
                if (dp[i][j] == -1) return;
                dp[i][j] += i;
            });

            loop_dp(dp, [&] (std::vector<std::vector<int>>& dp, int i, int j) {
                if (dp[i][j] == -1) return;
                int last_max_card = i;
                if (last_max_card > max_card) {
                    return;
                }
                int card_can_use = std::min(max_card, j);
                if (card_can_use < last_max_card) return;
                int remain_card = j - card_can_use;
                int happiness = dp[i][j] + card_can_use;
                cur_dp[card_can_use][remain_card] = std::max(cur_dp[card_can_use][remain_card], happiness);
            });

            dp = cur_dp;

            std::cout << "dp at step " << i << std::endl;
            for (int j = 0; j < dp.size(); j++) {
                for (int k = 0; k < dp[j].size(); k++) {
                    std::cout << dp[j][k] << " ";
                }
                std::cout << std::endl;
            }
        }
        int ans = -1;
        loop_dp(dp, [&] (std::vector<std::vector<int>>& dp, int i, int j) {
            ans = std::max(dp[i][j], ans);
        });
        
        std::cout << ans << std::endl;
    }

    return 0;
}


/**
 * link context: https://codeforces.com/contest/...
 */