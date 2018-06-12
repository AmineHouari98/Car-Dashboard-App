#include "myparentobject.h"

#include <QComboBox>
#include <QInputDialog>


myParentObject::myParentObject()
{
    qDebug() << "myParentObject()" ;
    addToMap(EnumTableSensors::tableName, EnumTableSensors::columnsList) ;
    addToMap(EnumTableGps::tableName, EnumTableGps::columnsList) ;


    thisPath = QDir::toNativeSeparators(QApplication::applicationDirPath());
    settingsFilePath = thisPath +"/settings.ini" ;
    dirRS = thisPath +"/"+"localResource";
    nameOfSoftware = "obd_prototype_2";
    defaultSettingsGroup = "global" ;
    //_mySettings = new QSettings(nameOfSoftware, QSettings::NativeFormat, nullptr);
    //_mySettings = new QSettings(nameOfSoftware, "option") ;

    tModel = new QSqlRelationalTableModel ;


    _mySettings = new QSettings(settingsFilePath, QSettings::IniFormat);


}
myParentObject::~myParentObject()
{
    qDebug() << "~myParentObject()" ;
    delete tModel ;
    delete tModel_2;
    delete _mySettings;
}

void myParentObject::setSettings(QString key, QVariant data)
{
    _mySettings->setValue(key, data);
}

QVariant myParentObject::getSettings(QString key)
{
    return _mySettings->value(key) ;
}

void myParentObject::addToMap(QString tableName , QStringList columnsList)
{
    QStringList names, types ;
    QString temp ;
    for ( int i = 0 ; i < columnsList.length() ; i++ )
    {
        temp = columnsList[i] ;
        names << temp.split(" ")[0] ;
        types << temp.split(" ")[1] ;
    }
    _mapColumns.insert(tableName, names) ;
    _mapTypes.insert(tableName, types);
    _schemaMap.insert(tableName, prepare_create(tableName, columnsList));
}
QStringList myParentObject::tables()
{
    return tModel->database().tables() ;
}

bool myParentObject::executeQuery(QString query)
{
    //qDebug() << "executeQuery: " << query ;
    QSqlQuery cmd ;
    bool ok = cmd.exec(query);
    if ( !ok ) msgCritical("_executeQuery", query+"\n"+cmd.lastError().text());
    return ok ;
}

QStringList myParentObject::executeQueryAndGetList(QString query)
{
    QStringList list ;
    QSqlQuery cmd ;
    bool ok = cmd.exec(query);
    if ( !ok )
    {
        msgCritical("_executeQuery", query+"\n"+cmd.lastError().text());
        return list ;
    }

    while (cmd.next())
    {
        QSqlRecord record = cmd.record();

        for(int i=0; i < record.count(); i++)
        {
            list << record.value(i).toString();
        }
    }
    return list ;
}

QStringList myParentObject::getColumnFromTableWithoutDuplicates(QString tableName,  QString columnName)
{
    QStringList temperare ;
    QSqlQuery cmd("select DISTINCT "+columnName+" from "+ tableName +";") ;

    while (cmd.next())
    {
        QSqlRecord record = cmd.record();

        for(int i=0; i < record.count(); i++)
        {
            temperare << record.value(i).toString();
        }
    }

    return temperare ;
}

QStringList myParentObject::getColumnFromTableWithoutDuplicates(QString tableName,  QString columnName, QString filter)
{
    QStringList temperare ;
    QString query ;
    if(filter.isEmpty())
        query = "select DISTINCT "+columnName+" from "+ tableName +" ;" ;
    else
        query = "select DISTINCT "+columnName+" from "+ tableName +" where "+filter+" ;" ;

    QSqlQuery cmd(query) ;

    while (cmd.next())
    {
        QSqlRecord record = cmd.record();

        for(int i=0; i < record.count(); i++)
        {
            temperare << record.value(i).toString();
        }
    }
    //qDebug() << "getColumnFromTableWithoutDuplicates " << temperare  << query;
    return temperare ;
}

