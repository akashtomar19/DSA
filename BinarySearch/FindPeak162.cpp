#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)return 0;
        if(nums[0] > nums[1])return 0;
        if(nums.back() > nums[nums.size() - 2])return nums.size() - 1;
        int l = 1;
        int r = nums.size() - 2;
        while(l <= r){
            int mid = (l + r) / 2;

            if((nums[mid - 1] < nums[mid]) && (nums[mid] > nums[mid + 1])){
                return mid;
            }
            if(nums[mid] < nums[mid + 1]){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return -1;
    }
};