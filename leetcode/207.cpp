#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> g;//邻接表
    vector<int> colors;//0,1,2分别表示没访问过，正在访问，没问题

    //返回true则表示从x出发，最后找到了环
    bool dfs(int x){
        colors[x] = 1;

        for(auto& y:g[x]){
            if(colors[y]==1){
                return true;
            }

            //没访问过的就继续递归往下
            if(colors[y] == 0 &&dfs(y)){
                return true;
            }
        }
        colors[x] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //有向图寻找环

        //建图
        g.assign(numCourses,vector<int>());
        for(auto& p:prerequisites){
            g[p[1]].push_back(p[0]);
        }
        colors.assign(numCourses,0);

        //对于每一个未访问的节点进行深度遍历
        for(int i=0;i<numCourses;i++){
            if(colors[i]==0&&dfs(i)){
                return false;
            }
        }
        return true;
    }
};