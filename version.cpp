#ifdef _WINDOWS
#include "version.hh"
#else
#include "@CMAKE_CURRENT_SOURCE_DIR@/version.hh"
#endif

using namespace tunage;
const std::string& Version::GIT_SHA1 = "";
const std::string& Version::GIT_DATE = "";
const std::string& Version::GIT_COMMIT_SUBJECT = "[NO COMMIT FOUND]";
