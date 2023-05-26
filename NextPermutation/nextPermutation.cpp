template<class T> vector<vector<T>> nextPermutation(vector<T> a){
  srt(a);
  int n=len(a),count=0;
  ll x=1;
  repi(i,1,n)x*=i+1;
  vector<vector<T>> z(x,vector<T>(n));
  do{
    rep(i,n)z[count][i]=a[i];
    count++;
  }while(next_permutation(all(a)));
  return z;
}
