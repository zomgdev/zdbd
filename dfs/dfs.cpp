#include "dfs.h"
#include "structures.h"
#include "fileutils.h"

#include <iostream>
#include <fstream>
#include <arpa/inet.h>
#include <cstdio>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <filesystem>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>

#define DEBUG

using namespace std;
namespace fs = std::filesystem;


// Алгоритм проверки настроек:
// 1. Проверяем наличие файла с настройками по умолчанию(DEFAULT_CONFIG_FILE_PATH). 
//    В РАБОТЕ
// 2. Если конфиг не найден то ищем файл в той директории, откуда запустились. Имя файла - DEFAULT_CONFIG_FILE_NAME
//    В РАБОТЕ
// 3. Если есть параметры в командной строке, переопределяем опцтт
//    В РАБОТЕ
// 
// Возвращаемое значение - ссылка на полный путь до конфига.

char* checkConfig() {

	char* CfgName;
	cout << "ЗАГЛУШКА: checkConfig " << endl;
	return CfgName;
}

// Если есть, считываем и заполняем ими класс . Возвращаем ссылку на настройки.
// Формат, пока - JSON.
ZDFS* ParseConfig() {
	ZDFS* ParsedCFG;

	return ParsedCFG;
}
static int DFSStartup(ZDFS *inCfg) {
	int ReturnCode = 0;
	cout << "Starting up!" << endl;
	return ReturnCode;
}

static char* CheckDirectoryStructure(char *path) {
	char* DataDirPath;

	return DataDirPath;
}

int main(int argc, char const* argv[]) {
	
	// Сюда будем запихивать параметры самой DFS, а пока пользуемся дефолтным конструктором.
	ZDFS *ZDFSConfig = new(ZDFS);

	// А здесь будут параметры работы демона.
	ZDFSDaemon* DFSdaemon = new ZDFSDaemon();

	string cfgPath, dataPath, metadataPath;

	// get and parse command line parameters
	if ( argc > 1) {
		//проверка опций командной строки(help, version и выход)
		cout << "Программист ленив, по этому пока игнорируем опции командной строки. Но обработчик обязательно появится." << endl;
	} else {
		cout << "There is no incoming parameters using default settings:" << endl;
		//cout << "Config: " << endl;
		//cout << "Heap memory: " << endl;
		//cout << "Block size: " << endl;
	}

	// Продолжаем разбирать командную строку.
	// Todo: доработать детальный разбор командной строки
	// 
	//for (int argnum = 0; argnum < argc; ++argnum) {
	//	cout << "Arg: " << argnum << " " << argv[argnum] << endl;
	//}

	// 
	cfgPath = (string)argv[0] + '/' + DEFAULT_CONFIG_FILE_NAME;
	
	cout << "CFGPATH: " << cfgPath << endl;

	//dataPath, metadataPath
	fs::path DataDirPath     { DFSdaemon->ZDFS_RootDirPath };
	fs::path BlocksDirPath   { DFSdaemon->ZDFS_BlocksDirPath };
	fs::path MetadataDirPath { DFSdaemon->ZDFS_MetadataDirPath };
	fs::path WALDirPath      { DFSdaemon->ZDFS_WALDirPath };
	
	// Checking directories
	if (fs::exists(DataDirPath) && fs::exists(BlocksDirPath)) {
		cout << "Blocks directory" << BlocksDirPath << " exists - Ok" << endl;
	} else {
		cout << "CREATING blocks directory" << endl;
		fs::create_directories(BlocksDirPath);
	}

	if (fs::exists(DataDirPath) && fs::exists(MetadataDirPath)) {
		cout << "Metadata directory" << MetadataDirPath << " exists - Ok" << endl;
	} else {
		cout << "CREATING metadata directory" << endl;
		fs::create_directories(MetadataDirPath);
	}
	if (fs::exists(DataDirPath) && fs::exists(WALDirPath)) {
        cout << "WAL directory" << WALDirPath << " exists - Ok" << endl;
	} else {
		cout << "CREATING WAL directory" << endl;
		fs::create_directories(WALDirPath);
	}



	FSImage ZDFS;// = new FSImage;

	//ZDFS.FSImageVersion = 1;
	//std::fill(&ZDFS.FilesRecords[0], &ZDFS.FilesRecords[1000000],0);
	//ZDFS.FilesTotal = 10;
	//ZDFS.TotalBlocks = 30;
	//ZDFS.UnreplicatedBlocks = 0;

	
	cout << endl<<endl<<"Current ZDFS status:" << endl;
	cout << "ZDFS total files: " << ZDFS.HeaderStruct.FilesTotal << endl;
	cout << "ZDFS total files: " << ZDFS.HeaderStruct.TotalBlocks<< endl;
	cout << "ZDFS total files: " << ZDFS.HeaderStruct.UnreplicatedBlocks << endl;
	cout << endl;

	cout << "Class size: " << sizeof(ZDFS.HeaderStruct) << endl << endl;
	


	std::ofstream FSImageFile("./data/metadata/fsimage", std::ios_base::binary);

	FSImageFile.write((char*)&ZDFS, sizeof(ZDFS));


	fs::path TestFile{ "/home/fox/test.mkv" };

	cout << "File size: " << fs::file_size(TestFile) << endl;
	cout << endl;


	vector <FSImageFileRecord> ZDFSFiles;

	std::random_device rd;
	std::uniform_int_distribution<int> rnd(1, 10);
	

	std::fstream FSRecordsDataFile("./data/metadata/fsrecords.bin", FSRecordsDataFile.binary | FSRecordsDataFile.in | FSRecordsDataFile.out | FSRecordsDataFile.trunc);

	//
	uint64_t fuid = 0;
	for (uint64_t id = 0; id < 1000000; ++id) {

		++fuid;

		// Сперва создаём слот в векторе, потом присваиваем его полям значения.
		ZDFSFiles.push_back(FSImageFileRecord());
		
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
			sizeof(ZDFSFiles[id].FileReplicas) + \
			ZDFSFiles[id].FileName.length() + 1;

		// Записываем в файл
		// FSRecordsDataFile.write(reinterpret_cast<char*>(&strct01.SizeOf), sizeof(strct01.SizeOf));

		FSRecordsDataFile.write(reinterpret_cast<char*>(&ZDFSFiles[id].SizeOf),       sizeof(ZDFSFiles[id].SizeOf));
		FSRecordsDataFile.write(reinterpret_cast<char*>(&ZDFSFiles[id].FileUID),      sizeof(ZDFSFiles[id].FileUID));
		FSRecordsDataFile.write(reinterpret_cast<char*>(&ZDFSFiles[id].StorageUID),   sizeof(ZDFSFiles[id].StorageUID));
		FSRecordsDataFile.write(reinterpret_cast<char*>(&ZDFSFiles[id].FileSize),     sizeof(ZDFSFiles[id].FileSize));
		FSRecordsDataFile.write(reinterpret_cast<char*>(&ZDFSFiles[id].FileReplicas), sizeof(ZDFSFiles[id].FileReplicas));

		FSRecordsDataFile.write(reinterpret_cast<char*>(ZDFSFiles[id].FileName.data()), ZDFSFiles[id].FileName.length() + 1);
	}
	ZDFSFiles.clear();

	// read vector to test
	vector <FSImageFileRecord> testVector{};
	FSImageFileRecord tmpStr;

	
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

		FSRecordsDataFile.read(reinterpret_cast<char*>(strtmpbuf), testVector[vectNum].SizeOf-FileRecWithoutStrSize);

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
	cout << "Press enter..."; 
	std::cin.ignore();
	


	return 0;
}
