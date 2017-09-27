#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int sum(vector<int>v) {
    int res = 0;
    int n = v.size();
    for(int i = 0; i < n; i++) {
        res += v[i];
    }
    return res;
}
int equalHeight(vector<int> h1, vector<int> h2, vector<int> h3) {
    std::reverse(h1.begin(),h1.end());
    std::reverse(h2.begin(),h2.end());
    std::reverse(h3.begin(),h3.end());
    int res = 0,sum1 = sum(h1), sum2 = sum(h2), sum3 = sum(h3);
    if(sum1 == 0 || sum2 == 0 || sum3 == 0)
        return 0;
    while(sum1 != sum2 || sum2 != sum3 || sum1 != sum3) {
        if( sum1>=sum2 && sum1>=sum3 ) {
            sum1 -= h1[h1.size()-1];
            h1.pop_back();
        } else if( sum2>=sum1 && sum2>=sum3 ) {
            sum2 -= h2[h2.size()-1];
            h2.pop_back();
        } else if( sum3>=sum1 && sum3>=sum2 ) {
            sum3 -= h3[h3.size()-1];
            h3.pop_back();
        }
    }
    return sum1;
}

int main(){
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
        cin >> h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
        cin >> h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
        cin >> h3[h3_i];
    }
    
    int height;
    height = equalHeight(h1,h2,h3);
    cout<<height;
    return 0;
}

