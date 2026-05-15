/*
 *Description:* Obtiene los números primos hasta n usando la criba de Eratóstenes
  Devuelve un vector donde los índices que contienen 0 son primos
  Complejidad: O(n log log n)
*/

template<class T>
vector<T> criba(T n) {
  vector<T> primos (n+1, 0);
  primos[0] = primos[1] = 0;

  for (T i=2; i*i<=n; i++) {
    if (primos[i] == 0) {
      for (T j=i*i; j<=n; j+=i)
        primos[j] = 1;
    }
  }
  return primos;
}