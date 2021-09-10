int surfaceArea(vector<vector<int>> A) {    
    int answer = 0;
    int prev1 = 0;
    int prev2 = 0;
    int prev3 = 0;
    int prev4 = 0;
    
    int H = A.size();
    int W = A[0].size();
    
    for(int i=0; i<H; i++) {
        prev1 = 0;
        prev2 = 0;
        
        for(int j=0; j<W ;j++) {
            if(prev1 < A[i][j]) answer += (A[i][j]-prev1);
            if(prev2 < A[i][W-1-j]) answer += (A[i][W-1-j]-prev2);
            
            prev1 = A[i][j];
            prev2 = A[i][W-1-j];
        }
    }
    
    for(int i=0; i<W; i++) {
        prev3 = 0;
        prev4 = 0;
        
        for(int j=0; j<H ;j++) {
            if(prev3 < A[j][i]) answer += (A[j][i]-prev3);
            if(prev4 < A[H-1-j][i]) answer += (A[H-1-j][i]-prev4);

            prev3 = A[j][i];
            prev4 = A[H-1-j][i];
        }
    }
    
    answer += H*W*2;

    return answer;
}