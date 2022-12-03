#include <iostream>
#include <string>

using namespace std;
void top3(int &contender, int &first, int &second, int &third)
{
    if (contender > third)
    {
        if (contender > second)
        {
            if (contender > first)
            {
                third = second;
                second = first;
                first = contender;
                contender = 0;
            }
            else
            {
                third = second;
                second = contender;
                contender = 0;
            }
        }
        else
        {
            third = contender;
            contender = 0;
        }
    }
    else
    {
        contender = 0;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int calories = 0, caloriesFirst = 0, caloriesSecond = 0, caloriesThird = 0;
    
    string line;
    while (getline(cin, line))
    {
        if (!line.empty())
        {
            calories += stoi(line);
        }
        else
        {
            top3(calories, caloriesFirst, caloriesSecond, caloriesThird);
        }
    }
    
    // We have to run top3() once more since we don't know if the input
    // will end with a blank line.
    top3(calories, caloriesFirst, caloriesSecond, caloriesThird);
    
    cout << caloriesFirst + caloriesSecond + caloriesThird;
    
    return 0;
}
