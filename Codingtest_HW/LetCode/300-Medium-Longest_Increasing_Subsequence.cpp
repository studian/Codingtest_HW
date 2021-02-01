class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        vector<int> lis(nums.size(), 0); // ������ v�迭 ũ�� ��ŭ �����, 0���� �ʱ�ȭ
        lis[0] = nums[0]; // ù ������ ���� �ϰ� length �� 1��
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