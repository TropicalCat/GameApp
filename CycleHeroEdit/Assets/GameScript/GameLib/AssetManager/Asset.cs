/*
 * ----------------------------------------------------------------------------------------
 *          file name : Asset.cs
 *          desc      : 资源对象的描述和本资源加载的策略[ Asset 与 Assetbunble 关联起来 ]
 *          author    : LJP
 *          
 *          log       : [ 2015-05-23 ]
 * ----------------------------------------------------------------------------------------         
*/
using UnityEngine;
using System.Collections;
using System;
using System.IO;
using LuaFramework;
using System.Collections.Generic;
using GameObject = UnityEngine.GameObject;
using Object     = UnityEngine.Object;






public class AssetObject
{

    public UnityEngine.GameObject gameObject
    {
        get;
        set;
    }


	// 加载对象完成以后调用，这是一个虚函数，实现在子类实现
    public virtual void OnAsyncLoaded( )
	{

	}
}



public class Asset 
{
    public AssetObject              LoaderObj = null;
	
	public enum TYPE
	{
        NORMAL                      =-1,
		NPC				            = 0,
		PLAYER				        = 1,
        PLAYERCARD                  = 2,
		UI          		        = 3,
		MESH			            = 4,
        TERRAIN                     = 5,
	}

    /// <summary>
    ///  资源加载时机
    /// </summary>
	public enum LOAD_LEVEL
	{
		LEVEL_IDLE                  = 0,
		LEVEL_ENTER_BEFORE          = 1,
		LEVEL_ENTER_AFTER           = 2,
		LEVEL_SCRIPT_DYNAMIC        = 3,
		LEVEL_SPAWNPOINT            = 4
	}

	public enum UNLOAD_LEVEL
	{
		LEVEL_NORMAL                = 0,
		LEVEL_FORBID                = 1,
		LEVEL_FORBID_GAMEOBJECT     = 2
	}

    public enum LOADRES_TYPE
    {
        LOAD_PERFAB                 = 0,
        LOAD_ASSETBUNDLE            = 1
    }
	

	public TYPE type				= TYPE.NORMAL;
    public LOADRES_TYPE loadRes     = LOADRES_TYPE.LOAD_PERFAB;
	
    public Asset() 
	{  
		isLoaded = false;
    }  
  	
  	
    public string source {  
        get;  
        set;  
    }  
	
    public bool isLoaded {  
        get;  
        set;  
    }  
  
    public bool loading {  
        get;  
        set;  
    }  
	
    public UnityEngine.Object mainAsset {  
        get;  
        set;  
    }

    public AssetBundle bundle
    {
        get;
        set;
    } 

    /// -------------------------------------------------------------------------------------
    /// <summary>
    /// gai
    /// </summary>
    /// -------------------------------------------------------------------------------------
    public virtual void LoadEntiy()
    {
        LoaderObj.OnAsyncLoaded();
    }


    /// ---------------------------------------------------------------------------------
    /// <summary>
    /// 资源加载完成的时候执行，只加载文件映射和 Asset-Object[只是从网络上或磁盘上读取文件
    /// 完成,并没有加载对应的 GameObject Texture Mesh Script 等等
    /// </summary>
    /// ---------------------------------------------------------------------------------
    public void onLoadCompleted()
    {
        LoadEntiy();
    }


    /// ---------------------------------------------------------------------------------
    /// <summary>
    /// 销毁 Asset 相关的资源
    /// </summary>
    /// ---------------------------------------------------------------------------------
    public virtual void Destroy()
    {
        LoaderObj = null;
        mainAsset = null;
    }


    /// ---------------------------------------------------------------------------------
    /// <summary>
    /// 根据资源类型得到资源的路径
    /// </summary>
    /// ---------------------------------------------------------------------------------
    private string GetResPathByType()
    {
        if (type == Asset.TYPE.UI)
        {
            return "UIFrame/";
        }

        if (type == Asset.TYPE.NPC)
        {
            return "NPC/";
        }

        if (type == Asset.TYPE.PLAYER)
        {
            return "";
        }

        if( type == TYPE.PLAYERCARD )
        {
            return "PlayerCard/";
        }

        if (type == Asset.TYPE.MESH)
        {
            return "mesh/";
        }

        if( type == Asset.TYPE.TERRAIN )
        {
            return "TerrainSlicing/TerrainData/";
        }
        return "";
    }


    /// ---------------------------------------------------------------------------------
    /// <summary>
    /// 首先从本地加载资源并生成ASSET 资源对象， 这里只处理异步加载的过程
    /// </summary>
    /// ---------------------------------------------------------------------------------
    IEnumerator _loaderAsset()
    {
        if (loadRes == LOADRES_TYPE.LOAD_PERFAB)
        {
            string strPath          = GetResPathByType() + source.Replace(".prefab", "");
            ResourceRequest request = Resources.LoadAsync(strPath);;
            yield return request;

            if (request != null)
            {
                mainAsset = request.asset;
                loading = false;
                onLoadCompleted();
            }
        }

        if( loadRes == LOADRES_TYPE.LOAD_ASSETBUNDLE )
        {
            string uri                  = Util.DataPath + source.ToLower() + ".assetbundle";
            WWW bundlewww               = new WWW(uri);

            AssetBundleRequest request  = bundlewww.assetBundle.LoadAssetAsync(uri);
            yield return request; 
            if( request != null )
            {
                mainAsset   = request.asset;
                loading     = false;
                bundlewww   = null;
                onLoadCompleted();
            }
        }
    }


    ///--------------------------------------------------------------------------------------------
    /// <summary>
    /// 异步加载资源
    /// </summary>
    ///--------------------------------------------------------------------------------------------
    public bool LoadAsset()
    {
        if (loading == true)
            return false;

        loading = true;
        CBundleManager BundleMgr = LuaFramework.LuaHelper.GetResManager();
        if (BundleMgr != null )
        {
            BundleMgr.StartCoroutine(_loaderAsset());
        }
        return true;
    }

    ///--------------------------------------------------------------------------------------------
    /// <summary>
    /// 同步加载资源
    /// </summary>
    ///--------------------------------------------------------------------------------------------
    public void LoadBundle(string bundleName, bool bAsynLoad )
    { 
        
        source          = bundleName;
#if UNITY_EDITOR

        loadRes         = LOADRES_TYPE.LOAD_PERFAB;
        if (bAsynLoad)
        {
            // 这是一个异步加载过程
            LoadAsset();
        }
        else
        {
            // 这是一个同步加载过程
            string strPath = GetResPathByType() + source.Replace(".prefab", "");
            mainAsset   = Resources.Load( strPath ) as Object;
        }
#else
        loadRes         = LOADRES_TYPE.LOAD_ASSETBUNDLE;
        if (bAsynLoad)
        {
            // 这是一个异步加载过程
            LoadAsset();
        }
        else
        {
             // 从 assetbundle 加载资源
            byte[] stream   = null;
            string uri      = Util.DataPath + source.ToLower() + ".assetbundle";
            stream          = File.ReadAllBytes(uri);
            bundle          = AssetBundle.CreateFromMemoryImmediate(stream); 
        }
       
#endif

    }

}  


