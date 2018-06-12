#include "mydatabase.h"

MyDatabase::MyDatabase(QObject *parent) : QObject(parent)
{

}

void MyDatabase::onStart()
{
    qDebug() << "void MyDatabase::onStart() ..." ;

    initializeTables();

    qDebug() << tables() ;
    tModel->setTable(EnumRecord::tableName);
    tModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    tModel->select();
}

void MyDatabase::saveData(EnumRecord data)
{
    //qDebug() << "void MyDatabase::saveData(EnumRecord data)...";
    //qDebug() << data._temperature << data._light ;
    int row = tModel->rowCount() ;
    tModel->insertRow(row);

    tModel->setData(tModel->index(row, EnumRecord::_01Date),
                      getCurrentDateTime());
//    tModel->setData(tModel->index(row, EnumRecord::_02Temperature),
//                      data._temperature);
//    tModel->setData(tModel->index(row, EnumRecord::_03Humidity),
//                      data._humidity);
//    //tModel->setData(tModel->index(row, EnumRecord::_04HeatIndex),data._heatIndex);
//    tModel->setData(tModel->index(row, EnumRecord::_05Light),
//                      data._light);
    //tModel->setData(tModel->index(row, EnumRecord::_06CO), data._CO);
    //tModel->setData(tModel->index(row, EnumRecord::_07lamp), data._lamp);
    //tModel->setData(tModel->index(row, EnumRecord::_08window), data._window);
    //tModel->setData(tModel->index(row, EnumRecord::_09fan), data._fan);

    if( !tModel->submitAll() ) msgCritical("insertion erreur", tModel->lastError().text());

}

