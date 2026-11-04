class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int answer=0;
    vector<pair<int,int>>cars;
    for (int i=0; i<position.size(); i++){
        cars.push_back({position[i],speed[i]});
    }
    sort(cars.begin(),cars.end());
    double fleet = (double)(target - cars[cars.size()-1].first)/cars[cars.size()-1].second;
    answer++;
    for(int i=cars.size()-1; i>=0; i--){
        if((double)(target-cars[i].first)/cars[i].second>fleet){
            answer++;
            fleet = (double)(target-cars[i].first)/cars[i].second;
        }
    }
    return answer;
    }
};
