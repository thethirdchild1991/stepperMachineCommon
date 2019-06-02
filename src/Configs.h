#ifndef CONFIGS_H
#define CONFIGS_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include "ConfigHelper.h"

using namespace CONFIGS;

class ConfigsStorage
{    

public:
    explicit ConfigsStorage( const QString& filename ) : m_filename(filename)
    {
    }

    void load(){
        QFile configsFile( m_filename );

        if (!configsFile.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open save file.");
            return;
        }

        QJsonDocument configsDoc( QJsonDocument::fromJson( configsFile.readAll() ) );

        parseJson(configsDoc.object());
        configsFile.close();
    }
    void save() const {
        QFile configsFile( m_filename );

        if (!configsFile.open(QIODevice::WriteOnly)) {
            qWarning("Couldn't open save file.");
            return;
        }

        QJsonObject configObject;

        QJsonDocument configDoc(configObject);

        configsFile.write(configDoc.toJson());
        configsFile.close();

    }

    void add( const configsNames name, const config_t value );
    config_t get( const configsNames configName ) const { return m_configs.value( configName ); }

    void parseJson( const QJsonObject& jsonObject ){
        for( auto key : jsonObject.keys() ){
            auto value = toConfig_t(jsonObject.value(key));
            auto configName = toConfigName(key);
            add(configName, value);
        }
    }

private:

    QMap<configsNames, config_t> m_configs;
    QString m_filename;
};

#endif // CONFIGS_H
