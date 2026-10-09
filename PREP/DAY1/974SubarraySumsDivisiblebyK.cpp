#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& v,int k){
    vector<int>m(k,0);
    m[0]=1;
    int ps=0;
    int c=0;
    for(auto it:v){
        ps+=it;
        int p=((ps%k)+k)%k;
        if(m[p]!=0){
            c+=m[p];
        }
        m[p]++;
    }
    return c;
}

int main(){
    vector<int> v={4,5,0,-2,-3,1};
    int k=5;
    cout<<solve(v,k);
}