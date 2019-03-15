#ifndef auto_lock_h__
#define auto_lock_h__

#include "common.h"

namespace DroidPad
{

class CAutoLock
{
  public:
	CAutoLock(CRITICAL_SECTION *cs) : m_cs(cs)
	{
		EnterCriticalSection(m_cs);
	}
	~CAutoLock()
	{
		LeaveCriticalSection(m_cs);
	}

  private:
	CRITICAL_SECTION *m_cs;
};

}

#endif // auto_lock_h__
