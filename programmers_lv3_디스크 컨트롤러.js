function solution(jobs) {
    var answer = 0;
    
    //실행 여부
    var exec = new Array(jobs.length).fill(0);
    
    //현재 시간
    var  time = 0;
    var job = -1;
    var T = jobs.length;
    var sum = 0;
    
    while(T>0){
        job = -1;
        for(var j=0; j<jobs.length; j++){
            //1. 실행한 적이 없어야 함
            //2. 현재 이미 들어온 작업이어야함
            if(exec[j]==0 && jobs[j][0]<=time){
                if(job==-1){
                    job=j;
                }
                else if(jobs[j][1]<jobs[job][1]){
                    job=j;
                }
                else if(jobs[j][1]==jobs[job][1]){
                    if(jobs[j][0]<jobs[job][0]){
                        job=j;
                    }
                }
            }
            
        }
        if(job==-1){
            time++;
        }
        else{
            console.log(job);
            exec[job] = 1;
            time += jobs[job][1];
            sum += (time-jobs[job][0]);
            T--;
        }
        console.log("time:",time);
    }
    
    console.log("sum:", sum);
    
    answer=Math.floor(sum/jobs.length);
    
    return answer;
}