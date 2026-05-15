/*
 *Description:* Ordena un DAG (grafo dirigido acíclico) para ser recorrido desde sus extremos.
*/

void topological_sort() {
  visited.assign(n, false);
  ans.clear();
  for (int i = 0; i < n; ++i)
    if (!visited[i])
      dfs(i);
  reverse(ans.begin(), ans.end());
}