/*
 *Description:* Recorre un grafo no ponderado desde un nodo inicial, calculando la distancia mínima a cada nodo.
  Complejidad: $O(V + E)$
*/
visited[x] = true;
dist[x] = 0;
q.push(x);
while (!q.empty()) {
  int u = q.front(); q.pop();
  // process node s
  for (auto v : graph[u]) {
    if (visited[v]) continue;
    visited[v] = true;
    dist[v] = dist[u]+1;
    q.push(v);
  }
}