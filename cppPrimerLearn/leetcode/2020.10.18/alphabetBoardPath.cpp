#include<iostream>
#include<map>
/*
1138. 字母板上的路径
我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。

在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]，如下所示。
我们可以按下面的指令规则行动：

如果方格存在，'U' 意味着将我们的位置上移一行；
如果方格存在，'D' 意味着将我们的位置下移一行；
如果方格存在，'L' 意味着将我们的位置左移一列；
如果方格存在，'R' 意味着将我们的位置右移一列；
'!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。
（注意，字母板上只存在有字母的位置。）

返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。
来源：力扣（LeetCode）
*/
using namespace std;

string findPath(char source, char target)
{
    if(source == target){
        return "";
    }
    if(source == 'z')
    {
        return "U"+findPath('u', target);
    }
    if(target == 'z')
    {
        return findPath(source, 'u') + "D";
    }
    int number1 = source - 'a';
    int number2 = target - 'a';
    int r1, c1, r2, c2;
    r1 = number1/5;
    c1 = number1%5;
    r2 = number2/5;
    c2 = number2%5;

    string result = "";
    if(r1>r2){
        result.append(r1-r2, 'U');
    }
    if(r1<r2){
        result.append(r2-r1, 'D');
    }

    if(c1>c2){
        result.append(c1-c2, 'L');
    }
    if(c1<c2){
        result.append(c2-c1, 'R');
    }
    
    return result;
}
string alphabetBoardPath(string target) {
    string result = "";
    char s = 'a';
    char t = target[0];
    result += findPath(s, t);
    result += "!";
    for(int i=1;i<target.size();i++){
        s = t;
        t = target[i];
        result += findPath(s, t);
        result += "!";
    }
    return result;
}

int main(){
    string test = "zz";
    cout<<alphabetBoardPath(test)<<endl;
    return 0;
}