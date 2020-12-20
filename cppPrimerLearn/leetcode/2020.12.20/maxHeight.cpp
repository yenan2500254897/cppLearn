#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1691. 堆叠长方体的最大高度
给你 n 个长方体 cuboids ，其中第 i 个长方体的长宽高表示为 cuboids[i] = [widthi, lengthi, heighti]（下标从 0 开始）。请你从 cuboids 选出一个 子集 ，并将它们堆叠起来。

如果 widthi <= widthj 且 lengthi <= lengthj 且 heighti <= heightj ，你就可以将长方体 i 堆叠在长方体 j 上。你可以通过旋转把长方体的长宽高重新排列，以将它放在另一个长方体上。

返回 堆叠长方体 cuboids 可以得到的 最大高度 。

来源：力扣（LeetCode）
*/
int maxHeight(vector<vector<int>>& cuboids) {
    for(auto &item:cuboids)
    {
        sort(item.begin(), item.end());
    }

    sort(cuboids.begin(), cuboids.end(), [&](const auto &u, const auto &v)
    {
        return pair(u[2], u[0] + u[1]) < pair(v[2], v[0] + v[1]);
    });

    vector<int> result(cuboids.size(), 0);

    for(int j = 0;j<cuboids.size();j++)
    {
        for(int i=0;i<j;i++){
            if(cuboids[i][0] <= cuboids[j][0] && cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2])
            {
                result[j] = max(result[i], result[j]);
            }
        }
        result[j] += cuboids[j][2];
    }
    return *max_element(result.begin(), result.end());
}

int main()
{
    vector<vector<int>> test = {{50,45,20},{95,37,53},{45,23,12}};
    cout<<maxHeight(test)<<endl;
}