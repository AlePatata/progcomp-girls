/*
 *Descripción:* Cantidad de formas de comer entre $l$ y $r$ flores dado que solo come flores en grupos de $k$
*/
vector<ll> dp(INF);
dp[0] = 1;
for (int i = 1; i < INF; ++i) {
  dp[i] = dp[i-1];
  if (i-k >= 0) dp[i] = (dp[i] + dp[i-k])%mod;
}
for (int i = 1; i < INF; ++i)
  dp[i] = (dp[i] + dp[i-1])%mod;
cout << dp[r] - dp[l-1] << endl;
