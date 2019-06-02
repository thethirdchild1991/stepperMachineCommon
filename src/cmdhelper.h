#ifndef CMDHELPER_H
#define CMDHELPER_H

#include "cmdtype.h"
#include <QDataStream>
#include <QMap>

namespace CMDs {


inline QDataStream &operator<<(QDataStream &out, const CMDs::CMD_t &data){
    out << static_cast<uint8_t>(data.first)
        << static_cast<uint8_t>(data.second.first)
        << static_cast<uint8_t>(data.second.second);
    return out;
}

inline QDataStream &operator>>(QDataStream &in, CMDs::CMD_t &data)
{
    uint8_t tmp[3];
    in >> tmp[0] >> tmp[1] >> tmp[2];
    data.first = static_cast<CMDs::CMDs_NAMES>(tmp[0]);
    data.second.first = static_cast<CONFIGS::configsNames>(tmp[1]);
    data.second.second = tmp[2];

    return in;

}

static QMap<QString, CMDs_NAMES> cmdsMap(){

    QMap<QString, CMDs_NAMES> map = {
        {QString("MOVE_mSTEPS"),    CMDs_NAMES::MOVE_mSTEPS},
        {QString("MOVE_mm"),        CMDs_NAMES::MOVE_mm},
        {QString("SET"),            CMDs_NAMES::SET},
        {QString("GET"),            CMDs_NAMES::GET},
        {QString("SET_ZERO"),       CMDs_NAMES::SET_ZERO},
        {QString("BACK_TO_ZERO"),   CMDs_NAMES::BACK_TO_ZERO}
    };

    return  map;
}


static QStringList getCMDsNames(){

    auto helper = cmdsMap();

    QStringList names;
    for(auto key : helper.keys()){
        names.push_back(key);
    }
    return names;
}



}

#endif // CMDHELPER_H
