/* 
*Descripcion*: Encuentra la longitud del período positivo más corto de una string, permitiendo que la última repetición del patrón quede incompleta.
*Complejidad*:(O(n)) tiempo y (O(n)) memoria.

*/
int minPeriod(const string &s) {
    int n = s.size();
    if (n == 0) return 0;

    auto pi = prefix_function(s);
    return n - pi[n-1];
}

