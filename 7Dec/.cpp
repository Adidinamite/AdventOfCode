#include <fstream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
vector<int> v;
long long Gauss(int n)
{
    return(n * (n+1))/2;
}
int calc_total_fuel(vector<int>n, int target)
{
    int total_fuel=0;
    for(int i = 0; i< v.size(); i++)
    {
        total_fuel += abs(target - v[i]);
    }
    return total_fuel;
}
long long calc_total_fuel_gauss(vector<int>n, int target)
{
    int total_fuel=0;
    for(int i = 0; i< v.size(); i++)
    {
        total_fuel += Gauss(abs(target - v[i]));
    }
    return total_fuel;
}
int arith_median(vector<int> x)
{
    int sum=0,size;
    size = x.size()-1;
    for(int i = 0; i<=size; i++)
        sum += x[i];
    return round((long)sum/size);
}
int main() {
    int x, size = 1;
    char comma;
    cin >> x;
    v.push_back(x);
    while (cin >> comma >> x) {
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int tg = v[v.size()/2];
    cout<<calc_total_fuel(v, tg)<<endl;//p1
    cout<<calc_total_fuel_gauss(v, arith_median(v));//p2
}


