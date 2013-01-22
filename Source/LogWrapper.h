/*
  ==============================================================================

    LogWrapper.h
    Created: 22 Jan 2013 9:28:57pm
    Author:  Nik Reiman

  ==============================================================================
*/

#ifndef __LOGWRAPPER_H_FFBD92D6__
#define __LOGWRAPPER_H_FFBD92D6__

#include "../JuceLibraryCode/JuceHeader.h"

class GuiLogger : public Logger {
public:
  GuiLogger() {}
  virtual ~GuiLogger() {}

  virtual void logMessage(const String& message) {}

private:
};

class LogWrapper : public Logger {
public:
  LogWrapper(GuiLogger* guiLogger);
  virtual ~LogWrapper();

  static void log(const String& message);
  virtual void logMessage(const String& message);

private:
  GuiLogger* guiLogger;
  ScopedPointer<FileLogger> fileLogger;
};

#endif
