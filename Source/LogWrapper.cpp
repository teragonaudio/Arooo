/*
  ==============================================================================

    LogWrapper.cpp
    Created: 22 Jan 2013 9:28:57pm
    Author:  Nik Reiman

  ==============================================================================
*/

#include "LogWrapper.h"

void LogWrapper::log(String const & message) {
}

LogWrapper::LogWrapper(GuiLogger* guiLogger) {
  this->guiLogger = guiLogger;
  this->fileLogger = FileLogger::createDefaultAppLogger("Arooo", "log.txt", String::empty, 0);
}

LogWrapper::~LogWrapper() {
  fileLogger = nullptr;
}

void LogWrapper::logMessage(const String& message) {
  fileLogger->logMessage(message);
  guiLogger->logMessage(message);
}




