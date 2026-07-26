/*
 *Descripción:* Rota una matriz $n times n$
 *Complejidad:* $O(n^2)$
*/

template <class T>
// clockwise
void rotate(vector<vector<T>> &a) {
  int n = a.size();
  vector<vector<T>> mat(n, vector<T>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = a[n - 1 - j][i]; // clockwise
      //mat[i][j] = a[j][n - 1 - i]; // counterclockwise
    }
  }
  swap(a, mat);
}

