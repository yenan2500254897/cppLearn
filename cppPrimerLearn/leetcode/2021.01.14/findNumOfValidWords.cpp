#include<iostream>
#include<string>
#include<vector>

/*
1178. 猜字谜
外国友人仿照中国字谜设计了一个英文版猜字谜小游戏，请你来猜猜看吧。

字谜的迷面 puzzle 按字符串形式给出，如果一个单词 word 符合下面两个条件，那么它就可以算作谜底：

单词 word 中包含谜面 puzzle 的第一个字母。
单词 word 中的每一个字母都可以在谜面 puzzle 中找到。
例如，如果字谜的谜面是 "abcdefg"，那么可以作为谜底的单词有 "faced", "cabbage", 和 "baggage"；而 "beefed"（不含字母 "a"）以及 "based"（其中的 "s" 没有出现在谜面中）。
返回一个答案数组 answer，数组中的每个元素 answer[i] 是在给出的单词列表 words 中可以作为字谜迷面 puzzles[i] 所对应的谜底的单词数目。

来源：力扣（LeetCode）
思路：将word和puzzles都转换为整数number， number的二进制中的第i位（从右往左）表示'a'+i是否存在，然后两个判断条件用位与即可判断。
*/
using namespace std;
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) 
{
    vector<int> transferWords(words.size(), 0);
    vector<int> transferPuzzles(puzzles.size(), 0);
    vector<int> firstCharacter(puzzles.size(), 0);

    int index = 0;
    int temp = 0;
    for(string item:words)
    {
        for(char ch:item)
        {
            temp |= (1<<(ch-'a'));
        }
        transferWords[index] = temp;
        index++;
        temp = 0;
    }

    index = 0;
    temp = 0;
    for(string item:puzzles)
    {
        for(char ch:item)
        {
            temp |= (1<<(ch-'a'));
        }
        transferPuzzles[index] = temp;
        firstCharacter[index] = (1<<(item[0]-'a'));
        index++;
        temp = 0;
    }

    vector<int> result(puzzles.size(), 0);
    for(int i=0;i<puzzles.size();i++)
    {
        for(int j=0;j<words.size();j++)
        {
            if((transferWords[j] & firstCharacter[i])!=0
            && (transferWords[j] & transferPuzzles[i]) == transferWords[j])
            {
                result[i]++;
            }
        }
    }
    return result;
}

int main()
{
    vector<string> words = {"aaaa","asas","able","ability","actt","actor","access"}; 
    vector<string> puzzles = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    vector<int> result = findNumOfValidWords(words, puzzles);
    for(auto item:result)
    {
        cout<<item<<" ";
    }
    cout<<endl;
    return 0;
}