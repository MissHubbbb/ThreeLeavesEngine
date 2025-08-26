//***************************************************************************************
// GameTimer.h by Frank Luna (C) 2011 All Rights Reserved.
//***************************************************************************************

#ifndef GAMETIMER_H
#define GAMETIMER_H

class GameTimer
{
public:
	GameTimer();

	float TotalTime()const; // in seconds
	float DeltaTime()const; // in seconds

	void Reset(); // Call before message loop.
	void Start(); // Call when unpaused.
	void Stop();  // Call when paused.
	void Tick();  // Call every frame.

private:
	double mSecondsPerCount;
	double mDeltaTime;

	__int64 mBaseTime;
	__int64 mPausedTime;	// 累计暂停的时间
	__int64 mStopTime;		// 记录最后一次暂停的时间点
	__int64 mPrevTime;
	__int64 mCurrTime;
	// _int64 startTime;		// Start()函数内的变量，表示再次开始运行的时间点

	bool mStopped;
};

#endif // GAMETIMER_H