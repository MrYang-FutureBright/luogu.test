#include<iostream>
#include<stack>
#include<string>
using namespace std;
string s;

void solve() {
    stack<char> st1;  
    stack<char> st2;  
    int isnot = 0;

    for (char i : s) {
        if (i == '.') {
            isnot = 1;
            continue;
        }
        else if (i == '%') {
            isnot = 2;
            continue;
        }
        else if (i == '/') {
            isnot = 3;
            continue;
        }

        if (!isnot) st1.push(i);
        else st2.push(i);
    }

    while (!st1.empty() && st1.top() == '0') {
        st1.pop();
    }

    string temp;
    while (!st2.empty()) {
        temp += st2.top();
        st2.pop();
    }

    while (!temp.empty() && temp.back() == '0') {
        temp.pop_back();
    }
    int start = 0;
    while (start < temp.size() && temp[start] == '0') {
        start++;
    }
    temp = temp.substr(start);
    if (st1.empty()) cout << "0";
    else {
        while (!st1.empty()) {
            cout << st1.top();
            st1.pop();
        }
    }

    if (isnot == 1) cout << ".";
    if (isnot == 2) cout << "%";
    if (isnot == 3) cout << "/";
    if(isnot==1&&temp.empty())
    {
        cout<<'0';
        return;
    }
    cout << temp;
}

int main() {
    cin >> s;
    solve();
    return 0;
}