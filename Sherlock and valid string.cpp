#include <bits/stdc++.h>

using namespace std;

string isValid(string s){
    // Complete this function
    double a[26] = {0}, len, sum = 0, count = 0, flag = 0;
    len = s.length();
    for(int i = 0; i < len; i++) {
        a[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(a[i] > 0)
            count++;
        sum += a[i];
    }
    if(count == 1)
        return "YES";
    else if(sum / count == a[0] && sum / count == a[1])
        return "YES";
    else {
        count = 0;
        sum = 0;
        for(int i = 1; i < 26-1; i++) {
            if(a[i] != a[i-1] && a[i] != a[i+1]) {
                a[i]--;
                flag = 1;
            }
        }
        if(flag != 1) {
            if(a[0] != a[1])
                a[0]--;
            else if(a[25] != a[24])
                a[25]--;
        }
        for(int i = 0; i < 26; i++) {
            if(a[i] > 0)
                count++;
            sum += a[i];
        }
        if(sum / count == a[0] && sum / count == a[1])
            return "YES";
        else return "NO";
        
    }
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}

