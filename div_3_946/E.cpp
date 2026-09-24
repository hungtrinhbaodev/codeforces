#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <typeinfo>
#define ll long long int
#define infinity - 1
#define modulo (ll)(10e9 + 7)
#define MAX 5000

int main(){
    int t;
    std::cin >> t;
    while (t--) {
        int m;
        ll x;
        std::cin >> m >> x;
        std::vector<std::vector<ll>> dp;
        std::vector<std::pair<ll, ll>> happiness_by_costs;
        ll max_happiness = -1;
        for (int i = 0;i < m;i++) {
            ll cost, happiness;
            std::cin >> cost >> happiness;
            happiness_by_costs.push_back({cost, happiness});
            if (max_happiness < happiness) {
                max_happiness = happiness;
            }
        }
        ll total_max_happiness = m * max_happiness + 5;
        for (int i = 0;i < m;i++) {
            dp.push_back({});
            for (int j = 0;j < total_max_happiness;j++) {
                dp[i].push_back(infinity);
            }
        }
        dp[0][0] = 0;
        if (happiness_by_costs[0].first <= 0) {
            dp[0][happiness_by_costs[0].second] = 0;
        }
        for (int i = 1;i < m;i++) {
            ll money_at_month = x * i;
            ll cost_at_month = happiness_by_costs[i].first;
            ll happiness_at_month = happiness_by_costs[i].second;
            for (int j = 0;j < total_max_happiness;j++) {
                int cur_happiness = j;
                if (dp[i - 1][cur_happiness] != infinity) {
                    dp[i][cur_happiness] = dp[i - 1][cur_happiness];
                    // std::cout << "replace: " << i << " " << cur_happiness << " " << dp[i][cur_happiness] << std::endl;
                }
            }
            for (int j = 0;j < total_max_happiness;j++) {
                int cur_happiness = j;
                if (dp[i - 1][cur_happiness] != infinity) {
                    ll cost_can_use = money_at_month - dp[i - 1][cur_happiness];
                    // std::cout << "cost can use: " << cost_can_use << " " << money_at_month << std::endl;
                    if (cost_can_use >= cost_at_month) {
                        int next_happiness = cur_happiness + happiness_at_month;
                        // std::cout << "next_happiness: " << next_happiness << " " << cur_happiness << " " << happiness_at_month << std::endl;
                        if (dp[i][next_happiness] == infinity) {
                            dp[i][next_happiness] = dp[i - 1][cur_happiness] + cost_at_month;
                        }
                        else if (dp[i][next_happiness] > dp[i - 1][cur_happiness] + cost_at_month) {
                            dp[i][next_happiness] = dp[i - 1][cur_happiness] + cost_at_month;
                        }
                        // std::cout << "dp[i][next_happiness]: " << i << " " << next_happiness << " " << dp[i][next_happiness] << std::endl;
                    }
                }
            }
        }
        for(int i = total_max_happiness - 1;i > -1;i--) {
            if (dp[m - 1][i] != infinity) {
                std::cout << i << std::endl;
                break;
            }
        }
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1974/problem/E
 */
