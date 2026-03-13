class Solution {
public:
    bool isSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;
        int freq1[26] = {0}, freq2[26] = {0};
        for (int i = 0; i < n1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        for (int i = 0; i <= n2 - n1; i++) {
            if (isSame(freq1, freq2)) return true;
            if (i < n2 - n1) {
                freq2[s2[i] - 'a']--;
                freq2[s2[i + n1] - 'a']++;
            }
        }
        return false;
    }
};
