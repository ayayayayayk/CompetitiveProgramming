#include <chrono>
#include <ctime>
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
