class Solution {
public:
    int firstStableIndex(vector<int>& v, int k) {
        int stability_index = -1;
        int n = v.size();
        for(int i=0;i<v.size();i++){
            int max_range = *max_element(v.begin(),v.begin()+(i+1));
            int min_range = *min_element(v.begin()+i,v.begin()+n);
            int instability_score = max_range - min_range;
            if(instability_score <= k){
                stability_index = i;
                break;
            }
        }
        return stability_index;
    }
};