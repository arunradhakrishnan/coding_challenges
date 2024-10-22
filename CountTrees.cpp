

int countTrees(int n)
{
    if(n<=1) 
        return 1;
    else
    {
        int sum =0;
        for(int i = 1; i <= n; i++)
        {
            int left = countTrees(i - 1);
            int right = countTrees(n - i);
            sum += left*right;
        }
        return sum;
    }
}