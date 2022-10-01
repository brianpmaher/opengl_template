#pragma once

typedef enum LogLevel {
    LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL,
} LogLevel;

void TraceLog(LogLevel logLevel, char *format, ...);
#define DebugLog(...) TraceLog(LOG_DEBUG, __VA_ARGS__)
#define InfoLog(...) TraceLog(LOG_INFO, __VA_ARGS__)
#define WarningLog(...) TraceLog(LOG_WARNING, __VA_ARGS__)
#define ErrorLog(...) TraceLog(LOG_ERROR, __VA_ARGS__)
#define FatalLog(...) TraceLog(LOG_FATAL, __VA_ARGS__)

void SetLogLevel(LogLevel logLevel);
