/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans;
        if(n == 1){
            cout << "? "<< 1 <<endl;
            cout.flush();
            cin>>ans;
            if(ans){
                cout<< "! " << 1 << endl;
                cout.flush();
            }
            else {
                cout << "! " << 0 << endl;
                cout.flush();
            }
        }
        else if(n >= 2){
            string s = string("10");
            cout<< "? " << s <<endl;
            cout.flush();
            cin>>ans;
            if(ans){
                if(n <= 2){
                    cout << "! "<< s << endl;
                    cout.flush();
                    continue;
                }
            }
            else{
                s = string("01");
                cout<<"? "<<s<<endl;
                cout.flush();
                cin>>ans;
                if(!ans) {
                    char binary = '0';
                    cout<<"? 00"<<endl;
                    cout.flush();
                    cin>>ans;
                    if(!ans){
                        binary = '1';
                    }
                    cout<< "! ";
                    for(int i = 0;i < n;i++){
                        cout<<binary;
                    }
                    cout<<endl;
                    cout.flush();
                    continue;
                }
                else{
                    if(n <= 2){
                        cout << "! "<<s << endl;
                        cout.flush();
                        continue;
                    }
                }
            }
            bool is_left = false;
            while(s.size() < n){
                string tmp_s = s;
                if(!is_left){
                    tmp_s.append("1");
                }
                else{
                    tmp_s.insert(0, "1");
                }
                cout<<"? "<<tmp_s<<endl;
                cout.flush();
                cin>>ans;
                if(ans){
                    s = tmp_s;
                    continue;
                }
                else{
                    tmp_s = s;
                    if(!is_left){
                        tmp_s.append("0");
                    }
                    else{
                        tmp_s.insert(0, "0");
                    }
                    cout<<"? "<<tmp_s<<endl;
                    cout.flush();
                    cin>>ans;
                    if(ans){
                        s = tmp_s;
                        continue;
                    }
                    else{
                        if(!is_left){
                            is_left = true;
                        }
                    }
                }
            }
            cout<<"! "<<s<<endl;
            cout.flush();
        }
    }

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/2013/problem/C
 */
