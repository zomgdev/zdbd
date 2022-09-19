#pragma once
#define DEBUG
// Настройки по умолчанию для основных параметров 
// Default settings



// 
// Daemon settings
// 

// Абсолютный путь до конфига по умолчанию
// ZDFS config files path
#define DEFAULT_CONFIG_FILES_DIR  "/etc/zdfs";

// Имя конфигов по умолчанию
// Configuration files names
#define DEFAULT_CONFIG_FILE_NAME  "zdfs.conf";

// Путь к каталогу данных по умолчанию
// Data directory paths

#ifdef DEBUG

#define DEFAULT_DATA_DIR_PATH     "./data";
#define DEFAULT_BLOCKS_DIR_PATH   "./data/blocks";
#define DEFAULT_METADATA_DIR_PATH "./data/metadata";
#define DEFAULT_WAL_DIR_PATH      "./data/wal";

#else

 #define DEFAULT_DATA_DIR_PATH     "/var/lib/zdfs";
 #define DEFAULT_BLOCKS_DIR_PATH   "/var/lib/zdfs/blocks";
 #define DEFAULT_METADATA_DIR_PATH "/var/lib/zdfs/metadata";
 #define DEFAULT_WAL_DIR_PATH      "/var/lib/zdfs/wal";

#endif // DEBUG


// 
// ZDFS settings
// 

// Базовые параметры файловой системы
// Filesystem base parameters
#define DEFAULT_BLOCK_SIZE   64*1024*1024;      // bytes
#define DEFAULT_STORAGE_SIZE 4*1024*1024*1024;  // bytes
