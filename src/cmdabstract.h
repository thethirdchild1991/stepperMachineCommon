#ifndef CMDABSTRACT_H
#define CMDABSTRACT_H

#include "cmdtype.h"
#include "Configs.h"

namespace CMDs {

class CMDAbstract {
    public:

        virtual ~CMDAbstract() = 0;
        virtual config_t execute() = 0;

//        static std::unique_ptr<CMDAbstract> createCMD( CMD_t& cmd );
        static std::unique_ptr<CMDAbstract> createCMD( CMD_t& cmd, std::shared_ptr<ConfigsStorage> storage );

    protected:
        CMD_t mCMD;
        std::shared_ptr<ConfigsStorage> mStorage;

};


}

#endif // CMDABSTRACT_H
