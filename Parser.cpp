#include "Parser.h"

std::pair<double, std::vector<item>> Parser::parse(std::string filename){
    std::ifstream File(filename);
    std::vector<item> items;
    std::pair<double, std::vector<item>> res = std::make_pair(0.0,items);

    if(!File.is_open()) {
        std::cout << "can not read file" << std::endl;
        return res;
    }

    int n;
    File >> n;
    File >> res.first;

    double first, second;

    for(int i = 0; i<n; i++){
        File >> first;
        File >> second;
        res.second.push_back(std::make_pair(first, second));
    }

    File.close();
    return res;

}

