#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 层序遍历
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // 初始化，找到所有腐烂橘子和新鲜,腐烂入队
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if(fresh==0)return 0;


        //阶段2：bfs遍历，分钟形式腐烂
        int minutes = 0;
        //定义方向数组
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(q.size()){
            bool rotted = false;//当前是否有腐烂的橘子
            int size = q.size();
            
            //开始腐化
            for(int k=0;k<size;k++){
                auto [i,j] = q.front();//拿到当前这一批腐烂的橘子的坐标
                q.pop();

                //这里开始传染
                for(auto& dir:dirs){
                    //计算被腐烂的橘子的坐标
                    int ni = i+dir[0];
                    int nj =j+dir[1];

                    //检查是否符合边界以及新鲜
                    if(ni>=0&&ni<m&&nj>=0&&nj<n&&grid[ni][nj]==1){
                        //对于处在范围内的进行腐化
                        grid[ni][nj]=2;
                        fresh--;
                        q.push({ni,nj});
                        rotted=true;
                    }
                }
            }
            if(rotted)minutes+=1;
        }
        return fresh==0?minutes:-1;
    }
};