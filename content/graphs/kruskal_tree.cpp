/*
 *Description*: Retorna la construcción de un MST
 *NEED*: UNION_FIND
*/

typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;

vector<vector<ii>> kruskal(vector<vector<ii>> &gr){ 
  int n = sz(gr);
  vector<vector<ii>> ans(n);
  vector<iii> edges;
  for (int i=0;i<n;i++){
    for (int j=0;j<sz(gr[i]); j++){
      edges.emplace_back(gr[i][j].second,ii{i,gr[i][j].first});
    }
  }
  sort(edges.begin(),edges.end());
  union_find uf(n);
  for (int i=0;i<sz(edges);i++){
    ll repa = uf.findSet(edges[i].second.first), repb = uf.findSet(edges[i].second.second);
    if (repa!=repb){
      ans[edges[i].second.first].emplace_back(edges[i].second.second, edges[i].first);
      ans[edges[i].second.second].emplace_back(edges[i].second.first, edges[i].first);
      uf.unionSet(repa,repb);
    }
  }
  return ans;
}