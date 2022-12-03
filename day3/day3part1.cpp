#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <numeric>

using namespace std;

char find_common_item(string first_compartment, string second_compartment)
{
    unordered_map<char,int> repeated;
    
    for (auto &item : first_compartment)
    {
        repeated[item] = 0;
    }
    
    for (auto &item : second_compartment)
    {
        if (repeated.find(item) == repeated.end())
        {
            continue;
        }
        else
        {
            return item;
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
    
    
    string rucksack, first_compartment, second_compartment;
    char repeated_item;

    while (getline(cin, rucksack))
    {
        first_compartment = rucksack.substr(0, rucksack.length()/2);
        second_compartment = rucksack.substr(rucksack.length()/2);
        
        repeated_item = find_common_item(first_compartment, second_compartment);
        
        //cout << first_compartment << " " << second_compartment << "\n";
        priorities.push_back(priorities_table[repeated_item]);
        //int x = priorities_table[repeated_item];
        //cout << x << " " << repeated_item << "\n";
        
    }
    
    sum_of_priorities = reduce(priorities.begin(), priorities.end());
    cout << sum_of_priorities;

    return 0;
}