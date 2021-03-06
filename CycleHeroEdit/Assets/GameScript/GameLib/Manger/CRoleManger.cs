using UnityEngine;
using System.Collections;
using System;
using System.Collections.Generic;




// 一些物体的缓存对象
class CObjectCache
{


    private int     m_cacheSize = 10;
    private int     m_cacheIndex= 0;


    public  UnityEngine.GameObject   m_prefab = null;
    private UnityEngine.GameObject[] m_objects;


    public void Initialize()
    {
        m_objects = new UnityEngine.GameObject[m_cacheSize];
        // Instantiate the objects in the array and set them to be inactive
		for (int i = 0; i < m_cacheSize; i++)
		{
			m_objects[i].SetActive (false);
			m_objects[i].name = m_objects[i].name + i;
		}
    }

	public int 	GetCacheSize()
	{
		return m_cacheSize;
	}

    public UnityEngine.GameObject NextObjectInCache()
    {

        UnityEngine.GameObject obj = null;
        for (int i  = 0; i < m_cacheSize; i++) 
        {
			obj = m_objects[m_cacheIndex];

			// If we found an inactive object in the cache, use that.
			if (!obj.activeSelf)
				break;

			// If not, increment index and make it loop around
			// if it exceeds the size of the cache
			m_cacheIndex = (m_cacheIndex + 1) % m_cacheSize;
		}

        if (obj.activeSelf) 
        {
			CRoleManger.Destroy (obj);
		}

		// Increment index and make it loop around
		// if it exceeds the size of the cache
		m_cacheIndex = (m_cacheIndex + 1) % m_cacheSize;

		return obj;
    }

}

// 管理战斗中的所有物体
public class CRoleManger
{



	public  static CRoleManger  m_rolemgr = null;

    private CObjectCache[]      m_caches;
    private Hashtable           activeCachedObjects;


	public CRoleManger()
	{

		m_caches   = new CObjectCache[2];
		m_rolemgr  = this;
        int amount = 0;
        for( int i = 0; i < m_caches.Length; i++ )
        {
			m_caches[i].Initialize ();
			amount += m_caches[i].GetCacheSize();
        }

		activeCachedObjects = new Hashtable (amount);
	}


    ~CRoleManger()
    {

    }


    // 创建一个生物
   public  static UnityEngine.GameObject CreateGameObject(UnityEngine.GameObject prefab, Vector3 position, Quaternion rotation)
    {
        CObjectCache cache = null;
        if( m_rolemgr != null )
        {
			for( int i = 0; i < m_rolemgr.m_caches.Length; i++ )
            {
                if( m_rolemgr.m_caches[i].m_prefab == prefab )
                    cache = m_rolemgr.m_caches[i];
            }
        }


        if( cache == null )
        {
            return UnityEngine.GameObject.Instantiate(prefab, position, rotation) as UnityEngine.GameObject;
        }


        // Find the next object in the cache
	    UnityEngine.GameObject obj = cache.NextObjectInCache ();

	    // Set the position and rotation of the object
	    obj.transform.position = position;
	    obj.transform.rotation = rotation;

	    // Set the object to be active
	    obj.SetActive (true);
	    m_rolemgr.activeCachedObjects[obj] = true;
		return obj;
    }


    public static void Destroy ( UnityEngine.GameObject pObj ) 
    {
	    if ( m_rolemgr != null && m_rolemgr.activeCachedObjects.ContainsKey ( pObj )) 
        {
		    pObj.SetActive (false);
		    m_rolemgr.activeCachedObjects[ pObj ] = false;
	    }
	    else 
        {
		    UnityEngine.GameObject.Destroy ( pObj );
	    }
    }
}

