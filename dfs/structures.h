#pragma once

#include "defaults.h"
#include <string>

#define ZDFS_MAX_FILES 1000000


class ZDFS {
private:
	int ZDFS_BlockSize;

public:
	ZDFS();
};

class ZDFSDaemon{
private:
	unsigned long long* MaxHeapMemory;


public:
	std::string ZDFS_RootDirPath;
	std::string ZDFS_MetadataDirPath;
	std::string ZDFS_BlocksDirPath;
	std::string ZDFS_WALDirPath;

	void NodeStart(ZDFS* Instance);
	ZDFSDaemon(void);
};

