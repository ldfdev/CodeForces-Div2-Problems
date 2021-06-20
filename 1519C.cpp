#include <bits/stdc++.h>

typedef long long ull;
const int max_size = 1 + 2e5;

std::unordered_map<ull, std::vector<ull>> university_skills;
ull strength_of_region[max_size];

struct student {
    ull enrolled_in;
    ull skill;
};

student students[max_size];

namespace std {
    bool function_ (const student& s1, const student& s2) {
        return s1.skill > s2.skill;
    }
}

void solve() {
    university_skills.clear();
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> students[i].enrolled_in;
    for (int i = 0; i < n; i++)
        std::cin >> students[i].skill;
    std::sort(students, students + n, std::function_);
    std::fill(strength_of_region, strength_of_region + n + 1, 0);

    for (int index = 0; index < n; index++) {
        ull university_ = students[index].enrolled_in;
        university_skills[university_].push_back(students[index].skill);
    }
    for (auto& university_ : university_skills) {
        auto& vec = university_.second;
        for (int i = 1; i < vec.size(); i++)
            vec[i] += vec[i - 1];
    }
    for (auto it = university_skills.begin(); it != university_skills.end(); it++) {
        int l = it->second.size();
        for (int team_size = 1; team_size <= l; team_size++) {
            int teams = team_size * (int)(l / team_size);
            strength_of_region[team_size] += it->second[teams - 1];
        }
    }
    for (int team_size = 1; team_size <= n; team_size++)
        std::cout << strength_of_region[team_size] << " ";
    std::cout << std::endl;
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; test++)
        solve();
    return 0;
}