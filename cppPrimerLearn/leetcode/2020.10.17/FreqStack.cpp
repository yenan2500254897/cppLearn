#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
/*
895. 最大频率栈
实现 FreqStack，模拟类似栈的数据结构的操作的一个类。

FreqStack 有两个函数：

push(int x)，将整数 x 推入栈中。
pop()，它移除并返回栈中出现最频繁的元素。
如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。

来源：力扣（LeetCode）
 * /
class FreqStack {
    public:
        vector<int> data;
        map<int, set<int> > record;
        map<int, int> exist;
        
    FreqStack() {
        
    }

    void push(int x) {
        int number = 0;
        if(exist.count(x)>0){
            number = exist[x];
            exist[x] = number+1;
            record[number].erase(x);
            record[number+1].insert(x);
        }else{
            exist[x] = 1;
            number += 1;
            record[number].insert(x);
        }
        data.push_back(x);
    }

    int pop() {
        auto iter = record.end();
        iter--;
        int result = 0;
        for(int i=data.size()-1;i>=0;i--){
            if(iter->second.count(data[i])>0){
                result = data[i];
                record[exist[result]].erase(result);
                record[exist[result]-1].insert(result);
                
                if(record[exist[result]].empty()){
                    record.erase(exist[result]);
                }
                exist[result] -= 1;
                if(exist[result] == 0){
                    exist.erase(result);
                }
                data.erase(data.begin()+i);
                break;
            }
        }
        return result;
    }
};

int main(){
    FreqStack *test = new FreqStack();
    test->push(5);
    test->push(7);
    test->push(5);
    test->push(7);
    test->push(4);
    test->push(5);
    cout<<test->pop()<<endl;
    cout<<test->pop()<<endl;
    cout<<test->pop()<<endl;
    cout<<test->pop()<<endl;
    
}