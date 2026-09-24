/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <vector>
using namespace std;
#define big_int long long int
 
int main()
{
    int t;
    cin>>t;
    while(t--){
       int n;
       big_int k, max = - 1, total_card = 0;
       cin>>n>>k;
       for (int i = 0;i < n;i++){
           big_int a;
           cin>>a;
           total_card += a;
           if (max < a){
               max = a;
           }
       }
       max = max <= 0 ? 1 : max;
       int ans = 1;
       for (int i = 1;i < n;i++){
           int cur_ans = (i + 1);
           big_int mod = total_card % cur_ans;
           big_int div = total_card / cur_ans;
           if (mod > 0) div++;
           if (div <= max){
               if ((max * cur_ans) <= (total_card + k)){
                   ans = cur_ans;
               }
               continue;
           }
           if (mod == 0){
               ans = cur_ans;
               continue;
           }
           if (div - (total_card % div) <= k){
               ans = cur_ans;
               continue;
           }
       }
       cout<<ans<<endl;
    }
 
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2019/problem/C
 */
