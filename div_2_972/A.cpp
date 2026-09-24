/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        string s = string("aeiou");
        int d = n / s.size();
        int m = n % s.size();
        string ans_s;
        for(int i = 0;i < s.size();i++){
            string tmp_ans_s;
            for(int j = 0;j < d;j++){
                tmp_ans_s.append(s, i, 1);
            }
            if(m > 0){
                tmp_ans_s.append(s, i, 1);
                m--;
            }
            ans_s.append(tmp_ans_s, 0, tmp_ans_s.size());
        }
        cout<<ans_s<<endl;
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2005/problem/A
 */
