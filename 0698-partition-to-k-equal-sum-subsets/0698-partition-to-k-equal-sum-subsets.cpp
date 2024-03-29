class Solution {
public:
    int n, avg;
    vector<int> nums;
    static const int maxN = 16, finalState = (1 << maxN) - 1;
    int dp[finalState][maxN + 1];

    bool helper(int mask, int parts, int currSum) {
        int curr = __builtin_popcount(mask);

        if (curr >= n)
            return parts == 0;

        if (parts < 0)
            return false;

        int &ans = dp[mask][parts];

        if (ans != -1)
            return ans;

        ans = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                continue;

            int newMask = mask | (1 << i);
            int curP = (currSum + nums[i] == avg) ? 1 : 0;
            ans = ans || helper(newMask, parts - curP, (currSum%avg + nums[i]%avg)%avg);
        }

        return ans;
    }

    bool canPartitionKSubsets(vector<int> &arr, int k) {
        n = arr.size();
        nums = arr;

        int sum = 0, maxi = 0;

        for (int &i : arr) {
            sum += i;
            maxi = max(maxi, i);
        }

        avg = sum / k;

        if (n < k || (sum % k) || maxi > avg)
            return false;

        memset(dp, -1, sizeof dp);
        return helper(0, k, 0);
    }
};
