class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> res(n, 0); // Only allocate the required return array
        
        int hottest = 0; // Track the absolute hottest temp seen from the right
        
        // Iterate backwards
        for (int i = n - 1; i >= 0; --i) {
            int current_temp = temperatures[i];
            
            // Optimization 1: If this is the hottest day we've ever seen, 
            // there is no warmer day in the future. res[i] remains 0.
            if (current_temp >= hottest) {
                hottest = current_temp;
                continue;
            }
            
            // Optimization 2: The "Jump" Trick
            int days = 1;
            while (temperatures[i + days] <= current_temp) {
                // Instead of iterating 1 by 1, we use the already computed 'res' 
                // to JUMP directly to the next known warmer day for that element!
                days += res[i + days];
            }
            
            res[i] = days;
        }
        
        return res;
    }
};