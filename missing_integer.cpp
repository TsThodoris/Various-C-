#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int solution(vector<int> &v){
    sort(v.begin(),v.end());
    vector<int> diffs;
    int missing = 1;
    while(true){
        auto ind = find(v.begin(),v.end(),missing);
        if(ind == v.end()){
            return missing;
        }
        ++missing;
    }
    
}

int main(){
    vector<int> A{14172,213,1,2,3,4,5,6,7,8,9,12,11,10,123,23,124};
    int res = solution(A);
    cout << "The smallest missing integer in vector : " << endl;
    for(auto v : A){
        cout << v << ",";
    }
    cout << endl;
    cout << "is -> " << res << endl;

}