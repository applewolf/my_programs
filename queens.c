#include <stdio.h>
#define N 8           // 定义棋盘的格数, 通过改变,也可以是4皇后, 16皇后, 9皇后什么的.
int chess[N][N] = {0}; // 棋盘
int count = 0; // 有多少种放法
int canput(int row, int col) // 确定某一格能不能放
{
int i,j;
for(i = 0; i < N; i ++)
{
   if(chess[i][col] == 1) //有 同列的
   {
    return 0;
   }
   for(j = 0; j < N; j++)
   {
    if(chess[row][j]==1) //有同行的
    {
     return 0;
    }
    if(((i-row)==(j-col)||(i-row)==(col-j))&&chess[i][j]==1) // 对角线上有的
    {
     return 0;
    }
   }
}
return 1;
}
void print_chess() // 打印放置的方案
{
int i, j;
for(i = 0; i < N; i++)
{
   for(j = 0; j < N; j++)
   {
    printf("%d ", chess[i][j]);
   }
   printf("\n");
}
printf("\n");
}
int put(int row)     // 放置棋子, row是从哪一行开始, 通常是0
{
int j, s;
for(j = 0; j < N; j++) // 此一行的每一个格子都要试试能不能放
{
   if(canput(row, j)) // 假如这格能放的话
   {
    chess[row][j] = 1; // 放置
    if(row == N-1) // 已经到了最后一行, 那么肯定成功******************************************************
    {
     count = count +1;
    print_chess();
     chess[row][j] = 0; //成功后, 寻找下一种方法
     continue;
    }
    s = put(row+1); // 放置下一行的
    if(s == 0)    // 假如下一行不能放
    {
     chess[row][j] = 0; // 那么这格是放错了的, 清除
     continue;           // 找本行的下一个方格
    }
    else
    {
     break;
    }   
   }
}
if(j==N)    // 如果这一行的每个空格都不能放置
{
   return 0; // 那么本行放置失败
}
else
{
   return 1; // 本行放置成功
}
}
int main()
{
int s ;
s = put(0); // 放置
printf("the number of put way is %d\n", count); //打印信息
return 0;
}
