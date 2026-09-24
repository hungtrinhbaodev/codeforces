#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#define ll long long int
#define infinity - 1
#define modulo (ll)(10e9 + 7)
#define MAX 5000

int main(){
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::vector<int> inputs;

        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            std::cin >> a;
            inputs.push_back(a);
        }

        int max_number = *std::max_element(inputs.begin(), inputs.end());
        std::vector<std::vector<int>> dp(n + 1);
        
        dp[0] = std::vector<int>(max_number + 1, infinity);
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            auto &cur_dp = dp[i];
            auto &last_dp = dp[i - 1];
            int cur_number = inputs[i - 1];

            cur_dp[cur_number] = 0;

            for (int j = 1; j <= max_number; j++) {

                if (last_dp[j] == infinity) continue;

                int gcd = std::gcd(cur_number, j);

                if (gcd == cur_number) continue;

                if (cur_dp[gcd] == infinity) {
                    cur_dp[gcd] = last_dp[j] + 1;
                }
                else {
                    if (cur_dp[gcd] > last_dp[j] + 1) {
                        cur_dp[gcd] = last_dp[j] + 1;
                    }
                }
            }
        }

        int result_gcd = 1;
        int total_number_merge = MAX;
        for (int i = 1; i <= max_number; i++) {
            if (dp[n][i] == infinity) continue;

            bool is_valid = true;
            for (int j = 0; j < n; j++) {
                if (inputs[j] % i != 0) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                if (dp[n][i] < total_number_merge) {
                    total_number_merge = dp[n][i];
                    result_gcd = i;
                }
            }
        }
        
        // std::cout << "result gcd: " << result_gcd << " ,total number merge: " << total_number_merge << std::endl;

        if (total_number_merge <= 0) {
            int number_shame = std::count(inputs.begin(), inputs.end(), result_gcd);
            std::cout << n - number_shame << std::endl;
            continue;
        }

        std::cout << (n - 1) + total_number_merge << std::endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2116/problem/C
 */
