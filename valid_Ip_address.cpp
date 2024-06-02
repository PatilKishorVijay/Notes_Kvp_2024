#include<sstream>
void isValidIp(string ip)
{
	int dotcount=0;
	for (char c : ip)
	{
		if (c == '.')
			dotcount++;
	}

	if (dotcount != 3)
	{
		cout << "not a valid ip..incorrect dots" << endl;
		return;
	}
	stringstream ss(ip);
	string segment;
	vector<string>segments;
	while (getline(ss, segment, '.'))
	{
		segments.push_back(segment);
	}

	if (segments.size() != 4)
	{
		cout << "not a valid ip..incorrect numbers of segemtns" << endl;
		return;
	}

	for (auto x : segments)
	{
		int value;
		value = stoi(x);
		if (value < 0 || value>255)
		{
			cout << "not a valid ip....incorrect values" << endl;
			return;
		}
	}

	cout << "valid ip address" << endl << endl;
}
int main()
{
	string str;
	//cin >> str;
	getline(cin, str);
	cout << str<<endl<<endl;
	isValidIp(str);

	//obj[0] =
}
