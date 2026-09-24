#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define lli long long int
using namespace std;
bool compare(pair<int, int> &a, pair<int, int> &b){
    int min_a = min(a.first, a.second), max_a = max(a.first, a.second);
    int min_b = min(b.first, b.second), max_b = max(b.first, b.second);
    if(max_a < max_b){
        return true;
    }
    else if(max_a > max_b){
        return false;
    }
    else{
        if(min_a < min_b){
            return true;
        }
        else if(min_a > min_b){
            return false;
        }
        else{
            int index_max_a = max_a == a.first ? 0 : 1;
            int index_max_b = max_b == b.first ? 0 : 1;
            return index_max_a < index_max_b;
        }
    }
}
 
int test(vector<int> &arr){
    int count = 0;
    for(int i = 0;i < arr.size();i++){
        for(int j = i + 1;j < arr.size();j++){
            int a = arr[i];
            int b = arr[j];
            if(a > b){
                count++;
            }
        }
    }
    return count;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        vector<pair<int, int>> arr;
        int n;
        cin>>n;
        for(int i = 0;i < n;i++){
            int a, b;
            cin>>a>>b;
            arr.push_back(pair<int, int>(a, b));
        }
        sort(arr.begin(), arr.end(), compare);
        vector<int> my_ans, cf_ans = vector<int>({4, 1, 2, 3, 5, 10, 8, 7, 9, 6});
        for(int i = 0;i < n;i++){
            pair<int, int> p = arr[i];
            cout<<p.first<<" "<<p.second<<" ";
            my_ans.push_back(p.first);
            my_ans.push_back(p.second);
        }
        cout<<endl;
        // cout<<test(my_ans)<<" "<<test(cf_ans)<<endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2024/problem/C
 */
