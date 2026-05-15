/*
 *Descripcion:* Minimo numero de monedas para formar un monto x con monedas de valores c1, c2, ..., cn. Forma recursiva con memoizacion
*/
int f(int monto) {
	if (!monto) return 0;
	int ans = INF;
	if (memo[monto] <= INF) return memo[monto];
	for (int i = 0; i < n; ++i) 
		if (monto >= c[i]) 
			ans = min(ans, 1 + f(monto - c[i])); 
	memo[monto] = ans;
	return ans;
}
memo.resize(x+1, INF+1);
int ans = f(x); if (ans == INF) ans = -1;
cout << ans << endl;