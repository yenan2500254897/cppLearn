#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mctFromLeafValues(vector<int>& arr) {

    int len = arr.size();

    if(len == 1 || len == 0){
        return 0;
    }

    if(len == 2){
        return arr[0] * arr[1];
    }

    int result = INT32_MAX;
    //根据索引i将arr分为左右两个部分
    for(int i=1;i<len;i++){
        
        vector<int> leftVector(arr.begin(), arr.begin()+i);
        vector<int> rightVector(arr.begin()+i, arr.end());
        //leftValue为左子树非叶子节点值的和
        int leftValue = mctFromLeafValues(leftVector);
        //rightValue为右子树非叶子结点值的和
        int rightValue = mctFromLeafValues(rightVector);

        //leftMaxLeafValue为左子树中最大的叶子节点的值
        int leftMaxLeafValue = *(max_element(leftVector.begin(), leftVector.end()));
        //rightMaxLeafValue为右子树中最大的叶子节点的值
        int rightMaxLeafValue = *(max_element(rightVector.begin(), rightVector.end()));
        result = result>leftValue+rightValue + leftMaxLeafValue*rightMaxLeafValue ? leftValue+rightValue + leftMaxLeafValue*rightMaxLeafValue : result ;
    }
    return result;
}

int solution(vector<int> arr, int left, int right, vector<vector<int> >& record){
    //左边界必须小于右边界
    if(left>=right){
        return 0;
    }
    //只有两个节点的情况
    if(left == right-1){
        record[left][right] = arr[left] * arr[right];
        return record[left][right];
    }

    //如果record[left][right]之前已经计算出结果，直接返回
    if(record[left][right] != 0){
        return record[left][right];
    }
    int result = INT32_MAX;
    //讲arr[left][right]再分为左右两个部分
    for(int i = right;i>left;i--){
        //record[i][right]之前未计算出来，则计算
        if(record[i][right] == 0){
            solution(arr, i, right, record);
        }
        //record[left][i-1]之前未计算出来，则计算
        if(record[left][i-1] == 0){
            solution(arr, left, i-1, record);
        }

        //leftMaxLeafValue为左子树中最大的叶子节点的值
        int leftMaxLeafValue = *(max_element(arr.begin()+left, arr.begin()+i));
        //rightMaxLeafValue为右子树中最大的叶子节点的值
        int rightMaxLeafValue = *(max_element(arr.begin()+i, arr.begin()+right+1));

        //更新result
        if(result > record[left][i-1] + record[i][right] + leftMaxLeafValue * rightMaxLeafValue){
            result = record[left][i-1] + record[i][right] + leftMaxLeafValue * rightMaxLeafValue;
        }
    }

    //记录record[left][right]的值
    record[left][right] = result;
    return record[left][right];
}

int mctFromLeafValuesSec(vector<int>& arr){
    int len = arr.size();
    if(len == 2){
        return arr[0]*arr[1];
    }

    vector<vector<int> > record(len, vector<int>(len, 0));
    //vector[i][j]记录arr[i][j]的最小的非叶子节点之和
    return solution(arr, 0, len-1, record);
}


int main(){
    vector<int> vec(5);
    vec[0] = 15;
    vec[1] = 13;
    vec[2] = 5;
    vec[3] = 3;
    vec[4] = 15;
    int result = mctFromLeafValuesSec(vec);
    cout<<result<<endl;
    return 0;
}