/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define big_int long long int

void add_seg_to_map(map<big_int, big_int> &map_ans, big_int key, big_int seg){
    if(map_ans.find(key) != map_ans.end()){
        map_ans[key] += seg;
    }
    else{
        map_ans[key] = seg;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<big_int> arr_p, arr_q;
        map<big_int, big_int> map_ans;
        for(int i = 0;i < n;i++){
            int p;
            cin>>p;
            arr_p.push_back(p);
        }
        for(int i = 0;i < m;i++){
            big_int q;
            cin>>q;
            arr_q.push_back(q);
        }
        for(int i = 0;i < n - 1;i++){
            big_int seg = arr_p[i + 1] - arr_p[i] - 1;
            big_int l = i + 1, r = n - 1 - i;
            big_int key = l * r;
            add_seg_to_map(map_ans, key, seg);
            add_seg_to_map(map_ans, key + i, 1);
        }
        add_seg_to_map(map_ans, n - 1, 1);
        for(int i = 0;i < m;i++){
            big_int key = arr_q[i];
            if(map_ans.find(key) != map_ans.end()){
                cout<<map_ans[key]<<" ";
            }
            else {
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2019/problem/B
 */
