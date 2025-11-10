#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Logger
{
    void Init(const char* filepath)
    {
        spdlog::set_default_logger(
            spdlog::basic_logger_mt("root", filepath, true)
        );

        spdlog::set_level(spdlog::level::debug);

        spdlog::flush_on(spdlog::level::info);

        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] %l: %v");
    }
}
