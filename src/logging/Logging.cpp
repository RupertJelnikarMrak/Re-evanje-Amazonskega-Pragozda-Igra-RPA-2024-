#include "logging/Logging.hpp"
#include "helper/Constants.hpp"
#include "helper/FileUtils.hpp"

#include <vector>
#include <fstream>
#include <chrono>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_sinks.h>


void Logging::init()
{
    //auto time = std::chrono::system_clock::now();
    // TODO: Change the file cycle to archive old logs in timed zip format

    std::string logs_path = Const::getExePath() + "/logs/";

    // Cycle through the log files
    if (fileutils::fileExists(logs_path + "Log5.txt"))
        std::remove((logs_path + "Log5.txt").c_str());

    for (int i = 4; i > 0; i--)
        if (fileutils::fileExists(logs_path + "Log" + std::to_string(i) + ".txt"))
            std::rename((logs_path + "Log" + std::to_string(i) + ".txt").c_str(), (logs_path + "Log" + std::to_string(i + 1) + ".txt").c_str());

    if (fileutils::fileExists(logs_path + "Latest.txt"))
        std::rename((logs_path + "Latest.txt").c_str(), (logs_path + "Log1.txt").c_str());

    std::vector<spdlog::sink_ptr> sinks;
    sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
    sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(logs_path + "Latest.txt"));

    auto logger = std::make_shared<spdlog::logger>("main_logger", begin(sinks), end(sinks));

    spdlog::set_default_logger(logger);
    spdlog::flush_on(spdlog::level::info);
    spdlog::set_level(spdlog::level::info);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");

    spdlog::info("Logger initialized!");
}