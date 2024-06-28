#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using item = std::pair<double,double>;

class Parser{

public:
    std::pair<double, std::vector<item>> parse(std::string filename);
};


