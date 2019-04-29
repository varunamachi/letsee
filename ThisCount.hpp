#pragma once

// Input : THIS IS A TEST STRING
// Find the occurence of THIS? all possible ways from left to right.
// answer: {1,2,3,4} {1,2,5,6} {1,2,3,6} .....

#include <array>
#include <string>
#include <vector>

class ThisCount {
public:
  using Pos = std::array<int, 4>;
  void run() {
    std::vector<Pos> results;
    auto res = Pos{-1, -1, -1, -1};
    auto exp = std::string{"THIS"};
    int match = 0;
    auto input = std::string{"THIS IS A TEST STRING"};
    while (true) {
      for (std::size_t j = 0; j < input.size(); ++j) {
        if (input[j] == exp[match]) {
          ++match;
          res[match] = j;
          if (!contains(results, res)) {

          } else {
            res[match] = -1;
            --match;
          }
        }
        // if (match == exp.size()) {
        //   results.push_back(res);
        //   reset(res);
        //   break;
        // }
      }
    }
  }

  bool contains(const std::vector<Pos> &results, Pos res) {
    for (const auto &pos : results) {
      if (pos == res) {
        return true;
      }
    }
    return false;
  }

  void reset(Pos &res) { res[0] = -1, res[1] = -1, res[2] = -1, res[3] = -1; }
};