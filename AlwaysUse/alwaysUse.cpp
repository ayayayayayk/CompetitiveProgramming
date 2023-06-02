//#include <bits/stdc++.h>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cfenv>
#include <cinttypes>
#include <cstdint>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <atcoder/all>
//#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using unit = unsigned int;
using ull = unsigned long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<ld>;
using vvd = vector<vd>;
using vc = vector<char>;
using vvc = vector<vc>;
using str = string;
using vs = vector<str>;
using vvs = vector<vs>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using psl = pair<str,ll>;
using vpsl = vector<psl>;
using pls = pair<ll,str>;
using vpls = vector<pls>;
using psi = pair<str,int>;
using vpsi = vector<psi>;
using pis = pair<int,str>;
using vpis = vector<pis>;
using tiii = tuple<int,int,int>;
using tiil = tuple<int,int,ll>;
using tili = tuple<int,ll,int>;
using tlii = tuple<ll,int,int>;
using till = tuple<int,ll,ll>;
using tlil = tuple<ll,int,ll>;
using tlli = tuple<ll,ll,int>;
using tiis = tuple<int,int,str>;
using tisi = tuple<int,str,int>;
using tsii = tuple<str,int,int>;
using tiss = tuple<int,str,str>;
using tsis = tuple<str,int,str>;
using tssi = tuple<str,str,int>;
using tlll = tuple<ll,ll,ll>;
using tsss = tuple<str,str,str>;
using tssl = tuple<str,str,ll>;
using tsls = tuple<str,ll,str>;
using tlss = tuple<ll,str,str>;
using tsll = tuple<str,ll,ll>;
using tlsl = tuple<ll,str,ll>;
using tlls = tuple<ll,ll,str>;
using tils = tuple<int,ll,str>;
using tisl = tuple<int,str,ll>;
using tlis = tuple<ll,int,str>;
using tsil = tuple<str,int,ll>;
using tlsi = tuple<ll,str,int>;
using tsli = tuple<str,ll,int>;
constexpr ll INF=(ll)9223372036854775807;
constexpr int IINF = (int)2147483647;
constexpr ld PI = acos((ld)-1);
const str yes = "Yes";
const str no = "No";
constexpr ld EPS = 1E-12;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define repi(j, i, n) for (int j = i; j < (int)(n); j++)
#define repr(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define repin(e, a) for (auto&& e: (a))
#define pb push_back
#define prt(a) cout << a << endl
#define prtd(a) cout << setprecision(15) << a << endl
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define str(s) to_string(s)
template<class T> ld lg(const T &a,const T &b){return log(a)/log(b);}
template <class T,class U> ll count(T &a,U b){ll x=0; repin(i,a)if(i==b)x+=1; return x;}
inline str toUpper(str s){
  transform(s.cbegin(), s.cend(), s.begin(), ::toupper);
  return s;
}
inline str toLower(str s){
  transform(s.cbegin(), s.cend(), s.begin(), ::tolower);
  return s;
}
template<class T,class S>ll modInv(T a, S m) {
  // assert(gcd(a,m)==1);
  ll p = gcd(a,m), x = a/p, y = m/p, u = 1, v = 0;
  while (y) {
    ll t = x / y;
    x -= t * y; swap(x, y);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u*p;
}
 
 
 
// mint
// using mint = modint998244353;
// using mint = modint1000000007;
using mint = modint;
using vm = vector<mint>;
using vvm = vector<vm>;
using pmm = pair<mint,mint>;
using vpmm = vector<pmm>;
using psm = pair<str,mint>;
using vpsm = vector<psm>;
using plm = pair<ll,mint>;
using vplm = vector<plm>;
using pml = pair<mint,ll>;
using vpml = vector<pml>;
inline void prtm(const mint &a) {cout << a.val() << endl;}
inline void printm(const vm &a) {ll x=a.size(); rep(i,x) x>1 ? i<x-1 ? i>0 ? cout << " " << a[i].val() : cout << a[i].val() : cout << " " << a[i].val() << endl : prt(a[i].val()) ;}
template<class T> inline void scanm(T &a) {ll x=a.size(); rep(i,x){int y; cin >> y; a[i]=y;}}
 
 
 
// set
template<class T> inline T set_max(const set<T>& st) {return *rbegin(st);}
template<class T> inline T set_min(const set<T>& st) {return *begin(st);}
template<class T> inline void set_unite(set<T>& a,set<T>& b,set<T>& c){
  // c <- a + b;
  set_union(all(a),all(b),inserter(c,end(c)));
}
 
 
 
// multiset
template<class T> inline T multiset_max(const multiset<T>& st) {return *prev(st.end());}
template<class T> inline T multiset_min(const multiset<T>& st) {return *st.begin();}
template<class T> inline bool Contains(const multiset<T>& st, T x) {return st.find(x) != st.end();}
template<class T> inline bool EraseOne(multiset<T>& st, T x) {auto it=st.find(x); if (it!=st.end()) {st.erase(it); return true;} else return false;}  // delete only one element and return yes if can delete.
 
 
 
// vector
#define srt(a) sort(all(a))
#define srtr(a) sort(rall(a))
#define len(a) (ll)(a).size()
template<class T> inline void print(const T &a) {ll x=len(a); rep(i,x) x>1 ? i<x-1 ? i>0 ? cout << " " << a[i] : cout << a[i] : cout << " " << a[i] << endl : prt(a[i]) ;}
template<class T> inline void scan(T &a) {ll x=len(a); rep(i,x) cin >> a[i];}
template<class T>inline void vec_sortl(vector<T> &s){sort(all(s), [] (T &x, T &y) { return len(x) < len(y);});}
template<class T> inline ll vec_max(T &a) {return *max_element(all(a));}
template<class T> inline ll vec_min(T &a) {return *min_element(all(a));}
template<class T> inline ll vec_sum(T &a) {ll x=0; repin(i,a) x+=i; return x;}
template<class T,class U> inline ll lbd(T &a,U x) {ll y; len(a)>0 ? y=lower_bound(all(a),x)-a.begin() : y=-1; return y;}
template<class T,class U> inline ll ubd(T &a,U x) {ll y; len(a)>0 ? y=upper_bound(all(a),x)-a.begin() : y=-1; return y;}
template<class T> inline void ers(T &a) {srt(a); a.erase(unique(all(a)),a.end());}
 
 
/*
// arrangement
#define size(a) (ll)sizeof(a)/sizeof(*a)
#define srt(a) sort(a,a+size(a))
#define rsrt(a) sort(a,a+size(a),greater<int>())
template<class T,size_t S> void print(const T (&a)[S]) {rep(i,S) i>0 ? i<S-1 ? cout << " " << a[i] : cout << " " << a[i] << endl : cout << a[i];}
template<class T,size_t S> void scan(T (&a)[S]) {rep(i,S) cin >> a[i];}
template<class T,size_t S> ll max(T (&a)[S]) {return *max_element(a,a+S);}
template<class T,size_t S> ll min(T (&a)[S]) {return *min_element(a,a+S);}
template<class T,size_t S> ll sum(T (&a)[S]) {ll x=0; rep(i,S) x+=a[i]; return x;}
*/
 
 
 
// xoroshiro128++
// this struct is a pseudorandom number generator.
// U must set seed w/ xoro.set_seed.
// in general, the recommended seed is {123456789, 362436069}.
struct xoroshiro128pp
{
  vector<uint64_t> xoro_seed;
  
  xoroshiro128pp(const uint64_t s0=123456789, const uint64_t s1=362436069):
  xoro_seed({s0, s1}){}
  
  inline void set_seed(const vector<uint64_t> s)
  {
    assert(len(s)==2);
    xoro_seed=s;
  }
  
  static inline uint64_t rotl(const uint64_t x, int k)
  {
    return (x << k) | (x >> (64 - k));
  }
  
  uint64_t next(void)
  {
    const uint64_t s0 = xoro_seed[0];
    uint64_t s1 = xoro_seed[1];
    const uint64_t result = rotl(s0 + s1, 17) + s0;
    s1 ^= s0;
    xoro_seed[0] = rotl(s0, 49) ^ s1 ^ (s1 << 21);
    xoro_seed[1] = rotl(s1, 28);
    return result;
  }
  
  template<class T, class U> inline ll rand(T a, U b)
  {
    assert(a < b);
    return next() % (b - a) + a;
  }
};
 
 
 
// the time_threshold, the TimeKeeper argument, is only used w/ the isTimeOver func.
class TimeKeeper
{
private:
  chrono::high_resolution_clock::time_point start_time_;
  int64_t time_threshold_;
 
public:
  TimeKeeper(const int64_t &time_threshold=0)
    : start_time_(chrono::high_resolution_clock::now()),
  time_threshold_(time_threshold)
  {
  }
 
  // return whether now-time is above time_threshold_.
  bool isTimeOver() const
  {
    auto diff = chrono::high_resolution_clock::now() - this->start_time_;
    return chrono::duration_cast<chrono::milliseconds>(diff).count() >= time_threshold_;
  }
  
  // return milli-seconds.
  ld elapsed_time() 
  {
    auto diff = chrono::high_resolution_clock::now() - this->start_time_;
    return (ld)(chrono::duration_cast<chrono::milliseconds>(diff).count());
  }
  
};
 
 
 
template<class T> ld squareRoot(T value)
{
  assert(value>=0);
  ld ok=0,ng=sqrt(INF);
  while(ng*ng-ok*ok>1)
  {
    ld mid=(ok+ng)/2;
    if(mid*mid>value) ng=mid;
    else ok=mid;
  }
  return ok;
}



template<typename T> struct mat
{
  vector<vector<T>> m;
  // constructor
  // idx 0->row, 1->col, 2->first value
  mat():m(vector<vector<T>>()){}
  mat(int h,int w):m(vector<vector<T>>(h,vector<T>(w))){}
  mat(int h,int w, T d):m(vector<vector<T>>(h,vector<T>(w,d))){}
  
  vector<T> operator[](const int i) const {return m[i];}
  vector<T>& operator[](const int i){return m[i];}
  int nrow = len(m);
  int ncol = len(m[0]);
  mat& operator=(const mat& a){return *a;}
  mat& operator+=(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] += a[i][j]; return *this;}
  mat& operator-=(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] -= a[i][j]; return *this;} 
  mat& operator*=(const mat& a){assert(ncol == a.nrow);mat<T> m2(nrow, a.ncol, 0);rep(i,nrow)rep(j,a.ncol)rep(k,ncol)m2[i][j] += m[i][k]*a[k][j];ncol = a.ncol;rep(i,nrow)m[i].resize(ncol);rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j]; return *this;}
  mat operator+(const mat& a) const { return mat(*this) += a;}
  mat operator-(const mat& a) const { return mat(*this) -= a;}
  mat operator*(const mat& a) const { return mat(*this) *= a;}
  bool operator==(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);bool flg = true;rep(i,nrow)rep(j,ncol)if(m[i][j] != a[i][j])flg = false; return flg;}
  mat& operator+=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] += a;return *this;}
  mat& operator-=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] -= a;return *this;}
  mat& operator*=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] *= a;return *this;}
  mat& operator/=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] /= a;return *this;}
  mat operator+(const T& a) const { return mat(*this) += a;}
  mat operator-(const T& a) const { return mat(*this) -= a;}
  mat operator*(const T& a) const { return mat(*this) *= a;}
  mat operator/(const T& a) const { return mat(*this) /= a;}
    
  //rotate
  mat& rot(int deg){
    assert(deg>=0 && deg<4);
    if(deg==0)return *this;
    mat<T> m2(ncol, nrow);
    if(deg == 1 || deg == 3){
      if(deg == 1)rep(i,nrow)rep(j,ncol)m2[j][nrow -i -1] = m[i][j];
      else rep(i,nrow)rep(j,ncol)m2[ncol -j -1][i] = m[i][j];
      swap(ncol,nrow);
      m.resize(nrow);rep(i,nrow)m[i].resize(ncol);
    }
    else if(deg == 2)rep(i,nrow)rep(j,ncol)m2[nrow -i -1][ncol -j -1] = m[i][j];
    rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j];
    return *this;
  }
};



int main(){
  //auto time_keeper = TimeKeeper(9000);
  //modint::set_mod(998244353);
  
  
}


