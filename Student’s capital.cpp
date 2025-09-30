#include "StudentCapital.h"
#include <queue>
#include <algorithm>
using namespace std;

struct Laptop {
	int price;
	int gain;
};
bool static compareByPrice(const Laptop& a, const Laptop& b) {
	return a.price < b.price;
}
int static maximizeCapital(int N, int C, const vector<int>& gains, const vector<int>& prices) {
    int K = gains.size();

    vector<Laptop> laptops(K);
    for (int i = 0; i < K; ++i) {
        laptops[i] = { prices[i], gains[i] };
    }

    sort(laptops.begin(), laptops.end(), compareByPrice);

    priority_queue<int> maxGainHeap;
    int idx = 0;

    for (int i = 0; i < N; ++i) {

        while (idx < K && laptops[idx].price <= C) {
            maxGainHeap.push(laptops[idx].gain);
            idx++;
        }

        if (maxGainHeap.empty()) {
            break;
        }

        C += maxGainHeap.top();
        maxGainHeap.pop();
    }

    return C;
}
