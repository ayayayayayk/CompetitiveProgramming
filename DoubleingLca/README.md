doubleingを用いたLCA（最小共通祖先）を求める構造体。

辺の入力は辺の両端を保持したvector<vector<int>>、各頂点の隣接頂点を保持したvector<set<int>>の両方が可能。

関数lca(u,v)でu,vのlcaとなる頂点の番号を取得できる。
また、各頂点の木での深さはdepthに保持される。

以上。
