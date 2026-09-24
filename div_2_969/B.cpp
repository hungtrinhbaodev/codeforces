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
       int n, m;
       cin>>n>>m;
       int max = -1;
       for(int i = 0;i < n;i++){
           int a;
           cin>>a;
           if(max < a){
               max = a;
           }
       }
       vector<int> arr_ans;
       for(int i = 0;i < m;i++){
           char c;
           int l, r;
           cin>>c>>l>>r;
           if (l <= max && max <= r){
               if(c == '+'){
                   max++;
               }
               else{
                   max--;
               }
           }
           arr_ans.push_back(max);
       }
       for(int i = 0;i < arr_ans.size();i++){
           int a = arr_ans[i];
           cout<<a<< " ";
       }
       cout<<endl;
   }
   return 0;
}


/**
 * link contest: https://codeforces.com/contest/2007/problem/B
 */
