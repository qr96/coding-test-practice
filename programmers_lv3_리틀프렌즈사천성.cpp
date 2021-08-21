#include <string>
#include <vector>

using namespace std;

bool find(vector<string> &bd, char now){
    int n1r,n1c,n2r,n2c;
    bool flag=0;
    for(int i=0;i<bd.size();i++){ //해당 블럭 찾는 부분
        for(int j=0;j<bd[0].size();j++){
            if(bd[i][j]==now){
                if(flag==0){
                    n1r=i; n1c=j; flag=1;
                }
                else{
                    n2r=i; n2c=j; break;
                }
            }
        }
    }
    if(flag==0) return false;
    if(n1r==n2r){ // 일렬인 경우
        if(n1c>n2c) swap(n1c,n2c);
        for(int i=n1c+1;i<n2c;i++){
            if(bd[n1r][i]!='.') return false;
        }
    }
    else if(n1c==n2c){
        for(int i=n1r+1;i<n2r;i++){
            if(bd[i][n1c]!='.') return false;
        }
    }
    else{ //n1r은 n2r 보다 항상 작다
        bool tflag=true;
        if(n1c<n2c){
            for(int i=n1c+1;i<=n2c;i++){
                if(bd[n1r][i]!='.') tflag=false;
            }
            for(int i=n1r;i<n2r;i++){
                if(bd[i][n2c]!='.') tflag=false;
            }
            if(tflag==false){
                for(int i=n1r+1;i<=n2r;i++){
                    if(bd[i][n1c]!='.') return false;
                }
                for(int i=n1c;i<n2c;i++){
                    if(bd[n2r][i]!='.') return false;
                }
            }
        }
        else{
            for(int i=n2c+1;i<=n1c;i++){
                if(bd[n2r][i]!='.') tflag=false;
            }
            for(int i=n1r+1;i<n2r;i++){
                if(bd[i][n1c]!='.') tflag=false;
            }
            if(tflag==false){
                for(int i=n1r;i<n2r;i++){
                    if(bd[i][n2c]!='.') return false;
                }
                for(int i=n2c;i<n1c;i++){
                    if(bd[n1r][i]!='.') return false;
                }
            }
        }
    }
    bd[n1r][n1c]='.';
    bd[n2r][n2c]='.';
    return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    int aa[26]={};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]>='A' && board[i][j]<='Z') aa[board[i][j]-'A']=1;
        }
    }
    
    while(1){
        bool flag=true;
        for(int i=0;i<26;i++){
            if(aa[i]==1){
                char now=i+'A';
                if(find(board, now)==true){
                    answer+=now;
                    aa[i]=0;
                    flag=false;
                    break;
                }
            }
        }
        if(flag) break;
    }
    for(int i=0;i<26;i++){
        if(aa[i]!=0) answer="IMPOSSIBLE";
    }
    if(answer.size()==0) answer="IMPOSSIBLE";
    return answer;
}