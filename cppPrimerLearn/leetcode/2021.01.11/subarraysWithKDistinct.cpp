#include<iostream>
#include<vector>
#include<map>
#include <cstring>

/*
992. K 个不同整数的子数组
给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。

（例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）

返回 A 中好子数组的数目。

来源：力扣（LeetCode）
思路：
1.用一个右侧递增的窗口[l...r]，当该窗口中的不同字符数等于K时，判断[l...r]中有多少个子数组[m, r]满足不同字符数等于K的条件
2.当该窗口中的不同字符数大于K时，窗口[l...r]的左端递增，直到最新的[newL, r]满足不同字符数等于K

优化：map频繁的插入和删除，可能会有扩缩容问题，导致超时，这里完全可以用一个数组记录数i的个数，diff记录不同的字符数。
*/
using namespace std;

int subarraysWithKDistinct(vector<int>& A, int K) 
{
    int len = A.size();
    int left = 0;
    int right = 0;
    int result = 0;
    int record[len+1];
    int temp[len+1];
    memset(record, 0, (len+1)*sizeof(int));
    memset(temp, 0, (len+1)*sizeof(int));

    int diff = 0;
    
    while(right<len)
    {
        if(right<len)
        {
            int rValue = A[right];
            if(record[rValue] == 0)
            {
                diff++;
            }
            record[rValue]++;
            right++;
        }

        if(diff>K)
        {
            while(diff!=K)
            {
                int value = A[left];
                record[value] -= 1;
                if(record[value] == 0)
                {
                    diff--;
                }
                left++;
            }
        }

        if(diff == K)
        {
            memcpy(temp, record, (len+1)*sizeof(int));
            int tempLeft = left;
            int tempDiff = diff;
            while(tempDiff == K)
            {
                if(tempDiff == K)
                {
                    result += 1;
                }
                int lValue = A[tempLeft];
                temp[lValue] -= 1;
                if(temp[lValue] == 0)
                {
                    tempDiff--;
                }
                tempLeft++;
            }
        }
        
    }
    return result;
    
}

int main()
{
    vector<int> A = {1,2,1,2,3};
    int K = 2;
    cout<<subarraysWithKDistinct(A, K)<<endl;
    return 0;
}