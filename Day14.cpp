#include <fstream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("fcc.in");
ofstream cout("fcc.out");
string s;
string modified;
long long freq[200];
map <string, char> dex;
char delim[3], x;
string group;
void max_min(long long &maxx, long long &minn)
{
    for(int k = 'A'; k <= 'Z'; k++)
    {
        if(freq[k] > maxx)
            maxx = freq[k];
        if(freq[k] < minn && freq[k] >=1)
            minn = freq[k];
    }
}
string modify(string cuv){
    int i = 0, j =1;
    string result = "";
    result+= string(1, cuv[i]);
    string check = "";

    while(j < cuv.size())
    {
        check = string(1, cuv[i]) + string(1, cuv[j]);
        if(!(dex.find(check) == dex.end()))
        {
            result+=dex[check];
            freq[dex[check]]++;
            //cout<<"modificat";
        }
        result+=cuv[j];
        i++,j++;
    }
    return result;
}
int main() {
    cin >> s;
    modified = s;
    for(auto i = 0; i < s.size(); i++)
        freq[s[i] ]++;
    while(cin >> group >> delim >> x)
    {
        dex[group] = x;
    }
    const int step = 10;
    for(int k = 1; k <=step; ++k)
    {
        modified = modify(modified);
    }
    long long maxim = -1, minim = LONG_LONG_MAX;
    max_min(maxim, minim);
    cout << maxim - minim<<endl ;



}
