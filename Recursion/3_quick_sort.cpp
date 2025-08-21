// quick sort
// TC: O(n log n)
// SC: O(1)

class Solution {
public:
    int partitionI(int low, int high, vector<int>& nums) {
        // choosing first element as pivot & place it to its correct position
        int pivot = nums[low];
        int i = low;
        int j = high;

        while (i < j) {
            // move i forward until we find element >= pivot
            while (i <= j && nums[i] <= pivot)
                i++;

            // move j backward until we find element <= pivot
            while (i <= j && nums[j] > pivot)
                j--;

            if (i < j) {
                swap(nums[i], nums[j]);
            } else {
                break;
            }
        }

        // swap pivot with j - correct place of pivot
        swap(nums[low], nums[j]);
        return j;
    }
    void quickSort(int low, int high, vector<int>& nums) {
        if (low < high) {
            // partition index
            int pIndx = partitionI(low, high, nums);

            quickSort(low, pIndx - 1, nums);
            quickSort(pIndx + 1, high, nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(0, nums.size() - 1, nums);
        return nums;
    }
};
