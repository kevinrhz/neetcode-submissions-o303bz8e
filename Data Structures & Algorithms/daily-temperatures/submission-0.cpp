class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> res(n, 0);
        
        // 1. Vector as a Stack: Contiguous memory, cache-friendly.
        std::vector<int> stack; 
        
        // 2. Pre-allocate memory: The stack can never be larger than 'n'.
        // This guarantees exactly ZERO heap re-allocations during the loop.
        stack.reserve(n); 

        for (int i = 0; i < n; ++i) {
            int current_temp = temperatures[i];
            
            // 3. Store ONLY indices in the stack. 
            // Look up the temperature via temperatures[stack.back()]
            while (!stack.empty() && current_temp > temperatures[stack.back()]) {
                int prev_index = stack.back();
                stack.pop_back();
                
                // Calculate distance
                res[prev_index] = i - prev_index;
            }
            
            // Push the current index onto the stack
            stack.push_back(i);
        }
        
        return res;
    }
};