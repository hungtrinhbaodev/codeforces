/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int main()
{
    int t, x, y, k;
    cin>>t;
    while(t--){
        cin>>x>>y>>k;
        int dx = x / k, mx = x % k;
        int dy = y / k, my = y % k;
        if (mx > 0) dx++;
        if (my > 0) dy++;
        if (dx == dy) {
            cout<< 2 * dx <<endl;
        }
        else {
            if(dx > dy){
                cout << 2 * dx - 1 << endl;
            }
            else{
                cout <<2 * dy << endl;
            }
        }
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2009/problem/C
 */
