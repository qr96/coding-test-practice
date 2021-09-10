vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> dense;
    vector<int> answer;
    
    for(int i=0; i<ranked.size(); i++) {
        if(dense.empty() || dense.back()!=ranked[i]) {
            dense.push_back(ranked[i]);
        }
    }
    
    for(int i=0; i<player.size(); i++) {
        int left = 0;
        int right = dense.size()-1;
        int mid = 0;
        
        if(player[i] >= dense[0]) {
            answer.push_back(1);
            continue;
        }
        else if(player[i] < dense[right]) {
            answer.push_back(right+2);
            continue;
        }
        
        while(left<right) {
            mid = (right+left)/2;
            if(left == mid) {
                answer.push_back(left+2);
                break;
            }
            
            if(player[i] == dense[mid]) {
                answer.push_back(mid+1);
                break;
            }
            else if(player[i] < dense[mid]) {
                left = mid;
            } 
            else if(player[i] > dense[mid]) {
                right = mid;
            }
            
        }
        
        
    }
    
    return answer;
}