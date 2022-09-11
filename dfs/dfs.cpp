#include <iostream>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>


using namespace std;

// Абсолютный путь до конфига по-умолчанию
#define DEFAULT_CONFIG_FILE_PATH '/etc/zdfs/zdfs.conf';

// Имя конфига по-умолчанию
#define DEFAULT_CONFIG_FILE_NAME 'zdfs.conf';


class Configuration {
private:
	long somth;

public:
	long* ZDFS_DataDirPath;
	long* ZDFS_BlockSize;
	long* MaxHeapMemory;
};


// Алгоритм проверки настроек:
// 1. Проверяем наличие файла с настройками по умолчанию(DEFAULT_CONFIG_FILE_PATH). 
// 
// 2. Если конфиг не найден то ищем файл в той директории, откуда запустились. Имя файла - DEFAULT_CONFIG_FILE_NAME
//    Возвращаем ан
//
char* checkConfig() {

	char* CfgName;
	cout << "ЗАГЛУШКА: checkConfig " << endl;
	return CfgName;
}

// Если есть, считываем и заполняем ими класс . Возвращаем ссылку на настройки.
// Формат, пока - JSON.
Configuration* ParseConfig() {
	Configuration* ParsedCFG;

	return ParsedCFG;
}
static int DFSStartup(Configuration *inCfg) {
	int ReturnCode = 0;
	cout << "Starting up!" << endl;
	return ReturnCode;
}

int main(int argc, char const* argv[]) {
	
	Configuration *DFSConfig = new(Configuration);

	// get command line parameters
	if ( argc > 1) {
		//проверка опций командной строки(help, version и выход)

	}

	// Здесь проверяем остальное и стартуем
	// 1. Проверяем наличие файла с конфигом
	// 2. А если есть параметры в командной строке, то переопределяем ими параметры из конфига



	// Старт DFS
	DFSStartup(DFSConfig);



	return 0;
}
