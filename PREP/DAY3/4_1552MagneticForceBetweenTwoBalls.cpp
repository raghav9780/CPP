#include<bits/stdc++.h>
using namespace std;
int isMinMax(int m,vector<int>&v,int d){
    int j=v[0];
    m--;
    for(int i=1;i<v.size();i++){
        if(m>0 && v[i]-j>=d){
            m--;
            j=v[i];
        }
    }
    if(m>0){
        return -1;
    }
    return d;
}

int solve(vector<int>&v , int m){
    sort(v.begin(),v.end());
    int i=INT_MAX;
    for(int h=0;h<v.size()-1;h++){
        i=min(v[h+1]-v[h],i);
    }
    int j=v[v.size()-1]-v[0];
    int ans=INT_MIN;
    while(j>=i){
        int mid=i+(j-i)/2;
        int kk=isMinMax(m,v,mid);
        if(kk!=-1){
            ans=max(ans,kk);
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v={5,4,3,2,1,1000000000} ;
    int m =2;
    cout<<solve(v,m);
    return 0;
}