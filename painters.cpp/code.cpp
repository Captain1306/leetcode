#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
bool isValid(vector<int>& arr, int n, int m, int maxall){
    int painter = 1;
    int time = 0;
    for(int i = 0; i < n; i++){
        if(time + arr[i] <= maxall){
            time += arr[i];
        }
        else{
            painter++;
            time = arr[i];
        }
    }
    return painter <= m;
}
int painter(vector<int>& arr, int n, int m){
    int maximum = INT_MIN;
    int ans;
    int Tsum = 0;
    for(int i = 0; i < n; i++){
        maximum = max(arr[i], maximum);
        Tsum += arr[i];
    }
    while(maximum <= Tsum){
        int mid = maximum + (Tsum - maximum) / 2;

        if(isValid(arr, n, m, mid)){
            ans = mid;
            Tsum = mid - 1;
        }
        else{
            maximum = mid + 1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {40,30,10,20};
    int n = 4;
    int m = 2;
    cout << painter(arr,n,m) << endl;
    return 0;
}