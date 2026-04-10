#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (min(a, b) > 0 && max(a, b) - min(a, b) > 0) {
        return gcd(min(a, b), max(a, b)-min(a, b));
    }
    return min(a, b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int lpd(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}

vector<int> pf(int n) {
    vector<int> p;
    queue<int> q;

    int lp = lpd(n);
    if (lp == 1) {
        p.push_back(n);
        return p; //prime, can't be factorized
    }

    q.push(lp);
    q.push(n / lp);
    
    while (!q.empty()) {
        lp = lpd(q.front());

        if (lp == 1) {
            p.push_back(q.front());
        }
        else {
            q.push(lp);
            q.push(q.front() / lp);
        }

        q.pop();
    }

    return p;

    // queue with numbers to divide, check if prime
}

// examples of using the functions
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n' << lcm(a, b) << '\n';
    
    vector<int> ap = pf(a);
    vector<int> bp = pf(b);
    for (int i : ap) {
        cout << i << " ";
    }
    cout << '\n';
    for (int i : bp) {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}