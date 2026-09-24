#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main (){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin>>n;
        vector<int> vec;
        long curAnd = -1;
        for(int i = 0;i < n;i++){
            int a;
            cin>>a;
            vec.push_back(a);
            if(curAnd == -1){
                curAnd = a;
            }
            else{
                curAnd &= a;
            }
        }
        if(curAnd != 0) {
            cout<< 1 << endl;
        }
        else{
            curAnd = -1;
            int numGroup = 0;
            for(int i = 0;i < n;i++){
                if(curAnd == -1){
                    curAnd = vec[i];
                    numGroup++;
                }
                curAnd &= vec[i];
                if(curAnd == 0){
                    curAnd = -1;
                }
            }
            if(curAnd != -1) numGroup--;
            cout<<numGroup<<endl;
        }
        
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1847/problem/B
 */
