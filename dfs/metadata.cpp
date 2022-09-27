#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <random>

#include "metadata.h"

using namespace std;

// FSImage constructor


void ZDFSMetaData::StartupChecking(ZDFSDaemon *zdfsd) {
	
	DataDirPath = { zdfsd->ZDFS_RootDirPath };
	MetadataDirPath = { zdfsd->ZDFS_MetadataDirPath };

	if (fs::exists(DataDirPath) && fs::exists(MetadataDirPath)) {
		cout << "Metadata directory" << MetadataDirPath << " exists - Ok" << endl;
	}
	else {
		cout << "CREATING metadata directory" << endl;
		fs::create_directories(MetadataDirPath);
	}
};

ZDFSMetaData::ZDFSMetaData() {
	// ZDFS Metadata constructor
	// fill the structure by test data for a while
	HeaderStruct.FSImageVersion = 1;
	HeaderStruct.FilesTotal = 65535;
	HeaderStruct.TotalBlocks = 255;
	HeaderStruct.UnreplicatedBlocks = 255;

	std::fill(&HeaderStruct.FilesRecords[0], &HeaderStruct.FilesRecords[ZDFS_MAX_FILES], 0);
};

bool ZDFSMetaData::LoadFSImage(ZDFSDaemon zfdfsd) {
	// read vector to test
	vector <ZDFSImageFileRecord> testVector{};
	ZDFSImageFileRecord tmpStr;
	
	std::fstream FSRecordsDataFile("./data/metadata/fsrecords.bin", FSRecordsDataFile.binary | FSRecordsDataFile.in | FSRecordsDataFile.out | FSRecordsDataFile.trunc);


	uint64_t vectNum = 0;
	uint64_t CurrentFilePos = 0;

	string tmpString;

	uint16_t FileRecWithoutStrSize = \
		sizeof(tmpStr.SizeOf) + sizeof(tmpStr.FileUID) + sizeof(tmpStr.StorageUID) + \
		sizeof(tmpStr.FileSize) + sizeof(tmpStr.FileReplicas);


	FSRecordsDataFile.seekp(CurrentFilePos);

	while (!FSRecordsDataFile.eof()) {


		//cout << "Current file position: " << FSRecordsDataFile.tellg() << endl;

		FSRecordsDataFile.read(reinterpret_cast<char*>(&tmpStr.SizeOf), sizeof(tmpStr.SizeOf));
		FSRecordsDataFile.read(reinterpret_cast<char*>(&tmpStr.FileUID), sizeof(tmpStr.FileUID));
		FSRecordsDataFile.read(reinterpret_cast<char*>(&tmpStr.StorageUID), sizeof(tmpStr.StorageUID));
		FSRecordsDataFile.read(reinterpret_cast<char*>(&tmpStr.FileSize), sizeof(tmpStr.FileSize));
		FSRecordsDataFile.read(reinterpret_cast<char*>(&tmpStr.FileReplicas), sizeof(tmpStr.FileReplicas));
		testVector.push_back(tmpStr);


		char* strtmpbuf = new char[testVector[vectNum].SizeOf - FileRecWithoutStrSize];

		FSRecordsDataFile.read(reinterpret_cast<char*>(strtmpbuf), testVector[vectNum].SizeOf - FileRecWithoutStrSize);

		testVector[vectNum].FileName = strtmpbuf;


		// Debug through the cout rules!!! :D

		//cout << "Struct size without string: " << FileRecWithoutStrSize << endl;
		//cout << "String size: " << tmpStr.SizeOf - FileRecWithoutStrSize << endl;
		/*
		std::cout \
			<< " SizeOf: " << testVector[vectNum].SizeOf \
			<< " FileUID: " << testVector[vectNum].FileUID \
			<< " StorageUID: " << testVector[vectNum].StorageUID \
			<< " FileSize: " << tmpStr.FileSize \
			<< " FileReplicas: " << unsigned(testVector[vectNum].FileReplicas) \
			//<< endl << endl;
			<< " FileName: " << testVector[vectNum].FileName << endl;
			*/
		vectNum++;

	}

	// todo: разобраться, нужен ли здесь такой тест.
	//uint64_t id;
	//cout << "Enter number: "; cin >> id;
	//cout << "id: " << id << " FileSize: " << ZDFSFiles[id].FileSize << " FileName: " << ZDFSFiles[id].FileName << " Sizeof: " << sizeof(ZDFSFiles) << endl;
	return true;
}
// Test metadata generator ;)
void GenerateTestMeta(ZDFSDaemon* zdfsd) {
	
	std::fstream FSRecordsDataFile("./data/metadata/fsrecords.bin", FSRecordsDataFile.binary | FSRecordsDataFile.in | FSRecordsDataFile.out | FSRecordsDataFile.trunc);
	vector <ZDFSImageFileRecord> ZDFSFiles;

	std::random_device rd;
	std::uniform_int_distribution<int> rnd(1, 10);

	//
	uint64_t fuid = 0;
	for (uint64_t id = 0; id < 1000000; ++id) {

		++fuid;

		// Сперва создаём слот в векторе, потом присваиваем его полям значения.
		ZDFSFiles.push_back(ZDFSImageFileRecord());

		ZDFSFiles[id].FileUID = fuid;
		ZDFSFiles[id].StorageUID = 1;
		ZDFSFiles[id].FileSize = (uint64_t)rnd(rd) * 1024 * 1024 * 1024;
		ZDFSFiles[id].FileReplicas = 3;
		ZDFSFiles[id].FileName = "test_file." + to_string(id);
		ZDFSFiles[id].SizeOf = \
			sizeof(ZDFSFiles[id].SizeOf) + \
			sizeof(ZDFSFiles[id].FileUID) + \
			sizeof(ZDFSFiles[id].StorageUID) + \
			sizeof(ZDFSFiles[id].FileSize) + \
			sizeof(ZDFSFiles[id	].FileReplicas) + \
			ZDFSFiles[id].FileName.length() + 1;

		// Записываем в файл
		// FSRecordsDataFile.write(reinterpret_cast<char*>(&strct01.SizeOf), sizeof(strct01.SizeOf));

		FSRecordsDataFile.write(reinterpret_cast<char*>(&ZDFSFiles[id].SizeOf), sizeof(ZDFSFiles[id].SizeOf));
		FSRecordsDataFile.write(reinterpret_cast<char*>(&ZDFSFiles[id].FileUID), sizeof(ZDFSFiles[id].FileUID));
		FSRecordsDataFile.write(reinterpret_cast<char*>(&ZDFSFiles[id].StorageUID), sizeof(ZDFSFiles[id].StorageUID));
		FSRecordsDataFile.write(reinterpret_cast<char*>(&ZDFSFiles[id].FileSize), sizeof(ZDFSFiles[id].FileSize));
		FSRecordsDataFile.write(reinterpret_cast<char*>(&ZDFSFiles[id].FileReplicas), sizeof(ZDFSFiles[id].FileReplicas));

		FSRecordsDataFile.write(reinterpret_cast<char*>(ZDFSFiles[id].FileName.data()), ZDFSFiles[id].FileName.length() + 1);
	}
	ZDFSFiles.clear();

}
