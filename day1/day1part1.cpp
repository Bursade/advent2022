#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int calories = 0, caloriesAux = 0;
    
    string line;
    while (getline(cin, line))
    {
        if (!line.empty())
        {
            caloriesAux += stoi(line);
        }
        else
        {
            if (calories < caloriesAux)
            {
                calories = caloriesAux;
                caloriesAux = 0;
            }
            else
            {
                caloriesAux = 0;
            };
        }
    }
 
    cout << calories;
    
    return 0;
}
