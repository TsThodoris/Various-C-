#include <iostream>
using namespace std;


int main(){
    int array[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int len = sizeof(array) / sizeof(array[0]) , rain = 0;
    for(int i = 1 ; i < len ; ++i){
        int left = array[i] , right = array[i];
        for(int j = 0 ; j < i ; ++j){
            left = max(left , array[j]);
        }
        for(int j =  i + 1 ; j < len ; ++j){
            right = max(right , array[j]);
        }
        rain += min(left , right) - array[i];
    }
    cout << "Number of rain units stored : " << rain << endl;
}