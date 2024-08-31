#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

// Comparator function to sort segments by their end points
bool compareSegments(const Segment &a, const Segment &b) {
    return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end(), compareSegments);
  int currentPoint = segments[0].end;
  points.push_back(currentPoint);

  for (const Segment &segment : segments) {
      // If the current point does not cover the segment, choose a new point
      if (currentPoint < segment.start) {
          currentPoint = segment.end;
          points.push_back(currentPoint);
      }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << "\n";
  }
}
