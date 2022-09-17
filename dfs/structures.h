#pragma once

#include "defaults.h"
#include <string>


class ZDFS {
private:
	int ZDFS_BlockSize;

public:
	ZDFS();
};

// 
// Attributes
// 32 - bits

class ZDFS_File {
	unsigned long long uniq_id;
	std::string FileName;
	unsigned long long FileSize;
	
	long BlocksCount;
	long ActualBlocksCount;

	char ReplicationFactor;
	unsigned int Permissions;
	
};
class ZDFS_Block {
private:
	unsigned long long BlockSize;
	unsigned long long BlockID;

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

