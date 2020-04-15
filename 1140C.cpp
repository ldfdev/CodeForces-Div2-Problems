#include <bits/stdc++.h>

struct song
{
    int length, beauty;
};
struct comp
{
    bool operator () (const song&a, const song& b) const {
        if (a.beauty < b.beauty)
            return true;
        else if (a.beauty == b.beauty)
            return (a.length < b.length);
        return false;
    }
};

int main()
{
    int i, n, k;
    scanf("%d%d", &n, &k);
    std::vector<song> songs(n);
    for (i = 0; i < n; i++)
        scanf("%d%d", &songs[i].length, &songs[i].beauty);
    std::sort(songs.begin(), songs.end(), comp());
    std::priority_queue<int, std::vector<int>, std::greater<int>> top_k;
    unsigned long long pleasure = 0, running_sum = 0;
    for (i = n - 1; i > -1; --i) {
        // printf("Adding song %d %d\n", songs[i].length, songs[i].beauty);
        top_k.push(songs[i].length);
        running_sum += songs[i].length;
        
        if (i < n - k) { // there are more than k songs to choose from
            running_sum -= top_k.top();
            top_k.pop();
        }

        pleasure = std::max(running_sum * songs[i].beauty, pleasure);
    }

    printf("%llu\n", pleasure);

    return 0;
}