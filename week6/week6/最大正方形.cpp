#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:
    int maxedge = 0;  //最大边长

    void help(vector<vector<char>>& matrix,int x,int y){
        for(int edge = 1;edge <= 300;edge++){
            if(x + edge - 1 >= matrix.size() || y + edge - 1 >= matrix[0].size() ) return ; //边长越界直接减掉
            for(int i = 0;i < edge;i++){
                for(int j = 0;j <edge;j++){
                    if(matrix[x + i][y + j] == '0') return; //无法找到这个边长的正方形
                }
            }
            maxedge = max(maxedge,edge);    //到这了说明可以找到以edge为边的正方形，更新答案
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == '1'){  //往右下角开始找最大边长
                    help(matrix,i,j);
                }
                if(maxedge >= n - j) break; //后面的列已经没办法获得比现有最大边更大的边了
            }
            if(maxedge >= m - i ) break;    //后面的行已经没办法获得比现有最大边更大的边了
        }

        return maxedge * maxedge;
    }
};