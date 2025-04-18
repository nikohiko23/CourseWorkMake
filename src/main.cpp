#include "builder.h"
#include "parser.h"
#include <iostream>

int main() {
    std::cout << "=== Simple Build System ===" << std::endl;

    std::string config_file = "build.conf";
    auto rules = parse_build_file(config_file);

    if(rules.empty()) {
        std::cerr << "No assembly rules in " << config_file << std::endl;
        return 1;
    }

    execute_build(rules);
    return 0;
}