#pragma once

#include <filesystem>
namespace fs = std::filesystem;

bool isFileExists(const fs::path& p, fs::file_status s = fs::file_status{});
