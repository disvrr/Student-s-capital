#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Laptop {
	int price;
	int gain;
};
bool compareByPrice(const Laptop& a, const Laptop& b) {
	return a.price < b.price;
}
int maximizeCapital(int N, int C, const vector<int>& gains, const vector<int>& prices) {
    int K = gains.size();

    vector<Laptop> laptops(K);
    for (int i = 0; i < K; ++i) {
        laptops[i] = { prices[i], gains[i] };
    }

    // Sort laptops by price
    sort(laptops.begin(), laptops.end(), compareByPrice);

    priority_queue<int> maxGainHeap;
    int idx = 0;

    for (int i = 0; i < N; ++i) {
        // Push all affordable laptops into the max-heap
        while (idx < K && laptops[idx].price <= C) {
            maxGainHeap.push(laptops[idx].gain);
            idx++;
        }

        // If no affordable laptops, break
        if (maxGainHeap.empty()) {
            break;
        }

        // Take the most profitable one
        C += maxGainHeap.top();
        maxGainHeap.pop();
    }

    return C;
}




finalCapital = initialCapital + sumOfSelectedGains;

int main()
{
	int N, C;
	int* gainsArray = new int[N];
	int* priceArray = new int[N];

	
}
