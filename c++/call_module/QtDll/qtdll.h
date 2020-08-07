#ifndef QTDLL_H
#define QTDLL_H

#   ifdef WIN32
#    define Q_DECL_EXPORT     __declspec(dllexport)
#    define Q_DECL_IMPORT     __declspec(dllimport)
#   else
#    define Q_DECL_EXPORT     __attribute__((visibility("default")))
#    define Q_DECL_IMPORT     __attribute__((visibility("default")))
#    define Q_DECL_HIDDEN     __attribute__((visibility("hidden")))
#  endif

extern "C"{
int Q_DECL_EXPORT __cdecl add(int a, int b);
}

#endif // QTDLL_H
