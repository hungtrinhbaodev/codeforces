/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, m, q;
        cin>>n>>m>>q;
        vector<long> arr_a, arr_b;
        for(int i = 0;i < m;i++){
            long a;
            cin>>a;
            arr_a.push_back(a);
        }
        sort(arr_a.begin(), arr_a.end());
        for(int i = 0;i < q;i++){
            int b;
            cin>>b;
            arr_b.push_back(b);
        }
        for(int i = 0;i < q;i++){
            long b = arr_b[i];
            int l = 0, r = arr_a.size() - 1;
            if(b < arr_a[l] || b > arr_a[r]){
                if(b < arr_a[l]){
                    cout<<arr_a[l] - 1<<endl;
                }
                else{
                    cout<<n - arr_a[r]<<endl;
                }
            }
            else{
                while(r - l > 1){
                    int m = (r + l) / 2;
                    if(b < arr_a[m]){
                        r = m;
                    }
                    else{
                        l = m;
                    }
                }
                int del = (arr_a[r] - arr_a[l] - 1);
                int ans = (del / 2) + (del % 2);
                cout<<ans<<endl;
            }
        }
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2005/problem/B2
 */
