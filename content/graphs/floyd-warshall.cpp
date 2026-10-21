/*
 *Description:* All shortest path, runs on $O(V^3)$
 *Status:* Tested
*/

// Create dist matrix
for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= n; j++) {
    if (i == j) dist[i][j] = 0;
    else if (gr[i][j]) dist[i][j] = gr[i][j];
    else dist[i][j] = INF;
  }
}

// Floyd-Warshall
for (int k = 1; k <= n; k++) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }
  }
}
