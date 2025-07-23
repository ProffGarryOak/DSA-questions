class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        for (slow = nums[slow], fast = nums[nums[fast]]; slow != fast; slow = nums[slow], fast = nums[nums[fast]]);
        for (slow = nums[0]; slow != fast; slow = nums[slow], fast = nums[fast]);
        return slow;
    }
};