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

struct Segment {
    int l;
    int r;
    int index_pattern;
};

struct ValueInDP {
    Segment segment;
    int value;
};

bool compare(const Segment &a, const Segment &b) {
    return a.l < b.l;
}

int main(){
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string text;
        std::vector<std::string> patterns;
        std::vector<Segment> segments;
        std::cin >> text;
        std::cin >> n;
        std::vector<ValueInDP> dp(text.size());
        for (int i = 0;i < dp.size();i++) {
            dp[i].value = infinity;
        }
        for (int i = 0;i < n;i++) {
            std::string pattern;
            std::cin >> pattern;
            patterns.push_back(pattern);
        }
        for (int i = 0;i < n;i++) {
            std::string &pattern = patterns[i];
            if ((int)text.size() - (int)pattern.size() < 0) continue;
            for (int j = 0;j <= text.size() - pattern.size();j++) {
                bool is_matched = true;
                for (int k = 0;k < pattern.size();k++) {
                    if (pattern[k] != text[j + k]) {
                        is_matched = false;
                        break;
                    }
                }
                if (is_matched) {
                    segments.push_back({j, int(j + pattern.size() - 1), i});
                }
            }
        }
        std::sort(segments.begin(), segments.end(), compare);
        for (int i = 0;i < segments.size();i++) {
            Segment segment = segments[i];
            int l = segment.l;
            int r = segment.r;

            if (l > 0 && dp[l - 1].value == infinity) {
                continue;
            }

            int last_dp = 0;
            if (l > 0) {
                last_dp = dp[l - 1].value;
            }

            for (int j = l;j <= r;j++) {
                if (dp[j].value == infinity || dp[j].value > last_dp + 1) {
                    dp[j].value = last_dp + 1;
                    dp[j].segment = segment;
                }
            }
        }
        ValueInDP &end = dp[dp.size() - 1];
        int ans = end.value;
        std::cout << ans << std::endl;
        if (ans > 0) {
            int start_left = end.segment.l;
            int index_pattern = end.segment.index_pattern;
            while(true) {
                std::cout << index_pattern + 1 << " " << start_left + 1 << std::endl;
                if (start_left <= 0) break;
                int next_left = start_left - 1;
                start_left = dp[next_left].segment.l;
                index_pattern = dp[next_left].segment.index_pattern;
            }
        }
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1714/problem/D
 */
