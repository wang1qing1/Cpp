
#include <mutex>
#include "util.hpp"

#define _CONFILE "./cloud.conf"

namespace Cloud
{
    // 配置文件读取类————懒汉单例模式
    class Config
    {
    private:
        static Cloud::Config *_instance;
        static std::mutex _mutex;

    private:
        Config()
        {
            ReadConfile();
        }
        int _hot_time;                // 热点时间
        int _server_port;             // 端口
        std::string _server_ip;       // IP地址
        std::string _download_prefix; // 下载前缀
        std::string _packfile_suffix; // 压缩包后缀
        std::string _pack_dir;        // 压缩包存放路径
        std::string _back_dir;        // 备份文件存放路径
        std::string _backup_file;     // 备份信息的存放文件
        bool ReadConfile()
        {
            Cloud::FileUtil fileutil(_CONFILE);
            string body;
            fileutil.GetContent(&body);

            Json::Value root;
            Cloud::JsonUtil::UnSerialize(body, &root);

            _hot_time = root["hot_time"].asInt();
            _server_port = root["server_port"].asInt();
            _server_ip = root["server_ip"].asString();
            _download_prefix = root["download_prefix"].asString();
            _packfile_suffix = root["packfile_suffix"].asString();
            _pack_dir = root["pack_dir"].asString();
            _back_dir = root["back_dir"].asString();
            _backup_file = root["backup_file"].asString();
        }

    public:
        int GetHotTime() { return _hot_time; }
        int GetServerPort() { return _server_port; }
        std::string GetServerIp() { return _server_ip; }
        std::string GetDownloadPrefix() { return _download_prefix; }
        std::string GetPackFileSuffix() { return _packfile_suffix; }
        std::string GetPackDir() { return _pack_dir; }
        std::string GetBackDir() { return _back_dir; }
        std::string GetBackupFile() { return _backup_file; }

        static Config *GetInstance()
        {
            if (_instance == nullptr)
            {
                _mutex.lock();
                if (_instance == nullptr)
                {
                    _instance = new Config();
                }
                _mutex.unlock();
            }
            return _instance;
        }
    };
    Config *Config::_instance = nullptr;
    std::mutex Config::_mutex;
}
