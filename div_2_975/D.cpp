/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
    return a.first > b.first;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i = 0;i < n;i++){
            int a;
            cin>>a;
            arr.push_back(a);
        }
        map<int, pair<int, int>> map_left_right;
        for(int i = 0;i < n;i++){
            int a = arr[i];
            if(map_left_right.find(a) == map_left_right.end()){
                map_left_right[a] = pair<int, int>(i, i);
            }
            else{
                pair<int, int> p = map_left_right[a];
                if (p.first > i){
                    p.first = i;
                }
                if(p.second < i){
                    p.second = i;
                }
                map_left_right[a] = p;
            }
        }
        // check valid
        bool valid = map_left_right.find(n) != map_left_right.end();
        vector<pair<int, pair<int, int>>> arr_sort;
        if(valid){
            for (map<int, pair<int, int>>::iterator it = map_left_right.begin();it != map_left_right.end();it++){
                pair<int, int> p = it->second;
                int length = it->first;
                int l = p.first, r = p.second;
                if(r - l + 1 > length){
                    valid = false;
                    break;
                }
                arr_sort.push_back(pair<int, pair<int, int>>(length, pair<int, int>(l, r)));
            } 
        }
        // cout<<"0: "<<valid<<endl;
        if(!valid){
            cout<<0<<endl;
            continue;
        }
        sort(arr_sort.begin(), arr_sort.end(), compare);
        int l = 0, r = 0, length = n;
        int count = 0;
        for(int i = 0;i < arr_sort.size();i++){
            pair<int, pair<int, int>> pair_info = arr_sort[i];
            int cur_length = pair_info.first;
            if(cur_length == n) continue;
            pair<int, int> p = pair_info.second;
            // cout<<"p "<<count<<": "<<cur_length<<" "<<p.first<<" "<<p.second<<endl;
            int cur_l = p.second - cur_length + 1;
            cur_l = cur_l < 0 ? 0 : cur_l;
            int cur_r = p.first;
            
            // check invalid
            // cout<<"check 1 "<<count<<": "<<cur_r<<" "<<l<<endl;
            if (cur_r < l){
                valid = false;
                break;
            }
            int cur_max_length_l = cur_l + cur_length - 1;
            int last_max_length_r = r + length - 1;
            cur_max_length_l = cur_max_length_l >= n ? n - 1 : cur_max_length_l;
            last_max_length_r = last_max_length_r >= n ? n - 1 : last_max_length_r;
            // cout<<"check 2 "<<count<<": "<<cur_max_length_l<<" "<<last_max_length_r<<endl;
            if(cur_max_length_l > last_max_length_r){
                valid = false;
                break;
            }
            
            // optimal
            if (l <= cur_l){
                l = cur_l;
            }
            int cur_max_length_r = cur_r + cur_length - 1;
            cur_max_length_r = cur_max_length_r >= n ? n - 1 : cur_max_length_r;
            if (cur_max_length_r > last_max_length_r){
                r = last_max_length_r - cur_length + 1;
            }
            else{
                r = cur_r;
            }
            length = cur_length;
            // cout<<"res "<<count<<": "<<l<<" "<<r<<" "<<length<<endl;
            count++;
        }
        // cout<<"1: "<<valid<<endl;
        if(!valid){
            cout<<0<<endl;
            continue;
        }
        int max_length = r + length - 1;
        max_length = max_length >= n ? n - 1 : max_length;
        cout<<max_length - l + 1<<endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2019/problem/D
 */
