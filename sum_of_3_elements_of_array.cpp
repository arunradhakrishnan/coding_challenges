#include <iostream>
 
 

// NOTE THE WAY 3 SUM IS CALCULATED...!! 

// i , left, right

 
 int threeSumClosest(vector<int>& nums, int target) {


    sort(nums.begin(),nums.end());

    int closestSum = nums[0] + nums[1] + nums[2];

    for(int i = 0; i < nums.size()-2; i++)
    {
        int left = i + 1;//------------------>Note this
        int right = nums.size() - 1;//------------------>Note this
        

        while(left < right)
        {
        int currentsum =  nums[i] + nums[left] + nums[right];

        if(abs(currentsum - target) < abs(closestSum - target))
        {
            closestSum = currentsum;
        }

        if(currentsum < target)
        {
            left++;
        }
        else if(currentsum > target)
        {
            right--;
        }
        else // currentsum == target
        {
            return currentsum;
        }

        }

    }

return closestSum;

    }
