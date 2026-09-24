/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define lli long long int
using namespace std;
bool compare(pair<lli, lli> &a, pair<lli, lli> &b){
    return a.first < b.first;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        lli n, k;
        cin>>n>>k;
        vector<pair<lli, lli>> cans;
        map<lli, lli> map_cans_to_number;
        
        for(int i = 0;i < n;i++){
            int a;
            cin>>a;
            if (map_cans_to_number.find(a) == map_cans_to_number.end()){
                map_cans_to_number[a] = 0;
            }
            map_cans_to_number[a]++;
        }
        for (map<lli, lli>::iterator it = map_cans_to_number.begin();it != map_cans_to_number.end();it++){
            lli can = it->first;
            lli number_slot = it->second;
            cans.push_back(pair<lli, lli >(can, number_slot));
        }
        sort(cans.begin(), cans.end(), compare);
        lli presses = 0;
        lli number_total_can = n;
        lli last_can = 0;
        for(int i = 0;i < cans.size();i++){
            lli can = cans[i].first;
            lli number_can = cans[i].second;
            lli total_can_can_get = number_total_can * (can - last_can);
            // cout<<i<<": "<< can<<" "<<number_can<<" "<<total_can_can_get<<endl;
            if(total_can_can_get < k){
                k -= total_can_can_get;
                presses += total_can_can_get + number_can;
                number_total_can -= number_can;
                last_can = can;
            }
            else{
                presses += k;
                break;
            }
        }
        cout<<presses<<endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2024/problem/B
 */
