#include "structures.h"
#include <string>
#include <iostream>

// FSImage constructor
FSImage::FSImage(void) {
	HeaderStruct.FSImageVersion = 1;
	HeaderStruct.FilesTotal = 65535;
	HeaderStruct.TotalBlocks = 255;
	HeaderStruct.UnreplicatedBlocks = 255;
	
	std::fill(&HeaderStruct.FilesRecords[0], &HeaderStruct.FilesRecords[ZDFS_MAX_FILES], 0);
}


// Конструктор для ZDFS
ZDFS::ZDFS(void) {
	ZDFS_BlockSize = DEFAULT_BLOCK_SIZE;
}

ZDFSDaemon::ZDFSDaemon(void) {
	ZDFS_RootDirPath     = DEFAULT_DATA_DIR_PATH;
	ZDFS_MetadataDirPath = DEFAULT_METADATA_DIR_PATH;
	ZDFS_BlocksDirPath   = DEFAULT_BLOCKS_DIR_PATH;
	ZDFS_WALDirPath      = DEFAULT_WAL_DIR_PATH;
#ifdef DEBUG
	using namespace std;
	cout << "Defaults using: " << endl;
	cout << "Data directory: " << ZDFS_RootDirPath << endl;
	cout << "Data directory: " << ZDFS_BlocksDirPath << endl;
	cout << "Data directory: " << ZDFS_MetadataDirPath<< endl;
	cout << "Data directory: " << ZDFS_WALDirPath << endl;
#endif // DEBUG

}