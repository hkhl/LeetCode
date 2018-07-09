/*
 *We are playing the Guess Game. The game is as follows:
 *
 *I pick a number from 1 to n. You have to guess which number I picked.
 *
 *Every time you guess wrong, I'll tell you whether the number is higher or lower.
 *
 *You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
 *
 *-1 : My number is lower
 * 1 : My number is higher
 * 0 : Congrats! You got it!
 *Example:
 *n = 10, I pick 6.
 *
 *Return 6.
 */



// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:

    int twoFind(int left, int right)
    {
        if (left <= right)
        {
            //int mid = (left + right) / 2;  //溢出问题
            int mid = left + (right - left) / 2;
            if (guess(mid) == -1)
            {
                return twoFind(left, mid-1);
            }
            else if (guess(mid) == 1)
            {
                return twoFind(mid+1, right);
            }
            else
            {
                return mid;
            }
        }
    }

    int guessNumber(int n)
    {
       return twoFind(1, n);
    }
};
