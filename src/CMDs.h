#ifndef CMDS_H
#define CMDS_H

#include <cstdint>
#include <memory>
#include <QString>
#include <QJsonObject>


#ifdef DEBUG_IO
    #include <QDebug>
#endif

#include "cmdabstract.h"

namespace CMDs{


    class CMD_MOVE_mSTEPS : public virtual CMDAbstract {
        public:
        ~CMD_MOVE_mSTEPS() override {
            qDebug() << "Destructor of CMD_MOVE_mSTEPS";
        }

        config_t execute() override {
            qDebug() << "From CMD_MOVE_mSTEPS ";
            mStorage->add(configsNames::steps, mCMD.second.second);
            return  mCMD.second.second;
        }
    };

    class CMD_MOVE_mm : public virtual CMDAbstract {
        public:
        ~CMD_MOVE_mm() override {
            qDebug() << "Destructor of CMD_MOVE_mm";
        }
        config_t execute() override {
            qDebug() << "From CMD_MOVE_mm";
            auto steps = mCMD.second.second * mStorage->get(configsNames::microStepsInMM);
            mStorage->add(configsNames::steps, steps);
            return mCMD.second.second;
        }
    };

    class CMD_SET : public virtual CMDAbstract {
        public:
        ~CMD_SET() override {
            qDebug() << "Destructor of CMD_SET";
        }
        config_t execute() override {
            qDebug() << "From CMD_SET";
            mStorage->add( mCMD.second.first, mCMD.second.second );
            return mCMD.second.second;
        }
    };

    class CMD_GET : public virtual CMDAbstract {
        public:
        ~CMD_GET() override {
            qDebug() << "Destructor of CMD_GET";
        }
        config_t execute() override {
            qDebug() << "From CMD_GET";
            return mStorage->get( mCMD.second.first );
        }
    };

    class CMD_SET_ZERO : public virtual CMDAbstract {
        public:
        ~CMD_SET_ZERO() override {
            qDebug() << "Destructor of CMD_SET_ZERO";
        }
        config_t execute() override {
            qDebug() << "From CMD_SET_ZERO";
            mStorage->add(configsNames::distanceToZero, 0);
            return 0;
        }
    };

    class CMD_BACK_TO_ZERO : public virtual CMDAbstract {
        public:
        ~CMD_BACK_TO_ZERO() override {
            qDebug() << "Destructor of CMD_BACK_TO_ZERO";
        }
        config_t execute() override {
            qDebug() << "From CMD_BACK_TO_ZERO";
            return mStorage->get(configsNames::distanceToZero);
        }
    };


};

#endif // CMDS_H
