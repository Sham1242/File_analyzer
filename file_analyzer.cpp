#include <iostream>
#include <filesystem>
#include <chrono>

void analyzeFile(const std::filesystem::directory_entry& file) {
    std::cout << "Analyzing file: " << file.path() << std::endl;
    
    // File analysis code in C++ goes here
    // Example: Get file size
    std::cout << "File size: " << std::filesystem::file_size(file.path()) << " bytes" << std::endl;
    
    // Example: Get creation time
    std::time_t creationTime = std::chrono::system_clock::to_time_t(std::filesystem::last_write_time(file.path()));
    std::cout << "Creation time: " << std::ctime(&creationTime);
    
    std::cout << std::endl;
}

void analyzeDirectory(const std::filesystem::path& directory) {
    std::cout << "Analyzing directory: " << directory << std::endl;
    
    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (std::filesystem::is_regular_file(entry)) {
            analyzeFile(entry);
        } else if (std::filesystem::is_directory(entry)) {
            analyzeDirectory(entry);
        }
    }
}

int main() {
    std::string directoryPath;
    std::cout << "Enter the directory path to analyze: ";
    std::cin >> directoryPath;
    
    analyzeDirectory(directoryPath);
    
    return 0;
}