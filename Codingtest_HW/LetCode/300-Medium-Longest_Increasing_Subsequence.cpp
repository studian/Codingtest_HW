class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        vector<int> lis(nums.size(), 0); // 데이터 v배열 크기 만큼 만들고, 0으로 초기화
        lis[0] = nums[0]; // 첫 데이터 같게 하고 length 는 1로
        int length = 1;

        for (int i = 1; i < nums.size(); i++) {
            auto s = lis.begin();
            auto e = s + length;
            auto it = lower_bound(s, e, nums[i]);

            if (it == e) {
                lis[length++] = nums[i];
            }
            else {
                *it = nums[i];
            }
        }

        return length;
    }
};