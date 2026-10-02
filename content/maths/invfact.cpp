/*
 *Descripción:* Calcula el invfactorial hasta maxv
 *Complejidad:* $O(maxv)$
 *Necesita:* Factorial y invmod
 */
invfact[maxv-1] = invmod(fact[i-1],mod);
for(int i = maxv-2; i > 0; i--){
  invfact[i] = invfact[i+1]*(i+1)%mod;
}
