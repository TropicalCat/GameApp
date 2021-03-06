/*
 * -----------------------------------------------------------------------------
 *  file name : CityMatrix.cs
 *  desc      : 个人战略基地，主要实现各种建筑无的养成和点选操作
 *  log       :
 *  author    : ljp
 * -----------------------------------------------------------------------------
*/
using UnityEngine;
using System.Collections;
using System;
using System.Collections.Generic;





public class CityMatrix 
{

    /// -----------------------------------------------------------------------
    /// <summary>
    /// 可养成建筑物类象
    /// </summary>
    /// -----------------------------------------------------------------------
    enum buildtype
    {
        cby_city,                   // 主城
        cby_wenpon_factory,         // 武器工厂
        cby_ship_factory,           // 舰艇工厂
        cby_matrix_factory,         // 材料工厂
        cby_technology_factory,     // 科技工厂
        cby_power_factory,          // 动力工厂
        cby_train_factory,          // 训练营地
        cby_biology_factory,        // 生物工厂
        cby_Soldiers_factory,       // 士兵工厂
    };


	private List<UnityEngine.GameObject> 	 m_listHero;
	private Dictionary< string, CHeroEntity> m_mapPrefabs;
	private UnityEngine.GameObject			 m_curSelCar 	= null;
	void Awake ()     
	{
		
	}
	
	// Use this for initialization
	void Start () 
	{
		UpdateHeroPic ();

	}
	
	// Update is called once per frame
	void Update () 
	{

	}

	private void UpdateModel( CHeroEntity pEntity )
	{
		if ( m_curSelCar != null ) 
		{
			m_curSelCar.SetActive( false );
			m_curSelCar = null;
		}

		m_curSelCar = pEntity.gameObject;
		m_curSelCar.SetActive (true);

		m_curSelCar.transform.localPosition = new Vector3 ( 14.3f, 53.4f, -25.1f);
		m_curSelCar.transform.localScale 	= new Vector3 ( 1.5f, 1.5f, 1.5f);
	}

	void on_itemClickHero( UnityEngine.GameObject item )
	{
		CHeroEntity pEntity = null;
		m_mapPrefabs.TryGetValue (item.name, out pEntity );
		if (pEntity != null) 
		{

            CFightTeamMgr.Instance.m_pBattleHero = pEntity;

			UpdateModel( pEntity );
		}
	}
	
	void on_itemMouseOverHero(UnityEngine.GameObject item, bool isOver)
	{
		if(isOver == true)
			Common.DEBUG_MSG("on_itemMouseOver: " + item.name);
		else
			Common.DEBUG_MSG("on_itemMouseOver: " + item.name);
	}

	void UpdateHeroPic( )
	{

		int i = 0;
        foreach (var item in CFightTeamMgr.Instance.m_mapHero)	
		{
			CHeroEntity pEntity =  item.Value;
			if( pEntity != null )
			{
				tagHeroProto pProto = pEntity.GetProto();
				if( pProto == null )
					continue;
				
				if( i < m_listHero.Count )
				{
					UIAtlas tu = Resources.Load("GameIcon", typeof(UIAtlas)) as UIAtlas;
					UnityEngine.GameObject ctrl = m_listHero[i];
					ctrl.GetComponent<UISprite>().atlas = tu;
					ctrl.GetComponent<UISprite>().spriteName = pProto.strIcon;

					m_mapPrefabs.Add( ctrl.name, pEntity );
				}


				if( m_curSelCar == null )
				{
					UpdateModel( pEntity );
				}

				i++;
			}
		}
	}
}
 