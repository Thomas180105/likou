class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool> isPrime(101, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= 100; ++i)
        {
            if (isPrime[i])
            {
                for (int j = 2 * i; j <= 100; j += i) isPrime[j] = false;
            }
        }

        int n = nums.size(), l = 0, r = n - 1;
        int ans = -1;
        while(l <= r)
        {
            if (!isPrime[nums[l]]) ++l;
            else if (!isPrime[nums[r]]) --r;
            else
            {
                ans = r - l;
                break;
            }
        }
        return ans;
    }
};