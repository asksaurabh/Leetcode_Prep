// T.C -> O(n)
int findMinimumCoins(int amount)
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = coins.size();

    int minCoins = 0;
    int remainingAmount = amount - 0;
    for (int i = n - 1; i >= 0; i--) {
        if (coins[i] > remainingAmount) continue;

        // If Can't make direct change
        if (remainingAmount % coins[i] != 0) {
            int changeCurrCoinCanMake = (remainingAmount / coins[i]) * coins[i];
            minCoins += remainingAmount / coins[i];
            remainingAmount -= changeCurrCoinCanMake;
        }

        // Can make direct change
        if (remainingAmount % coins[i] == 0) {
            minCoins += remainingAmount / coins[i];
            break;
        }
    }

    return minCoins;
}
