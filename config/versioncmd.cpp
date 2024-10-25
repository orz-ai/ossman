
#include "versioncmd.h"

VersionCmd::VersionCmd(int argc, char *argv[])
{
    if(argc == 2)
    {
        QString args = argv[1];
        mArgv = args.split(".");
    }
}

void VersionCmd::setVersion()
{
    if(!isValid())
    {
        throw QString::fromLocal8Bit("√¸¡Ó––∏Ò Ω¥ÌŒÛ 1%").arg(mArgv.join("."));
    }

    m_major = mArgv[0];
    m_env = mArgv[1];
    m_v1 = mArgv[2].toInt();
    m_v2 = mArgv[3].toInt();
    m_v3 = mArgv[4].toInt();
}

bool VersionCmd::isValid()
{
    return mArgv.size() == 5;
}
