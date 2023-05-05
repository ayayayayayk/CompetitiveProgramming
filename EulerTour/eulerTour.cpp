template<class T> struct eulerTour
{
  /*
    how to use
    
    auto g=eulerTour(e);
    g.changeWeight(idx,w);
    g.sumWeight(u,v);
  */
  struct fw
  {
    int siz,n;
    vector<T> weight;
    fw():n(0){}
    fw(const vector<T> w):n(w.size())
    {
      siz=1;
      while(siz<n) siz*=2;
      weight=vector<T>(siz*2);
      rep(i,n)update(i,w[i]);
    }
    
    void update(const int pos,const int x)
    {
      int idx=pos+siz;
      weight[idx]=x;
      while(idx>=2)
      {
        idx/=2;
        weight[idx]=weight[idx*2]+weight[idx*2+1];
      }
    }
    
    T calc(int l,int r,int a,int b,int u)
    {
      if(r<=a || b<=l) return 0;
      if(l<=a && b<=r) return weight[u];
      return calc(l,r,a,(int)((a+b)/2),u*2)+calc(l,r,(int)((a+b)/2),b,u*2+1);
    }
    
    T apply(int l,int r)
    {
      return calc(l+1,r,1,siz+1,1);
    }
  };
  int n,r,size;
  // path_v(vertex,3) : idx0 -> vertex_num. , idx1 -> in / out / depth / parent
  // path_e(2*vertex,4) : idx0 -> index , idx1 -> edge_num. / depth
  vector<vector<int>> path_v,path_e;
  vector<set<pair<int,T>>> edge;
  vector<vector<T>> adjMat;
  vector<pair<int,int>> seg_lca;
  vector<T> weight;
  fw f;
  
  eulerTour(const vector<vector<T>> &e): n(e.size()+1),r(0)
  {
    adjMat=vector<vector<T>>(e.size(),vector<T>(2));
    rep(i,e.size())rep(j,2)adjMat[i][j]=e[i][j];
    set<pair<int,T>> s;
    rep(i,n)edge.push_back(s);
    repin(i,e)
    {
      edge[i[0]].insert(make_pair(i[1],i[2]));
      edge[i[1]].insert(make_pair(i[0],i[2]));
    }
    path_v=vector<vector<int>>(n,{-1,-1,0,-1});
    path_e=vector<vector<int>>(2*n,{0,0});
    weight=vector<T>(2*n,0);
    dfs();
  }
  
  //use 1 time only
  void dfs()
  {
    stack<pair<int,T>> st;
    st.push(make_pair(r,0));
    int count=0;
    while(st.size()>0)
    {
      int x=st.top().first;
      T w=st.top().second;
      if(path_v[x][0]==-1)
      {
        path_v[x][0]=count;
        path_e[count][0]=x;
        if(count>0) path_e[count][1]=path_e[count-1][1]+1;
        weight[count]=w;
        repin(i,edge[x]){
          if(path_v[i.first][0]==-1)
          {
            st.push(i);
            path_v[i.first][3]=x;
            path_v[i.first][2]=path_v[x][2]+1;
          }
        }
      }
      else
      {
        path_v[x][1]=count;
        path_e[count][0]=-x;
        if(count>0)path_e[count][1]=path_e[count-1][1]-1;
        weight[count]=-w;
        st.pop();
      }
      count++;
    }
    
    // make seg-lca
    size=1;
    while(size<2*n)size*=2;
    seg_lca=vector<pair<int,int>>(size*2-1,{-1,n+1});
    rep(i,2*n)
    {
      int x=i+size;
      if(path_e[i][0]>=0) seg_lca[x]=make_pair(path_e[i][0],path_e[i][1]);
      else seg_lca[x]=make_pair(path_v[-path_e[i][0]][3],path_e[i][1]);
      while(x>=2)
      {
        x/=2;
        if(seg_lca[2*x].second<seg_lca[2*x+1].second) seg_lca[x]=seg_lca[2*x];
        else seg_lca[x]=seg_lca[2*x+1];
      }
    }
    
    f=fw(weight);
  }
  
  // fi -> vertex_num. , se -> depth
  // [l,r)
  pair<int,int> LCA(int l,int r,int a,int b,int u)
  {
    if(r<=a || b<=l) return {-1,n+1};
    if(l<=a && b<=r) return seg_lca[u];
    pair<int,int> x=LCA(l,r,a,(a+b)/2,2*u),y=LCA(l,r,(a+b)/2,b,2*u+1);
    if(x.second<y.second) return x;
    else return y;
  }
  
  // [u,v]
  // the lca depth is path_v[lca][2] or lca.se.
  int lca(int u,int v)
  {
    if(path_v[u][0]>path_v[v][0]) swap(u,v);
    return LCA(path_v[u][0]+1,path_v[v][0]+2,1,size+1,1).first;
  }
  
  // idx is edge num.
  void changeWeight(const int idx,const T w)
  {
    if(path_v[adjMat[idx][0]][3]==adjMat[idx][1])
    {
      f.update(path_v[adjMat[idx][0]][0],w);
      f.update(path_v[adjMat[idx][0]][1],-w);
    }
    else
    {
      f.update(path_v[adjMat[idx][1]][0],w);
      f.update(path_v[adjMat[idx][1]][1],-w);
    }
  }
  
  T sumWeight(const int u,const int v)
  {
    return f.apply(0,path_v[u][0]+2)+f.apply(0,path_v[v][0]+2)-2*f.apply(0,path_v[lca(u,v)][0]+2);
  }
};
