#include<iostream>
#include <vector>

using namespace std;

struct Point{
    double x,y;
};

bool insidePolygon(Point& point, vector<Point>& polygon){
    int num_vertices = polygon.size();
    double x = point.x , y = point.y;
    bool inside = false;

    Point p1 = polygon[0] , p2;
    for(int i = 1 ; i <= num_vertices ; i++){
        p2 = polygon[i % num_vertices];
        if(y > min(p1.y , p2.y)){
            if(y <= max(p1.y, p2.y)){
                if(x <= max(p1.x , p2.x)){
                    double x_intersection = p1.x + (y-p1.y)/(p2.y-p1.y)*(p2.x-p1.x);
                    if(p1.x == p2.x || x <= x_intersection){
                        inside = !inside;
                    }
                }
            }
        }
        p1 = p2;
    }
    return inside;
}

int main(){
    Point point = { 150, 85 };
    vector<Point> polygon = {{ 186, 14 }, { 186, 44 }, { 175, 115 }, { 175, 85 }};
    auto res = insidePolygon(point,polygon);
    cout << boolalpha << res << endl;
}   