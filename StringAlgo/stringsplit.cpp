vector<string>split(string str,char delimiter)
{
	vector<string>internal;
	stringstream ss(str);
	string input;

	while(getline(ss,input,delimiter))
	{
            internal.push_back(input);
	}
	return internal;
}