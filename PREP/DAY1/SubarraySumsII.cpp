#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(vector<ll>& v, ll k){
    map<ll,ll>m;
    m[0]=1;
    ll c=0;
    ll ps=0;
    for(auto it : v){
        ps+=it;
        ll n= ps-k;
        if(m.find(n)!=m.end()){
            c+=m[n];
        }
        m[ps]++;
    }
    return c;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n, x;
    cin>>n>>x;
    vector<ll> v;
    while(n>0){
        int t;
        cin>>t;
        v.push_back(t);
        n--;
    }
    cout<<solve(v,x);
}