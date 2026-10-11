#include<bits/stdc++.h>
using namespace std;
pair<int, int>  solve(vector<int>& v,int x){
    map<int,int>m;
    for(int i=0;i<v.size();i++){
        m[v[i]]=i;
    }
    pair<int, int> ans={-1,-1};
    for(int i=0;i<v.size();i++){
        if(m.find(x-v[i])!=m.end() && i!=m[x-v[i]]){
            ans.first=i+1;
            ans.second=m[x-v[i]]+1;
            return ans;
        }
    }
    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<int>v;
    for (int i = 0; i < n; i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    pair<int, int> ans=solve(v,x);
    if(ans.first==-1 && ans.second==-1){
        cout<<"IMPOSSIBLE";
    }else{
        cout<<ans.first<<" "<<ans.second;    
    }
    return 0;
}