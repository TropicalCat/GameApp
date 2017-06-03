using UnityEngine;
using System.Collections;
using System;
using System.Collections.Generic;




//-----------------------------------------------------------------------------
// Buff效果类型
//-----------------------------------------------------------------------------
enum EBuffEffectType
{
	EBET_Null			=	0,		// 无
	EBET_Teleport		=	1,		// 瞬间移动
	EBET_Dizzy			=	2,		// 眩晕
	EBET_Repel			=	3,		// 击退
	EBET_Assault		=	4,		// 冲锋
	EBET_NoSkill		=	5,		// 封技
	EBET_Spor			=	6,		// 昏睡
	EBET_Tie			=	7,		// 定身
	EBET_Invincible		=	8,		// 无敌
	EBET_Pull			=	9,		// 拖拽
	EBET_Lurk			=	10,		// 隐身
	EBET_Funk			=	11,		// 恐惧
	EBET_Sneer			=	12,		// 嘲讽
	EBET_Suspension		= 	13,		// 悬浮
	EBET_End			,
};

class CBufEffect 
{


	public CBufEffect()
	{

	}

	~CBufEffect()  // destructor
    {
    	
    }


}

