/*************************************************************************
	> File Name: 027RemoveElement.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月27日 星期二 16时47分39秒
 ************************************************************************/

#include <stdio.h>
/*Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

    Given nums = [3,2,2,3], val = 3,

    Your function should return length = 2, with the first two elements of nums being 2.
*/

int removeElement(int* nums, int numsSize, int val) {
    int i=0;
    for(int j = 0; j < numsSize; j++)
    {
        if(nums[j]!=val)
        {
            nums[i]=nums[j];
            i++;
        }
    }
    return i;
}

int main()
{
    int a[4] = {3,2,2,3};
    int ret = removeElement(a, 4, 3);

    return 0;
}
