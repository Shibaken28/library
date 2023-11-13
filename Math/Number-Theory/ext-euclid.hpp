// 拡張Euclidの互除法
// ax + by = gcd(a, b) となるような (x, y) を求める 
long extGCD(long a, long b, long &x, long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
