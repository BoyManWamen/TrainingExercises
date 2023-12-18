class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        multiset<int> m;
       
        vector<int> v;
        
        for (int i = 0; i < arr.size(); i++) { 
             
            m.insert(arr[i]) ;

            if (m.size() == k) { 
                auto ma = m.rbegin();
                v.push_back(*ma);
                auto it = m.find(arr[i - k + 1]);
                m.erase(it); 
            }
        } 
        
        return v;
    }
};
