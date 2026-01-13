#include <bits/stdc++.h>
using namespace std;

class Solution {
    class LineArea{
        public:
        double above;
        double below;
    };

    LineArea areaFromLine(vector<vector<int>>& squares, double yLine){
        
        LineArea ans;
        ans.below = 0;
        ans.above = 0;

        for(const auto& sq : squares){
            double y = sq[1];
            double s = sq[2];

            if(yLine >= s + y){ // case yLine is above the square top
                ans.below += s * s;
            }

            else if(yLine <= y){ // case yLine is below the square bottom
                ans.above += s * s;
            }

            else{ // case yLine lies between the square somewhere
                ans.above += s * ((y + s) - yLine);
                ans.below += s * (yLine - y);
            }
        }
        
        return ans;
    }

    double binSearch(vector<vector<int>>& squares){
        double left = DBL_MAX; // minimum can be the bottom of bottom most square;
        double right = DBL_MIN; // maximum can be the top of top most square;

        for(const auto& sq : squares){
                left = min(left, (double)sq[1]);
                right = max(right, (double)(sq[1] + sq[2]));
        }

        while(right - left > 1e-7){
            double mid = left + (right - left) / 2;
            LineArea area = areaFromLine(squares,mid);

            if(area.below < area.above) left = mid;
            else right = mid;
        }
        return (left + right)/2;
    }


public:

    double separateSquares(vector<vector<int>>& squares) {

        if(squares.empty()) return 0;
        return binSearch(squares);




    }
};

int main(){
    return 0;
}