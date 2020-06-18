#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int minTaps(int n, vector<int>& ranges) {
    //visited[i]表示第i个水龙头被访问过
    vector<bool> visited(n+1, false);
    //covered[j]表示点i被灌溉到过
    vector<bool> covered(n+1, false);

    //key为visited，value为covered
    map<vector<bool> , vector<bool> > record;
    int step = 0;

    while(step<=n+1){
        step++;
        //record初始化
        if(record.empty()){
            
            for(int i=0;i<=n;i++){
                //选一个点做第一个打开的水龙头
                vector<bool> initVisited(visited.begin(), visited.end());
                initVisited[i] = true;

                //更新灌溉到的点的vector
                vector<bool> initCovered(covered.begin(), covered.end());
                if(ranges[i] <= 0){
                    continue;
                }

                for(int j = i-ranges[i];j<=i+ranges[i];j++){
                    if(j>=0 && j<=n && initCovered[j] == false){
                        initCovered[j] = true;
                    }
                }
                //如果全部灌溉到了，终止
                if(find(initCovered.begin(), initCovered.end(), false) == initCovered.end()){
                    return step;
                }
                //未全部灌溉到，则放入map
                record.insert(make_pair(initVisited, initCovered));
            }
        }else{
            //bfs非初始化
            map<vector<bool>, vector<bool> >::iterator iter = record.begin();
            map<vector<bool>, vector<bool> > assistant;
            while(iter != record.end()){
            
                for(int i=0;i<=n;i++){
                    vector<bool> preVisited = iter->first;
                    vector<bool> preCovered = iter->second;

                    //选一个之前未访问到的水龙头
                    if(preVisited[i] == true){
                        continue;
                    }
                    preVisited[i] = true;

                    //如果该水龙头不能灌溉，则跳过
                    if(ranges[i] <= 0){
                        continue;
                    }

                    //该水龙头可以灌溉，则更新灌溉vector
                    for(int j = i-ranges[i];j<=i+ranges[i];j++){
                        if(j>=0 && j<=n && preCovered[j] == false){
                            preCovered[j] = true;
                        }
                    }

                    //全部点被灌溉到，则终止
                    if(find(preCovered.begin(), preCovered.end(), false) == preCovered.end()){
                        return step;
                    }
                    //还有点未被灌溉，继续执行
                    assistant.insert(make_pair(preVisited, preCovered));
                }
                //增加iter
                iter++;
            }
            //更新bfs的广度
            record = assistant;

        }
        
    }
    return -1;

}

//用于sort函数排序，先根据区间右端排序，再根据区间左端排序
static bool cmp(vector<int>& pre, vector<int>& next){
    return pre[1]<next[1] || (pre[1]==next[1] && pre[0]>next[0]);
}

int solution(int n, vector<vector<int> > intervals){

    //都已经被灌溉，返回0
    if(n == 0){
        return 0;
    }
    
    //点n无法被灌溉，返回-1
    int len = intervals.size();
    if(len == 0 || intervals[len-1][1] < n){
        return -1;
    }

    int left = intervals[len-1][0];
    int index = len-1;
    while(index>=0){
        //找出可以所有可以灌溉到点n的区间里，可以灌溉到的最左端点的索引
        if(intervals[index][1] >= n){
            if(intervals[index][0]<left){
                left = intervals[index][0];
            }
            index--;
        }else{
            break;
        }
    }

    vector<vector<int> > nextIntervals(intervals.begin(), intervals.begin() + index +1);

    int nextValue = solution(left, nextIntervals);
    //子迭代中有点无法被灌溉到，返回-1
    if(nextValue == -1){
        return -1;
    }
    //子迭代中所有点被灌溉到，返回nextValue+1
    return nextValue+1;
}
//贪心：每次选一个区间，区间右端可以覆盖当前需要覆盖的最右端，同时该区间能覆盖的最左侧点索引最小
int minTapsSec(int n, vector<int>& ranges) {
    vector<vector<int> > intervals;

    vector<int>::iterator iter = ranges.begin();
    while (iter != ranges.end())
    {
        //将可以喷水的水龙头可以灌溉的区域用区间表示
        if(*iter !=0){
            vector<int> internal(2, 0);
            int r= *iter;
            int center = iter-ranges.begin();
            //cout<<"center:"<<center<<" r:"<<r<<endl;
            internal[0] = max(center-r, 0);
            internal[1] = min(center+r, n);
            //cout<<"["<<internal[0]<<", "<<internal[1]<<"]"<<endl;
            intervals.push_back(internal);
        }
        iter++;
    
    }
    //将区间排序，先根据区间右端排序，再根据区间左端排序
    sort(intervals.begin(), intervals.end(), cmp);
    // cout<<"sort:"<<endl;
    // for(vector<vector<int> >::iterator i=intervals.begin();i!=intervals.end();i++){
    //     cout<<"["<<(*i)[0]<<" ,"<<(*i)[1]<<"]"<< endl;
    // }
    return solution(n, intervals);
}

//有点像投票：每个需要被灌溉的点，选取一个水龙头，该水龙头可以灌溉到该点，
//同时是所以可以灌溉到该点的水龙头中，右侧能覆盖到的点索引最大的水龙头
int minTapsThird(int n, vector<int>& ranges){
    vector<int> covered(n+1, 0);

    for(int i=0;i<=n;i++){
        if(ranges[i] == 0){
            continue;
        }

        int l=max(0, i-ranges[i]);
        int r=min(n, i+ranges[i]);

        for(int j=l;j<=r;j++){
            covered[j] = max(covered[j], r);
        }
    }

    int index = 0;
    int step = 0;
    while(index<=n){
        if(index == n){
            break;
        }
        //有点无法被灌溉
        if(covered[index] == 0 || (covered[index]<n && covered[covered[index]] == covered[index])){
            return -1;
        }
        index = covered[index];
        step++;
    }
    return step;
}

int main(){
    // int arr[] = {1,2,1,0,2,1,0,1};
    // int n =7;
    // vector<int> test(arr, arr+sizeof(arr)/sizeof(int));
    // cout<< minTapsSec(n, test) <<endl;
    // int arr[] = {2,0,0,0};
    // int n =3;
    // vector<int> test(arr, arr+sizeof(arr)/sizeof(int));
    // cout<< minTapsThird(n, test) <<endl;

    int arr[] = {1,0,4,0,4,1,4,3,1,1,1,2,1,4,0,3,0,3,0,3,0,5,3,0,0,1,2,1,2,4,3,0,1,0,5,2};
    int n =35;
    vector<int> test(arr, arr+sizeof(arr)/sizeof(int));
    cout<< minTapsThird(n, test) <<endl;

}