#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int> (n,0));
        int x;
        int y;
        int startx=0;
        int starty=0;
        int offset=1;
        int loop=n/2;
        int count=1;
        int mid = n/2;
        while(loop--){//左闭右开
        x=startx;
        y=starty;
            //顶部填充
            for(y;y<n-offset;y++){
                matrix[x][y]=count++;
            }
            //右边
            for(x;x<n-offset;x++){
                matrix[x][y]=count++;
            }
            
            //下边
            for(y;y>starty;y--){
                matrix[x][y]=count++;
            }         
            //左边
            for(x;x>startx;x--){
                matrix[x][y]=count++;
            }
            startx++;
            starty++;
            offset++;
            
        }
        if(n%2!=0){
                matrix[mid][mid]=count++;
            }
        return matrix;
    }
};