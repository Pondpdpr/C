// https://codeforces.com/problemset/problem/2/A
#include <bits/stdc++.h>
using namespace std;
int n,t1,ma;
string a;
struct node{
    string s;
    int point;
}t;
map<string,int>point;
vector<string>v;
queue<node>q;
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin >> a >> t1;
//        cout << a << " get " << t1 << " point " << endl;
        point[a]+=t1;
        q.push({a,point[a]});
    }
//    for(auto kk : point) cout << kk.first << "really have " << kk.second<< endl;
    for(auto k : point)
    {
        a=k.first;
        t1=k.second;
//        cout << a << " max " << t1 << endl;
        if(t1>ma)
        {
            ma=t1;
            while(!v.empty()) v.pop_back();
            v.push_back(a);
        }else if(t1==ma) v.push_back(a);
    }
    if(v.size()>1)
        while(!q.empty())
        {
            t=q.front(); q.pop();
//            cout << "queue " << t.s << " get " << t.point << endl;
            if(t.point>=ma)
                for(i=0;i<v.size();i++)
                    if(t.s==v[i])
                    {
                        cout << v[i];
                        return 0;
                    }
        }
    cout << v[0];
}
