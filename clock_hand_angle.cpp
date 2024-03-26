#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "Give digital hour : " << endl;
    string time;
    cin >> time;
    double angle_per_num = 360.0/12.0;
    auto ind = time.find(':');
    double hours = stoi(time.substr(0,ind));
    double mins = stoi(time.substr(ind+1,time.size()));

    double hour_point = hours;
    if(hours > 12){
        double hour_point = hours - 12.0;
    }
    
    //find what number does the minute hand is pointing to
    double min_point = mins/5.0;
    double min_angle = min_point *angle_per_num;
    
    double hour_angle = hour_point*angle_per_num + mins/60.0*angle_per_num;
    double res = abs(min_angle - hour_angle);
    res = abs(min(res, 360 - res));
    cout << "The angle is : " << res << " degrees" << endl;
    
    



}