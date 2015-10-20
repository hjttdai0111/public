using UnityEngine;
using System.Collections;
using UnityEngine.Advertisements;

public class UnityAdsScript : MonoBehaviour {

	// Use this for initialization
	void Start () {
		#if UNITY_ANDROID
		Advertisement.Initialize("1009XXX");
		#elif UNITY_IOS
		Advertisement.Initialize("1009YYY");
		#endif
	}
	
	// Update is called once per frame
	void Update () {
		if( Advertisement.IsReady() ) 
		{
			Advertisement.Show ();
		}
	}
}
