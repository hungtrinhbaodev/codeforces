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
        int n, x, y;
        cin>>n>>x>>y;
        int a = x < y ? x : y;
        int m = n % a;
        int d = n / a;
        d = m > 0 ? (d + 1) : d;
        cout << d<< endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2013/problem/A
 */
