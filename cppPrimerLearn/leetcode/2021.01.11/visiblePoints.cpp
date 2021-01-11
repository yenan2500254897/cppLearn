#include<iostream>
#include<vector>
#include<math.h>
#include<iostream>
#include<algorithm>

/*
1610. 可见点的最大数目
给你一个点数组 points 和一个表示角度的整数 angle ，你的位置是 location ，其中 location = [posx, posy] 且 points[i] = [xi, yi] 都表示 X-Y 平面上的整数坐标。

最开始，你面向东方进行观测。你 不能 进行移动改变位置，但可以通过 自转 调整观测角度。换句话说，posx 和 posy 不能改变。你的视野范围的角度用 angle 表示， 这决定了你观测任意方向时可以多宽。设 d 为你逆时针自转旋转的度数，那么你的视野就是角度范围 [d - angle/2, d + angle/2] 所指示的那片区域。

来源：力扣（LeetCode）
思路：算出各个点相对于location的极坐标，然后排序，然后用一个滑动窗口求出窗口内的值之差小于angle的窗口的最大长度（固定窗口左边，右边增加，检查新加入的值是否满足要求）。
补充：
1、atan（x）表示求的是x的反正切，其返回值为[-pi/2,+pi/2]之间的一个数。
2、atan2（y，x）求的是y/x的反正切，其返回值为[-pi,+pi]之间的一个数。
3、需要dp中的每个值加上360且放入dp中。
*/
using namespace std;

int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) 
{
    int common = 0;
    double MY_PI = 3.1415926;
    vector<double> dp;
    for(int i=0;i<points.size();i++)
    {
        if(location[0] == points[i][0] && location[1] == points[i][1])
        {
            common++;
        }
        else
        {
            dp.push_back(atan2(points[i][1]-location[1], points[i][0]-location[0])*180/MY_PI);
        }
    }
    sort(dp.begin(), dp.end());
    int len = dp.size();
    for(int i=0;i<len;i++)
    {
        dp.emplace_back(dp[i]+360);
    }

    int right=0;
    int result = 0;
    for(int left = 0;left<len;left++)
    {
        while(right<dp.size() && dp[right] - dp[left] <= angle)
        {
            right++;
        }
        result = max(result, right-left);
    }
    return result+common;
}

int main()
{
    // vector<vector<int>> points = {{1,0},{2,1}};
    // int angle = 13;
    // vector<int> location = {1,1};
    vector<vector<int>> points = {{2,1},{2,2},{3,4},{1,1}};
    int angle = 90;
    vector<int> location = {1,1};
    cout<<visiblePoints(points, angle, location)<<endl;
    return 0;
}