#include <iostream>
#include <fstream>
#include <string>
	
std::string new_line(std::string str, const std::string& from, const std::string& to)
{
	std::size_t start;

	while((start = str.find(from, 0)) != std::string::npos) {
		std::string newline= str.substr (0,start);
		str = str.substr (start + from.length(),str.length() -  start + from.length());
		str =  newline + to + str;
	}
	return str;
}

int main() {
	std::string file;
	std::string from;
	std::string to;

	std::cout << "file name:";
	std::cin >> file;
	std::cout << "Change which: ";
	std::cin >> from;
	std::cout << "After replacement: ";
	std::cin >> to;

	std::ifstream infile(file.c_str());
    if (!infile) {
		std::cout << "file open error" << std::endl;
        return 1;
    }
	std::string newfile = file;
	newfile.append(".replace");
	std::ofstream outfile(newfile.c_str());
	    if (!outfile) {
        std::cerr << "file open error"<< std::endl;
        return 1;
    }

    std::string line;
    while (getline(infile, line)) {
			line =  new_line(line,from,to);
			outfile << line << std::endl;
    }
    
    outfile.close();
    infile.close();
    return 0;
}
