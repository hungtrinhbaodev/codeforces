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
        vector<int> arr_a;
        for(int i = 0;i < m;i++){
            int a;
            cin>>a;
            arr_a.push_back(a);
        }
        sort(arr_a.begin(),arr_a.end());
        while(q--){
            int b;
            cin>>b;
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
                    int m = (l - r) / 2;
                    if(b < arr_a[m]){
                        r = m;
                    }
                    else{
                        l = n;
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
 * link contest: https://codeforces.com/contest/2005/problem/B1
 */
