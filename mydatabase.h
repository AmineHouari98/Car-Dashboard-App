#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QObject>
#include <myparentobject.h>

class MyDatabase : public QObject, public myParentObject
{
    Q_OBJECT
public:
    explicit MyDatabase(QObject *parent = nullptr);

    bool initializeDatabse(QString);
signals:

public slots:
    void onStart();
    void saveData(EnumRecord data) ;
private:

    QSqlDatabase myDatabase ;
};

#endif // MYDATABASE_H
