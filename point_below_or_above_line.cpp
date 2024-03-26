#include <iostream>
#include <vector>

using namespace std;

int main(){
    cout << "Give slope : " << endl;
    double slope;
    cin >> slope;
    cout << "Give constant : " << endl;
    double con;
    cin >> con;

    vector<int> x{1,2,3,4,5,6,7,8,9,10};
    vector<int> y{1,2,3,4,5,6,7,8,9,10};
    int above = 0, below = 0;
    for(unsigned int i = 0 ; i < x.size() ; ++i){
        if(double(y[i]) > slope * double(x[i]) + con){
            ++above;
        }else{
            ++below;
        }
    }
    cout << "Number of points above y = " << slope << "x + " << con << " : " << above << endl; 
    cout << "Number of points below y = " << slope << "x + " << con << " : " << below << endl;
}