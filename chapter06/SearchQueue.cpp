//
// Created by 涂飞明 on 2023/7/19.
//

#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool IsSeller(const string &name) {
    return name.substr(name.size() - 1, 1) == "m";
}

bool Search(const vector<vector<string>> &graph, const string &name) {
    deque<string> searchQueue = deque<string>();
    deque<string> searched = deque<string>();
    searchQueue.emplace_back(name);
    while (!searchQueue.empty()) {
        string person = searchQueue.front();
        searchQueue.pop_front();
        if (find(searched.cbegin(), searched.cend(), person) == searched.cend()) {
            if (IsSeller(person)) {
                cout << person << " is a mango seller!" << endl;
                return true;
            } else {
                for (const auto &vec: graph) {
                    if (vec.front() == person) {
                        searchQueue.emplace_back(vec.at(1));
                    }
                }
                searched.emplace_back(person);
            }
        }
    }
    cout << "no one is a mango seller!" << endl;
    return false;
}

int main() {
    // vector<string> names = {"you", "alice", "bob", "claire", "anuj", "peggy", "thom", "jonny"};
    vector<vector<string>> graph = {{"you",    "alice"},
                                    {"you",    "bob"},
                                    {"you",    "claire"},
                                    {"bob",    "anuj"},
                                    {"bob",    "peggy"},
                                    {"alice",  "peggy"},
                                    {"claire", "thom"},
                                    {"claire", "jonny"}};
    Search(graph, "you");
    return 0;
}