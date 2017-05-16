class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        sort(nums.begin(), nums.end());
        vector<int> parent(nums.size(), 0);
        vector<int> count(nums.size(), 0);
        int max_count_index = 0;
        for (int i=0; i<nums.size(); i++){
            parent[i] = i;
            count[i] = 1;
            for(int j=i-1; j>=0; j--){
                if(nums[i]%nums[j]==0 && count[i] < count[j] + 1){
                    // if nums[i] mod nums[j] == 0, it means count[j] can form a larger subset by putting nums[i] into count[j]
                    // if count[i] < count[j] + 1, it means one can get a larger subset by putting nums[i] into count[j]
                    parent[i] = j;
                    count[i] = count[j] + 1;
                    // update the index of the largest element in largest subset
                    if (count[max_count_index] < count[i])
                        max_count_index = i;
                }
            }
        }
        vector <int> answer;
        // backtrace for forming the result array
        while (max_count_index != parent[max_count_index]){
            answer.push_back(nums[max_count_index]);
            max_count_index = parent[max_count_index];
        }
        answer.push_back(nums[max_count_index]);
        return answer;
    }
};
