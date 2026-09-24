/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, a, b, max = -1;
        vector<int> arr_n, arr_mode_delta;
        cin>>n>>a>>b;
        for(int i = 0;i < n;i++){
            int ip;
            cin>>ip;
            arr_n.push_back(ip);
            if(ip > max){
                max = ip;
            }
        }
        int min_delta = __gcd(a, b);
        for(int i = 0;i < n;i++){
            arr_mode_delta.push_back(arr_n[i] % min_delta);
        }
        sort(arr_mode_delta.begin(), arr_mode_delta.end());
        int ans = arr_mode_delta[n - 1] - arr_mode_delta[0];
        for(int i = 0;i < n - 1;i++){
            int delta = arr_mode_delta[i] + min_delta - arr_mode_delta[i + 1];
            if(delta < ans){
                ans = delta;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2007/problem/C
 */
