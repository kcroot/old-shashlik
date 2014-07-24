#define LOG_TAG "appproc"

//#include <stdlib.h>
//#include <stdio.h>
//#include <unistd.h>

//#include <cutils/properties.h>
//#include <binder/IPCThreadState.h>
//#include <binder/ProcessState.h>
//#include <utils/Log.h>
//#include <cutils/process_name.h>
//#include <cutils/memory.h>
//#include <cutils/trace.h>
//#include <android_runtime/AndroidRuntime.h>
//#include <sys/personality.h>

#include "runtime/ShashlikRuntime.h"


namespace shashlik {

class JNIEnv;


using namespace android;

class AppRuntime : public ShashlikRuntime
{
public:
    AppRuntime();
    ~AppRuntime();

    void setParentDir(const char* parentDir);
#if 0
    // this appears to be unused
    const char* getParentDir() const;
#endif

    void setClassName(const char *className);
    const char* getClassName() const;

    void setArgcArgv(int argc, const char *const *argv);

    // Reimplemented virtual functions
    virtual void onVmCreated(JNIEnv* env);
    virtual void onStarted();
    virtual void onZygoteInit();
    virtual void onExit(int code);

private:

    const char*        m_parentDir;
    const char*        m_className;
    //jclass             m_class;  #temporarily disabled to make it build
    int                m_argC;
    const char* const* m_argV;
};


} // namespace shashlik

