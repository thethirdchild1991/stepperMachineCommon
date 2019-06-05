#ifndef CONFIGHELPER_H
#define CONFIGHELPER_H

#include "confignames.h"
#include <QJsonValue>
#include <QMap>
namespace CONFIGS {


    using config_t = uint32_t;
    static config_t toConfig_t( const QJsonValue& value ) { return static_cast<config_t>(value.toInt()); }

    static QMap<uint8_t, std::pair<QString, configsNames>> configsMap(){
//        QMap<QString, configsNames> map = {
//            {QString("speed"),                  configsNames::speed },
//            {QString("acceleration"),           configsNames::acceleration },
//            {QString("microStepsInMM"),         configsNames::microStepsInMM},
//            {QString("mmInRotation"),           configsNames::mmInRotation},
//            {QString("microStepsInRotation"),   configsNames::microStepsInRotation},
//            {QString("N"),                      configsNames::N},
//            {QString("distanceToZero"),         configsNames::distanceToZero},
//            {QString("steps"),                  configsNames::steps}
//        };

        QMap<uint8_t, std::pair<QString, configsNames>> map = {
            {0, {QString("speed"),                  configsNames::speed } },
            {1, {QString("acceleration"),           configsNames::acceleration } },
            {2, {QString("microStepsInMM"),         configsNames::microStepsInMM} },
            {3, {QString("mmInRotation"),           configsNames::mmInRotation} },
            {4, {QString("microStepsInRotation"),   configsNames::microStepsInRotation} },
            {5, {QString("N"),                      configsNames::N} },
            {6, {QString("distanceToZero"),         configsNames::distanceToZero} },
            {7, {QString("steps"),                  configsNames::steps} }
        };

        return map;
    }

    static QStringList getParamsNames(){

        auto helper = configsMap();

        QStringList names;

        for( uint8_t key = 0; key < helper.keys().size(); key++ ){
            names.push_back( helper.value(key).first );
        }
//        for(auto key : helper.keys()){
//            names.push_back(key);
//        }
        return names;
    }

    static configsNames toConfigName( const QString& name ) {
//        auto namesHelper = configsMap();
//        return namesHelper.value(name);
    }

}


#endif // CONFIGHELPER_H
