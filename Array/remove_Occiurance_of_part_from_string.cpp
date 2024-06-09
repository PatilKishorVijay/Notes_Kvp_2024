/* i/p -->
	string str = "DAABCBABCDA";
part=ABC
  o/p--> DABDA
*/
void removeOccurance(string &str,string part)
{
	int found = str.find(part);
	int partSize = part.size();
	
	if (found!=string::npos)
	{
		string left = str.substr(0, found);
		string right = str.substr(found + partSize);
		str = "";
		str = left + right;
		removeOccurance(str, part);
	}
	else
		return;
	

}
int main()
{
  	string str = "DAABCBABCDA";
	cout << str << endl;
	string part;
	cin >> part;
	removeOccurance(str,part);
	cout << str << endl;
	//checkPalindrome(str, 0, str.size() - 1);
}
