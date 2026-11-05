/* 
*Descripción:* Encuentra la longitud del bloque más corto que, repetido un número entero de veces, forma exactamente s. Si no existe un bloque propio que cumpla la condición, retorna n.
*Complejidad:* O(n) tiempo
*/

int exactPeriod(const string &s) {
    int n = s.size();
    if (n == 0) return 0;

    auto pi = prefix_function(s);
    int p = n - pi[n-1];

    return (n % p == 0 ? p : n);
}
