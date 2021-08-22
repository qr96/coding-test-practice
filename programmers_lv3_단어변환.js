function solution(begin, target, words) {
    var answer = 0;
    
    var visited = new Array(words.length).fill(0);
    var que = [begin, 0];
    
    while(que.length>0){
        var now = que.shift();
        var depth = que.shift();
        if(now == target){
            answer=depth;
        }
        for(var i=0; i<words.length; i++){
            if(visited[i]==0 && comp(now, words[i])==1){
                que.push(words[i]);
                que.push(depth+1);
                visited[i]=1;
            }
        }
    }
    
    return answer;
}

function comp(a, b) { //변환 가능한 단어인지 체크
    var diff = 0;
    for(var i=0; i<a.length; i++){
        if(a[i] != b[i]) diff++;
        if(diff>1) return 0;
    }
    return 1;
}