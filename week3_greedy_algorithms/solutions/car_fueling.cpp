#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int mileage, vector<int> & stops) {
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);

    int numRefills = 0;
    int currentStop = 0;

    while (currentStop < stops.size() - 1) {
        int lastStop = currentStop;

        // Move to the farthest stop within the car's mileage
        while (currentStop < stops.size() - 1 && stops[currentStop + 1] - stops[lastStop] <= mileage) {
            currentStop++;
        }

        // If no progress is made, it's impossible to reach the next stop
        if (currentStop == lastStop) {
            return -1;
        }

        // If we haven't reached the final destination, we need to refill
        if (currentStop < stops.size() - 1) {
            numRefills++;
        }
    }

    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
