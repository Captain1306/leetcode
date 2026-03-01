class Solution {
public:
    bool isValid(vector<int>& quant, int n, int maxAllowed) {
        long long stores = 0;
        for(int i = 0; i < quant.size(); i++) {
            stores += (quant[i] + maxAllowed - 1) / maxAllowed;
        }
        return stores <= n;
    }
    int minimizedMaximum(int n, vector<int>& quant) {
        int low = 1;
        int high = *max_element(quant.begin(), quant.end());
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isValid(quant, n, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};