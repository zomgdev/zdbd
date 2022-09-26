#pragma once

#include <string>


// FSImage format structures

// HEADER
struct FSImageHeader {
	uint64_t FSImageVersion;
	uint64_t FilesTotal;
	uint64_t TotalBlocks;
	uint64_t UnreplicatedBlocks;
	uint64_t FilesRecords[ZDFS_MAX_FILES];
};

// File record
struct FSImageFileRecord {
	uint16_t    SizeOf;
	uint64_t    FileUID;
	uint32_t    StorageUID;
	uint64_t    FileSize;
	uint8_t     FileReplicas;
	std::string FileName;
};
struct FilesPermissions{}{

};


class ZDFS_Block {
private:
	unsigned long long BlockSize;
	unsigned long long BlockID;

};

