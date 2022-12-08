#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> pii;


pii split_string(string s){
    int c = 0;
    while(s[c] != '-') c++;
    return {stoi(s.substr(0, c)), stoi(s.substr(c + 1, s.size() - c - 1))};
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int result = 0;
    string line;
    while (getline(cin, line))
    {
        int pair_delimiter = 0;
        while(line[pair_delimiter] != ',') pair_delimiter++;
        pii elf1 = split_string(line.substr(0, pair_delimiter));
        pii elf2 = split_string(line.substr(pair_delimiter + 1, line.size() - pair_delimiter - 1));

        int overlap_begins = max(elf1.first, elf2.first);
        int overlap_ends = min(elf1.second, elf2.second);
        int overlap = overlap_ends - overlap_begins;
        if (overlap >= elf1.second - elf1.first ||
            overlap >= elf2.second - elf2.first) 
            result++;

        //cout << elf1.first << " " << elf1.second << "\n";
        //cout << elf2.first << " " << elf2.second << "\n";
    }

    cout << result;

    return 0;
}