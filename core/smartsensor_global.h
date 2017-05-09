#ifndef SMARTSENSOR_GLOBAL_H
#define SMARTSENSOR_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef SMARTSENSOR_LIB
# define SMARTSENSOR_EXPORT Q_DECL_EXPORT
#else
# define SMARTSENSOR_EXPORT Q_DECL_IMPORT
#endif

#endif // SMARTSENSOR_GLOBAL_H
