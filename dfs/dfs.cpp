#include "dfs.h"

#include <iostream>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>


using namespace std;

// Абсолютный путь до конфига по-умолчанию
#define DEFAULT_CONFIG_FILE_PATH "/etc/zdfs/zdfs.conf";

// Имя конфига по-умолчанию
#define DEFAULT_CONFIG_FILE_NAME "zdfs.conf";

// Путь к каталогу данных по умолчанию
#define DEFAULT_DATA_DIR     "/var/lib/zdfs";
#define DEFAULT_BLOCKS_DIR   "/var/lib/zdfs/storage";
#define DEFAULT_METADATA_DIR "/var/lib/zdfs/metadata";
#define DEFAULT_WAL_DIR      "/var/lib/zdfs/wal";

// Параметры файловой системы
#define DEFAULT_BLOCK_SIZE   128*1024*1024;
#define DEFAULT_STORAGE_SIZE 1000*1024*1024;


class ZDFS {

public:
	char* ZDFS_DataDirPath;
	long* ZDFS_BlockSize;
	long* MaxHeapMemory;
};


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
	
	ZDFS *DFSConfig = new(ZDFS);

	// get command line parameters
	if ( argc > 1) {
		//проверка опций командной строки(help, version и выход)

	} else {
		cout << "There is no incoming parameters using default settings:" << endl;
		//cout << "Config: " << endl;
		//cout << "Heap memory: " << endl;
		//cout << "Block size: " << endl;
	}

	//for (int argnum = 0; argnum < argc; ++argnum) {
	//	cout << "Arg: " << argnum << " " << argv[argnum] << endl;
	//}

	string cfgPath;

	cfgPath = (string)argv[0] + '/' + DEFAULT_CONFIG_FILE_NAME;

	cout << "CFGPATH: " << cfgPath << endl;


	// Здесь проверяем остальное и стартуем
	// 1. Проверяем наличие файла с конфигом
	// 2. А если есть параметры в командной строке, то переопределяем ими параметры из конфига



	// Старт DFS
	DFSStartup(DFSConfig);



	return 0;
}
