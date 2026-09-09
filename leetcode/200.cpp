#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    //用i和j来控制走向
    void dfs(vector<vector<char>>& grid,int i,int j){
        int m = grid.size();//行
        int n = grid[0].size(); //列

        //边界检查与判断是否为水
        if(i<0||i>=m||j>=n||j<0||grid[i][j]=='0'){
            return;
        }        

        //沉岛
        grid[i][j] = '0';

        //四个方向扩散遍历
        dfs(grid,i-1,j);//向左
        dfs(grid,i+1,j);//向右
        dfs(grid,i,j-1);//向上
        dfs(grid,i,j+1);//向下
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()||grid[0].empty())return 0;//如果是空的岛屿
        int m =grid.size();
        int n = grid[0].size();

        int count=0;

        //这里的双层循环用于寻找岛屿小格子，要不然只能在(0,0)徘徊
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};