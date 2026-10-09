#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& v){
    int n=v.size();
    vector<int> ans(n);

    // pass 1: ans[i] = product of everything left of i
    int pre=1;
    for(int i=0;i<n;i++){
        ans[i]=pre;
        pre*=v[i];
    }

    // pass 2: multiply in product of everything right of i
    int suf=1;
    for(int i=n-1;i>=0;i--){
        ans[i]*=suf;
        suf*=v[i];
    }
    return ans;
}

int main(){
    vector<int> v={1,2,3,4};
    vector<int> ans=solve(v);
    for(auto it:ans){
        cout<<it<<" ";
    }
}
