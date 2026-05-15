/*
 *Descripcion:* Dado un arreglo de alturas, encuentra el costo minimo
 para llegar del primer al ultimo indice, donde el costo de saltar
 de i a j es |h[i]-h[j]| y solo se puede saltar a i+1, i+2, ..., i+k.
*/
vector <ll> dp(n);
for (int i = 0; i < n; ++i)
    cin >> h[i];
dp[0] = 0;
for (int i = 1; i < n; ++i) {
    ll min = INF;
    for (int j = max(i-k,0); j < i; ++j) {
        ll lmin = dp[j] + abs(h[j]-h[i]);
        if (lmin < min) min = lmin;
    }
    dp[i] = min;
}
cout << dp[n-1] << endl;