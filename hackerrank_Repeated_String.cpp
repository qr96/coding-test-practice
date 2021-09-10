long repeatedString(string s, long n) {
    int apb = 0; //a per block
    int slen = s.length();
    long answer = 0;
    
    for(int i=0; i<s.length(); i++) {
        if(s[i] == 'a') apb++;
    }
    
    answer += (n / slen) * apb;
    
    for(int i=0; i<n%slen; i++) {
        if(s[i] == 'a') answer++;
    }
    
    return answer;
}