#include <functional>
#include <iostream>
#include <unordered_map>

#include "LinkedList.hpp"
#include "ThisCount.hpp"

const std::unordered_map<std::string, std::function<bool()>> commands = {
    {"llist",
     []() -> bool {
       letsee::LinkedList<int> ll;
       ll.print();
       return true;
     }},
    {"this-count",
     []() -> bool {
       auto counter = ThisCount();
       return counter.run();
     }},
};

void printAvailable() {
  std::cout << "Choose one of:\n";
  for (const auto kv : commands) {
    std::cout << "\t" << kv.first << '\n';
  }
}

int main(int argc, char **argv) {
  if (argc > 1) {
    try {
      const auto executer = commands.at(std::string(argv[1]));
      auto res = executer();
      std::cout << (res ? "Success" : "Failure") << '\n';
      return res ? 0 : -1;
    } catch (std::out_of_range &) {
      std::cout << "Invalid command " << argv[0] << " provided\n";
      printAvailable();
    }
  } else {
    std::cout << "Please provide a command!\n";
    printAvailable();
  }
  return -2;
}
