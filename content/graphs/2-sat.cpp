/*
 *Complejidad:* $O(n + m)$
 *Descripción:* Resuelve el problema de 2-Satisfacibilidad (2-SAT). Dada una colección de restricciones de la forma (A o B), determina en tiempo lineal si existe una asignación booleana válida para todas las variables y la reconstruye. 
 *Uso:* 
 - `either(u, v)` agrega la restricción (u o v). Usar `~u` para negar la variable u.
 - `setValue(u)` fuerza que u sea true (`setValue(~u)` para false).
 - `solve()` retorna true si hay solución y guarda los valores (0 o 1) en `values`.
 - `atMostOne(list)` restringe a que como máximo una variable del grupo sea true.
*/ 
struct TwoSat {
  int N;
  vector<vector<int>> gr;
  vector<int> values; // 0 = false, 1 = true
  TwoSat(int n = 0) : N(n), gr(2*n) {}
  void either(int f, int j) {
    f = max(2*f, -1-2*f), j = max(2*j, -1-2*j);
    gr[f].pb(j^1), gr[j].pb(f^1);
  }
  void setValue(int x) { either(x, x); }
  vector<int> val, comp, z; int time = 0;
  int dfs(int i) {
    int low = val[i] = ++time, x; z.pb(i);
    for (int e : gr[i]) if (!comp[e])
      low = min(low, val[e] ?: dfs(e));
    if (low == val[i]) do {
      x = z.back(); z.pop_back();
      comp[x] = low;
      if (values[x>>1] == -1)
        values[x>>1] = x&1;
    } while (x != i);
    return val[i] = low;
  }
  bool solve() {
    values.assign(N, -1);
    val.assign(2*N, 0); comp = val;
    for (int i=0;i<2*N;++i) if (!comp[i]) dfs(i);
    for (int i=0;i<N;++i) if (comp[2*i] == comp[2*i+1]) return 0;
    return 1;
  }
  int addVar() { // (optional)
    gr.emplace_back();
    gr.emplace_back();
    return N++;
  }
  void atMostOne(const vector<int>& li) { // (optional)
    if (sz(li) <= 1) return;
    int cur = ~li[0];
    for(int i=2;i<sz(li);++i) {
      int next = addVar();
      either(cur, ~li[i]);
      either(cur, next);
      either(~li[i], next);
      cur = ~next;
    }
    either(cur, ~li[1]);
  }
};
