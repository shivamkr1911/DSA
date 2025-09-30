class Solution
{
public:
    int setBit(int n)
    {
        // Set the rightmost unset bit of n
        return n | (n + 1);
    }
};
