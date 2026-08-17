#ifndef _ACI_MAIN_H
#define _ACI_MAIN_H

//
// Include files
//
#include "aci.h"        	//!< Include header for the ACI object
#include "aci_const.h"      //!< Include header for the ACI_CONST object
#include "aci_fe.h"        	//!< Include header for the ACIFE object
#include "aci_fe_const.h"   //!< Include header for the ACIFE_Const object
#include "aci_se.h"        	//!< Include header for the ACISE object
#include "aci_se_const.h"   //!< Include header for the ACISE_Const object
#include "clarke.h"         //!< Include header for the CLARKE object
#include "iclarke.h"        //!< Include header for the ICLARKE object
#include "ipark.h"       	//!< Include header for the IPARK object
#include "park.h"       	//!< Include header for the PARK object
#include "pid_reg3.h"       //!< Include header for the PIDREG3 object
#include "svgen.h"          //!< Include header for the SVGEN object

//
// Defines
//

#define DLOG_NUMBER_SAMPLES  1024

#define SIGNAL_CHAIN 1

void ACI_main(void);

#endif   //_ACI_MAIN_H
