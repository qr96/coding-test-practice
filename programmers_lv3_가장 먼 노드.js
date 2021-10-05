function solution(n, edge) {
    var answer = 0;
    var max_dis = 0;
    
    var que = [];
    var visited = new Array(n+1).fill(0);
    
    que.push(1);
    que.push(0);
    visited[1]=1;
    
    while(que.length>0){
        var now = que.shift();
        var dis = que.shift();
        
        if(max_dis<dis){
            max_dis=dis;
            answer=1;
        }
        else if(max_dis==dis){
            answer++;
        }
        
        for(var e of edge){
            if(e[0]==now && visited[e[1]]==0){
                que.push(e[1]);
                que.push(dis+1);
                visited[e[1]]=1;
            }
            else if(e[1]==now && visited[e[0]]==0){
                que.push(e[0]);
                que.push(dis+1);
                visited[e[0]]=1;
            }
        }
    }
    
    return answer;
}