#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int k){
    unordered_map<int,int>m;
    m[0]=1;
    int c=0;
    int ps=0;
    for(auto it : v){
        ps+=it;
        int n= ps-k;
        if(m.find(n)!=m.end()){
            c+=m[n];
        }
        m[ps]++;
    }
    return c;
}

int main(){
    vector<int> v={2,-1,3,5,-2};
    int k =7;
    cout<<solve(v,k);
}