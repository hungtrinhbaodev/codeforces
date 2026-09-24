/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long sum = 0, ans = 0;
        for(int i = 0;i < n;i++){
            int a;
            cin >> a;
            if(i < n - 2){
                sum += a;
            }
            else if(i < n - 1){
                ans -= a;
            }
            else {
                ans += a + sum;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2013/problem/B
 */
