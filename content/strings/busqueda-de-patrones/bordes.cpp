/*
*Descripción:* Retorna los largos de todos los bordes, ordenados de menor a mayor.Un borde es un prefijo propio que también es sufijo de una string.
*Complejidad:* O(n)
*Requiere de Prefix-function
*/

vector<int> borders(const string &s) {
    if (s.empty()) return {};

    vector<int> pi = prefix_function(s);
    vector<int> ans;

    for (int k = pi.back(); k > 0; k = pi[k-1])
        ans.push_back(k);

    reverse(ans.begin(), ans.end());
    return ans;
}
