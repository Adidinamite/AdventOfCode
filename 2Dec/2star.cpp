#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
int main()
{
    long long h=0, d=0;
    long long aim = 0;
    char s[20];
    unsigned long long res=0;
    int n;
    while(cin >> s >> n)
    {
        if(!strcmp(s, "up"))
        {
            aim-=n;
        }
        else if(!strcmp(s, "down"))
        {
            aim+=n;
        }
        else if(!strcmp(s, "forward"))
        {
            h+=n;
            d+= aim * n;
        }
    }
    res = h * d;
    cout << res;
    return 0;
}
