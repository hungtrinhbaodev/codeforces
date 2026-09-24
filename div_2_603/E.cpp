#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define LL long long int
#define MAX 1000007
using namespace std;

struct node{
    int l,r,vl,vr;
};

node vec[4*MAX];

void build()
{
    for(int i = 0;i < 4*MAX;i++)
    {
        node t;
        t.l=t.r=t.vl=t.vr = 0;
        vec[i] = t;
    }
}

int getOutput()
{
    if(vec[0].l !=0 || vec[0].r !=0)
        return -1;
    else
    {
        if(vec[0].vr > vec[0].vr)
            return vec[0].vr;

        return vec[0].vl;
    }
}


void update(int id, int l, int r, int pos, node val)
{
    if(l == r)
    {
        vec[id] = val;
        return;
    }

    int mid = (l+r)/2;

    if(pos <= mid)
        update(id*2+1,l,mid,pos,val);
    else
        update(id*2+2,mid+1, r,pos,val);

    node nodel = vec[2*id+1], noder = vec[2*id+2];

    if(nodel.r <= noder.l)
    {
        int d = noder.l - nodel.r, tmp;

        if(nodel.vr + d > noder.vl)
            tmp = nodel.vr+d;
        else
            tmp = noder.vl;

        if(tmp < nodel.vl + d)
            tmp = nodel.vl + d;

        vec[id].l = nodel.l + d;
        vec[id].vl = tmp;
        vec[id].r = noder.r;
        vec[id].vr = noder.vr;

    }
    else
    {
        int d = nodel.r - noder.l, tmp;

        if(noder.vl + d > nodel.vr)
            tmp = noder.vl + d;
        else
            tmp = nodel.vr;

        if(tmp < noder.vr + d)
            tmp = noder.vr+d;

        vec[id].l = nodel.l;
        vec[id].vl = nodel.vl;
        vec[id].r = noder.r+d;
        vec[id].vr = tmp;
    }
    //cout<<l<<" "<<r<<" "<<vec[id].l <<" "<<vec[id].r<<" "<<vec[id].vl<<" "<<vec[id].vr<<endl;
}

void getInput()
{
    int n, pos = 0;
    string s;
    cin>>n>>s;

    for(int i = 0;i < n;i++)
    {
        if(s[i] == 'L')
        {
            if(pos > 0)
                pos--;
        }
        else if(s[i] == 'R')
        {
            if(pos < n - 1)
                pos++;
        }
        else if(s[i] == '(')
        {
            node t;
            t.r = 1;
            t.l = 0;
            t.vr = 1;
            t.vl = 0;
            update(0,0,n - 1,pos,t);
        }
        else if(s[i] == ')')
        {
            node t;
            t.r = 0;
            t.l = 1;
            t.vr = 0;
            t.vl = 1;
            update(0,0,n - 1,pos,t);
        }
        else
        {
            node t;
            t.r = 0;
            t.l = 0;
            t.vr = 0;
            t.vl = 0;
            update(0,0,n - 1,pos,t);
        }

        cout<<getOutput()<<" ";
    }
}



int main()
{
    build();
    getInput();
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1263/problem/E
 */
