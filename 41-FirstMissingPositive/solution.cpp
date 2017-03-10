class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, j = 0;
        for( ; i < nums.size(); i++)        //Ԥ����nums[0 ~ j-1]Ϊ���е�j��������
            if(nums[i] > 0) nums[j++] = nums[i];
        for(int i = 0; i < j; i++){
            int n = nums[i]&0x7fffffff;        //ȡ�������������
            if(n <= j) nums[n-1] |= 0x80000000;//��Ǹ��������Ĵ���
        }
        int ans = 0;    //�������ҵ�һ�������ڵ�������
        while(ans < j && (nums[ans]&0x80000000)) ans++;
        return ans+1;
    }
};
