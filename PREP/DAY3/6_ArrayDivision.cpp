#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool helper(vector<ll>& v,ll k,ll mid){
    ll ct=1;
    ll sum=0;
    for(auto it:v){
        if(sum+it>mid){
            sum=it;
            ct++;
        }else{
            sum+=it;
        }
        if(ct>k){
            return false;
        }
    }
    return true;
}
ll solve(vector<ll>& v,ll k){
    ll i =*max_element(v.begin(),v.end());
    ll j= accumulate(v.begin(),v.end(),0LL);
    ll ans= LLONG_MAX;
    while(j>=i){
        ll mid=i+(j-i)/2;
        if(helper(v,k,mid)){
            ans=min(mid,ans);
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
    ll n,k;
    cin>>n>>k;
    vector<ll>v;
    while(n-->0){
        ll x;
        cin>>x;
        v.push_back(x);
    }
    cout<<solve(v,k);
    return 0;
}