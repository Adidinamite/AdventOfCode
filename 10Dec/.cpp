#include <fstream>
#include <cmath>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
vector <long long>v;
const int MULTIPLY = 5;
long long s;
bool compare(char x, char y)
{
    if(x == '(' && y == ')')
        return 1;
    if(x == '[' && y==']')
        return 1;
    if(x=='<' && y== '>')
        return 1;
    if(x == '{' && y == '}')
        return 1;
    return 0;
}
bool open_chunk(char x)
{
    if(x == '(')
        return 1;
    if(x == '[')
        return 1;
    if(x=='<')
        return 1;
    if(x == '{')
        return 1;
    return 0;
}
int score(char x)
{
    if(x == ')')
        return 3;
    if(x == ']')
        return 57;
    if(x=='}')
        return 1197;
    if(x == '>')
        return 25137;
    return 0;
}
int score2(char x)
{
    if(x == '(')
        return 1;
    if(x == '[')
        return 2;
    if(x=='{')
        return 3;
    if(x == '<')
        return 4;
    return 0;
}
int main(){
    string line;
    unsigned long long points = 0;
    while(cin >> line)
    {   int temporary_points = 0;
        s= 0;
        int size = line.size();
        stack<char>lifo;
        bool ok = true;
        for(int i = 0; i<size;i++)
        {
            if(open_chunk(line[i]))
            {
                lifo.push(line[i]);
            }
            else if(!(open_chunk(line[i])) && ok)
            {
                if(lifo.empty() || (!compare(lifo.top(), line[i])))
                {
                        temporary_points = score(line[i]);
                    ok = false;
                }
                else if(compare(lifo.top(), line[i]))
                {
                    lifo.pop();
                }
            }
        }
        if(ok) {
            while (!lifo.empty()) {
                s = s * MULTIPLY + score2(lifo.top());
                lifo.pop();
            }
            v.push_back(s);
        }
            points+= temporary_points;
    }
    cout << points<<endl; //part 1

    sort(v.begin(),v.end());
    cout<< v[(v.size()-1)/2];

}
