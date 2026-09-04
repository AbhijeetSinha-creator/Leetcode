class Solution {
public:
    int firstStableIndex(vector<int>& v, int k) {
        int stability_index = -1;
        int n = v.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        vector<int> maximum(n);
        vector<int> minimum(n);
        for(int i=0;i<n;i++){
            maxi = max(maxi,v[i]);
            maximum[i] = maxi;
        }
        for(int i=n-1;i>=0;i--){
            mini = min(v[i],mini);
            minimum[i] = mini;
        }
        for(int i=0;i<n;i++){
            if((maximum[i] - minimum[i]) <= k){
                stability_index = i;
                break;
            }
        }
        return stability_index;
    }
};