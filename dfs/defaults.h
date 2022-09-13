#ifndef ZDFS_DEFAULTS_H
#define ZDFS_DEFAULTS_H

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
#define DEFAULT_DATA_DIR_PATH     "/var/lib/zdfs";
#define DEFAULT_BLOCKS_DIR_PATH   "/var/lib/zdfs/storage";
#define DEFAULT_METADATA_DIR_PATH "/var/lib/zdfs/metadata";
#define DEFAULT_WAL_DIR_PATH      "/var/lib/zdfs/wal";

// 
// ZDFS settings
// 

// Базовые параметры файловой системы
// Filesystem base parameters
#define DEFAULT_BLOCK_SIZE   128*1024*1024;
#define DEFAULT_STORAGE_SIZE 4*1024*1024*1024;

#endif
