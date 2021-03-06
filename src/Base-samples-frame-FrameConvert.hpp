/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/*
 * Conversion functions for asn1SccBase_samples_frame_Frame.
 */

#ifndef BASE_SAMPLES_FRAME_FRAME_CONVERT
#define BASE_SAMPLES_FRAME_FRAME_CONVERT

#include "baseTypes.h"
#include <base/samples/Frame.hpp>
#include <base/samples/Frame.hpp>
#include <string.h>
#include <stdio.h>

#include "Base-TimeConvert.hpp"
#include "Base-TimeConvert.hpp"
#include "Base-samples-frame-frame-attrib-tConvert.hpp"
#include "Base-samples-frame-frame-size-tConvert.hpp"
#include "Base-samples-frame-frame-mode-tConvert.hpp"
#include "Base-samples-frame-frame-status-tConvert.hpp"


//Conversion functions from asn1 to c++ type

template <typename T>
void asn1SccBase_samples_frame_Frame_fromAsn1(base::samples::frame::Frame& result, const T & asnVal,    asn1SccT_UInt32 length_numBase_samples_frame_Frame_image=numBase_samples_frame_Frame_image,     asn1SccT_UInt32 length_numBase_samples_frame_Frame_attributes=numBase_samples_frame_Frame_attributes)
{

    asn1SccBase_Time_fromAsn1(result.time, asnVal.time);

    asn1SccBase_Time_fromAsn1(result.received_time, asnVal.received_time);

    result.image.resize(asnVal.image.nCount);
    for(int i = 0; i < asnVal.image.nCount;i++)
    {
        result.image[i] = asnVal.image.arr[i];
    }

    result.attributes.resize(asnVal.attributes.nCount);
    for(int i = 0; i < asnVal.attributes.nCount;i++)
    {
        asn1SccBase_samples_frame_frame_attrib_t_fromAsn1(result.attributes[i], asnVal.attributes.arr[i]);
    }

    asn1SccBase_samples_frame_frame_size_t_fromAsn1(result.size, asnVal.size_t);

    result.data_depth = asnVal.data_depth;

    result.pixel_size = asnVal.pixel_size;

    result.row_size = asnVal.row_size;

    asn1SccBase_samples_frame_frame_mode_t_fromAsn1(result.frame_mode, asnVal.frame_mode);

    asn1SccBase_samples_frame_frame_status_t_fromAsn1(result.frame_status, asnVal.frame_status);

}

//Conversion functions from C++ to Asn1 type

template <typename T>
void asn1SccBase_samples_frame_Frame_toAsn1(T & result, const base::samples::frame::Frame& baseObj,    asn1SccT_UInt32 length_numBase_samples_frame_Frame_image=numBase_samples_frame_Frame_image,     asn1SccT_UInt32 length_numBase_samples_frame_Frame_attributes=numBase_samples_frame_Frame_attributes)
{


    asn1SccBase_Time_toAsn1(result.time, baseObj.time);


    asn1SccBase_Time_toAsn1(result.received_time, baseObj.received_time);

    if( baseObj.image.size() > numBase_samples_frame_Frame_image)
    {
        fprintf(stderr, "WARNING:  truncated image of asn1SccBase_samples_frame_Frame to %lld elements.\n",numBase_samples_frame_Frame_image);
        result.image.nCount = numBase_samples_frame_Frame_image;
    }
    else
    {
        result.image.nCount = baseObj.image.size();
    }

    for(int i = 0; i < result.image.nCount ;i++)
    {
        result.image.arr[i]= baseObj.image[i];
    }

    if( baseObj.attributes.size() > numBase_samples_frame_Frame_attributes)
    {
        fprintf(stderr, "WARNING:  truncated attributes of asn1SccBase_samples_frame_Frame to %lld elements.\n",numBase_samples_frame_Frame_attributes);
        result.attributes.nCount = numBase_samples_frame_Frame_attributes;
    }
    else
    {
        result.attributes.nCount = baseObj.attributes.size();
    }

    for(int i = 0; i < result.attributes.nCount;i++)
    {
        asn1SccBase_samples_frame_frame_attrib_t_toAsn1(result.attributes.arr[i], baseObj.attributes[i]);
    }


    asn1SccBase_samples_frame_frame_size_t_toAsn1(result.size_t, baseObj.size);


    result.data_depth = baseObj.data_depth;


    result.pixel_size = baseObj.pixel_size;


    result.row_size = baseObj.row_size;


    asn1SccBase_samples_frame_frame_mode_t_toAsn1(result.frame_mode, baseObj.frame_mode);


    asn1SccBase_samples_frame_frame_status_t_toAsn1(result.frame_status, baseObj.frame_status);

}


#endif //BASE_SAMPLES_FRAME_FRAME_CONVERT