QStringList myParentObject::getColumnFromTable(QString tableName,  QString columnName)
{
    QStringList temperare ;
    QString query ;
    query = "select "+columnName+" from "+ tableName +" ;" ;
    QSqlQuery cmd(query) ;

    while (cmd.next())
    {
        QSqlRecord record = cmd.record();

        for(int i=0; i < record.count(); i++)
        {
            temperare << record.value(i).toString();
        }
    }
    qDebug() << "getColumnFromTableWithoutDuplicates " << temperare  << query;
    return temperare ;
}
QString myParentObject::prepare_create(QString tableName, QStringList columnsList)
{
    QString returnValue = "CREATE TABLE IF NOT EXISTS "+ tableName +"(";
    int n = columnsList.length() ;
    for ( int i = 0 ; i < n ; i++ )
    {
        if ( i == n-1 )
        {
            returnValue += columnsList[i] + "); " ;
            break ;
        }
        returnValue += columnsList[i] + ", " ;
    }
    return returnValue ;
}
QString myParentObject::prepare_dropTable(QString tableName)
{
    QString returnValue = "drop table "+ tableName +" ;" ;
    return returnValue;
}

QString myParentObject::prepare_deleteItem(QString tableName, QString id)
{
    QString returnValue = "delete from "+ tableName +" where id='"+id+"';" ;
    return returnValue;
}
QString myParentObject::prepare_clearTable(QString tableName)
{
    QString returnValue = "TRUNCATE "+ tableName +" ;" ;
    return returnValue;
}

bool myParentObject::msgQuestion(QString title ,QString body)
{
    qDebug() << "title: "+ title << "\nboady: "+ body ;
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(body);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
        return true ;
    }

    return false ;
}
void myParentObject::msgCritical(QString title ,QString body)
{
    qDebug() << "title: "+ title << "\nboady: "+ body ;
    QMessageBox::critical(0,title,body);
}
void myParentObject::msgInformation(QString title ,QString body)
{
    qDebug() << "title: "+ title << "\nboady: "+ body ;
    QMessageBox::information(0,title,body);
}
void myParentObject::msgWarning(QString title ,QString body)
{
    qDebug() << "title: "+ title << "\nboady: "+ body ;
    QMessageBox::warning(0,title,body);
}


QString myParentObject::getCurrentTime()
{
    return QTime::currentTime().toString("HH:mm:ss") ;
}
QString myParentObject::getCurrentDate()
{
    return QDate::currentDate().toString("yyyy-MM-dd");
}
QString myParentObject::getCurrentDateTime()
{
    return getCurrentDate()+" "+getCurrentTime() ;
    //return QDateTime::currentDateTime().toString("")
}

void myParentObject::initializeTables()
{
    foreach (QString schema, _schemaMap)
        executeQuery(schema);
}

void myParentObject::createFolderIfNotExsist(QString dirName)
{
    QString documentDir = dirName +"\\";
    if(!QDir(documentDir).exists()) QDir().mkdir(documentDir);
    if(!QDir(documentDir).exists())
        msgCritical("bool myParentObject::createFolderIfNotExsist(QString dirName)",
                    documentDir);
}

void myParentObject::copyFileTo(QString from, QString to)
{
    bool ok ;
    to.replace("\\","/");
    if( !fileExists(to) )
    {
        ok = QFile::copy(from, to);
        if(!ok)
        {
            msgCritical("void myParentObject::copyFileTo(QString from, QString to)",
                        from+"\n"+to+"\n");
            return ;
        }
        QFile myfile(to);
        ok = myfile.setPermissions(QFile::ReadOwner |QFile::WriteOwner ) ;
        if(!ok)
            msgCritical("void myParentObject::copyFileTo(QString from, QString to)",
                        myfile.errorString());
    }
}

bool myParentObject::fileExists(QString path)
{
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}

QStringList myParentObject::listFile(QString path)
{
    QDir myDir(path);
    return myDir.entryList(QDir::NoDotAndDotDot
                           | QDir::System
                           | QDir::Hidden
                           | QDir::AllDirs
                           | QDir::Files,
                           QDir::DirsFirst);
}

QString myParentObject::getStringFromUser(QWidget *parent, QString title, QString label)
{
    return QInputDialog::getText(parent, title, label,QLineEdit::Password);
}

void myParentObject::fillCombobox(QString tableName, QString columnName, QComboBox *combobox)
{
    QStringList tmp = getColumnFromTable(tableName,columnName) ;
    combobox->addItems(tmp);
    combobox->setCurrentIndex(-1);
    QCompleter *completer = new QCompleter(tmp, combobox);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    combobox->setCompleter(completer);
}
