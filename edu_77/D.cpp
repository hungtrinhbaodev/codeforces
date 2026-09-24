#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#define LL long long int

using namespace std;

struct node{
    int l, r, d;
};

bool SS(node &a, node &b)
{
    return a.l < b.l;
}

int m, n, k, t;

vector<node> traps;
vector<int>  solids;

bool check(int agi)
{
    int pos = 0;
    while(traps[pos].d <= agi)
        pos++;

    int res = traps[pos].l - 1, Min = traps[pos].l, Max = traps[pos].r;

    for(int i = pos + 1;i < traps.size(); i++)
    {
        if(traps[i].d > agi)
        {
            if(Max >= traps[i].l)
            {
                if(Max < traps[i].r)
                    Max = traps[i].r;
            }
            else
            {
               res += 2* (Max - Min + 1) + traps[i].l - Min;
               Max = traps[i].r;
               Min = traps[i].l;
            }
        }
    }

    if(res + 1 <= t)
        return true;
    else
        return false;
}


int binarySearch(int l, int r)
{
    while(r - l > 1)
    {
        int mid = (l + r)/2;

        if(!check(solids[mid]))
            l = mid;
        else
            r = mid;
    }

    return r;
}

int main()
{
    cin>>m>>n>>k>>t;

    solids.push_back(-1);

    for(int i = 0;i <m;i++)
    {
        int t;
        cin>>t;
        solids.push_back(t);
    }

    sort(solids.begin(),solids.end());

    for(int i = 0;i < k;i++)
    {
        node t;
        cin>>t.l>>t.r>>t.d;
        traps.push_back(t);
    }

    node t;
    t.l = n + 1;
    t.r = n + 1;
    t.d = 2*100007;
    traps.push_back(t);

    sort(traps.begin(),traps.end(),SS);

    int n1 = binarySearch(0,solids.size());
    
    if(n1 == solids.size())
    {
        cout <<0<<endl;
        return 0;
    }
    
    
    vector<int>::iterator up;

    up = upper_bound(solids.begin(),solids.end(), (solids[n1] - 1));

    cout<<solids.end() - up <<endl;

    return 0;
}


/**
 * link contest: https://codeforces.com/contest/1260/problem/D
 */
