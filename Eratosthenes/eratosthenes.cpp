template<class T> vector<T> eratosthenes(const T n){
  vb is_prime(n+1,true);
  vector<T> p;
  repi(i,2,n+1){
    if(is_prime[i]){
      for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
      p.emplace_back(i);
    }
  }
  return p;
}
