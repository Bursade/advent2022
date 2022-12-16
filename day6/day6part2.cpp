#include <iostream>
#include <string>
#include <queue>

using namespace std;


bool find_duplicate(vector<char> v)
{
    bool duplicate_found = false;
    
    if (v.size() < 14)
    {
        return true;
    }

    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] == v[j])
            {
                duplicate_found = true;
            }
        }
    }

    return duplicate_found;
}


int main()
{
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);
    vector<char> marker;
    for (int i = 0; i < line.size(); i++)
    {
        if (marker.size() < 14)
        {
            marker.push_back(line[i]);
        }
        else
        {
            marker.erase(marker.begin());
            marker.push_back(line[i]);
        }

        if (!find_duplicate(marker))
        {
            cout << i + 1;
            return 0;
        }
    }

    return 0;
}