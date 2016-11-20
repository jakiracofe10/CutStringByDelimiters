#include <iostream>
#include <vector>

using namespace std;

vector<string> cutString(string s, vector<char> c) {
    int prevIndex = 0;
    vector<string> result;
    bool foundDel = false;
    for (int i=0; i<s.length(); i++) {
        for (int j=0; j<c.size(); j++) {
            if (s[i] == c[j]) {
                if (i-prevIndex != 0) {
                    result.push_back(s.substr(prevIndex, i - prevIndex));
                }
                prevIndex=i+1;
                foundDel = true;
                break;
            }
        }
    }
    if (foundDel) {
        if (s.length()-prevIndex != 0) {
            result.push_back(s.substr(prevIndex, s.length() - prevIndex));
        }
    }
    return result;
}

int main() {
    string s = "cgcujjj";
    vector<char> delimiters = {'c','g','j'};
    vector<string> result = cutString(s,delimiters);
    //for (string::iterator it=result;)
    for (int i=0; i<result.size(); i++) {
        cout << result[i];
        if (i != result.size()-1) {
            cout << ", ";
        }
    }
    return 0;
}