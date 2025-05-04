class Solution {
    public:
        vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
            vector<int> freq(1001, 0);
            for (int v : arr1) freq[v]++;
            vector<int> res;
            res.reserve(arr1.size());
            for (int v : arr2) {
                int c = freq[v];
                while (c--) res.push_back(v);
                freq[v] = 0;
            }
            for (int v = 0; v <= 1000; ++v) {
                int c = freq[v];
                while (c--) res.push_back(v);
            }
            return res;
        }
    };
    