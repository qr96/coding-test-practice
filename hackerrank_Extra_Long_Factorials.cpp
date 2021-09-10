void extraLongFactorials(int n) {
    vector<long long> number;
    long long tmp;
    int UNIT = 1000000000;
    string ans = "";
    
    number.push_back(1);
    
    while(n) {
        for(int i=0; i<number.size(); i++) {
            number[i] *= n;
        }
        for(int i=0; i<number.size(); i++) {
            if(number[i] >= UNIT) {
                tmp = number[i] / UNIT;
                number[i] %= UNIT;
                if(i+1 < number.size()) number[i+1] += tmp;
                else number.push_back(tmp);
            }
        }
        n--;
    }
    
    for(int i=number.size()-1; i>=0; i--) {
        ans = to_string(number[i]);
        if(i < number.size()-1) while(ans.size() < 9) ans = '0'+ans;
        cout<<ans;
    }
    cout<<endl;
}