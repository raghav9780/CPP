#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll helper(vector<ll> & v,ll t, ll k){
    ll count=0;
    for(auto it:v){
        count+=k/it;
        if(count>=t){
            return count;
        }
    }
    return count;
}

ll solve(vector<ll>& v,ll t){
    ll i=1;
    ll j=(*min_element(v.begin(),v.end()))*t;
    ll ans=LLONG_MAX;
    while(j>=i){
        ll mid=i+(j-i)/2;
        ll isAns=helper(v,t,mid);
        if(isAns>=t){
            ans=min(ans,mid);
            j=mid-1;
        }else{
            i=mid+1;
        }
    }
    return ans;
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll>v;
    ll n,t;
    cin>>n>>t;
    while(n-->0){
        ll x;
        cin>>x;
        v.push_back(x);
    }
    cout<<solve(v,t);
    return 0;
}