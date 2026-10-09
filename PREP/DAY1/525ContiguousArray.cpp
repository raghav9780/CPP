#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> v){
    unordered_map<int,int>m;
    m[0]=-1;
    int ans=0;
    int ps=0;
    for(int i =0;i<v.size();i++){
        ps+=v[i]==1?1:-1;
        if(m.find(ps)!=m.end()){
            ans=max(i-m[ps],ans);
        }else{
            m[ps]=i;
        }
    }
    return ans;
}
int main(){
    vector<int>v={0,1,1,0,1,1,1,0};
    cout<<solve(v);
}