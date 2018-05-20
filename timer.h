#ifndef _TIMER_H_
#define _TIMER_H_

#include <cstdint>
#include <chrono>
#include <string>

enum TimeUnit {
	NANOSECONDS,
	MICROSECONDS,
	MILLISECONDS,
	SECONDS,
	MINUTES,
	HOURS
};

class Timer {
public:
	Timer();
	~Timer();

	void start();

	void reset();

	void stop();

	__int64 timeElapsed(TimeUnit t);

	std::string timeElapsedStr(TimeUnit t, bool lbl = false);

private:
	std::chrono::high_resolution_clock::time_point start_point;

	bool stopped;
};

#endif // !_TIMER_H_
