#include <bits/stdc++.h>
using namespace std;  
class BigInt{
public:
    vector<short> value;
    short sign;
    int size(){
        return value.size();
    }
    void clear_leading_zeros(){
        while(!value.empty() && value.back() == 0)
            value.pop_back();
        if(value.empty()) sign = 0;
    }
    BigInt(){
        sign = 0;
    }
    BigInt(string s){
        sign = 1;
        if(s[0] == '-'){
            sign = -1;
            s = s.substr(1);
        }
        for(int i = s.size() - 1 ; i >= 0 ; i--)
            value.push_back(s[i] - '0');
        clear_leading_zeros();
    }

    BigInt(long long a){
        *this = BigInt(to_string(a));
    }

    short& operator [](int i){
        return value[i];
    }
    BigInt operator -(){
        BigInt result = *this;
        result.sign *= -1;
        return result;
    }

    bool friend operator <(BigInt a, BigInt b){
        if(a.sign != b.sign) return a.sign < b.sign;
        if(a.size() != b.size()) return a.size() * a.sign < b.size() * b.sign;
        int i = a.size() - 1;
        while(i > 0 && a[i] == b[i]) i--;
        return a[i] * a.sign < b[i] * b.sign;
    }

    BigInt friend operator -(BigInt a , BigInt b){
        if(b.sign == 0) return a;
        if(a.sign == 0) return -b;
        if(b.sign == -1) return a + -b;
        if(a.sign == -1) return -(-a + b);
        if(a < b) return -(b - a);

        BigInt c;
        c.sign = 1;
        int x;
        for(int i = 0 ; i < a.size() ; i++){
            x = a[i];
            if(i < b.size()) x -= b[i];
            if(x < 0){
                x += 10;
                a[i + 1] --;
            }
            c.value.push_back(x);
        } 
        c.clear_leading_zeros();
        return c;
    }

    BigInt friend operator +(BigInt a , BigInt b){
        if(a.sign == 0) return b;
        if(b.sign == 0) return a;
        if(b.sign == -1) return a - -b;
        if(a.sign == -1) return b - -a;

        BigInt c;
        c.sign = 1;
        int d = 0 , sz = max(a.size() , b.size());
        for(int i = 0 ; i < sz ; i ++){
            if(i < a.size()) d += a[i];
            if(i < b.size()) d += b[i];
            c.value.push_back(d % 10);
            d /= 10;
        }
        if(d > 0) c.value.push_back(d);
        return c;
    }

    BigInt friend operator *(BigInt a, BigInt b){
        if(a.sign == 0 || b.sign == 0) return 0;
        BigInt c;
        c.sign = b.sign * a.sign;
        c.value.resize(a.size() + b.size());
        for(int i = 0 ; i < a.size() ; i++)
            for(int j = 0 ; j < b.size() ; j ++)
                c[i + j] += a[i] * b[j];
        for(int i = 0 ; i < c.size() ; i++){
            if(c[i] > 9){
                c[i + 1] += c[i] / 10;
                c[i] %= 10;
            }
        }
        c.clear_leading_zeros();
        return c;
    }
    BigInt friend operator /(BigInt a, int b){
        if(a.sign == 0) return 0;
        if(a.sign == -1) return -(-a / b);
        if(b < 0) return -(a / -b);
        if(a < b) return 0;
        BigInt c;
        c.sign = 1;
        long long s = 0;
        int i = a.size() - 1;
        while(s < b){
            s = s * 10 + a[i];
            i --;
        }
        c.value.push_back(s / b);
        s %= b;
        while(i >= 0){
            s = s * 10 + a[i --];
            c.value.push_back(s / b);
            s %= b;
        }
        reverse(c.value.begin(), c.value.end());
        return c;
    }
    BigInt friend operator %(BigInt a , int b){
        return a - b * (a / b);
    }
}; 

istream& operator >>(istream& in , BigInt &a){
    string s;
    in >> s;
    a = BigInt(s);
    return in;
}

ostream& operator <<(ostream& out , BigInt a){
    if(a.sign == 0) out << 0;
    else if(a.sign == -1) cout << '-';
    for(int i = a.size() - 1 ; i >= 0 ; i--)
        cout << a[i];
    return out;
}