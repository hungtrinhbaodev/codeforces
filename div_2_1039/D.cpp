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
        std::vector<int> permu;
        std::vector<ll> dp;
        int n;
        std::cin >> n;
        for (int i = 0;i < n;i++) {
            int num;
            std::cin >> num;
            permu.push_back(num);
        }

        // 2 * dp + i + 1
        // 2 * dp + 1
        dp.resize(n);

        dp[0] = 1;
        if (permu[0] > permu[1]) {
            dp[1] = 3;
        }
        else {
            dp[1] = 2;
        }

        for (int i = 2;i < n;i++) {
            ll last_dp = dp[i - 1];
            int last_permu = permu[i - 1];
            int cur_permu = permu[i];
            if (cur_permu < last_permu) {
                dp[i] = last_dp + (i + 1);
            }
            else {
                dp[i] = last_dp + 1;
            }
            // std::cout << "Dp at index " << (i + 1) << ": " << dp[i] << std::endl;
        }

        ll ans = 0;
        for (ll sum : dp) {
            ans += sum;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2128/problem/D
 */
