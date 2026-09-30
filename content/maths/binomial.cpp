template<class T>
T binomial(T n, T k, T mod){
    if(k > n or n < 0 or k < 0){
        return 0;
    }
    return fact[n]*invfact[n-k]%mod*invfact[k]%mod;
}
