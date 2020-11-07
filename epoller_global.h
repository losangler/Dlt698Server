#ifndef EPOLLER_GLOBAL_H
#define EPOLLER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(EPOLLER_LIBRARY)
#  define EPOLLERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define EPOLLERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // EPOLLER_GLOBAL_H
