#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main (){
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin>>n>>k;
        vector<int> vect, vecMinus;
        for(int i = 0;i < n;i++){
            int a;
            cin>>a;
            vect.push_back(a);
        }
        if(n <= 1) {
            cout<<0<<endl;
        }
        else{
            for(int i = 0;i < n-1;i++){
                vecMinus.push_back(abs(vect[i] - vect[i + 1]));
            }
            sort(vecMinus.begin(), vecMinus.end());
            int sum = 0;
            for(int i = 0;i < (n - k);i++){
                sum += vecMinus[i];
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1847/problem/A
 */
