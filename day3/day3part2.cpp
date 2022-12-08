#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <numeric>

using namespace std;

#define FOR(i, j) for(auto &i : j)
#define IF(i, j, k) if (i.find(j.first) != string::npos) k[j.first] +=1

char find_common_item(vector<string> group)
{
    unordered_map<char,int> common_item;
    
    string first_rucksack = group[0];
    string second_rucksack = group[1];
    string third_rucksack = group[2];

    for (auto &item : first_rucksack) common_item[item] = 0;

    FOR(item, common_item)
    {
        IF(second_rucksack, item, common_item);
    }

    FOR(item, common_item)
    {
        IF(third_rucksack, item, common_item);
    }

    FOR(item, common_item)
    {
        if (common_item[item.first] == 2)
        {
            return item.first;
        }
    }

    return ' ';
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<char, int> priorities_table;
    int priority = 1;
    for (int i = 97; i < 123; i++)
    {
        priorities_table[(char)i] = priority;
        priority++;
    }
    for (int i = 65; i < 91; i++)
    {
        priorities_table[(char)i] = priority;
        priority++;
    }
    vector<int> priorities;
    int sum_of_priorities = 0;
    
    
    string rucksack;
    vector<string> group;
    char repeated_item;

    while (getline(cin, rucksack))
    { 
        group.push_back(rucksack);
        if (group.size() == 3)
        {
            repeated_item = find_common_item(group);
            priorities.push_back(priorities_table[repeated_item]);
            group.clear();
        }
    }
    
    sum_of_priorities = reduce(priorities.begin(), priorities.end());
    cout << sum_of_priorities;

    return 0;
}