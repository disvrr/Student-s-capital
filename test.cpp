#include "D:\Diana\dev\progects\Student’s capital\Student’s capital\Student’s capital.cpp"
int main() {
    int N, C, K;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter C: ";
    cin >> C;
    cout << "Enter K: ";
    cin >> K;

    vector<int> gains(K), prices(K);

    cout << "Enter gains array:\n";
    for (int i = 0; i < K; ++i)
        cin >> gains[i];

    cout << "Enter prices array:\n";
    for (int i = 0; i < K; ++i) 
        cin >> prices[i];

    int result = maximizeCapital(N, C, gains, prices);

    cout << "Final capital after summer: " << result << endl;

    return 0;
}