#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll solve(vector<ll>&v){
    ll ps =0;
    ll mi=0;
    ll ans=LLONG_MIN;
    for(auto it:v){
        ps+=it;
        ans = max(ps-mi,ans);
        mi=min(ps,mi);
    }
    return ans;
}

ll solve2(vector<ll> &v){
    ll curr=0; //best sum of a subarray ending at current element
    ll ans=LLONG_MIN; //tells whats my best till now
    for(auto it : v){
        curr = max(it,it+curr);
        ans=max(curr,ans);
    }
    return ans;    
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v;
    while(n>0){
        ll x;
        cin>>x;
        v.push_back(x);
        n--;
    }
    cout<<solve2(v);
}