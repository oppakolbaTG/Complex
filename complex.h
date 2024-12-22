#ifndef INCLUDE_COMPLEX_H_
#define INCLUDE_COMPLEX_H_

#include <cmath>
#include <iostream>
#include <vector>

class complex {
private:
    long double real;
    long double imag;

public:
    explicit complex(long double r = 0.0L, long double i = 0.0L) 
        : real(r), imag(i) {}

    long double Re() const { return real; }
    long double Im() const { return imag; }
    long double Abs() const {
        return std::sqrt(real * real + imag * imag);
    }
    long double Arg() const {
        return std::atan2(imag, real);
    }
    complex Conjugate() const {
        return complex(real, -imag);
    }
    complex operator~() const {
        return Conjugate();
    }
    complex Pow(int deg) const {
        if (deg == 0) {
            return complex(1.0L, 0.0L);
        }
        long double r = Abs();
        long double theta = Arg();
        long double r_pow = std::pow(r, std::abs(deg));
        long double theta_mul = theta * std::abs(deg);
        if (deg < 0) {
            r_pow = 1.0L / r_pow;
            theta_mul = -theta_mul;
        }
        return complex(r_pow * std::cos(theta_mul), r_pow * std::sin(theta_mul));
    }
    std::vector<complex> Rt(unsigned int n) {
        if (n==0) {
            return std::vector<complex>();
        }
        static const long double pi = 3.141592653589793238L;
        std::vector<complex> roots;
        roots.reserve(n);
        long double r = Abs();
        long double theta = Arg();
        long double root_mod = std::pow(r, 1.0L / n);
        for (unsigned int k = 0; k < n; ++k) {
            long double angle = (theta + 2.0L * pi * k) / static_cast<long double>(n);
            roots.push_back(complex(
                root_mod * std::cos(angle),
                root_mod * std::sin(angle)
            ));
        }
        return roots;
    }
    complex Rt(unsigned int n, unsigned int k) const {
        if (n == 0) {
            return complex(0.0L, 0.0L);
        }
        static const long double pi = 3.141592653589793238L;
        long double r = Abs();
        long double theta = Arg();
        long double root_mod = std::pow(r, 1.0L / n);
        long double angle = (theta + 2.0L * pi * k) / static_cast<long double>(n);
        return complex(
            root_mod * std::cos(angle),
            root_mod * std::sin(angle)
        );
    }

    friend bool operator==(const complex& lhs, const complex& rhs) {
        return (lhs.real == rhs.real && lhs.imag == rhs.imag);
    }
    friend bool operator!=(const complex& lhs, const complex& rhs) {
        return !(lhs == rhs);
    }
    friend complex operator+(const complex& lhs, const complex& rhs) {
        return complex(lhs.real + rhs.real, lhs.imag + rhs.imag);
    }
    friend complex operator-(const complex& lhs, const complex& rhs) {
        return complex(lhs.real - rhs.real, lhs.imag - rhs.imag);
    }
    friend complex operator*(const complex& lhs, const complex& rhs) {
        long double a = lhs.real;
        long double b = lhs.imag;
        long double c = rhs.real;
        long double d = rhs.imag;
        return complex(a * c - b * d, a * d + b * c);
    }
    friend complex operator/(const complex& lhs, const complex& rhs) {
        long double a = lhs.real;
        long double b = lhs.imag;
        long double c = rhs.real;
        long double d = rhs.imag;
        long double denominator = c * c + d * d;
        if (denominator == 0.0L) {
            return complex(INFINITY, INFINITY);
        }
        long double real_part = (a * c + b * d) / denominator;
        long double imag_part = (b * c - a * d) / denominator;
        return complex(real_part, imag_part);
    }

    void operator+=(const complex& rhs) {
        *this = *this + rhs;
    }
    void operator-=(const complex& rhs) {
        *this = *this - rhs;
    }
    void operator*=(const complex& rhs) {
        *this = *this * rhs;
    }
    void operator/=(const complex& rhs) {
        *this = *this / rhs;
    }
};

inline std::ostream& operator<<(std::ostream& os, const complex& z) {
    long double r = z.Re();
    long double i = z.Im();
    if (r == 0.0L && i == 0.0L) {
        os << 0;
        return os;
    }
    if (r == 0.0L) {
        os << i << 'i';
        return os;
    }
    if (i == 0.0L) {
        os << r;
        return os;
    }
    if (i > 0.0L) {
        os << r << " + " << i << 'i';
    } else {
        os << r << " - " << (-i) << 'i';
    }
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const std::vector<complex>& vec) {
    os << '{';
    for (std::size_t idx = 0; idx < vec.size(); ++idx) {
        os << vec[idx];
        if (idx + 1 < vec.size()) {
            os << ", ";
        }
    }
    os << '}';
    return os;
}

#endif // INCLUDE_COMPLEX_H_
