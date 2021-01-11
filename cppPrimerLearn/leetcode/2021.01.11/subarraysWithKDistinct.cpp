#include<iostream>
#include<vector>
#include<map>

/*
992. K 个不同整数的子数组
给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。

（例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）

返回 A 中好子数组的数目。

来源：力扣（LeetCode）
思路：
1.用一个右侧递增的窗口[l...r]，当该窗口中的不同字符数等于K时，判断[l...r]中有多少个子数组[m, r]满足不同字符数等于K的条件
2.当该窗口中的不同字符数大于K时，窗口[l...r]的左端递增，直到最新的[newL, r]满足不同字符数等于K
*/
using namespace std;

int subarraysWithKDistinct(vector<int>& A, int K) 
{
    int len = A.size();
    int left = 0;
    int right = 0;
    int result = 0;
    map<int, int> record;
    map<int, int> temp;
    while(right<len)
    {
        if(right<len)
        {
            int rValue = A[right];
            if(record.count(rValue) == 0)
            {
                record[rValue] = 1;
            }
            else
            {
                record[rValue] += 1;
            }
            right++;
        }

        if(record.size()>K)
        {
            while(record.size()!=K)
            {
                int value = A[left];
                record[value] -= 1;
                if(record[value] == 0)
                {
                    record.erase(value);
                }
                left++;
            }
        }

        if(record.size() == K)
        {
            temp = record;
            int tempLeft = left;
            while(temp.size() == K)
            {
                if(temp.size() == K)
                {
                    result += 1;
                }
                int lValue = A[tempLeft];
                temp[lValue] -= 1;
                if(temp[lValue] == 0)
                {
                    temp.erase(lValue);
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