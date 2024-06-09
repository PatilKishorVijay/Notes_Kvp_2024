void getLastOccurance(string str,char key,int &ans,int i=0)
{
	int size = str.size();
	//static int ans=0;
	
	if (i >= size)
		return;
	if (str[i] == key)
		ans = i;
	getLastOccurance(str,key,ans,++i);
	
	/*
	// first approache to traverse from left to right...
	for (int i = 0; i < size; i++)
	{
		if (str[i] == key)
			ans = i;
	}
	cout << "char -- " << key << "occured llast at index --" << ans <<endl;
	*/

	/*
	//second approach is traversr from right and give its first occurance from last

	for (int i = size; i >= 0; i--)
		if (str[i] == key)
		{
			ans = i;
			break;
		}
	cout << "char -- " << key << "occured llast at index --" << ans << endl;

	*/


}