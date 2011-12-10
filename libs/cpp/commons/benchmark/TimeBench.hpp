/*
 * TimeBench.hpp
 *
 *  Created on: Dec 6, 2011
 *      Author: issle
 */

#ifndef TIMEBENCH_HPP_
#define TIMEBENCH_HPP_

#include <iostream>
#include <map>
#include <time.h>
#include <sys/time.h>

using namespace std;

/**
 * A Time Probe is an object that contains the time value at
 * two distinct points in time.
 */
class TimeProbe
{
private:

	/*
	 * Time at which measurement started.
	 */
	timeval* start;

	/*
	 * Time at which measurement ended.
	 */
	timeval* end;

	/*
	 * Status of measurement.
	 */
	int status;

public:

	~TimeProbe()
	{
		delete start;
		delete end;
	}

	/*
	 * No time value has been recorded.
	 */
	static const int INACTIVE = 0;

	/*
	 * One time value has been recorded and
	 * one more time value is allowed to be
	 * recorded.
	 */
	static const int OPEN = 1;

	/*
	 * Two time values have been recorded
	 * and no more values can be recorded.
	 */
	static const int CLOSED = 2;

    timeval *getEnd() const
	{
		return end;
	}

	timeval *getStart() const
	{
		return start;
	}

	int getStatus() const
	{
		return status;
	}

	void setEnd(timeval *end)
	{
		this->end = end;
	}

	void setStart(timeval *start)
	{
		this->start = start;
	}

	void setStatus(int status)
	{
		this->status = status;
	}

};

/**
 * A TimeBench ( Time Benchmark ) is an object that exposes
 * probing functionality towards an application. A user can
 * set probes between different sections of code. Each probe
 * has two end points, each of them measures the time value
 * in two different sections of the code.
 */
class TimeBench
{
private:

	/*
	 * Contains TimeProbes identified by their unique name.
	 */
	map<string, TimeProbe*> probes;

public:

	TimeBench()
	{

	}

	~TimeBench()
	{

		for(map<string , TimeProbe* >::iterator iter = probes.begin(); iter != probes.end(); iter++)
		{
			TimeProbe* probe = iter->second;
			delete probe;
		}
	}

	/*
	 * Opens a probe without a name.
	 */
	void tic()
	{
		openProbe("toc");
	}

	/*
	 * Closes a probe with a given description.
	 */
	void toc(string s)
	{
		closeProbe("toc");
		cout<< s <<":";
		printProbe("toc");
	}

	/**
	 * Open the probe with the specified name and measures
	 * the time value at that point in the program's path
	 * of execution.
	 *
	 * If a probe for that name already exists, this method
	 * does nothing.
	 */
	void openProbe(string s)
	{
		TimeProbe* tp;

		if (probes[s] == 0)
		{
			tp = new TimeProbe();
			probes[s] = tp;
		}
		else
		{
			tp = probes[s];
		}
		if (tp->getStatus() != TimeProbe::INACTIVE)
			return;

		tp->setStatus(TimeProbe::OPEN);

		timeval* tv = new timeval();
		struct timezone tz;

		gettimeofday(tv, &tz);
		tp->setStart(tv);

	}

	/**
	 * Closes the probe for the given name. If the probe
	 * is not open or if the probe is already closed this
	 * method does nothing.
	 */
	void closeProbe(string s)
	{

		TimeProbe* tp;
		if (probes[s] == 0)
			return;

		tp = probes[s];

		if (tp->getStatus() != TimeProbe::OPEN)
			return;

		timeval* tv = new timeval();
		struct timezone tz;
		gettimeofday(tv, NULL);
		tp->setEnd(tv);

		tp->setStatus(TimeProbe::CLOSED);

	}

	/*
	 * Prints the probe with the specified name. There
	 * are certain conditions that this method wont print
	 * anything:
	 *
	 * 1) No such probe exists.
	 * 2) The probe has not been closed.
	 */
	void printProbe(string s)
	{
		TimeProbe* tp;

		if (probes[s] == 0)
			return;
		tp = probes[s];

		if (tp->getStatus() != TimeProbe::CLOSED)
			return;

		timeval* t1 = tp->getStart();
		timeval* t2 = tp->getEnd();

		if (t1->tv_usec > t2->tv_usec)
		{
			t2->tv_usec += 1000000;
			t2->tv_sec--;
		}

		timeval lapsed;
		lapsed.tv_usec = t2->tv_usec - t1->tv_usec;
		lapsed.tv_sec = (int) (t2->tv_sec - t1->tv_sec);
		cout << s << ": ";
		printf("Time elapsed: %d.%06dsec\n", (int) lapsed.tv_sec,(int) lapsed.tv_usec);

	}

};

#endif /* TIMEBENCH_HPP_ */
