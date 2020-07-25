#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;
int main(){
    int a[] = {1,2,3};
    //不能用+连接字符串和数字
    std::cout<<"a[] size is: " << sizeof(a)/sizeof(*a)<<std::endl; 
    std::cout<<"hello world"<<std::endl;

    vector<int> test ;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    
    sort(test.begin(), test.end());

    for(int item:test){
        cout<<" "<<item<<" ";
    }

    cout<<endl;

    unique(test.begin(), test.end());

    for(vector<int>::iterator iter = test.begin();iter!=test.end();iter++){
        cout<<" "<< *iter<<" ";
    }

    cout<<endl;

}