/*
------------------------------------------------------------------------------------------------------------------
file Name	:
desc		: DBMgr �������
author		:
log			:
------------------------------------------------------------------------------------------------------------------
*/
#include "dbmgr.hpp"



using namespace KBEngine;
int main(int argc, char* argv[])
{
	AppDBServer app;
	if (app.Initialize(DBMGR_TYPE))
	{
		app.MainLoop();
	}
	return 0;
}
