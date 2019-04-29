#include <functional>
#include <iostream>
#include <unordered_map>

#include "LinkedList.hpp"

const std::unordered_map<std::string, std::function<bool()>> commands = {
    {"ll",
     []() -> bool {
       letsee::LinkedList<int> ll;
       ll.print();
       return true;
     }},
    {"hw", []() -> bool { return false; }},
    {"hw", []() -> bool { return false; }},
};

int main(int argc, char **argv) {
  if (argc > 1) {
    try {
      const auto executer = commands.at(std::string(argv[1]));
      auto res = executer();
      std::cout << (res ? "Success" : "Failure") << '\n';
      return res ? 0 : -1;
    } catch (std::out_of_range &) {
      std::cout << "Invalid command " << argv[0] << " provided\n";
    }
  } else {
    std::cout << "Please provide a command!\n";
  }
  return -2;
}
