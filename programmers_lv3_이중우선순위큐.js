function solution(operations) {
    var answer = [];
    
    //우선순위큐를 꼭 사용?
    var que = [];
    var num;
    var tmp;
    
    for(var oper of operations){
        if(oper[0]=="I"){
            num = oper.split(" ")[1];
            que.push(Number(num));
        }
        else if(oper[0]=="D"){
            num = oper.split(" ")[1];
            if(que.length<=0){
                
            }
            else if(num == 1){
                var max = que.pop();
                for(var q in que){
                    if(que[q]>max){
                        tmp=que[q];
                        que[q]=max;
                        max=tmp;
                    }
                }
            }
            else if(num == -1){
                var min = que.pop();
                for(var q in que){
                    if(que[q]<min){
                        tmp=que[q];
                        que[q]=min;
                        min=tmp;
                    }
                }
            }
        }
        console.log(que);
    }
    
    if(que.length>0){
        var max = que.pop();
        var min = max;
        for(var q of que){
            if(q>max){
                max=q;
            }
            if(q<min){
                min=q;
            }
        }
        answer.push(max);
        answer.push(min);
    }
    else if(que.length==0){
        answer.push(0);
        answer.push(0);
    }
    
    return answer;
}