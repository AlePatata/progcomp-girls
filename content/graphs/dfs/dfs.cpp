/*
 *Descripción:* Recorre un grafo en profundidad desde `s`: avanza por un camino hasta no poder más y luego retrocede.
 - Para recorrer todo el grafo (varias componentes) llamar `dfs(i)` para cada `i` no visitado
 - Pre-orden: procesar `s` antes de los hijos. Post-orden: procesar `s` después de todos los hijos (lo usa topo-sort)
 - Ojo: la recursión puede hacer stack overflow con $n tilde 10^6$ en un camino; usar dfs iterativo
 *Complejidad:* $O(V + E)$
 *Status:* Tested
*/
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int s) {
  visited[s] = true;
  // pre-orden: procesar s al entrar
  for (int u : adj[s])
    if (!visited[u]) dfs(u);
  // post-orden: procesar s al salir, todos sus descendientes ya terminaron
}
