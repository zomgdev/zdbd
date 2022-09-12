#ifndef ZDFS_SYSUTILS_H
#define ZDFS_SYSUTILS_H

#include "structures.h"
#include <string>
#include <iostream>

// 
// Проверка состояния настроек и компонент
// 1. Наличие конфгурационных файлов
// 2. Системные директории
// 3. Контент системных директорий
// 



class sysZDFS {
private:
public:
	Cfg();
	ZDFSParameters(&config);
	sysCheck();
};

#end