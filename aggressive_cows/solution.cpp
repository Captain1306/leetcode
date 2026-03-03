#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
bool isValid(vector<int>&arr, int n, int m, int maxallowed){
    int cows=1;
    int lastpos=arr[0];
    sort(arr.begin(),arr.end());
    for(int i=1; i<n; i++){
        if((arr[i]+lastpos)>=maxallowed){
            cows++;
        }
        if(cows==m){
            return true;
        }
    }
    return false;
}
int stall(vector <int> &arr,int n, int cows){
    int ans;
    int maximum=INT_MIN;
    int min=1;
    for(int i=0; i<n; i++){
        maximum=max(arr[i],maximum);
    }
    while(min<=maximum){
        int mid=min+(maximum-min)/2;
        if(isValid(arr,n,cows,mid)){
            min=mid+1;
            ans=mid;
        }
        else{
            maximum=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1,2,8,4,9};
    int n = 5;
    int cows = 3;
    cout << stall(arr,n,cows) << endl;
    return 0;
}