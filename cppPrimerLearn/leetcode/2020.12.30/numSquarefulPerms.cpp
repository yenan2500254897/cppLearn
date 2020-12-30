#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>

/*
996. 正方形数组的数目
给定一个非负整数数组 A，如果该数组每对相邻元素之和是一个完全平方数，则称这一数组为正方形数组。

返回 A 的正方形排列的数目。两个排列 A1 和 A2 不同的充要条件是存在某个索引 i，使得 A1[i] != A2[i]。

来源：力扣（LeetCode）

思路：
1.参考不带重复的全排列的做法，求出所有的排列可能
2.剪枝：如果交换A[i]和A[j]后，破坏了A[i-1]和A[i]的关系的话，拒绝交换交换A[i]和A[j]
3.记录A的索引为i的位置当前已经放过哪些值时，用vector存在形参复制问题，导致内存用的过多，改用map。具体见31行和54行。
*/
using namespace std;

bool isValid(int pre, int next)
{
    int total = pre+next;
    int value = sqrt(total);
    return total == pow(value, 2);
}
map<int, set<int>> visited;
//用向量记录input的第k个位置放过哪些值时，可能会导致复制代价太大
// void dfs(vector<int>& input, int left, int& result, vector<vector<bool>> visited)
void dfs(vector<int>& input, int left, int& result)
{
    if(left == input.size()-1)
    {
        for(int i=0;i<input.size();i++)
        {
            if(i-1>=0 && !isValid(input[i-1], input[i]))
            {
                return;
            }
        }
        // for(auto item:input)
        // {
        //     cout<<item<<" ";
        // }
        // cout<<endl;
        result++;
        return;
    }
    
    for(int right = left;right<input.size();right++)
    {
        //if(left == right || (input[left] != input[right] && visited[left][input[right]]==false))
        if(left == right || (input[left] != input[right] && visited[left].count(input[right])==0))
        {
            visited[left].insert(input[right]);
            int temp = input[left];
            input[left] = input[right];
            input[right] = temp;
            if(left-1<0 || isValid(input[left-1], input[left]))
            {
                // dfs(input, left+1, result, visited);
                dfs(input, left+1, result);
            }
            temp = input[left];
            input[left] = input[right];
            input[right] = temp;
        }
    }
    visited.erase(left);
    return ;
}
int numSquarefulPerms(vector<int>& A) 
{
    sort(A.begin(), A.end());
    int len = A.size();
    //vector<vector<bool>> visited(len, vector<bool>(A.back()+1, false));
    int result = 0;
    dfs(A, 0, result);
    return result;
    
}

int main()
{
    vector<int> input = {1,17,8};
    //vector<int> input = {1,1,8,1,8};
    //vector<int> input = {948507270,461613425};
    cout<<numSquarefulPerms(input)<<endl;

}