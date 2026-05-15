/*
 *Description:* Rota una matriz n x n
 Complejidad: $O(n^2)$
*/

template <class T>
// clockwise
void rotate(vector<vector<T>> &a) {
  int n = a.size();
  vector<vector<T>> mat(n, vector<T>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = a[n - 1 - j][i];
    }
  }

  swap(a, mat);
}

template <class T>
// counterclockwise
void rotate_ccw(vector<vector<T>> &a) {
  int n = a.size();
  vector<vector<T>> mat(n, vector<T>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = a[j][n - 1 - i];
    }
  }

  swap(a, mat);
}
