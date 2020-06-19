#include<iostream>
#include<vector>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    if(bills.size() == 0){
        return true;
    }

    vector<int>::iterator iter = bills.begin();
    //记录手中5元和10元的个数
    vector<int> changes(11, 0);
    while(iter != bills.end()){
        int currentMoney = *iter;
        switch (currentMoney)
        {
            //五元直接手下
        case 5:
            changes[5]+=1;
            break;
            //10元：手上是否有5元找零
        case 10:
            if(changes[5]>0){
                changes[5] -=1;
                changes[10] +=1;
            }else{
                return false;
            }
            break;
            //20元：优先10+5找零；其次5+5+5找零
        case 20:
            if(changes[10]>0 && changes[5]>0){
                changes[10]-=1;
                changes[5]-=1;

            }else if(changes[5]>=3){
                changes[5]-=3;
            }else
            {
                return false;
            }
            break;
            
        }
        //迭代器自增
        iter++;
    }
    return true;
}

int main(){
     int arr[] = {5,5,10};
    // int arr[] = {5,5,10,10,20};
    vector<int> test(arr, arr+sizeof(arr)/sizeof(int));
    cout<<"result:"<<lemonadeChange(test)<<endl;
}