#include "timer.h"
#include <chrono>
#include <sstream>



Timer::Timer() {
}

Timer::~Timer() {

}

void Timer::start() {
	stopped = false;
	this->start_point = std::chrono::high_resolution_clock::now();
}

void Timer::reset() {
	stopped = false;
	this->start_point = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
	stopped = true;
}

__int64 Timer::timeElapsed(TimeUnit t) {

	if (stopped)
		return 0;

	__int64 elapsed_time;
	auto now = std::chrono::high_resolution_clock::now();

	switch (t) {
	case NANOSECONDS: elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(now - this->start_point).count(); break;
	case MICROSECONDS: elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(now - this->start_point).count(); break;
	case MILLISECONDS: elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->start_point).count(); break;
	case SECONDS: elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(now - this->start_point).count(); break;
	case MINUTES: elapsed_time = std::chrono::duration_cast<std::chrono::minutes>(now - this->start_point).count(); break;
	case HOURS: elapsed_time = std::chrono::duration_cast<std::chrono::hours>(now - this->start_point).count(); break;
	default:break;
	}

	return elapsed_time;
}

std::string Timer::timeElapsedStr(TimeUnit t, bool lbl) {
	std::stringstream ss;

	long double nanos;
	long double micros;
	long double millis;
	long double seconds;
	long double minutes;
	long double hours;

	switch (t) {
	case NANOSECONDS:
		nanos = static_cast<double>(this->timeElapsed(t));
		ss << nanos; if (lbl) ss << "ns"; break;
	case MICROSECONDS:
		nanos = static_cast<double>(this->timeElapsed(NANOSECONDS));
		micros = nanos / 1000.0;
		ss << micros; if (lbl) ss << "ms"; break;
	case MILLISECONDS:
		nanos = static_cast<double>(this->timeElapsed(NANOSECONDS));
		micros = nanos / 1000.0;
		millis = micros / 1000.0;
		ss << millis; if (lbl) ss <<"ms"; break;
	case SECONDS:
		nanos = static_cast<double>(this->timeElapsed(NANOSECONDS));
		micros = nanos / 1000.0;
		millis = micros / 1000.0;
		seconds = millis / 1000.0;
		ss << seconds; if (lbl) ss << "s"; break;
	case MINUTES:
		nanos = static_cast<double>(this->timeElapsed(NANOSECONDS));
		micros = nanos / 1000.0;
		millis = micros / 1000.0;
		seconds = millis / 1000.0;
		minutes = seconds / 60.0;
		ss << minutes; if (lbl)  ss << "min"; break;
	case HOURS:
		nanos = static_cast<double>(this->timeElapsed(NANOSECONDS));
		micros = nanos / 1000.0;
		millis = micros / 1000.0;
		seconds = millis / 1000.0;
		minutes = seconds / 60.0;
		hours = minutes / 60.0;
		ss << hours; if (lbl) ss << "h"; break;
	default: 
		break;
	}

	return ss.str();
}