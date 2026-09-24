//
//  D.cpp
//  CodeforceLearning
//
//  Created by LAP13994 on 2/17/25.
//
#include<iostream>
#include<vector>
#include<string>
#define TYPE_ROW 0
#define TYPE_COL 1
 
using namespace std;
 
void print_vector_2D(string prefix, vector<vector<int>> &vec){
    cout<<prefix<<endl;
    for(int i = 0;i < vec.size();i++){
        for(int j = 0;j < vec[i].size();j++){
            cout<< vec[i][j] <<" ";
        }
        cout<<endl;
    }
}
 
void print_vector_1D(string prefix, vector<int> &vec){
    cout<<prefix<<endl;
    for(int i = 0;i < vec.size();i++){
        cout<< vec[i]<<" ";
    }
    cout<<endl;
}
 
vector<int> calc_arr_sum_black_by_line(int index_lines, int type, vector<vector<char>> &screen, int size_screen){
    vector<int> arr_sum_black_at_line;
    int count = 0;
    int n = size_screen;
    switch (type) {
        case TYPE_COL : {
            for(int i = 0;i < n;i++){
                if(screen[i][index_lines] == 'B'){
                    count++;
                }
                arr_sum_black_at_line.push_back(count);
            }
            break;
        }
        default:{
            for(int i = 0;i < n;i++){
                if(screen[index_lines][i] == 'B'){
                    count++;
                }
                arr_sum_black_at_line.push_back(count);
            }
            break;
        }
    }
    return arr_sum_black_at_line;
}
 
int get_value_in_range(int l, int r, vector<int> &arr_sum_white_lines){
    if (r < l) return 0;
    if (r >= arr_sum_white_lines.size()) return 0;
    int start_sum = 0;
    if(l  - 1 >= 0) start_sum = arr_sum_white_lines[l - 1];
    return arr_sum_white_lines[r] - start_sum;
}
 
int is_white_line_at_index(int index, int x, int y, vector<vector<int>> &arr_sum_back_by_line, int size_screen){
    int total_black_cell = get_value_in_range(x, y, arr_sum_back_by_line[index]);
    int max_black_cell = arr_sum_back_by_line[index][size_screen - 1];
    return max_black_cell <= total_black_cell ? 1 : 0;
}
 
int main(){
    int n, k;
    cin>>n>>k;
    vector<vector<char>> screen;
    for(int i = 0;i < n;i++){
        vector<char> line;
        for(int j = 0;j < n;j++){
            char input;
            cin>>input;
            line.push_back(input);
        }
        screen.push_back(line);
    }
    vector<vector<int>> arr_sum_black_by_rows, arr_sum_black_by_cols;
    for(int i = 0;i < n;i++){
        arr_sum_black_by_cols.push_back(calc_arr_sum_black_by_line(i, TYPE_COL, screen, n));
        arr_sum_black_by_rows.push_back(calc_arr_sum_black_by_line(i, TYPE_ROW, screen, n));
    }
//    print_vector_2D("sum black row arr:", arr_sum_black_by_rows);
//    print_vector_2D("sum black col arr:", arr_sum_black_by_cols);
    
    vector<int> arr_sum_white_rows, arr_sum_white_cols;
    int count_white_rows = 0;
    int count_white_cols = 0;
    for(int i = 0;i < n;i++){
        bool is_white_row = arr_sum_black_by_rows[i][n - 1] <= 0;
        if(is_white_row) count_white_rows++;
        arr_sum_white_rows.push_back(count_white_rows);
        
        bool is_while_col = arr_sum_black_by_cols[i][n - 1] <= 0;
        if(is_while_col) count_white_cols++;
        arr_sum_white_cols.push_back(count_white_cols);
    }
    
//    print_vector_1D("sum white rows:", arr_sum_white_rows);
//    print_vector_1D("sum white cols:", arr_sum_white_cols);
    
    vector<vector<int>> matrix_white_lines;
    
    for(int i = 0;i < n - k + 1;i++){
        vector<int> arr_white_lines;
        for(int j = 0;j < n - k + 1;j++){
            int total_white_rows_not_in_erase_erea = get_value_in_range(0, i - 1, arr_sum_white_rows) + get_value_in_range(i + k, n - 1, arr_sum_white_rows);
            int total_white_cols_not_in_erease_erea = get_value_in_range(0, j - 1, arr_sum_white_cols) + get_value_in_range(j + k, n - 1, arr_sum_white_cols);
            arr_white_lines.push_back(total_white_rows_not_in_erase_erea + total_white_cols_not_in_erease_erea);
        }
        matrix_white_lines.push_back(arr_white_lines);
    }
    
    for(int col = 0;col < n - k + 1;col++){
        int total_white_row = 0;
        for(int row = 0;row < n - k + 1;row++){
            if(row <= 0){
                for(int h = row;h <= row + k - 1;h++){
                    total_white_row += is_white_line_at_index(h, col, col + k - 1, arr_sum_black_by_rows, n);
                }
            }
            else{
                total_white_row += -is_white_line_at_index(row - 1, col, col + k - 1, arr_sum_black_by_rows, n) + is_white_line_at_index(row + k - 1, col, col + k - 1, arr_sum_black_by_rows, n);
            }
            matrix_white_lines[row][col] += total_white_row;
        }
    }
    
    for(int row = 0;row < n - k + 1;row++){
        int total_white_col = 0;
        for(int col = 0;col < n - k + 1;col++){
            if(col <= 0){
                for(int h = col;h <= col + k - 1;h++){
                    total_white_col += is_white_line_at_index(h, row, row + k - 1, arr_sum_black_by_cols, n);
                }
            }
            else{
                total_white_col += -is_white_line_at_index(col - 1, row, row + k - 1, arr_sum_black_by_cols, n) + is_white_line_at_index(col + k - 1, row, row + k - 1, arr_sum_black_by_cols, n);
            }
            matrix_white_lines[row][col] += total_white_col;
        }
    }
    
    int ans = 0;
    for(int i = 0;i < n - k + 1;i++){
        for(int j = 0;j < n - k + 1;j++){
            if(ans < matrix_white_lines[i][j]){
                ans = matrix_white_lines[i][j];
            }
        }
    }
    
    cout<<ans<<endl;
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1200/problem/D
 */
