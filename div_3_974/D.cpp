/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool sort_func(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    int t;
    cin>>t;
    int debug = t - (21);
    while(t--){
        int n, d, k;
        cin>>n>>d>>k;
        priority_queue<int, vector<int>, greater<int> >priority_queue;
        vector<pair<int, int>> arr_n;
        for(int i = 0;i < k;i++){
            int l, r;
            cin>>l>>r;
            pair<int, int> p;
            p.first = l - 1;
            p.second = r - 1;
            arr_n.push_back(p);
        }
        if(t == debug){
            // 10|4|4|1_5|2_2|7_7|3_6|
            string str;
            str.append(to_string(n), 0, to_string(n).size());
            str.push_back('|');
            str.append(to_string(d), 0, to_string(d).size());
            str.push_back('|');
            str.append(to_string(k), 0, to_string(k).size());
            str.push_back('|');
            for(int i = 0;i < arr_n.size();i++){
                pair<int, int> p = arr_n[i];
                str.append(to_string(p.first), 0, to_string(p.first).size());
                str.push_back('_');
                str.append(to_string(p.second), 0, to_string(p.second).size());
                str.push_back('|');
            }
            // cout<<str<<endl;
        }
        sort(arr_n.begin(), arr_n.end(), sort_func);
        int index = 0;
        int max_day = 0, min_day = n + 1, ans_mother = 1, ans_brother = 1;
        for(int i = 0;i < n - d + 1;i++){
            int min_range = i;
            int max_range = i + d;
            
            while(index < arr_n.size()){
                pair<int, int> a = arr_n[index];
                int l = a.first;
                if(l < max_range){
                    priority_queue.push(a.second);
                }
                else {
                    break;
                }
                index += 1;
            }
            
            while(priority_queue.size() > 0){
                int r = priority_queue.top();
                if(r < min_range){
                    priority_queue.pop();
                }
                else{
                    break;
                }
            }
            
            int days = priority_queue.size();
            if(days > max_day){
                max_day = days;
                ans_brother = i + 1;
            }
            if(days < min_day){
                min_day = days;
                ans_mother = i + 1;
            }
        }
        
        cout<<ans_brother<<" "<<ans_mother<<endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2014/problem/D
 */
