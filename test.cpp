#include <bits/stdc++.h>
using namespace std;
map<string,int>m;
int main(){
    m["kuay"]=1;
    m["hee"]=2;
    m["sus"]=3;
    for(auto k : m)
    {
        cout << k.first << " = " << k.second << endl;
    }
}
