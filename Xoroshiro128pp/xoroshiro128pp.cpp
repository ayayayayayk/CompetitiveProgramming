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
