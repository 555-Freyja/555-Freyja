#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        vector<vector<int>>dp(grid.size(),vector(grid[0].size(),0));//建立dp二维数组
        dp[0][0]=grid[0][0];//初始化第一个元素
        for(int i=1;i<grid.size();i++)//为dp数组的第一行元素赋值
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int j=1;j<grid[0].size();j++)//为dp数组的第一列元素赋值
        {
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for(int i=0;i<grid.size();i++)//为dp数组非首行非首列元素赋值
        {
            for(int j=0;j<grid[i].size();j++)
            {
            //对于非首行非首列元素，其值等于其左边或上面元素的较小者与grid原数组对应位置的和
                if(i>0&&j>0)
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
                }
            }
        }
        //最后输出右下角元素即可
        return dp[grid.size()-1][grid[0].size()-1];
    }
};