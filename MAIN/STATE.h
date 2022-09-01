#ifndef STATE_HD
#define STATE_HD

#include"../libOne/inc/graphic.h"
class STATE{
public:
	virtual ~STATE() { refreshCntnr(); }
	virtual void proc( class MANAGER* manager ) = 0;
};

#endif