struct doubleingLca
{
  /*
    how to use
    
    auto g=doubleingLca(n);
    g.lca(l,r);
  */
  
  int n,r,d_size;
  vector<set<int>> edge;
  vector<int> depth,parent;
  vector<vector<int>> db;
  
  doubleingLca(const int& n,const int& root,const vector<vector<int>> &e): n(n),r(root)
  {
    edge=vector<set<int>>(n);
    repin(i,e){
      edge[i[0]].insert(i[1]);
      edge[i[1]].insert(i[0]);
    }
    parent=vector<int>(n,-1);
    depth=vector<int>(n);
    d_size=log(n)/log(2)+2;
    db=vector<vector<int>>(d_size,vector<int>(n));
    dfs(r);
    doubleing();
  }
  
  doubleingLca(const int& n,const int& root,const vector<set<int>> &e): n(n),r(root)
  {
    edge=e;
    parent=vector<int>(n,-1);
    depth=vector<int>(n);
    d_size=log(n)/log(2)+2;
    db=vector<vector<int>>(d_size,depth);
    dfs(r);
    doubleing();
  }
  
  void dfs(const int& x)
  {
    repin(i,edge[x]){
      if(parent[i]==-1 && i!=r){
        depth[i]=depth[x]+1;
        parent[i]=x;
        dfs(i);
      }
    }
  }
  
  void doubleing()
  {
    rep(i,d_size)rep(j,n){
      if(i==0)db[i][j]=parent[j];
      else db[i][j]=db[i-1][db[i-1][j]];
    }
  }
  
  int lca(int x,int y)
  {
    if(depth[x]>depth[y])swap(x,y);
    int d=depth[y]-depth[x];
    repr(i,d_size){
      if(d-pow(2,i)>=0){
        d-=pow(2,i);
        y=db[i][y];
      }
    }
    if(x==y)return x;
    repr(i,d_size)if(db[i][x]!=db[i][y]){
      x=db[i][x];
      y=db[i][y];
    }
    return parent[x];
  }
};
