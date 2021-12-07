#include <iostream>
#include <numeric>
#include <vector>

size_t RunSim1() {
  int nDays = 80;
  std::vector test_init = {
      3, 5, 1, 2, 5, 4, 1, 5, 1, 2, 5, 5, 1, 3, 1, 5, 1, 3, 2, 1, 5, 1, 1, 1,
      2, 3, 1, 3, 1, 2, 1, 1, 5, 1, 5, 4, 5, 5, 3, 3, 1, 5, 1, 1, 5, 5, 1, 3,
      5, 5, 3, 2, 2, 4, 1, 5, 3, 4, 2, 5, 4, 1, 2, 2, 5, 1, 1, 2, 4, 4, 1, 3,
      1, 3, 1, 1, 2, 2, 1, 1, 5, 1, 1, 4, 4, 5, 5, 1, 2, 1, 4, 1, 1, 4, 4, 3,
      4, 2, 2, 3, 3, 2, 1, 3, 3, 2, 1, 1, 1, 2, 1, 4, 2, 2, 1, 5, 5, 3, 4, 5,
      5, 2, 5, 2, 2, 5, 3, 3, 1, 2, 4, 2, 1, 5, 1, 1, 2, 3, 5, 5, 1, 1, 5, 5,
      1, 4, 5, 3, 5, 2, 3, 2, 4, 3, 1, 4, 2, 5, 1, 3, 2, 1, 1, 3, 4, 2, 1, 1,
      1, 1, 2, 1, 4, 3, 1, 3, 1, 2, 4, 1, 2, 4, 3, 2, 3, 5, 5, 3, 3, 1, 2, 3,
      4, 5, 2, 4, 5, 1, 1, 1, 4, 5, 3, 5, 3, 5, 1, 1, 5, 1, 5, 3, 1, 2, 3, 4,
      1, 1, 4, 1, 2, 4, 1, 5, 4, 1, 5, 4, 2, 1, 5, 2, 1, 3, 5, 5, 4, 5, 5, 1,
      1, 4, 1, 2, 3, 5, 3, 3, 1, 1, 1, 4, 3, 1, 1, 4, 1, 5, 3, 5, 1, 4, 2, 5,
      1, 1, 4, 4, 4, 2, 5, 1, 2, 5, 2, 1, 3, 1, 5, 1, 2, 1, 1, 5, 2, 4, 2, 1,
      3, 5, 5, 4, 1, 1, 1, 5, 5, 2, 1, 1};
  std::vector<int> states = test_init;

  for (std::size_t epoch = 0; epoch < nDays; ++epoch) {

    size_t newCount = 0;
    for (std::size_t i = 0; i < states.size(); ++i) {
      if (states[i] == 0) {
        // reset count and produce a new one
        newCount++;
        states[i] = 6;
      } else {
        states[i]--;
      }
    }

    // add new
    states.resize(states.size() + newCount, 8);

    // std::cerr << "Day: " << epoch << ": ";
    // for (const int v : states) {
    //  std::cerr << v << ",";
    // }
    // std::cerr << "\n";
  }

  return states.size();
}

size_t RunSim2() {
  // instead of storing every one, just store count of number in each state
  int nDays = 256;
  //  std::vector test_init = {3, 4, 3, 1, 2};
  std::vector test_init = {
      3, 5, 1, 2, 5, 4, 1, 5, 1, 2, 5, 5, 1, 3, 1, 5, 1, 3, 2, 1, 5, 1, 1, 1,
      2, 3, 1, 3, 1, 2, 1, 1, 5, 1, 5, 4, 5, 5, 3, 3, 1, 5, 1, 1, 5, 5, 1, 3,
      5, 5, 3, 2, 2, 4, 1, 5, 3, 4, 2, 5, 4, 1, 2, 2, 5, 1, 1, 2, 4, 4, 1, 3,
      1, 3, 1, 1, 2, 2, 1, 1, 5, 1, 1, 4, 4, 5, 5, 1, 2, 1, 4, 1, 1, 4, 4, 3,
      4, 2, 2, 3, 3, 2, 1, 3, 3, 2, 1, 1, 1, 2, 1, 4, 2, 2, 1, 5, 5, 3, 4, 5,
      5, 2, 5, 2, 2, 5, 3, 3, 1, 2, 4, 2, 1, 5, 1, 1, 2, 3, 5, 5, 1, 1, 5, 5,
      1, 4, 5, 3, 5, 2, 3, 2, 4, 3, 1, 4, 2, 5, 1, 3, 2, 1, 1, 3, 4, 2, 1, 1,
      1, 1, 2, 1, 4, 3, 1, 3, 1, 2, 4, 1, 2, 4, 3, 2, 3, 5, 5, 3, 3, 1, 2, 3,
      4, 5, 2, 4, 5, 1, 1, 1, 4, 5, 3, 5, 3, 5, 1, 1, 5, 1, 5, 3, 1, 2, 3, 4,
      1, 1, 4, 1, 2, 4, 1, 5, 4, 1, 5, 4, 2, 1, 5, 2, 1, 3, 5, 5, 4, 5, 5, 1,
      1, 4, 1, 2, 3, 5, 3, 3, 1, 1, 1, 4, 3, 1, 1, 4, 1, 5, 3, 5, 1, 4, 2, 5,
      1, 1, 4, 4, 4, 2, 5, 1, 2, 5, 2, 1, 3, 1, 5, 1, 2, 1, 1, 5, 2, 4, 2, 1,
      3, 5, 5, 4, 1, 1, 1, 5, 5, 2, 1, 1};

  std::vector<size_t> states(9, 0);
  std::vector<size_t> oldState(9, 0);
  for (const auto &v : test_init) {
    states[v]++;
  }

  for (std::size_t epoch = 0; epoch < nDays; ++epoch) {

    // 0 -> 8 AND 6
    // 8 -> 7
    // 7 -> 6
    // ...
    // 1 -> 0
    std::swap(oldState, states);
    std::fill(states.begin(), states.end(), 0);
    states[6] = oldState[0];
    states[8] = oldState[0];
    for (size_t j = 1; j < 9; ++j) {
      states[j - 1] += oldState[j];
    }

    std::cerr << "Day: " << epoch << ": ";
    for (const auto v : states) {
      std::cerr << v << ",";
    }
    std::cerr << "\n";
  }

  size_t sum = 0;
  for (size_t v : states) {
    sum += v;
  }
  return sum;
}

int main() {
  size_t value1 = RunSim1();
  size_t value2 = RunSim2();
  std::cerr << value1 << std::endl;
  std::cerr << value2 << std::endl;
}
