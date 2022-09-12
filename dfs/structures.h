#ifndef ZDFS_STRUCTURES_H
#define ZDFS_STRUCTURES_H

#include "defaults.h"
#include <string>


class ZDFS {
private:
	int ZDFS_BlockSize;

public:
	ZDFS();
};

class ZDFSDaemon{
private:
	unsigned long long* MaxHeapMemory;

	std::string ZDFS_DataDirPath;
	std::string ZDFS_MetadataDirPath;
	std::string ZDFS_BlocksDirPath;
	std::string ZDFS_WALDirPath;

public:
	void NodeStart(ZDFS* Instance);
	ZDFSDaemon(void);
};

#endif
