/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, odd = 0, even = 0, max_odd = -1, max_even = -1;
        cin>>n;
        for(int i = 0;i < n;i++){
            int a;
            cin>>a;
            if(i % 2 == 0){
                even += 1;
                if(max_even < a){
                    max_even = a;
                }
            }
            else{
                odd += 1;
                if(max_odd < a){
                    max_odd = a;
                }
            }
        }
        cout<<((odd + max_odd) > (even + max_even) ? (odd + max_odd) : (even + max_even))<<endl;
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2019/problem/A
 */
