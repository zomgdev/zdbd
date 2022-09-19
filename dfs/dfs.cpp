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

	//FSImageFileRecord ZDFSRecord = new(FSImageFileRecord);
	//ZDFSRecord->FileSize = 1024 * 1024 * 1024;
	//ZDFSRecord->FileName = "test_file001.txt";

	cout << "Vector max_size: " << ZDFSFiles.max_size() << endl;
	for (uint64_t id = 0; id < 10000000; ++id) {
		ZDFSFiles.push_back(FSImageFileRecord());
		ZDFSFiles[id].FileSize = 1024 * 1024 * 1024;
		ZDFSFiles[id].FileName = "test_file."+to_string(id);
//		cout << "id: " << id << " FileSize: " << ZDFSFiles[id].FileSize << " FileName: " << ZDFSFiles[id].FileName << " Sizeof: " << sizeof(ZDFSFiles) << endl;
	}

	uint64_t id;
	cout << "Enter number: "; cin >> id;
	
	cout << "id: " << id << " FileSize: " << ZDFSFiles[id].FileSize << " FileName: " << ZDFSFiles[id].FileName << " Sizeof: " << sizeof(ZDFSFiles) << endl;
	
	cout << "Press enter..."; cin.ignore();
	
	




	return 0;

}
