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
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> arr_ans;
        int index = 0;
        int current_total = n;
        for(int i = 0;i < n;i++){
            arr_ans.push_back(-2);
        }
        while(k > 0){
            int delta = current_total > k ? k : current_total;
            arr_ans[index] = 2 * delta - 1;
            k -= delta;
            index++;
            current_total-=1;
        }
        for(int i = 0;i < arr_ans.size();i++){
            cout<<arr_ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1809/problem/C
 */
