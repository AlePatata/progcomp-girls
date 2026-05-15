/*
 *Description:* Obtiene los divisores de un número $n$
  Complejidad: $O(√n)$
*/
template<class T>
vector<T> divisores(T n) {
	vector<T> v1, v2;

	for (T i = 1; i*i <= n; ++i) {
        if (n%i == 0) {
            v1.push_back(i);
            if (i*i < n) v2.push_back(n/i);
        } 
    }
    reverse(v2.begin(), v2.end());
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}