//
// Created by Reeb Deve on 2022/5/16.
//

#ifndef CATLOG_ENV_H
#define CATLOG_ENV_H


#include "singleton.h"
#include "thread.h"
#include <map>
#include <string>
#include <vector>

namespace CatLog {

    class Env {
    public:
        typedef RWMutex RWMutexType;
        bool init(int argc, char** argv);

        void add(const std::string& key, const std::string& val);
        bool has(const std::string& key);
        void del(const std::string& key);
        std::string get(const std::string& key, const std::string& default_value );

        void addHelp(const std::string& key, const std::string& desc);
        void removeHelp(const std::string& key);
        void printHelp();

        const std::string& getExe() const { return m_exe;}
        const std::string& getCwd() const { return m_cwd;}

        bool setEnv(const std::string& key, const std::string& val);
        std::string getEnv(const std::string& key, const std::string& default_value );

        std::string getAbsolutePath(const std::string& path) const;
        std::string getAbsoluteWorkPath(const std::string& path) const;
        std::string getConfigPath();
    private:
        RWMutexType m_mutex;
        std::map<std::string, std::string> m_args;
        std::vector<std::pair<std::string, std::string> > m_helps;

        std::string m_program;
        std::string m_exe;
        std::string m_cwd;
    };

    typedef CatLog::Singleton<Env> EnvMgr;

}

#endif //CATLOG_ENV_H
