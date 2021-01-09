#include<iostream>
#include<string>

/*
1531. 压缩字符串 II
行程长度编码 是一种常用的字符串压缩方法，它将连续的相同字符（重复 2 次或更多次）替换为字符和表示字符计数的数字（行程长度）。例如，用此方法压缩字符串 "aabccc" ，将 "aa" 替换为 "a2" ，"ccc" 替换为` "c3" 。因此压缩后的字符串变为 "a2bc3" 。

注意，本问题中，压缩时没有在单个字符后附加计数 '1' 。

给你一个字符串 s 和一个整数 k 。你需要从字符串 s 中删除最多 k 个字符，以使 s 的行程长度编码长度最小。

请你返回删除最多 k 个字符后，s 行程长度编码的最小长度 。

来源：力扣（LeetCode）
*/
using namespace std;

int result = INT_MAX;

char findChar(string& s)
{
    if(s.empty())
    {
        return ' ';
    }
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            return s[i];
        }
    }
    return ' ';
}

int findNumber(string& s)
{
    if(s.empty())
    {
        return 0;
    }

    if(s.back()>='a' && s.back()<='z')
    {
        return 1;
    }

    string str = "";
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            break;
        }
        str.insert(str.begin(), s[i]);
    }
    return atoi(str.c_str());
}

void findSolution(string& s, int index, int remainK, string compressStr)
{
    //cout<<compressStr<<endl;
    if(index == s.size())
    {
        //cout<<compressStr<<endl;
        int len = compressStr.size();
        result = min(result, len);
        return;
    }
    if(compressStr.size()>result)
    {
        return;
    }

    int nextCharIndex = index+1;
    while(nextCharIndex<s.size() && s[index] == s[nextCharIndex])
    {
        nextCharIndex++;
    }

    char cur = s[index];
    int curNumber = nextCharIndex-index;
    string temp = "";
    for(int i=0;i<=min(remainK, curNumber);i++)
    {
        temp = compressStr;
        int diff = curNumber - i;
        if(diff>0)
        {
            temp.insert(temp.end(), cur);
            if(diff>1)
            {
                temp += to_string(diff);
            }
        }
        findSolution(s, nextCharIndex, remainK-i, temp);

    }
    

}

//index每次只往前走一部，会导致大量重复计算
// void findSolution(string& s, int index, int remainK, string compressStr)
// {
//     //cout<<compressStr<<endl;
//     if(index == s.size())
//     {
//         //cout<<compressStr<<endl;
//         int len = compressStr.size();
//         result = min(result, len);
//         return;
//     }
//     if(compressStr.size()>result)
//     {
//         return;
//     }

//     char cur = s[index];
//     char pre = findChar(compressStr);
//     int number = findNumber(compressStr);

//     //删除cur
//     if(remainK>0)
//     {
//         findSolution(s, index+1, remainK-1, compressStr);
//     }

//     //保留cur
//     if(pre == ' ' || pre != cur)
//     {
//         compressStr.insert(compressStr.end(), cur);
//     }
//     else
//     {
//         if(number>1)
//         {
//             string numberStr = to_string(number);
//             compressStr.erase(compressStr.size()-numberStr.size(), numberStr.size());
//             //cout<<"1: "<<compressStr<<endl;
//         } 
//         string newNumberStr = to_string(number+1);
//         compressStr += newNumberStr; 
//         //cout<<"2: "<<compressStr<<endl;
//     }
//     findSolution(s, index+1, remainK, compressStr);

// }

int getLengthOfOptimalCompression(string s, int k) 
{
    findSolution(s, 0, k, "");
    return result;
}

int main()
{
    string s = "aaabcccd";
    int k = 2;
    // string s = "aaaaaaaaaaa";
    // int k = 0;
    cout<<getLengthOfOptimalCompression(s, k)<<endl;
    return 0;
}