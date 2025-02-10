#ifndef COMMAND_SYSTEM_LIBRARY_H
#define COMMAND_SYSTEM_LIBRARY_H

#include <QMetatype>
#include <QtCore/qglobal.h>

#if defined(COMMAND_SYSTEM_LIBRARY)
#  define COMMAND_SYSTEM_EXPORT Q_DECL_EXPORT
#else
#  define COMMAND_SYSTEM_EXPORT Q_DECL_IMPORT
#endif

#endif // COMMAND_SYSTEM_LIBRARY_H
