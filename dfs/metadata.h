#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "structures.h"

namespace fs = std::filesystem;


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
struct ZDFSImageFileRecord {
	uint16_t    SizeOf;
	uint64_t    FileUID;
	uint32_t    StorageUID;
	uint64_t    FileSize;
	uint8_t     FileReplicas;
	std::string FileName;
};
struct FilesPermissions{
	uint64_t FileUID;
};


class ZDFS_Block {
private:
	unsigned long long BlockSize;
	unsigned long long BlockID;

};

class ZDFSMetaData {
private:
	fs::path DataDirPath;
	fs::path MetadataDirPath;
	FSImageHeader HeaderStruct{};

public:
	void GenerateTestMeta(ZDFSDaemon* zdfsd);
	void StartupChecking(ZDFSDaemon *zdfsd);
	bool LoadFSImage(ZDFSDaemon zdfsd);
	ZDFSMetaData();
};