class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xClosest, yClosest;
        if(xCenter < x1){
            xClosest = x1;
        }else if(xCenter > x2){
            xClosest = x2;
        }else {
            xClosest = xCenter;
        }
        if(yCenter < y1){
            yClosest = y1;
        }else if(yCenter > y2){
            yClosest = y2;
        }else {
            yClosest = yCenter;
        }
        int xDist = xCenter - xClosest;
        int yDist = yCenter - yClosest;
        return (xDist*xDist + yDist*yDist) <= radius*radius;
    }
};