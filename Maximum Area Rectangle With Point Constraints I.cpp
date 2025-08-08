class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        set<pair<int,int>> pointSet;
        for(auto it : points){
            pointSet.insert({it[0], it[1]});
        }

        int n = points.size();

        int maxArea = -1;

        for(int i=0;i<n;i++){
            auto [x1,y1] = make_pair(points[i][0], points[i][1]);

            for(int j=i+1;j<n;j++){
                auto [x2, y2] = make_pair(points[j][0], points[j][1]);

                if(x1 == x2 || y1 == y2) continue;

                pair<int,int> p1 = make_pair(x1,y2);
                pair<int,int> p2 = make_pair(x2,y1);

                if(pointSet.count(p1) && pointSet.count(p2)){
                    int minX = min(x1,x2), maxX = max(x1,x2);
                    int minY = min(y1,y2), maxY = max(y1,y2);

                    bool valid = true;

                    for(auto [x,y] : pointSet){
                       if((x == x1 && y == y1) || (x == x2 && y == y2) || (x == p1.first && y == p1.second) || (x == p2.first && y == p2.second)) continue;

                       if(x >= minX && x <= maxX && y >= minY && y <= maxY) {
                        valid = false;
                        break;
                       }
                    }
                    if(valid){
                         int area = (maxX - minX) * (maxY - minY);
                        maxArea = max(maxArea, area);
                    }
                }
            }
        }

        return maxArea;
    }
};
