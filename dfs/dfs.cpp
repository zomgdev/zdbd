#include <iostream>
#include <fstream>
#include <filesystem>
//#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <random>

//#include <cstdio>
//#include <sys/socket.h>
//#include <arpa/inet.h>
//#include <unistd.h>
//#include <iterator>
//#include <algorithm>

#include "dfs.h"
#include "structures.h"
#include "fileutils.h"
#include "metadata.h"

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

	char* CfgName=0;
	cout << "ЗАГЛУШКА: checkConfig " << endl;
	return CfgName;
}

// Если есть, считываем и заполняем ими класс . Возвращаем ссылку на настройки.
// Формат, пока - JSON.
ZDFS* ParseConfig() {
	ZDFS* ParsedCFG=0;

	return ParsedCFG;
}
static int DFSStartup(ZDFS *inCfg) {
	int ReturnCode = 0;
	cout << "Starting up!" << endl;
	return ReturnCode;
}

static char* CheckDirectoryStructure(char *path) {
	char* DataDirPath = 0;

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
//	fs::path DataDirPath     { DFSdaemon->ZDFS_RootDirPath };
//	fs::path MetadataDirPath { DFSdaemon->ZDFS_MetadataDirPath };
//	fs::path BlocksDirPath   { DFSdaemon->ZDFS_BlocksDirPath };
//	fs::path WALDirPath      { DFSdaemon->ZDFS_WALDirPath };
	
	//// Checking directories
	//if (fs::exists(DataDirPath) && fs::exists(BlocksDirPath)) {
	//	cout << "Blocks directory" << BlocksDirPath << " exists - Ok" << endl;
	//} else {
	//	cout << "CREATING blocks directory" << endl;
	//	fs::create_directories(BlocksDirPath);
	//}

	//if (fs::exists(DataDirPath) && fs::exists(WALDirPath)) {
    //    cout << "WAL directory" << WALDirPath << " exists - Ok" << endl;
	//} else {
	//	cout << "CREATING WAL directory" << endl;
	//	fs::create_directories(WALDirPath);
	//}



	string strCommand;
	map<string, uint16_t> todo{ { "bye",100}, { "make demo",1}, {"read meta", 2} };
	
	while (true) {
		cout << "DFS shell > ";
		getline(cin, strCommand);

		
		switch (todo[strCommand]) {
		
		case 100:
			cout << "Have a nice day!" << endl;
			return 0;

		case 1: 
			cout << "Create demo metadata storage" << endl;
			break;

		case 2: 
			cout << "Read metadata " << endl;
			break;

		default:
			break;
		}
	}

	cout << "Press enter..."; 
	std::cin.ignore();
	


	return 0;
}
