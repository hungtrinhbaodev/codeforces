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
       int l, r, ans = 0, cur_index = 0;
       cin>>l>>r;
       int arr_mode[3] = {1, 0, 1};
       for(int i = l;i <= r;i++){
           int a = i;
           int b = arr_mode[cur_index];
           if(a % 2 == b){
               if(cur_index >= 2){
                   ans++;
               }
               cur_index = (cur_index + 1) % 3;
           }
       }
       cout<<ans<<endl;
   }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2007/problem/A
 */
