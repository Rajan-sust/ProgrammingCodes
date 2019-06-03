//checking str1 is a subsequence of str2

bool isSub(string &str1,string &str2)
{
    deque<char>dq(str1.begin(),str1.end());

    for(char &ch : str2) {

    	if(ch==dq.front()){
    		dq.pop_front();
    	}
        if(dq.empty())return true;
    }

    return false;
}