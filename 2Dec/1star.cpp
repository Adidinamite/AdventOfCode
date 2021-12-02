#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
int main()
{
    int h=0, d=0;
    char s[20];
    unsigned long long res=0;
    int n;
    while(cin >> s >> n)
    {
        if(!strcmp(s, "up"))
        {
            d-=n;
        }
        else if(!strcmp(s, "down"))
        {
            d+=n;
        }
        else if(!strcmp(s, "forward"))
        {
            h+=n;
        }
    }
    res = h * d;
    cout << res;
    return 0;
}
