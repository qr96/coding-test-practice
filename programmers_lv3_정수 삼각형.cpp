#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[500][500] = {};
    
    int height = triangle.size();
    
    dp[0][0] = triangle[0][0];
    
    for(int i=1;i<height;i++){
        dp[i][0]=dp[i-1][0]+triangle[i][0];
        for(int j=1;j<i;j++){
            if(dp[i-1][j-1] > dp[i-1][j]){
                dp[i][j]=dp[i-1][j-1]+triangle[i][j];
            }
            else{
               dp[i][j]=dp[i-1][j]+triangle[i][j]; 
            }
        }
        dp[i][i]=dp[i-1][i-1]+triangle[i][i];
    }
    
    int max=0;
    
    for(int i=0;i<height;i++){
        if(max<dp[height-1][i]) max=dp[height-1][i];
    }
    
    answer=max;
    //answer=dp[4][0];
    return answer;
}