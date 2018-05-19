
/*
 *Write an algorithm to determine if a number is "happy".
 *
 *A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 *Example:
 *
 *Input: 19
 *Output: true
 *Explanation:
 *12 + 92 = 82
 *82 + 22 = 68
 *62 + 82 = 100
 *12 + 02 + 02 = 1
 */

class Solution {
public:
    //1.根据输入的数字计算平方之和
    //2.求出结果重复步骤1
    //3.最后得到1 为happy number
    bool isHappy(int n)
    {
        int res;

        int x = 10;
        while(x)
        {
            res = 0;
            while(n)
            {
                res = res + (n%10) * (n%10);
                n /= 10;
            }
            if(res == 1)
                return true;
            n = res;
            x--;
        }
        return false;
    }


//弗洛伊德周期检测算法   慢快快  3个指针
    /*
I see the majority of those posts use hashset to record values. Actually, we can simply adapt the Floyd Cycle detection algorithm. I believe that many people have seen this in the Linked List Cycle detection problem. The following is my code:

int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;*/




    /*  map解法， 当遇到重复的值， 说明无线循环 退出
    bool isHappy(int n) {
        map<int, int> M;
        int len = 0;
        while(n != 1){
            if(M.find(n)!= M.end()){
                return false;
            }else{
                int sum = 0;
                while(n != 0){
                    sum = sum + (n%10) * (n %10);
                    n = n / 10;
                }
                M[len++] = sum;
                n = sum;
            }
        }
        return true;
    }
    */





};
