using UnityEngine;
using System;
using System.IO;
using System.Collections;






public class Common 
{
	public static LayerMask moveIgonreLayerMask = ~(1 << LayerMask.NameToLayer("kbentity"));
	public static LayerMask flyIgonreLayerMask = ~(1 << (LayerMask.NameToLayer("kbentity")) | 1 << (LayerMask.NameToLayer("building")));

    public static string assetbundleFileSuffix = ".bytes";

    public static string DEBUGTYPENAME = "Resource";

    public static string assetbundleFilePath = Application.dataPath + "/assetbundles/";

    //public static string mServerAssetPath = @"http://192.168.123.1/assetbundles/";
    public static string mServerAssetPath = "file:///c:/";

	public static string safe_url(string path)
	{
#if UNITY_EDITOR
        return "file://" + Application.dataPath + path;
#endif

#if UNITY_IPHONE
		return "file://" + Application.dataPath + path;
#endif

#if UNITY_STANDALONE_OSX
		return "file://" + Application.dataPath + path;
#endif
	}

    public static string getServerPath(string path)
    {
        return string.Format("{0}/{1}", mServerAssetPath, path);
    }

    public static string getPath(string filePath)
    {
        string path = filePath.Replace("\\", "/");
        int index   = path.LastIndexOf("/");
        if (-1 == index)
            throw new Exception("can not find /!!!");
        return path.Substring(0, index);
    }

    public static void CheckFolder(string path)
    {
        if (!Directory.Exists(path))
            Directory.CreateDirectory(path);
    }

    public static string checkUrl(ref string url)
    {
        string p = url.Replace(" ", "%20");
        p = p.Replace("#", "%23");
        return p;
    }

    public static string url_path( )
    {
        return "UIPerfab/";
    }
	
	
	public static void DEBUG_MSG(object s)
	{
		Debug.Log("[DEBUG]:" + s);
	}
	
	public static void WARNING_MSG(object s)
	{
		Debug.LogWarning("[WARNING]:" + s);
	}
	
	public static void ERROR_MSG(object s)
	{
		Debug.LogError("[ERROR]:" + s);
	}
	
	public static bool calcPositionY(Vector3 pos, out float outy, bool fly)
	{
		RaycastHit hit = new RaycastHit();
		
		LayerMask mask = moveIgonreLayerMask;
		if(fly)
			mask = flyIgonreLayerMask;
		
		float y = 1.0f;
		while(y > -50.0f)
		{
			Vector3 offset = new Vector3(0, y, 0);
			if (Physics.Raycast (pos + offset, -Vector3.up, out hit, 2.0f, mask)) 
			{
				outy = hit.point.y;
				return true;
			}
			
			y -= 0.1f;
		}

		y = -1.0f;
		while(y > 50.0f)
		{
			Vector3 offset = new Vector3(0, y, 0);
			if (Physics.Raycast (pos + offset, Vector3.up, out hit, 2.0f, mask)) 
			{
				outy = hit.point.y;
				return true;
			}
			
			y += 0.1f;
		}
		
		outy = pos.y;
		return false;
	}

    public static Stream Open(string path)
    {
        string localPath;
        //Andrio跟IOS环境使用沙箱目录
        if (Application.platform == RuntimePlatform.Android || Application.platform == RuntimePlatform.IPhonePlayer)
        {
            localPath = string.Format("{0}/{1}", Application.persistentDataPath, path + Common.assetbundleFileSuffix);
        }
        //Window下使用assetbunlde资源目录
        else
        {
            localPath = Common.assetbundleFilePath + path + Common.assetbundleFileSuffix;
        }

        //首先检查沙箱目录中是否有更新资源
        if (File.Exists(localPath))
        {
            return File.Open(localPath, FileMode.Open, FileAccess.Read, FileShare.Read);
        }
        //没有的话原始包中查找
        else
        {
            TextAsset text = Resources.Load(path) as TextAsset;
            if (null == text)
                Debug.LogError("can not find : " + path + " in OpenText" + Common.DEBUGTYPENAME);
            return new MemoryStream(text.bytes);
        }
    }
}
