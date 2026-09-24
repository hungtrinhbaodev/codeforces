/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define big_int long long int

int main()
{
    int t;
    cin>>t;
    while(t--){
        big_int a, b, x;
        cin>>a>>b;
        // cout<<"Ans: ";
        if(a >= b) cout <<a<<endl;
        else{
            if (b >= 2 * a) cout<<0<<endl;
            else{
                cout<<2 * a - b<<endl;
            }
        }
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2024/problem/A
 */
