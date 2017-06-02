/*
-----------------------------------------------------------------------------
		file name : task.hpp
		desc      : ����һ������
		author    : ljp

		log       : create by ljp [ 2015-11-22 ]
-----------------------------------------------------------------------------
*/

#ifndef KBE_TASK_HPP
#define KBE_TASK_HPP
#include "common/common.hpp"






namespace KBEngine
{

	/**
	 *	����һ������
	 */
	class Task
	{
	public:
		virtual ~Task() {}
		virtual bool process() = 0;
	};
}

#endif // KBE_TASK_HPP
