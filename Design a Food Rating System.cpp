struct FoodComparator {
 bool operator()(const pair<string, int> &a, const pair<string, int> &b) const {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
 }
};

class FoodRatings {
public:
unordered_map<string, int> foodToRating;
unordered_map<string, string> foodToCuisine;
unordered_map<string, set<pair<string,int>, FoodComparator>> cuisineToFood;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

        for(int i=0;i<foods.size();i++){
            foodToRating[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
            cuisineToFood[cuisines[i]].insert({foods[i], ratings[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
         int oldRating = foodToRating[food];
       foodToRating[food] = newRating;
       string cuisine = foodToCuisine[food];
       cuisineToFood[cuisine].erase({food, oldRating});
       cuisineToFood[cuisine].insert({food, newRating});
    }
    
    string highestRated(string cuisine) {
        return cuisineToFood[cuisine].begin()->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
