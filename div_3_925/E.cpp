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

int number_decimal(ll number) {
    int count = 0;
    while(number) {
        number /= 10;
        count++;
    }
    return count;
}

int number_zeros_last(ll number) {
    int count = 0;
    while (number % 10 == 0 && number > 0) {
        number /= 10;
        count++;
    }
    return count;
}

bool compare(int a, int b) {
    return a < b;
}

int main(){
    int t;
    std::cin >> t;
    while (t--) {
        std::vector<ll> inputs;
        int n, m;
        std::cin >> n >> m;

        for (int i = 0; i < n; i++) {
            ll input;
            std::cin >> input;
            inputs.push_back(input);
        }

        int total_decimal = 0;
        for (int i = 0; i < n; i++) {
            total_decimal += number_decimal(inputs[i]);
        }

        if (total_decimal <= m) {
            std::cout << "Anna" << std::endl;
            continue;
        }

        std::vector<int> number_zeros_of_inputs;
        for (int i = 0; i < n; i++) {
            number_zeros_of_inputs.push_back(number_zeros_last(inputs[i]));
        }

        std::sort(number_zeros_of_inputs.begin(), number_zeros_of_inputs.end(), compare);

        int number_removed = 0;
        int turn = 0;
        while(number_zeros_of_inputs.size()) {

            if (turn % 2 == 0) {
                number_removed += number_zeros_of_inputs.back();
            }
            
            number_zeros_of_inputs.pop_back();
            turn = (turn + 1) % 2;
        }
        // std::cout << "res: " << m << " " << total_decimal << " " << number_removed << std::endl;
        if (m >= total_decimal - number_removed) {
            std::cout << "Anna" << std::endl;
        }
        else {
            std::cout << "Sasha" << std::endl;
        }
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1931/problem/E
 */
