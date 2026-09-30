/*
 *Descripción:* Calcula el binomial de n sobre k
 *Requiere:* factorial y inverso factorial
 *Complejidad:* $O(1)$
 */
template<class T>
T binomial(T n, T k, T mod){
    if(k > n or n < 0 or k < 0){
        return 0;
    }
    return fact[n]*invfact[n-k]%mod*invfact[k]%mod;
}
