/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

struct Group{
    long long number_cell;
    long long value_cell;
};

void push_group(stack<Group> &stack, vector<Group> &arr_group, int start_index){
    for(int i = start_index;i < arr_group.size();i++){
        stack.push(arr_group[i]);
    }
}

void print_group(Group &group, string s){
    cout<<s<<":"<<"{"<<group.value_cell << ": "<<group.number_cell<<"}";
}

void print_arr_group(vector<Group> &arr_group){
    for(int i = 0;i < arr_group.size();i++){
        Group group = arr_group[i];
        print_group(group, string(""));
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<long long> arr;
        stack<Group> stack;
        cin>>n;
        for(int i = 0;i < n;i++){
            long long a;
            cin>>a;
            arr.push_back(a);
        }
        for(int i = 0;i < n;i++){
            Group group;
            group.number_cell = 1;
            group.value_cell = arr[i];
            if(i <= 0){
                stack.push(group);
                continue;
            }
            vector<Group> arr_group;
            arr_group.push_back(group);
            while(stack.size() > 0){
                Group first_group = stack.top();
                Group group = arr_group[0];
                // add group
                if(group.value_cell > first_group.value_cell){
                    push_group(stack, arr_group, 0);
                    break;
                }
                // merge group
                else if(group.value_cell == first_group.value_cell){
                    group.number_cell += first_group.number_cell;
                    stack.pop();
                    arr_group[0] = group;
                    push_group(stack, arr_group, 0);
                    break;
                }
                // process check group
                else{
                    long long total_value = first_group.value_cell * first_group.number_cell;
                    long long total_cell = first_group.number_cell;
                    for(int j = 0;j < arr_group.size();j++){
                        Group group = arr_group[j];
                        total_value += group.number_cell * group.value_cell;
                        total_cell += group.number_cell;
                    }
                    vector<Group> tmp_arr_group;
                    if(total_value % total_cell == 0){
                        Group group;
                        
                        group.value_cell = total_value / total_cell;
                        group.number_cell = total_cell;
                        
                        tmp_arr_group.push_back(group);
                    }
                    else{
                        long long value_cell = total_value / total_cell;
                        long long cell_remain = total_cell - (total_value % total_cell);
                        Group small_group, big_group;
                        
                        small_group.value_cell = value_cell;
                        small_group.number_cell = cell_remain;
                        
                        big_group.value_cell = value_cell + 1;
                        big_group.number_cell = total_cell - cell_remain;
                        
                        tmp_arr_group.push_back(small_group);
                        tmp_arr_group.push_back(big_group);
                    }
                    
                    stack.pop();
                    arr_group = tmp_arr_group;
                }
            }
            if(stack.size() <= 0){
                push_group(stack, arr_group, 0);
            }
        }
        Group group = stack.top();
        stack.pop();
        long long min_value = group.value_cell, max_value = group.value_cell;
        while(stack.size()){
           group = stack.top();
           stack.pop();
           if(max_value < group.value_cell){
               max_value = group.value_cell;
           }
           if(min_value > group.value_cell){
               min_value = group.value_cell;
           }
        }
        cout<<(max_value - min_value)<<endl;
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2013/problem/D
 */
