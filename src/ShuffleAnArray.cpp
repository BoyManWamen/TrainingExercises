class Solution {
public:
    Solution(vector<int>& nums) 
        : m_nums(nums), m_reset(nums)
    { 
    }
    
    vector<int> reset() {
        return m_reset;
    }
    
    vector<int> shuffle() {
        std::random_shuffle(m_nums.begin(), m_nums.end());
        return m_nums;
    }

private:
    vector<int> m_nums;
    vector<int> m_reset;

};
