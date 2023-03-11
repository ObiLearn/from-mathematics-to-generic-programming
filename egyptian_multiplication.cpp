#include <iostream>
#include "helper.h"

int multiply1(int n, int a) {
    in(__FUNCTION__, n, a);
    if (n == 1) {
        out(__FUNCTION__, n, a);
        return a;
    }
    int result = multiply1(half(n), a + a);
    if (odd(n)) result = result + a;
    out(__FUNCTION__, result, n, a);
    return result;
}


int mult_acc0(int r, int n, int a) {
    in(__FUNCTION__, r, n, a);
    if (n == 1) {
        out(__FUNCTION__, r + a, r, n, a);
        return r + a;
    }
    if (odd(n)) {
        int rv =  mult_acc0(r + a, half(n), a + a);
        out(__FUNCTION__, rv, r, n, a);
        return rv;
    } else {
        int rv = mult_acc0(r, half(n), a + a);
        out(__FUNCTION__, rv, r, n, a);
        return rv;
    }
}

int mult_acc1(int const r, int n, int a) {
    in(__FUNCTION__, r, n, a);
    // tailrecursive
    int rr = r;
    if (n == 1) {
        out(__FUNCTION__, rr + a, r, n, a);
        return rr + a;
    }
    if (odd(n)) rr = rr + a;
    int rv = mult_acc1(rr, half(n), a + a);
    out(__FUNCTION__, rv, r, n, a);
    return rv;
}

int mult_acc2(int const r, int n, int a) {
    in(__FUNCTION__, r, n, a);
    int rr = r;
    if (odd(n)) {
        rr = rr + a;
        if (n == 1) {
            out(__FUNCTION__, rr, r, n, a);
            return rr;
        }
    }

    int rv = mult_acc2(rr, half(n), a + a);
    out(__FUNCTION__, rv, r, n, a);
    return rv;
}

int mult_acc3(int const r, int n, int a) {
    in(__FUNCTION__, r, n, a);
    int rr = r;
    if (odd(n)) {
        rr = rr + a;
        if (n == 1) {
            out(__FUNCTION__, rr, r, n, a);
            return rr;
        }
    }

    int nn = half(n);
    int aa = a + a;

    int rv = mult_acc3(rr, nn, aa);
    out(__FUNCTION__, rv, r, n, a);
    return rv;
}

int mult_acc4(int const r, int n, int a) {
    in(__FUNCTION__, r, n, a);
    int rr = r;
    int nn = n;
    int aa = a;

    while (true) {
        if (odd(nn)) {
            rr = rr + aa;
            if (nn == 1) {
                out(__FUNCTION__, rr, r, n, a);
                return rr;
            }
        }

        nn = half(nn);
        aa = aa + aa;
        step(__FUNCTION__, rr, nn , aa);

    }
}

int multiply2(int n, int a) {
    if (n==1) return a;
    return mult_acc4(a, n-1, a);
}

int multiply3(int n, int a) {
    while(!odd(n)) {
        a = a + a;
        n = half(n);
    }

    if (n==1) return a;

    return mult_acc4(a, n-1, a);
}

int multiply4(int n, int a) {
    while(!odd(n)) {
        a = a + a;
        n = half(n);
    }

    if (n==1) return a;

    return mult_acc4(a, half(n-1), a+a);
}


int main() {
    int n = 13 * 2 * 2 * 2 * 2;
    int a = 7;

    std::cout << multiply1(n, a) << std::endl;
    std::cout << mult_acc0(0, n, a) << std::endl;
    std::cout << mult_acc1(0, n, a) << std::endl;
    std::cout << mult_acc2(0, n, a) << std::endl;
    std::cout << mult_acc3(0, n, a) << std::endl;
    std::cout << mult_acc4(0, n, a) << std::endl;

    std::cout << multiply2(n, a) << std::endl;
    std::cout << multiply3(n, a) << std::endl;
    std::cout << multiply4(n, a) << std::endl;
}
