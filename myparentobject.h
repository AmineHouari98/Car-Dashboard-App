#ifndef MYPARENTOBJECT_H
#define MYPARENTOBJECT_H

#include "EnumTables.h"
#include <QObject>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QCompleter>

#include <QSettings>
#include <QFileInfo>
#include <QCoreApplication>
#include <QDebug>
#include <QPointer>
#include <QMessageBox>
#include <QTimer>
#include <QTableView>
#include <QHeaderView>
#include <QMap>
#include <QString>
#include <QDateTime>
#include <QLabel>
#include <QDir>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QInputDialog>
#include <QComboBox>

class myParentObject: public EnumTableSensors,public EnumTableGps
{

public:
    myParentObject();
    ~myParentObject();
    QMap<QString, QStringList> _mapColumns;
    QMap<QString, QStringList> _mapTypes;
    QMap<QString, QString> _schemaMap;
    QSqlRelationalTableModel *tModel;
    QSqlRelationalTableModel *tModel_2;


    void setSettings(QString key, QVariant data);
    QVariant getSettings(QString key);

    void addToMap(QString tableName, QStringList columnsList_1);
    bool executeQuery(QString query);
    QStringList getColumnFromTableWithoutDuplicates(QString tableName,  QString columnName);
    QStringList getColumnFromTableWithoutDuplicates(QString tableName,  QString columnName, QString filter);
    QString prepare_create(QString tableName, QStringList columnsList_1);
    QString prepare_dropTable(QString tableName);
    QString prepare_deleteItem(QString tableName, QString id);
    QString prepare_clearTable(QString tableName);
    QStringList tables();

    bool msgQuestion(QString title, QString body);
    void msgCritical(QString title, QString body);
    void msgInformation(QString title, QString body);
    void msgWarning(QString title, QString body);

    QString getCurrentTime();
    QString getCurrentDate();
    QString getCurrentDateTime();

    void createFolderIfNotExsist(QString dirName);
    bool fileExists(QString path);
    void copyFileTo(QString from, QString to);
    QStringList listFile(QString path);
    QString getStringFromUser(QWidget *parent, QString title, QString label) ;
    void initializeTables();
    /*-------- VAR -------*/
    QString nameOfSoftware ;
    QString thisPath, dirRS, settingsFilePath ;
    QString defaultSettingsGroup ;
    QSettings *_mySettings;




    QStringList executeQueryAndGetList(QString query);
    void fillCombobox(QString tableName, QString columnName, QComboBox *combobox);
    QStringList getColumnFromTable(QString tableName, QString columnName);

};

#endif // MYPARENTOBJECT_H
