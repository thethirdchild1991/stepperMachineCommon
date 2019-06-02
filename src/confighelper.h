#ifndef CONFIGHELPER_H
#define CONFIGHELPER_H

#include "confignames.h"
#include <QJsonValue>
#include <QMap>
namespace CONFIGS {


    using config_t = uint32_t;
    static config_t toConfig_t( const QJsonValue& value ) { return static_cast<config_t>(value.toInt()); }

    static QMap<QString, configsNames>configsMap(){
        QMap<QString, configsNames> map = {
            {QString("speed"),          configsNames::speed },
            {QString("acceleration"),   configsNames::acceleration },
            {QString("dS"),             configsNames::dS },
            {QString("SOnRotate"),      configsNames::SOnRotate },
            {QString("stepsOnRotate"),  configsNames::stepsOnRotate },
            {QString("N"),              configsNames::N },
            {QString("microStep"),      configsNames::microStep }
        };
        return map;
    }

    static QStringList getParamsNames(){

        auto helper = configsMap();

        QStringList names;
        for(auto key : helper.keys()){
            names.push_back(key);
        }
        return names;
    }

    static configsNames toConfigName( const QString& name ) {
        auto namesHelper = configsMap();
        return namesHelper.value(name);
    }

}


#endif // CONFIGHELPER_H
