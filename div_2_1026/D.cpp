#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long int
#define infinity - 1

int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n, m;
        std::vector<std::vector<std::pair<int, ll>>> adjusts;
        std::vector<ll> max_batteries_by_nodes;
        std::vector<ll> batteries;
        ll ans = infinity;
        std::cin>>n>>m;

        adjusts.resize(n);
        max_batteries_by_nodes.resize(n);

        for(size_t i = 0;i < n;i++){
            ll battery;
            std::cin>>battery;
            batteries.push_back(battery);
        }

        for(size_t i = 0;i < m;i++){
            int cur_node, next_node;
            ll batteries_needed;
            std::cin>>cur_node>>next_node>>batteries_needed;

            next_node--;
            cur_node--;

            adjusts[next_node].push_back(std::pair<int, ll>(cur_node, batteries_needed));
        }

        ll l = 0, r = 10e9 + 1;
        // std::cout<<r<<std::endl;
        while(l < r - 1){
            ll m = (r + l) / 2;
            
            for(size_t i = 0;i < n;i++){
                max_batteries_by_nodes[i] = infinity;
            }

            ll batteries_take = m;
            max_batteries_by_nodes[0] = std::min(batteries[0], batteries_take);
            for(int i = 1;i < n;i++){
                auto cur_node = i;
                auto adjust_at_node = adjusts[cur_node];
                ll max_batteries = infinity;
                for(auto adjust : adjust_at_node){
                    int last_node = adjust.first;
                    ll batteries_need = adjust.second;
                    
                    ll last_node_max_batteries = max_batteries_by_nodes[last_node];
                    if(last_node_max_batteries < batteries_need) continue;

                    last_node_max_batteries += batteries[cur_node];
                    if(max_batteries == infinity) {
                        max_batteries = last_node_max_batteries;
                        continue;
                    }

                    if(max_batteries < last_node_max_batteries){
                        max_batteries = last_node_max_batteries;
                    }
                }

                max_batteries_by_nodes[cur_node] = std::min(batteries_take, max_batteries);
            }

            if(max_batteries_by_nodes[n - 1] != infinity){
                r = m;
            }
            else{
                l = m;
            }
            // std::cout<<l<<" "<<m<<" "<<r<<std::endl;
        }
        if(r == 10e9 + 1){
            std::cout<<-1<<std::endl;
            continue;
        }
        std::cout<<r<<std::endl;
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2110/problem/D
 */
