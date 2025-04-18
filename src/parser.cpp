#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<BuildRule> parse_build_file(const std::string& filename) {
    std::vector<BuildRule> rules;
    std::ifstream file(filename);

    if (!file.is_open()){
        std::cerr << "ERROR: failed to open file " << filename << std::endl;
        return rules;
    }


    std::string line;
    BuildRule current;

    while (std::getline(file, line)) {
        if (line.empty()) continue;
    
        if (line[0] != ' ' && line[0] != '\t'){
            if (!current.target.empty()) {
            rules.push_back(current);
            current = BuildRule();
            }
    

            std::istringstream iss(line);
            std::string target;
            iss >> target;
            iss.ignore(); //miss ':'

            current.target = target;

            std::string dep;
            while (iss >> dep) {
            current.dependencies.push_back(dep);
            }
        } else {
            current.command = line.substr(line.find_first_not_of(" \t"));
        }
    }
    if (!current.target.empty()) {
        rules.push_back(current);
    }

    return rules;

}

