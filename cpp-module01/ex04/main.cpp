#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

std::string new_line(std::string str, const std::string &from,
                     const std::string &to) {
  std::size_t start;

  while ((start = str.find(from, 0)) != std::string::npos) {
    std::string newline = str.substr(0, start);
    str =
        str.substr(start + from.length(), str.length() - start + from.length());
    str = newline + to + str;
  }
  return str;
}

void flush_buffer_if_not_empty() {
  if (std::cin.rdbuf()->in_avail())
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void flush_cin() {
  std::cin.clear();
  flush_buffer_if_not_empty();
}

int get_cmd(std::string s, std::string *cmd) {
  std::cout << s;
  if (!std::getline(std::cin, *cmd)) {
    if (std::cin.eof()) {
      std::cin.clear();
      exit(0);
    } else {
      flush_cin();
      cmd->clear();
    }
    return 1;
  }
  flush_cin();
  return 0;
}

int main() {
  std::string file;
  std::string from;
  std::string to;
  std::string flag;

  do {
    if (get_cmd("file name:", &file))
      return 1;
    if (get_cmd("Change which: ", &from))
      return 1;
    if (get_cmd("After replacement: ", &to))
      return 1;

    std::ifstream infile(file.c_str());
    if (!infile) {
      std::cout << "file open error" << std::endl;
      return 1;
    }
    std::string newfile = file;
    newfile.append(".replace");
    std::ofstream outfile(newfile.c_str());
    if (!outfile) {
      std::cerr << "file open error" << std::endl;
      return 1;
    }

    std::string line;
    while (getline(infile, line)) {
      line = new_line(line, from, to);
      outfile << line << std::endl;
    }

    outfile.close();
    infile.close();
    get_cmd("continue or break:  y/n", &flag);
  } while (!flag.compare("y"));
  return 0;
}
