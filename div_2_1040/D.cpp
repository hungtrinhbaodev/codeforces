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
        int n;
        std::vector<int> permus;
        std::cin >> n;
        for (int i = 0;i < n;i++) {
            int permu;
            std::cin >> permu;
            permus.push_back(permu);
        }
        int inversion = 0;
        for (int i = 0;i < n;i++) {
            int permu = i + 1;
            int index_permu = std::find(permus.begin(), permus.end(), permu) - permus.begin();
            int number_remain = permus.size();
            if (number_remain % 2 == 1 && index_permu == number_remain / 2) {
                inversion += number_remain / 2;
            }
            else {
                // chose reversion at this permu
                if (index_permu >= number_remain / 2) {
                    inversion += number_remain - index_permu - 1;
                }
                else {
                    inversion += index_permu;
                }
            }
            permus.erase(permus.begin() + index_permu);
        }
        std::cout << inversion << std::endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2130/problem/D
 */
