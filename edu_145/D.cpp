/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define STATE_NULL 0
#define STATE_0 1
#define STATE_1 2
#define STATE_00 3
#define STATE_01 4
#define STATE_11 5
#define NUMBER_STATE 6
#define INVALID_VALUE (long long int)-1
#define big_int long long int

void init_arr_optimal(vector<vector<long long int>> &arr_optimal, string s, long long int cost_swap, long long int cost_erease){
    arr_optimal[STATE_00][0] = INVALID_VALUE;
    arr_optimal[STATE_01][0] = INVALID_VALUE;
    arr_optimal[STATE_01][0] = INVALID_VALUE;
    
    if(s[0]=='0'){
        arr_optimal[STATE_NULL][0] = cost_erease;
        arr_optimal[STATE_1][0] = INVALID_VALUE;
        arr_optimal[STATE_0][0] = 0;
    }
    else{
        arr_optimal[STATE_NULL][0] = cost_erease;
        arr_optimal[STATE_0][0] = INVALID_VALUE;
        arr_optimal[STATE_1][0] = 0;
    }
}

long long int get_optimal_cost_at_index(vector<vector<long long int>> &arr_optimal, int last_index){
    long long int ans = INVALID_VALUE;
    for(int i = 0;i < NUMBER_STATE;i++){
        long long int cur_value = arr_optimal[i][last_index];
        if(cur_value != INVALID_VALUE){
            if(ans == INVALID_VALUE){
                ans = cur_value;
            }
            else{
                ans = ans < cur_value ? ans : cur_value;
            }
        }
    }
    return ans;
}

long long int get_min_in_costs(long long int a, long long int add_a, long long int b, long long int add_b){
    if(a == INVALID_VALUE && b == INVALID_VALUE)  {
        return INVALID_VALUE;
    }
    else if(a == INVALID_VALUE) return b + add_b;
    else if(b == INVALID_VALUE) return a + add_a;
    else return (a + add_a) < (b + add_b) ? (a + add_a) : (b + add_b);
}

void update_arr_otimal_at_index(vector<vector<long long int>> &arr_optimal, int index, char cur_c, long long int cost_swap, long long int cost_erease){
    long long int last_cost_00 = arr_optimal[STATE_00][index - 1];
    long long int last_cost_01 = arr_optimal[STATE_01][index - 1];
    long long int last_cost_11 = arr_optimal[STATE_11][index - 1];
    
    long long int last_cost_null = arr_optimal[STATE_NULL][index - 1];
    long long int last_cost_0 = arr_optimal[STATE_0][index - 1];
    long long int last_cost_1 = arr_optimal[STATE_1][index - 1];
    
    // update STATE_NULL
    arr_optimal[STATE_NULL][index] = arr_optimal[STATE_NULL][index - 1] + cost_erease;
    
    switch(cur_c){
        case '0':{
            // update state 0
            long long int min_last_cost = get_min_in_costs(last_cost_0, cost_erease, last_cost_1, cost_erease);
            min_last_cost = get_min_in_costs(min_last_cost, 0, last_cost_null, 0);
            arr_optimal[STATE_0][index] = min_last_cost;
            
            // update state 1
            min_last_cost = get_min_in_costs(INVALID_VALUE, 0, last_cost_1, cost_erease);
            arr_optimal[STATE_1][index] = min_last_cost;
            
            // Update state 00
            min_last_cost = get_min_in_costs(last_cost_00, 0, last_cost_01, cost_erease);
            min_last_cost = get_min_in_costs(last_cost_0, 0, min_last_cost, 0);
            arr_optimal[STATE_00][index] = min_last_cost;
            
            // update state 01
            min_last_cost = get_min_in_costs(last_cost_01, cost_swap, last_cost_1, cost_swap);
            arr_optimal[STATE_01][index] = min_last_cost;
            
            // update state 11
            min_last_cost = get_min_in_costs(last_cost_11, cost_erease, INVALID_VALUE, 0);
            arr_optimal[STATE_11][index] = min_last_cost;
            break;
        }
        default:{
            // update state 0
            long long int min_cost = get_min_in_costs(last_cost_0, cost_erease, INVALID_VALUE, 0);
            arr_optimal[STATE_0][index] = min_cost;
            
            // update state 1
            min_cost = get_min_in_costs(last_cost_null, 0, last_cost_0, cost_erease);
            min_cost = get_min_in_costs(min_cost, 0, last_cost_1, cost_erease);
            arr_optimal[STATE_1][index] = min_cost;
            
            // update state 00
            min_cost = get_min_in_costs(last_cost_00, cost_erease, INVALID_VALUE, 0);
            arr_optimal[STATE_00][index] = min_cost;
            
            // update state 01
            min_cost = get_min_in_costs(last_cost_00, 0, last_cost_01, cost_erease);
            min_cost = get_min_in_costs(min_cost, 0, last_cost_0, 0);
            arr_optimal[STATE_01][index] = min_cost;
            
            // update state 11
            min_cost = get_min_in_costs(last_cost_11, 0, last_cost_01, 0);
            min_cost = get_min_in_costs(min_cost, 0, last_cost_1, 0);
            arr_optimal[STATE_11][index] = min_cost;
            break;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<vector<long long int>> arr_optimal;
        long long int cost_swap = 1000000000000, cost_erease = 1000000000001;
        for(int i = 0;i < NUMBER_STATE;i++){
            vector<long long int> arr_ans;
            for(int j = 0;j < s.size();j++){
                arr_ans.push_back(INVALID_VALUE);
            }
            arr_optimal.push_back(arr_ans);
        }
        if(s.size() <= 1){
            cout<<0<<endl;
        }
        else{
            init_arr_optimal(arr_optimal, s, cost_swap, cost_erease);
            for(int i = 1;i < s.size();i++){
                update_arr_otimal_at_index(arr_optimal, i, s[i], cost_swap, cost_erease);
            }
            cout<<get_optimal_cost_at_index(arr_optimal, s.size() - 1)<<endl;
        }
    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1809/problem/D
 */
