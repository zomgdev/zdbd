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

// FSImage format structures

// HEADER
struct FSImageHeader{
	uint64_t FSImageVersion;
	uint64_t FilesTotal;
	uint64_t TotalBlocks;
	uint64_t UnreplicatedBlocks;
	uint64_t FilesRecords[ZDFS_MAX_FILES];
};

// File record
struct FSImageFileRecord {
	uint64_t FileSize;
	std::string FileName;
};

class FSImage {
public:
	FSImageHeader HeaderStruct;
	FSImage(void);
};

class ZDFS_File {
	uint64_t uniq_id;
	std::string FileName;
	uint64_t FileSize;
	
	uint64_t BlocksCount;
	uint64_t ActualBlocksCount;

	char ReplicationFactor;
	uint32_t *Permissions[100];
	
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

