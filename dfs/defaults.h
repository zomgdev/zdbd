#ifndef ZDFS_DEFAULTS_H
#define ZDFS_DEFAULTS_H

// ��������� �� ��������� ��� �������� ���������� 
// Default settings



// 
// Daemon settings
// 

// ���������� ���� �� ������� �� ���������
// ZDFS config files path
#define DEFAULT_CONFIG_FILES_DIR  "/etc/zdfs";

// ��� �������� �� ���������
// Configuration files names
#define DEFAULT_CONFIG_FILE_NAME  "zdfs.conf";

// ���� � �������� ������ �� ���������
// Data directory paths
#define DEFAULT_DATA_DIR_PATH     "/var/lib/zdfs";
#define DEFAULT_BLOCKS_DIR_PATH   "/var/lib/zdfs/storage";
#define DEFAULT_METADATA_DIR_PATH "/var/lib/zdfs/metadata";
#define DEFAULT_WAL_DIR_PATH      "/var/lib/zdfs/wal";

// 
// ZDFS settings
// 

// ������� ��������� �������� �������
// Filesystem base parameters
#define DEFAULT_BLOCK_SIZE   128*1024*1024;
#define DEFAULT_STORAGE_SIZE 4*1024*1024*1024;

#endif
