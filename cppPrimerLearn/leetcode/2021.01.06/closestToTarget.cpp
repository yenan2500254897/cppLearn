#include<iostream>
#include<vector>
#include<set>

/*
1521. 找到最接近目标值的函数值

Winston 构造了一个如上所示的函数 func 。他有一个整数数组 arr 和一个整数 target ，他想找到让 |func(arr, l, r) - target| 最小的 l 和 r 。

请你返回 |func(arr, l, r) - target| 的最小值。

请注意， func 的输入参数 l 和 r 需要满足 0 <= l, r < arr.length 。

来源：力扣（LeetCode）
*/
using namespace std;


int closestToTarget(vector<int>& arr, int target)
{
    int len = arr.size();
    //set<long> res;
    long retValue = LONG_MAX;
    for(int right = 0;right<len;right++)
    {
        for(int left = 0;left<=right;left++)
        {
            int result = arr[left];
            for(int k=left;k<=right;k++)
            {
                result &= arr[k];
            }
            if(abs(target-result)<retValue)
            {
                retValue = abs(target-result);
            }
            //res.insert(abs(target-result));
        }
    }
    // return *res.begin();
    return retValue;
}

int main()
{
    // vector<int> arr = {9,12,3,7,15};
    // int target = 5;
    vector<int> arr = {1000000,1000000,1000000};
    int target = 1;
    
    cout<<closestToTarget(arr, target)<<endl;
    return 0;
}