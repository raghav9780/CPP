#include<bits/stdc++.h>
using namespace std;
bool help(int mid,int m,int n,int k){
    int count=0;
    for(int i=1;i<=m;i++){
        count+=min(mid/i,n);
    }
    return count>=k;
}
int solve(int n,int m, int k){
    int i =1;
    int j =m*n;
    int ans=INT_MAX;
    while(j>=i){
        int mid=i+(j-i)/2;
        if(help(mid,m,n,k)){
            j=mid-1;
            ans=min(mid,ans);
        }else{
            i=mid+1;
        }
    }
    return ans;
}
 
int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    cout<<solve(m,n,k);
    return 0;
}