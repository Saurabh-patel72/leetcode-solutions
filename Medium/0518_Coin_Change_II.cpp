/*
=========================================================
LeetCode Problem #518

Problem Name : Coin Change II
Difficulty   : Medium

Problem Link:
https://leetcode.com/problems/coin-change-ii/

---------------------------------------------------------
Problem Summary

Given an integer amount and an array of distinct coins,
return the number of combinations that make up that amount.

---------------------------------------------------------
Approach

1. Use Recursion.
2. At each coin, we have two choices:
   - Include the current coin (stay at same index).
   - Exclude the current coin (move to next index).
3. If amount becomes 0, one valid combination is found.
4. If all coins are used and amount is still greater than 0,
   return 0.

---------------------------------------------------------
Time Complexity

Exponential (O(2^N)) due to recursion.

---------------------------------------------------------
Space Complexity

O(N) (Recursion Stack)

---------------------------------------------------------
Language

C++

=========================================================
*/

class Solution {
public:
    int solve(int amount, vector<int>& coins, int index) {
        // Base Case
        if (amount == 0) {
            return 1;
        }

        if (index >= coins.size()) {
            return 0;
        }

        // Include current coin
        int includeAns = 0;
        if (coins[index] <= amount) {
            includeAns = solve(amount - coins[index], coins, index);
        }

        // Exclude current coin
        int excludeAns = solve(amount, coins, index + 1);

        return includeAns + excludeAns;
    }

    int change(int amount, vector<int>& coins) {
        return solve(amount, coins, 0);
    }
};

/*
---------------------------------------------------------
Status

Accepted ✅

Solved By:
Saurabh Kumar Patel

Date:
03-07-2026
---------------------------------------------------------
*/
