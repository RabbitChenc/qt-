#ifndef COM_H
#define COM_H

#include <QString>
class com
{
public:
    com();
    static void setStyle(const QString &style);

    static void whiteStyle(void);
    static void blackStyle(void);
};

#endif // COM_H
