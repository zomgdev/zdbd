#include <filesystem>
#include <exception>
#include <iostream>
#include <fstream>
#include <cstdint>

namespace fs = std::filesystem;

/*
int main()
{
    const fs::path sandbox{ "sandbox" };

    fs::create_directory(sandbox);
    std::ofstream{ sandbox / "file" }; // create regular file
    fs::create_symlink("non-existing", sandbox / "symlink");

    demo_exists(sandbox);

    for (const auto& entry : fs::directory_iterator(sandbox))
        demo_exists(entry, entry.status()); // use cached status from directory entry

    fs::remove_all(sandbox);
}
*/
bool isFileExists(const fs::path& p, fs::file_status s = fs::file_status{}) {
	bool fileExist = false;
    
    std::cout << p;
    if (fs::status_known(s) ? fs::exists(s) : fs::exists(p))
        std::cout << " exists\n";
    else
        std::cout << " does not exist\n";
        
	return fileExist;
}


