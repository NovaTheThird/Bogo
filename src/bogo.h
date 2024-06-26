//-----------------------------------------------------------------------------
//
// Name:    bogo.h
// Author:  Nicholas Brennan
// Purpose: Bogo sort functions
//
// Date Created: 05/03/2024
// Last Updated: 05/03/2024
//
//-----------------------------------------------------------------------------

#pragma once


//-----------------------------------------------------------------------------
// Include Files:
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Forward References:
//-----------------------------------------------------------------------------

typedef struct Bogo Bogo;

//-----------------------------------------------------------------------------
// Public Constants:
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Public Structures:
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Public Variables:
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Public Functions:
//-----------------------------------------------------------------------------

Bogo* CreateBogo(unsigned size);
void FreeBogo(Bogo* bogo);
void SetPrint(Bogo* bogo, int newPrint);
int GetPrint(Bogo* bogo);
void Sort(Bogo* bogo);
void Dump(Bogo* bogo);