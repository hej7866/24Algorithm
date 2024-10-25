#include "Greedy.h"

// 14916
int Greedy_remainMoney(int n)
{
	int money = n;

	// 5원이 최대가 아닌 경우에는 무조건 false
	// 13원 케이스 return해주기 위해서 5원 짜리를 기준으로 거슬러 줄 수 있는 케이스를 검산
	for (int i = 0; i * 5 <= n; i++)
	{
		int remain = n - i * 5;

		if (remain % 2 == 0)
		{
			int totalCoins = i + remain / 2;
			money = min(money, totalCoins);
		}
	}

	return money == n ? -1 : money;
}


// 11047
int cnt = 0;
int Coin(vector<int>& vec, int K)
{
    int size = vec.size();
    int idx = size - 1;

    int sum = 0;
    while (true)
    {
        if (sum + vec[idx] > K)
        {
            idx--;
        }
        else
        {
            while (true)
            {
                sum += vec[idx];
                cnt++;
                if (sum > K)
                {
                    sum -= vec[idx];
                    cnt--;
                    break;
                }
            }
        }

        if (sum == K) break;
    }
    return cnt;
}


// 1931
int MeetingRoomAllocation(vector<pair<long, long>>& vec)
{
    int cnt = 0;
    long end = 0;

    for (const auto& meeting : vec)
    {
        if (meeting.first >= end)
        {
            end = meeting.second;
            cnt++;
        }
    }
    return cnt;
}


//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int N;
//    cin >> N;
//
//    vector<pair<long, long>> time(N);
//    for (int i = 0; i < N; i++)
//    {
//        cin >> time[i].first >> time[i].second;
//    }
//
//    sort(time.begin(), time.end(), [](const pair<long, long>& a, const pair<long, long>& b) {
//        if (a.second == b.second)
//            return a.first < b.first;
//        return a.second < b.second;
//        });
//
//    cout << MeetingRoomAllocation(time) << "\n";
//
//    return 0;
//}

int ATM(vector<pair<int, int>>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].first = i + 1;
        cin >> vec[i].second;
    }

    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
        });

    int sum = 0;
    int total = 0;
    for (auto i : vec)
    {
        sum += i.second;
        total += sum;
    }
    return total;
}