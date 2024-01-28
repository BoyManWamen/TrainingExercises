static int tree_[100000001] = {0};
class BinaryIndexTree{
public:
    BinaryIndexTree(int m): tree_size_(m){
        memset(tree_, 0x00, tree_size_ * sizeof(int));
    }

    void update(int index, int diff){
        int tid = index + 1;
        for(; tid < tree_size_; tid += (tid&-tid)){
            tree_[tid] += diff;
        }
    }
    int get_sum(int index){
        int tid = index + 1, sum = 0;
        for(; tid > 0; tid -= (tid&-tid)){
            sum += tree_[tid];
        }
        return sum;
    }
private:
    int tree_size_;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        int max_val = INT_MIN, min_val = INT_MAX;
        for(int num: nums){
            max_val = max(max_val, num);
            min_val = min(min_val, num);
        }

        const int m         = max_val - min_val + 1;
        const int offset    = -min_val;
        const int num_elems = nums.size();

        BinaryIndexTree bit(m);
        vector<int> count(num_elems, 0);

        for(int i=num_elems-1; i>=0; --i){
            count[i] = bit.get_sum(nums[i] - 1 + offset);
            bit.update(nums[i] + offset, 1);
        }

        return count;
    }
};
