
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    
    int myApple = 0;
    int myOrange = 0;
    
    for(int i=0; i<apples.size(); i++) {
        if(apples[i]+a >= s && apples[i]+a <= t) myApple++;
    }
    for(int i=0; i<oranges.size(); i++) {
        if(oranges[i]+b >= s && oranges[i]+b <= t) myOrange++;
    }
    
    cout<<myApple<<endl;
    cout<<myOrange<<endl;
}
