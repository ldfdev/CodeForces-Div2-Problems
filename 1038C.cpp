#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

void make_move (priority_queue<long long int>& currentPlayer,
				priority_queue<long long int>& opponent,
				long long int& currentPlayerScore)
{
	if ( (currentPlayer.size() > 0) && (opponent.size() > 0))
	{
		int currentPlayer_candidateScore{currentPlayer.top()}, opponent_candidateScore{opponent.top()};
		if (currentPlayer_candidateScore >= opponent_candidateScore)
		{
			currentPlayer.pop();
			currentPlayerScore += currentPlayer_candidateScore;
		}
		else
		{
			opponent.pop();
		}
	}
}

int main()
{
	priority_queue<long long int> pq1, pq0;
	long long int n, aux, A_score, B_score, steps{0};
	A_score = B_score = 0;

	cin >> n;

	for (auto j = 0; j < n; j++)
	{
		cin >> aux;
		pq0.push(aux);
	}
	
	for (auto j = 0; j < n; j++)
	{
		cin >> aux;
		pq1.push(aux);
	}
	pq0.push(0); pq1.push(0);
	aux = 0;

	while ( steps++ < 2 * n )
	{
		// if ( !pq0.empty() )
		// 	cout << "Max elem of A's list is " << pq0.top() << endl;
		// if (! pq1.empty() )
		// 	cout << "Max elem of B's list is " << pq1.top() << endl;
		// this_thread::sleep_for(chrono::milliseconds(1500));
		if (aux == 0) //A's turn
		{
			make_move(pq0, pq1, A_score);
		}
		else // B's turn
		{
			make_move(pq1, pq0, B_score);
		}
		aux^=1;
	}

	cout << A_score - B_score;
	return 0;
}