#include "./trace_log.h"

#include <stdio.h>
#include <stdarg.h>

static LogLevel logLevel = LOG_INFO;

void TraceLog(LogLevel logLevel_, char *format, ...)
{
    if (logLevel_ < logLevel)
        return;


    switch (logLevel_)
    {
    case LOG_DEBUG:
        printf("DEBUG: ");
        break;
    case LOG_INFO:
        printf("INFO: ");
        break;
    case LOG_WARNING:
        printf("WARNING: ");
        break;
    case LOG_ERROR:
        printf("ERROR: ");
        break;
    case LOG_FATAL:
        printf("FATAL: ");
        break;
    }

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}

void SetLogLevel(LogLevel logLevel_)
{
    logLevel = logLevel_;
}
