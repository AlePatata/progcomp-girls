/*
 *Descripcion:* pi[x] computa el largo del prefijo más largo de $s$ que termina en $x$, other than s[0...x] itself (abacaba $->$ 0010123). Puede ser usado para encontrar todas las ocurrencias de un string.
 *Complejidad:* $0(n)$ 
*/
vector<int> pi(const string &s) {
  vector<int> p(sz(s));
  for(int i=1;i<sz(s);++i){
    int g = p[i - 1];
    while (g && s[i] != s[g]) g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}
vector<int> match(const string &s, const string &pat) {
  vector<int> p = pi(pat + '\0' + s), res;
  for (int i=sz(p)-sz(s); i<sz(p);++i)  
    if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
  return res;
}