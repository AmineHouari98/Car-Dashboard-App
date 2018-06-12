#ifndef ENUMTABLES_H
#define ENUMTABLES_H
#include <QString>
#include <QStringList>
#include <QMetaType>

class EnumTableSensors
{
public:
    QString tableName ;
    QStringList columnsList;


    void EnumColumnSensors()
    {
        tableName = "sensors_logs";
        columnsList << "id integer primary key autoincrement not null";
        columnsList << "Date DATETIME";
        columnsList << "charge_moteur  INTEGER";
        columnsList << "temp_liquide_froidissement INTEGER";
        columnsList << "regime_moteur INTEGER";
        columnsList << "vitesse_vehicule INTEGER";
        columnsList << "temperature_air_admission INTEGER";
        columnsList << "duree_demarrage_moteur INTEGER";
        columnsList << "reservoir INTEGER";
        columnsList << "pression_atmospherique INTEGER";
        columnsList << "temp_catalyseur INTEGER";
        columnsList << "temp_air_ambiante INTEGER";
        columnsList << "position_pedale_accelerateur INTEGER";
    }

    enum ColumnName
    {
        _00id,
        _01Date,
        _02charge_moteur,
        _03temp_liquide_froidissement,
        _04regime_moteur,
        _05vitesse_vehicule,
        _06temperature_air_admission,
        _07duree_demarrage_moteur,
        _08reservoir,
        _09pression_atmospherique,
        _10temp_catalyseur,
        _11temp_air_ambiante,
        _12position_pedale_accelerateur
    };
};

class EnumTableGps
{
public:
    QString tableName ;
    QStringList columnsList;


    void EnumColumnGps()
    {
        tableName = "gps_logs";
        columnsList << "id integer primary key autoincrement not null";
        columnsList << "Date DATETIME";
        columnsList << "longitude REAL";
        columnsList << "latitude REAL";
        columnsList << "altitude REAL";

    }

    enum ColumnName
    {
        _00id,
        _01Date,
        _02longitude,
        _03latitude,
        _04altitude,

    };
};



// hadi ki tabgi tarsel ahdi class bin deux class over signal as paramter
// emit save(EnumRecord data ) ;
//Q_DECLARE_METATYPE(EnumRecord);


#endif // ENUMTABLES_H
