/*
1. A line in 2D space can be demostrated by the following formula:
            slope = dy/dx = (y - y0)/(x - x0)
   so we can use two integers to denote a line's slope.

2. All the points in the same line has the equal lowest term fraction slope, 
   divide by the greatest common divisor.

3. Every two points can definetely determine a line, thus we can count lines by scanning
   all the possible points couples.

4. Points with the same cordinate are considered as two different points.

5. Even if there exist only one single point, it is also on a line.

6. slope = (0, 0) = (x - x0, y - y0)  imply there exist a 
   dunplicate point of the current base point.

7. Slopes of lines parallel to x-axis are all convert to (1, 0) form.
   (0, 1) for y-axis.
   
*/

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
            // sort by distance
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