#include <iostream>
#include <cstdio>

using namespace std;
// enum class Previous: bool {GOOD = true, BAD = false};

int main()
{
    // int n;
    // cin >> n;
    // int requests[n+1];
    // for (int i = 1; i <= n; i++)
    //     cin >> requests[i];
    
    // struct Time{
    //     int time, start_second, end_second;
    //     Time() : time(0), start_second(0), end_second(0) {}
    // };

    // struct Time time;
    // int requestsSoFar = 0;
    // Previous previous = Previous::GOOD;
    // long int bestTime = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     // fprintf(stdout, "DDoS details: <%i %i> duration %i s\n", time.start_second, time.end_second, time.time);
    //     if (time.time == 0)
    //         time.start_second = i;
    //     time.time += 1;
    //     requestsSoFar += requests[i];
    //     if (100 * time.time >= requestsSoFar)
    //     {   
    //         // check for reset
    //         if (previous == Previous::GOOD && (i != 1)) { // exclude first iteration
    //             // if (bestTime < time.time)
    //             //     bestTime = time.time;
    //             time.end_second = i;
    //             //reset if the case 
    //             time.time = 0;
    //             requestsSoFar = 0;

    //             previous = Previous::BAD; // uodate previous for the next iteration
    //         }
            
            
    //         // save current DDoS
    //         // if (time.end_second - time.start_second + 1 ==time.time)
    //         // {
    //         //     cout << "checking correctness of time slice ";
    //         // }
    //         // else 
    //         //     cout << "correctnes of time slice failed ";

    //     }
    //     else{
    //         previous = Previous::GOOD;
    //         if (bestTime < time.time)
    //         bestTime = time.time;
    //     }
        
    // }
    // cout << bestTime << endl;
    
    // second apporach
    void checkMax(int *Max, int Comp);
    int n, i, j, max{0};
    cin >> n;
    int requests[n+1], A[n+1][n+1], B[n+1][n+1];
    /* A counts requests
     * B counts interval length 
     */
    for (i = 1; i <= n; i++)
        cin >> requests[i];

    for (i = n; i >= 1; i--)
        for (j = i; j <= n; j++) 
        {
            A[i][j] = requests[i];
            if ((i < n) && (i < j))
                A[i][j] += A[i+1][j];
            B[i][j] = 0;
            if (A[i][j] > 100 * (j - i + 1))
            {
                B[i][j] = j - i + 1;
                // fprintf(stdout, "Indexes are %i, %i\n", i, j);
                checkMax(&max, B[i][j]);
            }
        }
    cout << max << endl;

    // for (i = 1; i <= n; i++)
    //     {
    //         for (j = 1; j <=n; j++)
    //         if (j < i)
    //             fprintf(stdout, "%6s ", "*");
    //         else
    //             fprintf(stdout, "%6i ", A[i][j]);
    //         fprintf(stdout, "\n");
    //     }
    return 0;
}

void checkMax(int *Max, int Comp)
{
    if (Comp > *Max)
        *Max = Comp;
}