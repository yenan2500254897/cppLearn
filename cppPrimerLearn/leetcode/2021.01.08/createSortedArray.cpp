#include<iostream>
#include<vector>
#include<set>
#include<map>

/*
1649. 通过指令创建有序数组
给你一个整数数组 instructions ，你需要根据 instructions 中的元素创建一个有序数组。一开始你有一个空的数组 nums ，你需要 从左到右 遍历 instructions 中的元素，将它们依次插入 nums 数组中。每一次插入操作的 代价 是以下两者的 较小值 ：

nums 中 严格小于  instructions[i] 的数字数目。
nums 中 严格大于  instructions[i] 的数字数目。
比方说，如果要将 3 插入到 nums = [1,2,3,5] ，那么插入操作的 代价 为 min(2, 1) (元素 1 和  2 小于 3 ，元素 5 大于 3 ），插入后 nums 变成 [1,2,3,3,5] 。

请你返回将 instructions 中所有元素依次插入 nums 后的 总最小代价 。由于答案会很大，请将它对 109 + 7 取余 后返回。

来源：力扣（LeetCode）
思路：区间树
先用set求出instructions中各个唯一数，且对他们排好顺序。
用input[i]表示set中第i个数number的个数，通过query(input, i-1)求出当前小于number的数的个数，用query(input, set.size()) - query(input, i)表示当前大于number的数的个数。
*/
using namespace std;

long query(vector<long>& input, int index)
{
    long result = 0;
    while(index>0)
    {
        result += input[index];
        index -= (index & -index);
    }
    return result;
}

void update(vector<long>& input, int index, int value)
{
    while (index<input.size())
    {
        input[index] += value;
        index += (index & -index);
    }
}

int createSortedArray(vector<int>& instructions) 
{
    set<int> tempSet;
    tempSet.insert(instructions.begin(), instructions.end());
    int index = 1;
    map<int,int> assistant;
    for(auto item:tempSet)
    {
        assistant[item] = index;
        index++;
    }

    vector<long> input(tempSet.size()+1, 0);

    long cost = 0;
    for(int i=0;i<instructions.size();i++)
    {
        int value = instructions[i];
        int valueIndex = assistant[value];
        
        int total = query(input, input.size()-1);
        int left = valueIndex-1==0?0:query(input, valueIndex-1);
        int right = total - query(input, valueIndex);

        cost += min(left, right);
        update(input, valueIndex, 1);
    }
    int mod = 1000000007;
    return cost%mod;
}

int main()
{
    //vector<int> instructions = {1,5,6,2};
    //vector<int> instructions = {1,2,3,6,5,4};
    vector<int> instructions = {1,3,3,3,2,4,2,1,2};
    
    cout<<createSortedArray(instructions)<<endl;
    return 0;
}