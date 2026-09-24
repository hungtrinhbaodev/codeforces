#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#define LL long long int

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        LL a, b, k;
        cin>>a>>b>>k;

        if(a > b)
            swap(a,b);

        if(b <= (k - 1)*a + 1)
            cout<<"OBEY"<<endl;
        else
        {
            if(a % (b - (k - 1)*a) != 0)
                cout<<"REBEL"<<endl;
            else
                cout<<"OBEY"<<endl;
        }

    }
    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1260/problem/C
 */
