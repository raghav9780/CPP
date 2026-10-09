#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(vector<ll>& v,ll n){
    ll ps=0;
    ll rem=0;
    ll c=0;
    vector<ll> m(n,0);
    m[0]=1;
    for(auto it:v){
        ps+=it;
        rem = ((ps%n)+n)%n;
        if(m[rem]!=0){
            c+=m[rem];
        }
        m[rem]++;
    }
    return c;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        v.push_back(x);
    }
    cout<<solve(v,n);
}