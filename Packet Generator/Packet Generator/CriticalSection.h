#include"stdafx.h"

#ifndef _CRITICALSECTION_H_
#define _CRITICALSECTION_H_

class CriticalSection			///state this class in class first
{
private:
	CRITICAL_SECTION criticalSection;

public:
	CriticalSection() { InitializeCriticalSection(&criticalSection); }
	~CriticalSection() { DeleteCriticalSection(&criticalSection); }
	inline void Enter() { EnterCriticalSection(&criticalSection); }
	inline void Leave() { LeaveCriticalSection(&criticalSection); }
};

class CriticalSectionSync		///and then use this class with CriticalSection class in function
{								///this created when function is started automatically
private:						///this destroyed when function is ended automatically
	CriticalSection& lock;

public:
	CriticalSectionSync(CriticalSection& cs) :lock(cs)
	{
		lock.Enter();
	}
	~CriticalSectionSync()
	{
		lock.Leave();
	}
};

#endif // !_CRITICALSECTION_H_
