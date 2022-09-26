
#include "metadata.h"

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

};

ZDFSMetaData::LoadFSImage() {
	// read vector to test
	vector <ZDFSImageFileRecord> testVector{};
	ZDFSImageFileRecord tmpStr;


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

	uint64_t id;
	cout << "Enter number: "; cin >> id;

	cout << "id: " << id << " FileSize: " << ZDFSFiles[id].FileSize << " FileName: " << ZDFSFiles[id].FileName << " Sizeof: " << sizeof(ZDFSFiles) << endl;
}
