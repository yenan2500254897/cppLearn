#include<iostream>
#include<vector>

/*
1541. 平衡括号字符串的最少插入次数
给你一个括号字符串 s ，它只包含字符 '(' 和 ')' 。一个括号字符串被称为平衡的当它满足：

任何左括号 '(' 必须对应两个连续的右括号 '))' 。
左括号 '(' 必须在对应的连续两个右括号 '))' 之前。
比方说 "())"， "())(())))" 和 "(())())))" 都是平衡的， ")()"， "()))" 和 "(()))" 都是不平衡的。

你可以在任意位置插入字符 '(' 和 ')' 使字符串平衡。

请你返回让 s 平衡的最少插入次数。

来源：力扣（LeetCode）
*/
using namespace std;

int minInsertions(string s) {
    int len = s.size();

    vector<char> assistant;
    int step = 0;
    for(int i=0;i<len;i++){
        char cur = s[i];
        //遇见左括号直接放入
        if('(' == cur){
            assistant.push_back(cur);
        }
        //遇见右括号，往前找匹配的左括号，往后找紧邻的右括号
        if(')' == cur){
            if(!assistant.empty()){
                assistant.pop_back();
            }else{
                step++;
            }

            if(i+1<len && s[i+1] == ')'){
                i++;
            }else{
                step++;
            }
        }
    }

    //还有多余的未匹配的左括号，加上两倍数量的右括号
    step += 2*assistant.size();
    return step;
}

int main(){
    // string test = "(()))";
    string test = ")))))))";
    cout<<minInsertions(test)<<endl;
}