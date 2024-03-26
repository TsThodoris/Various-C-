#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


struct Point2D {
  int x;
  int y;
};

int orientation(Point2D l, Point2D q, Point2D i){
    int dir = (q.y - l.y) * (i.x - q.x) - (q.x - l.x) * (i.y - q.y);
    if(dir == 0){return 0;} // collinear point then we swap q and i
    return dir > 0 ? 1 : 2; // clock or counterclockwise
}

//Jarvis Algorithm
int solution(vector<Point2D> &A) {
    vector<Point2D> convex_hull;
    //leftmost point:
    vector<int> x_coords;
    for(auto p : A){
        x_coords.push_back(p.x);
    }
    auto min_value = min_element(x_coords.begin(),x_coords.end());
    int index = distance(x_coords.begin(),min_value);
    int p = index;
    int n = A.size();
    while(true){
        convex_hull.push_back(A[p]);
        int q = (p+1)%n; //index of q point
        for(int i = 0; i < n ; ++i){
            if(orientation(A[p],A[i],A[q]) == 2){
                q = i;
            }
        }
        p = q;
        if(p == index){
            break;
        }
    }
    cout << "Convex hull vertices : " << endl;
    for(auto p : convex_hull){
        cout << p.x << "," << p.y << endl;
    } 
    if(convex_hull.size() == n){return -1;}
    else{
        for(auto point : convex_hull){
            auto ind = find_if(A.begin(),A.end(),[point](Point2D a) {return a.x == point.x && a.y == point.y;});
            if(ind != A.end()){
                return distance(A.begin(),ind)+1;
            }
        }
    }
    return -1;
}
int main(){
    Point2D a1{1,1};
    Point2D a2{3,3};
    Point2D a3{4,5};
    Point2D a4{2,4};
    Point2D a5{5,2};
    Point2D a6{3,0};
    Point2D a7{-1,2};
    vector<Point2D> A{a1,a2,a3,a4,a5,a6};
    int res = solution(A);

    if(res != -1){
        cout << "Point inside of convex hull : " << A[res].x << "," << A[res].y << endl;
        cout << "with index  " << res << endl;
    }else{
        cout << "All vertices are on convex hull ! "<< endl;
    }
    
 

}