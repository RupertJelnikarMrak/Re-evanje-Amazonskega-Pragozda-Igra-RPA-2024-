#include "logging/Logging.hpp"
#include "helper/Constants.hpp"

#include <vector>
#include <fstream>
#include <chrono>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_sinks.h>


bool fileExists(const std::string &pFileName)
{
    std::ifstream file(pFileName);
    return file.good();
}

void Logging::init()
{
    //auto time = std::chrono::system_clock::now();
    // TODO: Change the file cycle to archive old logs in timed zip format

    std::string logsPath = Const::getExePath() + "/logs/";

    // Cycle through the log files
    if (fileExists(logsPath + "Log5.txt"))
        std::remove((logsPath + "Log5.txt").c_str());

    for (int i = 4; i > 0; i--)
        if (fileExists(logsPath + "Log" + std::to_string(i) + ".txt"))
            std::rename((logsPath + "Log" + std::to_string(i) + ".txt").c_str(), (logsPath + "Log" + std::to_string(i + 1) + ".txt").c_str());

    if (fileExists(logsPath + "Latest.txt"))
        std::rename((logsPath + "Latest.txt").c_str(), (logsPath + "Log1.txt").c_str());

    std::vector<spdlog::sink_ptr> sinks;
    sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
    sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(logsPath + "Latest.txt"));

    auto logger = std::make_shared<spdlog::logger>("main_logger", begin(sinks), end(sinks));

    //auto logger = spdlog::basic_logger_mt("game_file_logger", (logsPath + "Latest.txt").c_str());
    
    spdlog::set_default_logger(logger);
    spdlog::flush_on(spdlog::level::info);
    spdlog::set_level(spdlog::level::info);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");

    spdlog::info("Logger initialized!");
}