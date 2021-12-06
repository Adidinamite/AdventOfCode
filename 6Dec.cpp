#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long ul;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
ul cnt(vector<ul> v, int size)
{
    if(size==-1)
        return 0;
    return v[size] + cnt(v, size-1);
}
void calculateFishPop(vector <ul> freq, int days)
{
    while(days--){
        ul child = freq[0];
        rotate(freq.begin(), freq.begin() + 1, freq.end());
        freq[6] += child;
    }
    cout<< cnt(freq, 9);
}

int x;
char comma;
int main() {
    vector <ul> freq(9, 0); // 0 <--> 8
    cin >> x;
    freq[x]++;
    while(cin >>comma >> x)
    {
        freq[x]++;
    }
    int days1 = 80;
    int days2 = 256;
    calculateFishPop(freq, days1);cout<< "\n";
    calculateFishPop(freq, days2);

}
