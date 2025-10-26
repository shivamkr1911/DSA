#include <bits/stdc++.h>
using namespace std;

// Bank class simulating basic bank operations
class Bank
{
private:
    vector<long long> balance; // Stores balance of each account

    // Helper function to check if an account number is valid
    bool isValidAcc(int acc)
    {
        return acc >= 1 && acc <= balance.size();
    }

public:
    // Constructor initializes bank with account balances
    Bank(vector<long long> &balance)
    {
        this->balance = balance;
    }

    // Transfer money from account1 to account2
    bool transfer(int account1, int account2, long long money)
    {
        if (!isValidAcc(account1) || !isValidAcc(account2) || balance[account1 - 1] < money)
            return false;               // Invalid account or insufficient funds
        balance[account1 - 1] -= money; // Deduct from sender
        balance[account2 - 1] += money; // Add to receiver
        return true;                    // Transfer successful
    }

    // Deposit money into an account
    bool deposit(int account, long long money)
    {
        if (!isValidAcc(account))
            return false;              // Invalid account
        balance[account - 1] += money; // Add money
        return true;                   // Deposit successful
    }

    // Withdraw money from an account
    bool withdraw(int account, long long money)
    {
        if (!isValidAcc(account) || balance[account - 1] < money)
            return false;              // Invalid account or insufficient funds
        balance[account - 1] -= money; // Deduct money
        return true;                   // Withdrawal successful
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
