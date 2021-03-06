using System;
using UnityEngine;







    //-------------------------------------------------------------------------------
    // 人物基本属性枚举(该处枚举顺序、个数调整,可能会影响到数据库装备表)
    //-------------------------------------------------------------------------------
    enum ERoleAttribute
    {
        ERA_Null = -1,		//

        // 一级属性
        ERA_AttA_Start          = 0,
        ERA_Physique            = 0,		// 当前筋骨	
        ERA_Strength            = 1,		// 当前劲力	
        ERA_Pneuma              = 2,		// 当前元气
        ERA_InnerForce          = 3,		// 当前真气 	
        ERA_Technique           = 4,		// 当前技力		
        ERA_Agility             = 5,		// 当前身法
        ERA_AttA_End            = 5,

        // 玩家的点数
        ERA_AttPoint            = 6,		// 当前属性点数
        ERA_TalentPoint         = 7,		// 当前天资点数

        // 二级属性
        ERA_AttB_Start          = 8,
        ERA_MaxHP               = 8,		// 最大体力
        ERA_HP                  = 9,		// 当前体力
        ERA_MaxMP               = 10,		// 最大真气
        ERA_MP                  = 11,		// 当前真气
        ERA_ExAttack            = 12,		// 外功攻击
        ERA_ExDefense           = 13,		// 外功防御
        ERA_InAttack            = 14,		// 内功攻击
        ERA_InDefense           = 15,		// 内功防御
        ERA_HitRate             = 16,		// 命中率
        ERA_Dodge               = 17,		// 闪避率
        ERA_Endurance           = 18,		// 持久力
        ERA_MaxEndurance        = 19,		// 持久力上限
        ERA_AttB_End            = 20,

        // 固有属性
        ERA_HPRegainRate        = 21,		// 体力恢复速度
        ERA_MPRegainRate        = 22,		// 真气恢复速度
        ERA_Speed_XZ            = 23,		// XZ平面速度速度
        ERA_Speed_Y             = 24,		// Y方向速度
        ERA_Speed_Mount         = 25,		// 骑乘的XZ速度
        ERA_WeaponDmgMin        = 26,		// 最小武器攻击
        ERA_WeaponDmgMax        = 27,		// 最大武器攻击
        ERA_Armor               = 28,		// 防具护甲
       
        ERA_Derate_Start        = 29,
        ERA_Derate_Ordinary     = 29,		// 普通伤害减免
        ERA_Derate_ExAttack     = 30,		// 外功伤害减免
        ERA_Derate_InAttack     = 31,		// 内功伤害减免
        ERA_Derate_ALL          = 32,		// 所有伤害减免
        ERA_Derate_End          = 33,

        ERA_ExDamage            = 33,		// 额外伤害
        ERA_ExDamage_Absorb     = 34,		// 额外伤害吸收
        ERA_Attack_MissRate     = 35,		// 攻击失误率
      
        ERA_Crit_Rate           = 36,		// 致命率加成
        ERA_Crit_Amount         = 37,		// 致命量加成
        ERA_Block_Rate          = 38,		// 格挡率加成

        ERA_Inspiration         = 39,		// 灵感
        ERA_Enmity_Degree       = 40,		// 仇恨度
        ERA_Shape               = 41,		// 体型
        ERA_Exp_Add_Rate        = 42,		// 经验获得加成		原经验/金钱/掉率 * (1+加成/10000)
        ERA_Money_Add_Rate      = 43,		// 金钱获得加成
        ERA_Loot_Add_Rate       = 44,		// 物品掉落几率加成

        // 社会属性
        ERA_Morality            = 45,		// 罪恶值

        ERA_End                 = 46,

    }


	//--------------------------------------------------------------------------
	// 角色与生物公有状态标示
	//--------------------------------------------------------------------------
	enum EState
	{
		ES_Dead					=	0,	// 死亡
		ES_Dizzy				=	1,	// 眩晕
		ES_Tie					=	2,	// 定身
		ES_Spor					=	3,	// 昏睡
		ES_Invincible			=	4,	// 无敌
		ES_Lurk					=	5,	// 隐身
		ES_DisArm				=	6,	// 缴械
		ES_NoSkill				=	7,	// 封技
		ES_Suspension			=   8,  // 悬浮
		ES_End					=	9,
	}

	
	//--------------------------------------------------------------------------
	// 英雄数据结构定义
	//--------------------------------------------------------------------------
	class tagHeroProto
	{
		public uint			dwID;
        public string       strName;
        public string       strDesc;
		public string		strIcon;
		public string      	strModel;
		public uint			dwSkill1;
		public uint			dwSkill2;
        public uint         dwSkill3;
        public uint         dwSkill4;
	}


	class tagCycleProto
	{
		public uint			dwID;
		public string		strIcon;
		public string      	strModel;
		public uint			dwSkill1;
		public uint			dwSkill2;
	}


	class tagLevelUpEffect
	{
		public int 			nLevel;
		public int			nExpLevelUp;
		public int[]		nRoleAtt;
		public int			nMaxHP;
		public int			nMaxMP;

		public tagLevelUpEffect()
		{
			nRoleAtt = new int[5];
		}
	}

	
	class tagTeamLevelEffect
	{
		public int 			nLevel;
		public int			nExpLevelUp;
		public int			nPhysique;
	}
