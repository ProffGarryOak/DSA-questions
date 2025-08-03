class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp.insert({'I', 1});
        mp.insert({'V', 5});
        mp.insert({'X', 10});
        mp.insert({'L', 50});
        mp.insert({'C', 100});
        mp.insert({'D', 500});
        mp.insert({'M', 1000});
        int z = 0;
        bool end = true, w=false;
        for (int i = 0; i < s.size(); i++) {
            if (i==s.size()-1){
                w=true;
            }
            else if (s[i] == 'I' and s[i + 1] == 'V') {
                z += 4;
                end = false;
                i++;
            } else if (s[i] == 'I' and s[i + 1] == 'X') {
                z += 9;
                end = false;
                i++;
            } else if (s[i] == 'X' and s[i + 1] == 'L') {
                i++;
                z += 40;
                end = false;
            } else if (s[i] == 'X' and s[i + 1] == 'C') {
                z += 90;
                end = false;
                i++;
            }

            else if (s[i] == 'C' and s[i + 1] == 'D') {
                z += 400;
                end = false;
                i++;
            } else if (s[i] == 'C' and s[i + 1] == 'M') {
                z += 900;
                end = false;
                i++;
            } else {
                z += mp[s[i]];
                if (i==s.size()-2){
                    w=true;
                }
            }
        }
        cout<<z<<endl;
        cout<<mp[s[s.size() - 1]]<<endl;
        cout<<w;
        if (w) {
            z += mp[s[s.size() - 1]];
            cout<<z<<endl;
        }
        return z;
    }
};