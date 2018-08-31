vector<vector<int> > Solution::threeSum(vector<int>& A)
{

    map<int, int> mp;

    for (int x : A)
        mp[x]++;

    set<vector<int> > s;

    set<int> unq(A.begin(), A.end());

    if (mp.count(0)) {
        if (mp[0] >= 3) {
            s.insert(vector<int>{ 0, 0, 0 });
        }
    }

    vector<int> num(unq.begin(), unq.end());

    int len = num.size();

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            int x = num[i],y = num[j],z = -(x+y),c = 0;
            if (z == x) c++;
            if (z == y) c++;

            auto it = mp.find(z);

            if (it != mp.end()) {
                if (it->second > c) {
                    vector<int> a = { x, y, z };
                    sort(a.begin(), a.end());
                    s.insert(a);
                }
            }
        }
    }

    return vector<vector<int> >(s.begin(), s.end());
}
