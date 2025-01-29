// This problem basically returns whether an array has a subset whose sum is equal to the given target
#include<bits/stdc++.h>
using namespace std;
bool solve(int target , int sum , vector<int>& arr , int n){
    //Base condition
    if(sum==target)return true;
    if(n==0 || sum>target)return false;

    bool take = solve(target , sum+arr[n-1], arr , n-1);
    bool notTake = solve(target , sum , arr , n-1);
    return take || notTake ;
}
int main(){
    int target;
    cin>>target;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i]=a;
    }

    bool ans = solve(target , 0  , arr , n);
    cout<<ans;
    return 0;
}