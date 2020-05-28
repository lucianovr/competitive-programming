#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int base = 1000000000;
const int base_digits = 9;
struct bigint {
    vector<int> a;
    int sign;
    /* Constructor */
    bigint() : sign(1) {}
    bigint(long long v) { *this = v; }
    bigint(const string &s) { read(s); }

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        a.clear();
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }
    /*  convert string para vector<int>  */
    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    /*  cin para bigint */
    friend istream &operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
    /*  cout para bigint */
    friend ostream &operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int)v.a.size() - 2; i >= 0; --i) {
            stream << setw(base_digits) << setfill('0') << v.a[i];
            // printf("\ni = %d  aqui\n",i);
        }
        return stream;
    }
    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const { return v < *this; }
    bool operator<=(const bigint &v) const { return !(v < *this); }
    bool operator>=(const bigint &v) const { return !(*this < v); }
    bool operator==(const bigint &v) const { return !(*this < v) && !(v < *this); }
    bool operator!=(const bigint &v) const { return *this < v || v < *this; }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int)max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int)res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int)a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int)v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int)v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }
};

int main() {
    bigint a, b, zero = bigint(0), ans, temp, f1, f2;
    string A, B;

    while (cin >> a >> b) {
        if (a == zero && b == zero)
            return 0;

        f1 = bigint(1);
        f2 = bigint(2);
        ans = 0;
        while (f1 < a) {
            temp = f1 + f2;
            f1 = f2;
            f2 = temp;
        }

        while (f1 <= b) {
            temp = f1 + f2;
            f1 = f2;
            f2 = temp;
            ans = ans + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}