/*
 * ----------------------------------------------------------------------------------------
 *          file name : AssetsPool.cs
 *          desc      : 管理 Asset 的池子，资源管理池子
 *          author    : LJP
 *          
 *          log       : [ 2015-05-04 ]
 * ----------------------------------------------------------------------------------------         
*/
using UnityEngine;
using System.Collections;
using System;
using System.Xml;
using System.Collections.Generic;







public class AssetBundlePool 
{



	private int currLoadings 	= 0;
    private List<Asset> loaders = new List<Asset>();
	public bool isLoading       = false;

    public AssetBundlePool() 
	{  
		
	}

	
	
	public void loadNext()
	{
        isLoading = true;
        for (int i = 0; i < loaders.Count; i++)
		{
            if (loaders[i].loading == false)
			{
				currLoadings += 1;
                loaders[i].LoadAsset();
				return;
			}
		}
		
		isLoading = false;
	}
	

	
	public bool removeLoad(string source)
	{

        for (int i = 0; i < loaders.Count; i++)
		{
            if (loaders[i].source == source)
			{
                if (loaders[i].loading == true)
					return false;

                loaders.RemoveAt(i);
				return true;
			}
		}
		
		return true;
	}

    public Asset findLoad(string source)
	{

        for (int i = 0; i < loaders.Count; i++)
		{
            if (loaders[i].source == source)
			{
                return loaders[i];
			}
		}
		
		return null;
	}

    public bool addLoad(Asset a)
	{
		if(a.isLoaded == true)
		{
			Common.DEBUG_MSG("LoadAssetsPool::addLoad:" + a.source + ", or isLoaded(" + a.isLoaded + ")!");
			return false;
		}
		
		if(findLoad(a.source) != null)
		{
			Common.DEBUG_MSG("LoadAssetsPool::addLoad: findLoad("+ a.source + ") = true!");
			return false;
		}
        else
        {
            loaders.Add(a);
        }
        return true;
	}
	
}  

