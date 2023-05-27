template<class T> struct BIT
{
  vector<int> bit;
  vector<T> v;
  int n,size;
  
  BIT(const vector<T>& a): n(a.size())
  {
    set<int> b(a.begin(),a.end());
    map<T,int> m;
    int count=1;
    for (auto&& i: (b)){
      m[i]=count;
      count++;
    }
    bit=vector<int>(count);
    v=vector<int>(n);
    size=count;
    for(int i=0;i<n;i++)v[i]=m[a[i]];
  }
  
  void add(const T a,const int w)
  {
    for (int x = a; x < size; x += x & -x){
      bit[x] += w;
    }
  }
  
  int sum(const T a)
  {
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
  }
  
  long long allInversion()
  {
    long long all_inversion=0;
    for(int i=0;i<n;i++)
    {
      all_inversion+=i-sum(v[i]);
      add(v[i],1);
    }
    return all_inversion;
  }
};
