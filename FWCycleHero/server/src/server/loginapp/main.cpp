/*
----------------------------------------------------------------------------------------------------
		file name : main.cpp
		desc	  : ��¼��������������ļ�
		author    : LJP

		log		  : [2015-04-26]
----------------------------------------------------------------------------------------------------
*/
#include "loginapp.hpp"




using namespace KBEngine;																				
int main(int argc, char* argv[])																						
{		

	
	Loginapp app;
	if (app.Initialize(LOGINAPP_TYPE))
	{
		app.MainLoop();
	}

	app.Destroy();
	
	return 0;
}


