/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myfunction (int i,int j) { return (i > j); }

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k;
        vector<int> arr_n;
        cin>>n>>k;
        for(int i = 0;i < n;i++){
            int a;
            cin>>a;
            arr_n.push_back(a);
        }
        sort(arr_n.begin(), arr_n.end(), myfunction);
        long total_point_alice = 0;
        long total_point_bob = 0;
        for(int i = 0;i < arr_n.size();i+=2){
            int a = arr_n[i];
            int b = arr_n[i + 1];
            int delta = a - b;
            delta = delta > k ? k : delta;
            k -= delta;
            arr_n[i + 1] += delta;
        }
        for(int i = 0;i < arr_n.size();i++){
            int a = arr_n[i];
            if(i % 2 == 0){
                total_point_alice += a;
            }
            else{
                total_point_bob += a;
            }
        }
        long ans = total_point_alice - total_point_bob;
        cout<<ans<<endl;
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2004/problem/C
 */
