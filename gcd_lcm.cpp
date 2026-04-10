#include <bits/stdc++.h>
using namespace std;
using rn = uint32_t;

rn gcd(rn a, rn b) {
    if (min(a, b) > 0 && max(a, b) - min(a, b) > 0) {
        return gcd(min(a, b), max(a, b)-min(a, b));
    }
    return min(a, b);
}

rn lcm(rn a, rn b) {
    return (a * b) / gcd(a, b);
}

rn lpd(rn n) {
    for (rn i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}

vector<rn> pf(rn n) {
    vector<rn> p;
    queue<rn> q;

    rn lp = lpd(n);
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
rn main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    rn a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n' << lcm(a, b) << '\n';
    
    vector<rn> ap = pf(a);
    vector<rn> bp = pf(b);
    for (rn i : ap) {
        cout << i << " ";
    }
    cout << '\n';
    for (rn i : bp) {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}