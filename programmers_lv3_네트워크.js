function solution(n, computers) {
    var answer = 0;
    
    var visited = new Array(n).fill(0); //방문 여부
    
    for(var i=0; i<n;i++){
        if(visited[i]==0){ //방문한 적이 없는 경우
            answer++;
            var que = [i,];
            while(que.length>0){ //BFS 탐색
                var now = que.shift();
                visited[now]=1;
                console.log(now);
                for(var j=0; j<n; j++){
                    if(computers[now][j]==1 && visited[j]==0){
                        que.push(j);
                    }
                }    
            }
            
            
        }
    }
    
    return answer;
}