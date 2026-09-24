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
    int count = 0;
    while (t--) {
        int n, d12, d23, d13;
        std::cin >> n >> d12 >> d23 >> d13;
        if ((d12 + d13) < d23 || (d12 + d13 - d23) % 2 != 0) {
            std::cout << "NO" << std::endl;
            continue;
        }
        else {
            int same_path = (d12 + d13 - d23) / 2;
            int diff_path_to_2 = d12 - same_path;
            int diff_path_to_3 = d13 - same_path;
            int min_vertex_needed = same_path + diff_path_to_2 + diff_path_to_3;
            if (min_vertex_needed > n - 1 || same_path > d12 || same_path > d13) {
                std::cout << "NO" << std::endl;
                continue;
            }
            std::cout << "YES" << std::endl;
            std::vector<std::pair<int, int>> adjust;

            int cur_vert = 1;
            int using_buffer_vert = 4;

            for (int i = 0;i < same_path;i++) {
                adjust.push_back({cur_vert, using_buffer_vert});
                cur_vert = using_buffer_vert;
                using_buffer_vert++;
            }

            if (d12 == same_path || d13 == same_path) {
                int start_vert = 3;
                int end_vert = 2;
                int remain_to_end = diff_path_to_2;
                if (d12 == same_path) {
                    start_vert = 2;
                    end_vert = 3;
                    remain_to_end = diff_path_to_3;
                }
                adjust.pop_back();
                if (adjust.size() <= 0) {
                    cur_vert = 1;
                }
                else {
                    cur_vert--;
                }
                using_buffer_vert--;
                adjust.push_back({cur_vert, start_vert});
                cur_vert = start_vert;
                for (int i = 0;i < remain_to_end;i++) {
                    if (i < remain_to_end - 1) {
                        adjust.push_back({cur_vert, using_buffer_vert});
                        cur_vert = using_buffer_vert;
                        using_buffer_vert++;
                    }
                    else {
                        adjust.push_back({cur_vert, end_vert});
                    }
                }
            }
            else {
                int tmp_cur_vert = cur_vert;
                for (int i = 0;i < diff_path_to_2;i++) {
                    if (i < diff_path_to_2 - 1) {
                        adjust.push_back({cur_vert, using_buffer_vert});
                        cur_vert = using_buffer_vert;
                        using_buffer_vert++;
                    }
                    else {
                        adjust.push_back({cur_vert, 2});
                    }
                }
                cur_vert = tmp_cur_vert;
                for (int i = 0;i < diff_path_to_3;i++) {
                    if (i < diff_path_to_3 - 1) {
                        adjust.push_back({cur_vert, using_buffer_vert});
                        cur_vert = using_buffer_vert;
                        using_buffer_vert++;
                    }
                    else {
                        adjust.push_back({cur_vert, 3});
                    }
                }
            }
            for (;using_buffer_vert <= n;using_buffer_vert++) {
                adjust.push_back({1, using_buffer_vert});
            }
            for (auto &path : adjust) {
                std::cout << path.first << " " << path.second << std::endl;
            }
        }
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1714/problem/F
 */
