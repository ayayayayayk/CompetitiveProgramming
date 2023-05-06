template<class T> struct BIT
{
  vector<int> bit;
  vector<T> v;
  int n,size;
  
  BIT(const vector<T>& a): n(a.size())
  {
    T x=1-min((T)1,(T)*min_element(a.begin(),a.end()));
    bit=vector<int>(*max_element(a.begin(),a.end())+1+x);
    v=vector<T>(n,x);
    rep(i,n) v[i]+=a[i];
    size=bit.size();
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
    rep(i,n)
    {
      all_inversion+=i-sum(v[i]);
      add(v[i],1);
    }
    return all_inversion;
  }
};
