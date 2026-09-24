#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#define ll long long int
#define infinity - 1
#define modulo (ll)(10e9 + 7)

int main(){
    int t;
    std::cin>>t;

    while(t--){
        std::string bracket, stack;
        std::cin >> bracket;

        int count_out_pair_bracket = 0;
        for(size_t i = 0;i < bracket.size();i++){
            if(stack.size() <= 0){
                stack.push_back(bracket[i]);
            }
            else{
                if(stack.back() == '(' && bracket[i] == ')'){
                    stack.pop_back();
                    if(stack.size() <= 0){
                        count_out_pair_bracket++;
                    }
                }
                else{
                    stack.push_back(bracket[i]);
                }
            }
        }

        if(count_out_pair_bracket >= 2){
            std::cout << "YES" << std::endl;
            continue;
        }

        std::cout << "NO" << std::endl;
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2110/problem/B
 */
