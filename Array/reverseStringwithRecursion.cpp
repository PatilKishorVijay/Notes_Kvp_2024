void reverseString(string &str,int low,int high)
{
	if (low >= high)
		return;
	swap(str[low],str[high]);
	reverseString(str,++low,--high);
}

int main()
{
  	string str = "abcde";
	//cout << strlen(str);
	cout << str << endl;
	reverseString(str, 0, str.size()-1);
	cout << str << endl;
}
