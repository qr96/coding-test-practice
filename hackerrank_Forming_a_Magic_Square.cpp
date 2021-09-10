int formingMagicSquare(vector<vector<int>> s) {
    int ms[8][3][3] = {{{8, 3, 4},
                     {1, 5, 9},
                     {6, 7, 2}},
                     {{4, 9, 2},
                      {3, 5, 7},
                      {8, 1, 6}},
                     {{2, 7, 6},
                      {9, 5, 1},
                      {4, 3, 8}},
                     {{6, 1, 8},
                      {7, 5, 3},
                      {2, 9, 4}},
                    {{4, 3, 8},
                     {9, 5, 1},
                     {2, 7, 6}},
                    {{2, 9, 4},
                      {7, 5, 3},
                      {6, 1, 8}},
                     {{6, 7, 2},
                      {1, 5, 9},
                      {8, 3, 4}},
                     {{8, 1, 6},
                      {3, 5, 7},
                      {4, 9, 2}}};
                     
    int answer = 1000;
    int sum = 0;
    
    for(int t=0; t<8; t++) {
        sum=0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(s[i][j] - ms[t][i][j] > 0) sum += s[i][j] - ms[t][i][j];
                else sum += (s[i][j] - ms[t][i][j]) * -1;
            }
        } 
        
        if(sum < answer) answer = sum;
    }
   
    
    return answer;
}
