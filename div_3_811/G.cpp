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

struct Node {
    int child = -1;
    ll a;
    ll b;
};

int binary_search(
    std::vector<ll> &sum_path,
    ll &cur_sum
) {
    int l = 0, r = sum_path.size();
    int ans = 0;
    while (l < r - 1) {
        int mid = (l + r) / 2;

        if (sum_path[mid] == cur_sum) {
            return mid;
        }

        if (sum_path[mid] < cur_sum) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    return l;
}

void dfs(
    std::vector<std::vector<Node>> &adjusts,
    int cur_node,
    std::vector<ll> &sum_path,
    ll &cur_sum,
    std::vector<int> &ans
) {
    for (int i = 0;i < adjusts[cur_node].size(); i++) {
        Node& node = adjusts[cur_node][i];
        sum_path.push_back(sum_path.back() + node.b);
        cur_sum += node.a;
        ans[node.child] = binary_search(
            sum_path,
            cur_sum
        );
        dfs(
            adjusts,
            node.child,
            sum_path,
            cur_sum,
            ans
        );
        sum_path.pop_back();
        cur_sum -= node.a;
    }
}

int main(){
    int t;
    std::cin >> t;
    std::vector<std::string> ans;
    while (t--) {
        std::vector<std::vector<Node>> adjusts;
        std::vector<int> ans;
        int n;
        std::cin >> n;
        adjusts.resize(n);
        ans.resize(n);
        for (int i = 0;i < n - 1;i++) {
            int parent, a, b;
            std::cin >> parent >> a >> b;
            adjusts[parent - 1].push_back({i + 1, a, b});
        }
        std::vector<ll> sum_path(1, 0);
        ll cur_sum = 0;
        dfs(
            adjusts,
            0,
            sum_path,
            cur_sum,
            ans
        );
        for (int i = 1;i < n;i++) {
            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1714/problem/G
 */
