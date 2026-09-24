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
    std::vector<std::string> ans;
    while (t--) {
        int n;
        std::vector<ll> inputs;
        std::vector<ll> diffs;
        std::map<ll, ll> counts;
        std::map<ll, ll> counts_revert;
        std::cin >> n;

        for (int i = 0;i < n;i++) {
            ll input;
            std::cin >> input;
            inputs.push_back(input);
            if (counts.find(input) == counts.end()) {
                counts[input] = 0;
            }
            counts[input]++;
        }

        ll cur_same = 1;
        ll total_count = 0;
        for (ll i = 1;i < n;i++) {
            if (inputs[i] == inputs[i - 1]) {
                cur_same++;
            }
            else {
                ll diff = inputs[i - 1] - inputs[i];
                total_count += cur_same;
                counts_revert[total_count] = diff;
                cur_same = 1;
            }
        }
        total_count += cur_same;
        counts_revert[total_count] = inputs[n - 1];

        if (counts.size() != counts_revert.size()) {
            ans.push_back("NO");
            continue;
        }

        bool is_valid = true;
        for (auto &item : counts_revert) {
            if (counts.find(item.first) == counts.end()) {
                is_valid = false;
                break;
            }
            if (counts[item.first] != item.second) {
                is_valid = false;
                break;
            }
        }
        ans.push_back(is_valid ? "YES" : "NO");
    }
    for (int i = 0;i < ans.size();i++) {
        std::cout << ans[i] << std::endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1862/problem/C
 */
