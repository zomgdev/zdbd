#include "structures.h"
#include <string>

// Конструктор для ZDFS
ZDFS::ZDFS(void) {
	ZDFS_BlockSize = DEFAULT_BLOCK_SIZE;
}

ZDFSDaemon::ZDFSDaemon(void) {
	ZDFS_RootDirPath     = DEFAULT_DATA_DIR_PATH;
	ZDFS_MetadataDirPath = DEFAULT_METADATA_DIR_PATH;
	ZDFS_BlocksDirPath   = DEFAULT_BLOCKS_DIR_PATH;
	ZDFS_WALDirPath      = DEFAULT_WAL_DIR_PATH;
}