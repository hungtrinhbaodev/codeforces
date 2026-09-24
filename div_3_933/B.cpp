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
    int t, a;
    cin>>t;
    while(t--){
        vector<int> arrs;
        int n;
        cin>>n;
        for(int i = 0;i < n;i++){
            int a;
            cin>>a;
            arrs.push_back(a);
        }
        bool valid = true;
        for(int i = 1;i < n - 1;i++){
            int a = arrs[i - 1];
            arrs[i - 1] -= a;
            arrs[i] -= 2 * a;
            arrs[i + 1] -= a;
            if(arrs[i] < 0 || arrs[i + 1] < 0){
                valid = false;
                break;
            }
        }
        if(valid){
            valid = (arrs[n - 1] == 0) && (arrs[n - 2] == 0);
        }
        if(valid) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1941/problem/B
 */
