class Solution {
public:

    int gcd(int a, int b){
        if(b != 0){
            return gcd(b, a%b);
        }
        return a;
    }

    int maxPoints(vector<Point> &points) {
        if( points.size() < 1 ) return 0;
        if( points.size() == 1 ) return 1;
        int ans = 2;
        for(int i = 0; i < points.size(); ++i){
            vector< pair<int, int> > slopes;
            for(int j = 0; j < points.size() ; ++j){
                if( j == i ) continue;
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                int g = gcd(dx, dy);
                if( g != 0 ){
                    dx /= g;
                    dy /= g;
                }
                slopes.push_back(pair<int, int>(dx, dy));
            }
            sort(slopes.begin(), slopes.end());
            int cur_count = 2;
            for( int k = 1; k < slopes.size(); ++k ){
                if( slopes[k] == slopes[k-1] || slopes[k-1].first==0 && slopes[k-1].second == 0 ) ++cur_count;
                else cur_count = 2;
                if( cur_count > ans ) ans = cur_count;
            }
        }
        return ans;
    }

};