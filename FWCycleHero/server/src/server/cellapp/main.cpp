/*
----------------------------------------------------------------------------------------------------
		file name : 
		desc      : �����������������
		author	  : ljp

		log		  : by ljp create 2017-06-11
----------------------------------------------------------------------------------------------------
*/
#include "cellapp.h"




using namespace KBEngine;
int main(int argc, char* argv[])
{
	CellServerApp app;
	if (app.Initialize(CELLAPP_TYPE))
	{
		app.MainLoop();
	}
	return 0; 
}
