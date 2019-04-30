#pragma once

// Input : THIS IS A TEST STRING
// Find the occurence of THIS? all possible ways from left to right.
// answer: {1,2,3,4} {1,2,5,6} {1,2,3,6} .....

#include <array>
#include <iostream>
#include <string>
#include <vector>

class ThisCount {

public:
  using Pos = std::array<int, 4>;

  bool run() {
    std::vector<Pos> results;
    auto res = Pos{-1, -1, -1, -1};
    const auto exp = std::string{"THIS"};
    const auto input = std::string{"THIS IS A TEST STRING"};
    auto len = exp.size();
    while (true) {
      int match = 0;
      bool atleastOneFound = false;
      for (std::size_t j = 0; j < input.size(); ++j) {
        if (input[j] == exp[match]) {
          res[match] = j;
          ++match;
          if (match == exp.size()) {
            if (!contains(results, res, len)) {
              results.push_back(res);
              reset(res);
              atleastOneFound = true;
            } else {
              res[match] = -1;
              --match;
            }
          }
        }
      }
      if (!atleastOneFound) {
        if (len > 0) {
          --len;
        } else {
          break;
        }
      }
    }
    print(results);
    return results.size() > 0;
  }

  bool contains(const std::vector<Pos> &results, Pos res, int len) {
    for (const auto &pos : results) {
      bool match = true;
      for (auto i = 0; i < len; ++i) {
        match = match && res[i] == pos[i];
      }
      if (match) {
        return true;
      }
    }
    return false;
  }

  void reset(Pos &res) { res[0] = -1, res[1] = -1, res[2] = -1, res[3] = -1; }

  void print(const std::vector<Pos> &results) {
    for (const auto pos : results) {
      std::cout << "{";
      for (auto i = 0; i < pos.size(); ++i) {
        std::cout << pos[i] << (i == pos.size() - 1 ? "" : ",");
      }
      std::cout << "}\n";
    }
  }
};