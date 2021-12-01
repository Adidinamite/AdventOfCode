#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
int main()
{
    vector <int> v;
    int x, cnt = 0;
    while(cin >> x)
    {
        v.push_back(x);
    }
    int size = v.size()-1;
    int pos1=-1, pos2= 2;
    //pos1 is included in a, but not in b
    //pos2 is include in b, but not in a
    if(size == pos2)// available only when a sum is possible
        return 0;          
    else
    {
        while(pos2 < size)
        {
            ++pos1,++pos2;
            if(v[pos1] < v[pos2])
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}
