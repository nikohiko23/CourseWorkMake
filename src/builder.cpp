#include "builder.h"
#include <filesystem>
#include <cstdlib>
#include <iostream>

namespace fs = std::filesystem;

bool needs_rebuild(const BuildRule& rule) {
    if (!fs::exists(rule.target)) return true;

    auto target_time = fs::last_write_time(rule.target);
    for(const auto& dep : rule.dependencies) {
        if (!fs::exists(dep)) return true;
        if (fs::last_write_time(dep) > target_time) return true;
    }

    return false;
}

void execute_build(const std::vector<BuildRule>& rules) {
    for (const auto& rule : rules) {
        if (needs_rebuild(rule)) {
            std::cout << "[BUILD] " << rule.target << "..." << std::endl;
            int result = std::system(rule.command.c_str());
            if (result != 0) {
                std::cerr << "[ERROR] Assembling the target '" << rule.target << "' ended with an error."  << std::endl;
                break;
            }
            else {
                std::cout << "[SKIP] " << rule.target << " is relevant." << std::endl;
            }
        }
    }
}