#include<iostream>
#include<vector>
#include<math.h>
#include<array>

using namespace std;

int findSquare(int , int , int , int , vector<vector<int> >& );
bool isvalid(int , int , int , int ,vector<vector<int> >& );
int largest1BorderedSquare(vector<vector<int> >& );

int largest1BorderedSquare(vector<vector<int> >& grid) {

    int row = grid.size();
    int col = grid[0].size();

    int result = 0;
    for(int m=0;m<row;m++){
        for(int n=0;n<col;n++){
            if(grid[m][n] == 1){
                int squareSize = findSquare(m, n, row, col, grid);
                if(squareSize>result){
                    result = squareSize;
                }
            }
        }
    }
    return result;
}

int findSquare(int m, int n, int row, int col, vector<vector<int> >& grid){
    int len = min(row-m, col-n);
    int retLen = 1;
    for(int i=2;i<=len;i++){
        if(isvalid(m,n,m,n+i-1,grid) && isvalid(m,n+i-1,m+i-1,n+i-1,grid) 
        && isvalid(m+i-1,n,m+i-1,n+i-1,grid) && isvalid(m,n,m+i-1,n,grid) ){
            //cout<< "findSquare: " << " m: "<< m<<" n: "<<n<<" len: "<< i<< " success"<<endl;
            retLen = i;
        }else
        {
            //cout<< "findSquare: " << " m: "<< m<<" n: "<<n<<" len: "<< i<< " failed"<<endl;
        }
        
    }
    return retLen * retLen;
}

bool isvalid(int m, int n, int mEnd, int nEnd,vector<vector<int> >& grid){
    bool valid = true;

    if(m==mEnd){
        for(int i=n;i<=nEnd;i++){
            valid = valid && (grid[m][i]==1);
        }
    }else
    {
        for(int j=m;j<=mEnd;j++){
            valid = valid && (grid[j][n] == 1);
        }
    }

    //cout<<"m: "<< m << " n: "<< n << " mEnd: "<< mEnd<<" nEnd: "<< nEnd<< " valid: "<<valid <<endl;
    return valid;
}

int main(){
    int arr[3][3] = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int> > test ;
    for(int i=0;i<3;i++){
        vector<int> temp;
        for(int j=0;j<3;j++){
            temp.push_back(arr[i][j]);
        }
        test.push_back(temp);
    }
    int result = largest1BorderedSquare(test);
    cout<<result<<endl;
    return 0;

}