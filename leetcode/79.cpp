#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    int m,n;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    bool backtrack(vector<vector<char>>& board,string& word,int i,int j,int k){
        //结束条件：所有字符都匹配完成
        if(k==word.size()){
            return true;
        }

        //剪枝
        if(i<0||i>=m||j<0||j>=n||board[i][j]!=word[k]){
            return false;
        }

        //做选择
        char tmp = board[i][j];//存储原来的值
        board[i][j] = '#';//标记已经读取过了

        //递归，尝试四个方向继续
        for(auto& dir:dirs){
            int ni=i+dir[0];
            int nj=j+dir[1];
            if(backtrack(board,word,ni,nj,k+1)){
                return true;
            }
        }

        board[i][j]=tmp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(backtrack(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};