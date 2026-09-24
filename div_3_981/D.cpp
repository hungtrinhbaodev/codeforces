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

bool compare(big_int a, big_int b){
    return a > b;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<big_int> arr, arr_sum, arr_optimal;
        big_int sum = 0;
        for(int i = 0;i < n;i++){
            big_int a;
            cin>>a;
            sum+=a;
            arr.push_back(a);
            arr_optimal.push_back(0);
            arr_sum.push_back(0);
        }
        map<big_int, vector<big_int>> map_sum;
        for(int i = 0;i < n;i++){
            if(map_sum.find(sum) == map_sum.end()){
                vector<big_int> arr_index;
                map_sum[sum] = arr_index;
            }
            map_sum[sum].push_back(i);
            arr_sum[i] = sum;
            // cout<<i<<": "<<sum<<" "<<arr_sum[i]<<endl;
            sum -= arr[i];
        }
        for (map<big_int, vector<big_int>>::iterator it = map_sum.begin();it != map_sum.end();it++){
            vector<big_int> *arr_index = &it->second;
            sort(arr_index->begin(), arr_index->end(), compare);
            // cout<<"sort arr index at "<<it->first<<" : ";
            // for(int i = 0;i < arr_index->size();i++){
            //     cout<<(*arr_index)[i]<<" ";
            // }
            // cout<<endl;
        }
        for(int i = 0;i < arr_optimal.size();i++){
            if(i <= 0){
                arr_optimal[i] = arr[i] == 0 ? 1 : 0;
            }
            else{
                // Find closet subset = 0 to i
                big_int a = arr[i];
                sum = arr_sum[i];
                big_int remain = sum - a;
                // cout<<i<<": "<<sum<<" "<<a<<" "<<remain<<" "<<(map_sum.find(remain) == map_sum.end())<<endl;
                // Cant find sum subset
                if(map_sum.find(remain) == map_sum.end()){
                    arr_optimal[i] = arr_optimal[i - 1];
                }
                else{
                    vector<big_int> *arr_index = &(map_sum[remain]);
                    if(arr_index->size() > 0){
                        
                        int last_min_index = (*arr_index)[arr_index->size() - 1];
                        arr_index->pop_back();
                        
                        while(arr_index->size() > 0 && (*arr_index)[arr_index->size() - 1] <= i){
                            last_min_index = (*arr_index)[arr_index->size() - 1];
                            arr_index->pop_back();
                        }
                        
                        // cout<<"last_min_index: "<<last_min_index<<" "<<i<<endl;
                        if(last_min_index > i){
                            arr_optimal[i] = arr_optimal[i - 1];
                        }
                        else{
                            int optimal = 1;
                            if(last_min_index > 0){
                                optimal = arr_optimal[last_min_index - 1] + 1;
                            }
                            optimal = optimal > arr_optimal[i - 1] ? optimal : arr_optimal[i - 1];
                            arr_optimal[i] = optimal;
                        }
                        arr_index->push_back(last_min_index);
                    }
                    else{
                        arr_optimal[i] = arr_optimal[i - 1];
                    }
                    // cout<<"optimal at "<<i<<": "<<arr_optimal[i]<<endl;
                }
            }
        }
        cout<<arr_optimal[n - 1]<<endl;
    }
 
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2033/problem/D
 */
