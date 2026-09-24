/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &adjusts, int cur_vertex, string &path, string &arr_val_vertex, vector<string> &arr_path, vector<bool> &visited){
    visited[cur_vertex] = true;
    path.push_back(arr_val_vertex[cur_vertex]);
    
    // checl is leaf node
    bool is_leaf = true;
    for(int i = 0;i < adjusts[cur_vertex].size();i++){
        int next_vertex = adjusts[cur_vertex][i];
        if(!visited[next_vertex]){
            is_leaf = false;
            break;
        }
    }
    
    // stop condition if node is leaf
    if(is_leaf){
        string final_path;
        int path_size = path.size();
        final_path.push_back(path[0]);
        final_path.push_back(path[path_size - 1]);
        arr_path.push_back(final_path);
        path.pop_back();
        return;
    }
    
    // recusion
    for(int i = 0;i < adjusts[cur_vertex].size();i++){
        int next_vertex = adjusts[cur_vertex][i];
        if(visited[next_vertex]) continue;
        dfs(adjusts, next_vertex, path, arr_val_vertex, arr_path, visited);
    }
}

void print_arr_path(vector<string> &arr_path){
    for(int i = 0;i < arr_path.size();i++){
        cout<<i<<" "<<arr_path[i]<<endl;
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    int debug_test = t - 252;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr_path;
        vector<bool> visited;
        vector<vector<int>> adjusts;
        string arr_val_vertex;
        
        for(int i = 0;i < n;i++){
            visited.push_back(false);
            vector<int> arr_v_adjust;
            adjusts.push_back(arr_v_adjust);
        }
        
        string test_case;
        for(int i = 0;i < n - 1;i++){
            int v_a, v_b;
            cin>>v_a>>v_b;
            v_a--;
            v_b--;
            adjusts[v_b].push_back(v_a);
            adjusts[v_a].push_back(v_b);
            
            string s_a = to_string(v_a);
            string s_b = to_string(v_b);
            test_case.append(s_a, 0, s_a.size());
            test_case.push_back('_');
            test_case.append(s_b, 0, s_b.size());
            test_case.push_back('|');
        }
        cin>>arr_val_vertex;
    
        // 4|1_3|1_0|2_0||??01
        // if(t == debug_test){
        //     string test;
        //     string s_n = to_string(n);
        //     test.append(s_n, 0, s_n.size());
        //     test.push_back('|');
        //     test.append(test_case, 0, test_case.size());
        //     test.push_back('|');
        //     test.append(arr_val_vertex, 0, arr_val_vertex.size());
        //     cout<<test<<endl;
        // }
        
        int root = 0;
        string path;
        
        dfs(adjusts, 0, path, arr_val_vertex, arr_path, visited);
        // print_arr_path(arr_path);
        
        // first step check first value of all arr path is ?
        int ans = 0;
        int is_first_move = true;
        // print_arr_path(arr_path);
        int count_missing = arr_path[0][0] == '?' ? 1 : 0;
        int total_missing = 0;
        // cout<<"count_missing"<<count_missing<<" "<<arr_path[0][0]<<" "<< (arr_path[0][0] == '?')<<endl;
        for(int i = 0;i < arr_path.size();i++){
            string final_path = arr_path[i];
            if(arr_path[i][1] == '?'){
                count_missing++;
            }
        }
        for(int i = 0;i < arr_val_vertex.size();i++){
            if(arr_val_vertex[i] == '?'){
                total_missing++;
            }
        }
        int remain_missing = total_missing - count_missing;
        // cout<<"remain_missing"<<count_missing<<" "<<total_missing<<" "<<remain_missing<<endl;
        if(arr_path[0][0] == '?'){
            int number_zero_count= 0, number_one_count = 0;
            for(int i = 0;i < arr_path.size();i++){
                string final_path = arr_path[i];
                if(final_path[1] == '0'){
                    number_zero_count++;
                }
                if(final_path[1] == '1'){
                    number_one_count++;
                }
            }
            int number_remain = arr_path.size() - (number_one_count + number_zero_count);
            // cout<<"number_remain "<<number_remain<<endl;
            if(number_one_count == number_zero_count){
                if(number_remain > 0 && number_remain % 2 == 1){
                    ans = number_one_count + (number_remain / 2) + (remain_missing % 2);
                }
                else
                    ans = number_one_count + (number_remain / 2);
            }
            else{
                int max_score = number_one_count > number_zero_count ? number_one_count : number_zero_count;
                ans = max_score + (number_remain / 2);
            }
        }
        else{
            int number_score_leaf = 0, number_remain = 0;
            for(int i = 0;i < arr_path.size();i++){
                string final_path = arr_path[i];
                if(final_path[1] == '?'){
                    number_remain++;
                }
                else{
                    if(final_path[0] != final_path[1]){
                        number_score_leaf++;
                    }
                }
            }
            int score_remain = (number_remain / 2) + (number_remain % 2);
            ans = number_score_leaf + score_remain;
        }
        cout<<ans<<endl;
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2007/problem/D
 */
