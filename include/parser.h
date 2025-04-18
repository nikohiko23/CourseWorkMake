#pragma once
#include <string>
#include <vector>

struct BuildRule {
    std::string target;
    std::vector<std::string> dependencies;
    std::string command;
};

std::vector<BuildRule> parse_build_file(const std::string& filename);