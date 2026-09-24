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
        std::vector<ll> costs, arr;
        int n;
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            ll element;
            std::cin >> element;
            arr.push_back(element);
        }

        for (int i = 0; i < n; i++) {
            ll cost;
            std::cin >> cost;
            costs.push_back(cost);
        }

        if (n <= 1) {
            std::cout << 0 << std::endl;
            continue;
        }

        std::map<ll, ll> dp;
        dp[0] = costs[0];
        dp[arr[0]] = 0;

        for (int i = 1; i < n; i++) {
            ll min_cost = infinity;
            for (auto it = dp.begin(); it != dp.end();it++) {
                if(it->first <= arr[i]) {
                    if (min_cost == infinity) {
                        min_cost = it->second;
                    }
                    else {
                        if (min_cost > it->second) {
                            min_cost = it->second;
                        }
                    }
                }
                it->second += costs[i];
            }
            dp[arr[i]] = min_cost;
        }

        ll min = infinity;
        for (auto it = dp.begin(); it != dp.end(); it++) {
            if (min == infinity) {
                min = it->second;
            }
            else {
                if (min > it->second) {
                    min = it->second;
                }
            }
        }

        std::cout << min << std::endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2167/problem/G
 */
