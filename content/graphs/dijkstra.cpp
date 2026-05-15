/*
 *Description:* Computa las distancias mínimas desde un nodo inicial a todos los demás en un grafo ponderado con pesos no negativos usando el algoritmo de Dijkstra.
  Complejidad: $O(V log (V + E) )$
*/

vec<ll> dist(n, INF);
dist[x] = 0;
priority_queue<pli, vec<pli>, greater<pli>> q; 
// esto o insertar pesos negativos
q.push({0, x});
while (!q.empty()) {
  auto [w0, u] = q.top(); q.pop();
  if (seen[u]) continue;
  seen[u] = true;
  for (auto [w, v] : graph[u]) {
    if (dist[v] > dist[u] + w) {
      dist[v] = dist[u] + w;
      q.push({dist[v], v});
    }
  }
}