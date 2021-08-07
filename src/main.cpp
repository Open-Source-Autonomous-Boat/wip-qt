#include "main.h"

int main(int argc, char *argv[]) {
  // Enable qml debugging
#if DEBUG
  QQmlDebuggingEnabler enabler;
#endif
  // Create application (duhh)
  InitialWindow win(argc, argv);
  // Return exit value
  return win.exec();
}
