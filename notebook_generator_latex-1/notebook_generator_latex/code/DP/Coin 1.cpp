/*GReturn the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.*/
int coinChange(vector<int> &coins, int amount)
{
    if (amount < 1)
        return 0;
    vector<int> minCoinsDP(amount + 1, INT_MAX);
    minCoinsDP[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i && minCoinsDP[i - coin] != INT_MAX)
            {
                minCoinsDP[i] = min(minCoinsDP[i], 1 + minCoinsDP[i - coin]);
            }
        }
    }
    if (minCoinsDP[amount] == INT_MAX)
    {
        return -1;
    }
    return minCoinsDP[amount];
}