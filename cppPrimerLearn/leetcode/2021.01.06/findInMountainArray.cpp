#include<iostream>
#include<vector>

/*
1095. 山脉数组中查找目标值
（这是一个 交互式问题 ）

给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。

如果不存在这样的下标 index，就请返回 -1。

 

何为山脉数组？如果数组 A 是一个山脉数组的话，那它满足如下条件：

首先，A.length >= 3

其次，在 0 < i < A.length - 1 条件下，存在 i 使得：

A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
 

你将 不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：

MountainArray.get(k) - 会返回数组中索引为k 的元素（下标从 0 开始）
MountainArray.length() - 会返回该数组的长度
 

注意：

对 MountainArray.get 发起超过 100 次调用的提交将被视为错误答案。此外，任何试图规避判题系统的解决方案都将会导致比赛资格被取消。

为了帮助大家更好地理解交互式问题，我们准备了一个样例 “答案”：https://leetcode-cn.com/playground/RKhe3ave，请注意这 不是一个正确答案。

 

来源：力扣（LeetCode）
*/
using namespace std;
class MountainArray 
{
public:
    int get(int index)
    {
        return arr[index];
    };
    int length()
    {
        return arr.size();
    };
    MountainArray();
    vector<int> arr;
};

MountainArray::MountainArray()
{

}
int maxIndex = -1;
int maxValue = -1;
int findSolution(int target, int left, int right, MountainArray &mountainArr)
{
    //比最大值小
    int leftValue = mountainArr.get(left);
    int rightValue = mountainArr.get(right);
    //等于左端点值
    if(target == leftValue)
    {
        //cout<<"case2:  left:= "<<left<<"  right:="<<right<<"  result:="<<left<<endl;
        return left;
    }
    //区间就两个点的情况
    if(right-left==1)
    {
        //cout<<"case4:  left:= "<<left<<"  right:="<<right<<"  result:="<<-1<<endl;
        return rightValue==target?right:-1;
    }
    //target不在该区间
    if(leftValue>target && rightValue>target)
    {
        //cout<<"case5:  left:= "<<left<<"  right:="<<right<<"  result:="<<-1<<endl;
        return -1;
    }

    //target在该区间
    int result = -1;
    //最大值位于该区间
    if(left<maxIndex && maxIndex<right)
    {
        result = findSolution(target, left, maxIndex, mountainArr);
        if(result == -1)
        {
            result = findSolution(target, maxIndex, right, mountainArr);
        }
        //cout<<"case6:  left:= "<<left<<"  right:="<<right<<"  result:="<<result<<endl;
        return result;
    }
    
    //该区间位于最大值一侧
    int mid = (left+right)/2;
    int midValue = mountainArr.get(mid);
    if(midValue == target)
    {
        //cout<<"case7:  left:= "<<left<<"  right:="<<right<<"  result:="<<mid<<endl;
        return mid;
    }
    else if(midValue<target)
    {
        if(leftValue<rightValue)
        {
            result = findSolution(target, mid, right, mountainArr);
        }
        if(leftValue>rightValue)
        {
            result = findSolution(target, left, mid, mountainArr);
        }
    }
    else if(midValue>target)
    {
        if(leftValue<rightValue)
        {
            result = findSolution(target, left, mid, mountainArr);
        }
        if(leftValue>rightValue)
        {
            result = findSolution(target, mid, right, mountainArr);
        }
    }
    //cout<<"case8:  left:= "<<left<<"  right:="<<right<<"  result:="<<result<<endl;
    return result;
    
}


void findMax(int target, int left, int right, MountainArray &mountainArr)
{
    int mid = (left+right)/2;
    int midValue = mountainArr.get(mid);
    int leftValue = mountainArr.get(mid-1);
    int rightValue = mountainArr.get(mid+1);
    if(midValue>leftValue && midValue>rightValue)
    {
        maxIndex = mid;
        maxValue = midValue;
        return ;
    }
    else if(leftValue<midValue && midValue<rightValue)
    {
        return findMax(target, mid, right, mountainArr);
    }
    else if(leftValue>midValue && midValue>rightValue)
    {
        return findMax(target, left, mid, mountainArr);
    }
    
    return ;
}
int findInMountainArray(int target, MountainArray &mountainArr) {
    int leftIndex = 0;
    int rightIndex = mountainArr.length()-1;
    findMax(target, leftIndex, rightIndex, mountainArr);
    //比最大值大
    if(target>maxValue)
    {
        cout<<"case0:  left:= "<<left<<"  right:="<<right<<"  result:="<<-1<<endl;
        return -1;
    }
    //等于最大值
    if(target == maxValue)
    {
        //cout<<"case1:  left:= "<<left<<"  right:="<<right<<"  result:="<<maxIndex<<endl;
        return maxIndex;
    }
    //cout<<"maxIndex :="<<maxIndex<<"   maxValue :="<<maxValue<<endl;
    return findSolution(target, leftIndex, rightIndex, mountainArr);
}

int main()
{
    // vector<int> arr = {1,2,3,4,5,3,1};
    // int target = 3;
    // vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2};
    // int target = 22;
    vector<int> arr = {3,5,3,2,0};
    int target = 2;

    MountainArray MArray;
    MArray.arr = arr;
    cout<<findInMountainArray(target, MArray)<<endl;
    return 0;
}