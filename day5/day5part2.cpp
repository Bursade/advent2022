#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <ranges>

using namespace std;


void move(int boxes, vector<char> &stack1, vector<char> &stack2)
{
    stack2.insert(stack2.end(), make_move_iterator(stack1.end() - boxes), make_move_iterator(stack1.end()));
    for (int i = 0; i < boxes; i++) stack1.pop_back();
}


void print_last_of_each(vector<vector<char>> stacks_of_crates)
{
    for (vector<char> stack : stacks_of_crates)
    {
        if (stack.back())
        {
            cout << stack.back();
        }
        else continue;
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> stacks_of_crates;
    bool are_boxes_parsed = false;
    string line;
    while (getline(cin, line))
    {
        if (!are_boxes_parsed)
        {
            for (int i = 0; i < line.length(); i++)
            {   
                if (isdigit(line[i])) {are_boxes_parsed = true; break;}
                if (!isupper(line[i])) continue;
                int stack_index = i/4;
                if (stacks_of_crates.size() <= stack_index) stacks_of_crates.resize(stack_index + 1);
                stacks_of_crates[stack_index].push_back(line[i]);
            }
        }
        else break;
    }

    for (vector<char> &stack : stacks_of_crates) reverse(stack.begin(), stack.end());

    while(getline(cin, line))
    {
        int boxes = atoi(&line[5]), from_stack = atoi(&line[12]) - 1, to_stack = atoi(&line[17]) - 1;
        move(boxes, stacks_of_crates[from_stack], stacks_of_crates[to_stack]);
    }
    print_last_of_each(stacks_of_crates);

    return 0;
}