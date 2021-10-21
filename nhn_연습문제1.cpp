void solution(int sizeOfMatrix, int **matrix) {
  queue<pair<int, int>> que;
	vector<vector<int>> visited;
	vector<int> answer;
	
	for(int i=0; i<sizeOfMatrix; i++) {
		vector<int> tmp(sizeOfMatrix);
		visited.push_back(tmp);
	}
	
	for(int i=0; i<sizeOfMatrix; i++) {
		for(int j=0; j<sizeOfMatrix; j++) {
			if(matrix[i][j]==1 && visited[i][j]==0) {
				que.push(make_pair(i, j));
				visited[i][j] = 1;
				answer.push_back(0);
				
				while(!que.empty()) {
					int r = que.front().first;
					int c = que.front().second;
					que.pop();
					answer.back()++;
					
					if(r-1>=0 && matrix[r-1][c]==1 && visited[r-1][c]==0) {
						que.push(make_pair(r-1, c));
						visited[r-1][c]=1;
					}
					if(c-1>=0 && matrix[r][c-1]==1 && visited[r][c-1]==0) {
						que.push(make_pair(r, c-1));
						visited[r][c-1]=1;
					}
					if(r+1<sizeOfMatrix &&  matrix[r+1][c]==1 && visited[r+1][c]==0) {
						que.push(make_pair(r+1, c));
						visited[r+1][c] = 1;
					}
					if(c+1<sizeOfMatrix && matrix[r][c+1]==1 && visited[r][c+1]==0) {
						que.push(make_pair(r, c+1));
						visited[r][c+1] = 1;
					}
				}
			}
		}
	}
	
	sort(answer.begin(), answer.end());
	
	cout<<answer.size()<<endl;
	for(int i=0; i<answer.size(); i++) {
		cout<<answer[i]<<" ";
	}
	cout<<endl;
}