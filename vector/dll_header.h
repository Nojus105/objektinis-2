#pragma once

#include "vector.h" // Ensure this is necessary

#ifdef EXPORTING_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

// Forward declaration of Zmogus
class Zmogus;

/**
 * @brief Exported function for the DLL.
 *
 * This function will be exported and can be used by other applications.
 */
DLL_API void Faile(Vektorius<Zmogus *> &grupe, char gal, double &TotalTime);