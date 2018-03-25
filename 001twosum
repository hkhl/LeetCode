/*************************************************************************
	> File Name: twosum.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月25日 星期日 15时01分14秒
 ************************************************************************/

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/



int* twoSum(int* nums, int numsSize, int target) {
    
    int *arrtwo = (int *)malloc(sizeof(int) * 2);
    for(int i = 0; i < numsSize - 1; i++){
        for(int j = i+1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                arrtwo[0] = i;
                arrtwo[1] = j;
                return arrtwo;
            }
        }
    }
    return NULL;
}
