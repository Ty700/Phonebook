#ifndef HELPERS_H
#define HELPERS_H

#define LOG(msg);                                \
    std::cout   << "==========\n"               \
                << "LOG: " << msg << "\n"       \
                << "==========" << std::endl;

#ifdef _WIN32
    #define CLEAR_SCREEN(); system("cls");
#else
    #define CLEAR_SCREEN(); system("clear");
#endif /* _WIN32 */

#endif /* HELPERS_H */
